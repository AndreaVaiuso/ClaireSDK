package iotsdk;

import javax.swing.*;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;

import java.awt.*;

import javax.swing.text.*;
import javax.swing.undo.UndoManager;

public class CodePane extends JScrollPane {

	private static final long serialVersionUID = 1L;
	private JTextPane tp;
	public JTextPane getTp() {
		return tp;
	}

	public void setTp(JTextPane tp) {
		this.tp = tp;
	}

	private UndoManager undoManager;

	private int findLastNonWordChar (String text, int index) {
		while (--index >= 0) {
			if (String.valueOf(text.charAt(index)).matches("\\W")) {
				break;
			}
		}
		return index;
	}

	private int findFirstNonWordChar (String text, int index) {
		while (index < text.length()) {
			if (String.valueOf(text.charAt(index)).matches("\\W")) {
				break;
			}
			index++;
		}
		return index;
	}

	public CodePane () {

		final StyleContext cont = StyleContext.getDefaultStyleContext();
		final AttributeSet kw2 = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c6);
		final AttributeSet numeric = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c2);
		final AttributeSet kw1 = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c5);
		final AttributeSet deviceid = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c4);
		final AttributeSet booleans = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c1);
		final AttributeSet strings = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.c3);
		final AttributeSet plainTextColor = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, ClaireSDK.settings.plainTextCode);


		DefaultStyledDocument doc = new DefaultStyledDocument() {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			public void insertString (int offset, String str, AttributeSet a) throws BadLocationException {
				super.insertString(offset, str, a);
				String text = getText(0, getLength());
				int before = findLastNonWordChar(text, offset);
				if (before < 0) before = 0;
				int after = findFirstNonWordChar(text, offset + str.length());
				int wordL = before;
				int wordR = before;
				while (wordR <= after) {
					if (wordR == after || String.valueOf(text.charAt(wordR)).matches("\\W")) {
						coloring(text,wordL,wordR);
						wordL = wordR;
					}
					wordR++;
				}
			}

			public void remove (int offs, int len) throws BadLocationException {
				super.remove(offs, len);
				String text = getText(0, getLength());
				int before = findLastNonWordChar(text, offs);
				if (before < 0) before = 0;
				int after = findFirstNonWordChar(text, offs);
				coloring(text,before,after);
			}

			private void coloring(String text,int l, int r) {
				String tx = text.substring(l,r); 

				if (tx.matches("(\\W)?(if|else|while|end|repeat|do|increase|decrease|by|endif)")) {
					setCharacterAttributes(l, r - l, kw1, false);
				} 
				else if (tx.matches("(\\W)?(collection|function|connect|return|is|break|\\?)")) {
					setCharacterAttributes(l, r - l, kw2, false);
				}
				else if (tx.matches("(\\W)?^#[A-Z0-9]+")) {
					setCharacterAttributes(l, r - l, deviceid, false);
				}
				else if (tx.matches("(\\W)?(yes|no)")) {
					setCharacterAttributes(l, r - l, booleans, false);
				}
				else if (tx.matches("(\\W)?[0-9]+\\.?[0-9]*")) {
					setCharacterAttributes(l, r - l, numeric, false);
				}
				else if (tx.matches("(\\W)?^\\\".*")) {
					setCharacterAttributes(l, r - l, strings, false);
				}
				else {
					setCharacterAttributes(l, r - l, plainTextColor, false);
				}
			}
		};

		setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.GRAY));
		tp = new JTextPane(doc);
		//setTabs(tp,5);
		tp.setBorder(BorderFactory.createCompoundBorder(tp.getBorder(), BorderFactory.createEmptyBorder(5, 5, 5, 5)));
		tp.setFont(ClaireSDK.settings.codeFont);
		tp.setForeground(ClaireSDK.settings.plainText);
		tp.setBackground(ClaireSDK.settings.codebkg);
		this.setViewportView(tp);
		tp.addCaretListener(new CaretListener() {
			public void caretUpdate(CaretEvent e) {
				try {
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});

		TextLineNumber tln = new TextLineNumber(tp);
		setRowHeaderView( tln );
		LinePainter lp = new LinePainter(tp);
		lp.setColor(ClaireSDK.settings.bkgc3);
		undoManager = new UndoManager();
		tp.getDocument().addUndoableEditListener(undoManager);

	}
	public void undo() {
		try {
			undoManager.undo();
			undoManager.undo();
		} catch (Exception e) {

		}
	}

	public void redo() {
		try {
			undoManager.redo();
			undoManager.redo();
		} catch (Exception e) {

		}
	}

	public void setText(String s) {
		tp.setText(s);
	}

	@Override
	public String toString() {
		return tp.getText();
	}

	public static void setTabs( JTextPane textPane, int charactersPerTab){
		FontMetrics fm = textPane.getFontMetrics( textPane.getFont() );
		int charWidth = fm.charWidth( 'w' );
		int tabWidth = charWidth * charactersPerTab;

		TabStop[] tabs = new TabStop[10];

		for (int j = 0; j < tabs.length; j++)
		{
			int tab = j + 1;
			tabs[j] = new TabStop( tab * tabWidth );
		}

		TabSet tabSet = new TabSet(tabs);
		SimpleAttributeSet attributes = new SimpleAttributeSet();
		StyleConstants.setTabSet(attributes, tabSet);
		int length = textPane.getDocument().getLength();
		textPane.getStyledDocument().setParagraphAttributes(0, length, attributes, true);
	}

}
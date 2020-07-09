package iotsdk;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.BorderFactory;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.UIManager;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.undo.UndoManager;

public class CodeTextPane extends JScrollPane {
	
	private JTextPane tp;
	private HashMap<String, Color> colorSet = new HashMap<>();
	
	public CodeTextPane() {
		setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.GRAY.brighter()));
		tp = new JTextPane();
		tp.setBorder(BorderFactory.createCompoundBorder(tp.getBorder(), BorderFactory.createEmptyBorder(5, 5, 5, 5)));
		tp.setFont(new Font("SF Mono", Font.PLAIN, 12));
		tp.setForeground(new Color(0, 0, 0));
		tp.setBackground(UIManager.getColor("Button.background"));
		this.setViewportView(tp);
		tp.addCaretListener(new CaretListener() {
			public void caretUpdate(CaretEvent e) {
				try {
					matchWord();
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
		
		TextLineNumber tln = new TextLineNumber(tp);
		setRowHeaderView( tln );
		UndoManager undoManager = new UndoManager();
		tp.getDocument().addUndoableEditListener(undoManager);

		tp.addKeyListener(new KeyListener(){
			@Override
			public void keyPressed(KeyEvent e){
				if((e.getKeyCode() == KeyEvent.VK_Z) && ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)){
					e.consume();
					System.out.println("Hello\n");
					undoManager.undo();
				}
				if((e.getKeyCode() == KeyEvent.VK_Y) && ((e.getModifiers() & KeyEvent.CTRL_MASK) != 0)){
					e.consume();
					undoManager.redo();
				}
			}

			@Override
			public void keyTyped(KeyEvent e) {
			}

			@Override
			public void keyReleased(KeyEvent e) {
			}
		});
	}
	
	public void matchWord() throws Exception {
		Pattern stringPattern = Pattern.compile("(?:(?<=int|float|String|double|char|long)(?:\\s+[a-zA-Z_$][\\w$]*\\s*)|(?<=\\G,)(?:\\s*[a-zA-Z_$][\\w$]*\\s*))(?=,|;|=)");
		Matcher matcherS = stringPattern.matcher(tp.getText());
		while (matcherS.find())
			changeColor(matcherS.group(), Color.RED, matcherS.start(), matcherS.end() - matcherS.start());
	}

	
	
	private void changeColor(String msg, Color c, int beginIndex, int length) throws Exception {
        SimpleAttributeSet sas = new SimpleAttributeSet(); 
        StyleConstants.setForeground(sas, c);
        StyledDocument doc = (StyledDocument)tp.getDocument();
        doc.setCharacterAttributes(beginIndex, length, sas, false);
        sas = new SimpleAttributeSet(); 
        StyleConstants.setForeground(sas, Color.BLACK);
        tp.setCharacterAttributes(sas, false);
    }

}

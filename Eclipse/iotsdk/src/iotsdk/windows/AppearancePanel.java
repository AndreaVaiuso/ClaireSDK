package iotsdk.windows;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GraphicsEnvironment;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import iotsdk.ClaireSDK;
import iotsdk.CodePane;
import iotsdk.SelAction;

public class AppearancePanel extends JPanel {
	
	private JComboBox<SelAction> comboBox;
	private JComboBox<SelAction> codeFontBox;
	private JComboBox<SelAction> colorSchemeBox;
	private JSpinner spinner;
	
	private Color newColor;
	private JLabel colorLabel;
	
	private GridBagConstraints gbc_panel_3;

	private CodePane codPane;
	
	public AppearancePanel() {
		setOpaque(false);

		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{118, 205, 46, 0};
		gbl_panel.rowHeights = new int[]{0, 0, 0, 53, 0, 0, 10, 0};
		gbl_panel.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, Double.MIN_VALUE};
		setLayout(gbl_panel);
		
		JLabel lblNewLabel_1 = new JLabel("Theme");
		lblNewLabel_1.setForeground(ClaireSDK.settings.plainText);
		
		colorLabel = new JLabel("");
		colorLabel.setMinimumSize(new Dimension(20,20));
		colorLabel.setPreferredSize(new Dimension(20,20));
		colorLabel.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.DARK_GRAY));
		colorLabel.setOpaque(true);
		
		comboBox = new JComboBox<SelAction>();
		comboBox.setModel(new DefaultComboBoxModel<SelAction>(new SelAction[] {
				new SelAction("Light") {
					@Override
					public void performAction() {
						ClaireSDK.settings.setLightTheme();
					}
				},
				new SelAction("Dark") {
					@Override
					public void performAction() {
						ClaireSDK.settings.setDarkTheme();
					}
				},
				new SelAction("Blue") {
					@Override
					public void performAction() {
						ClaireSDK.settings.setBlueTheme();
					}
				},
				new SelAction("Graphite") {
					@Override
					public void performAction() {
						ClaireSDK.settings.setGraphiteTheme();
					}
				}}));
		if(ClaireSDK.settings.themeSelected.equals("Light")) {
			comboBox.setSelectedIndex(0);
		} else if(ClaireSDK.settings.themeSelected.equals("Dark")) {
			comboBox.setSelectedIndex(1);
		} else if(ClaireSDK.settings.themeSelected.equals("Blue")) {
			comboBox.setSelectedIndex(2);
		} else if(ClaireSDK.settings.themeSelected.equals("Graphite")) {
			comboBox.setSelectedIndex(3);
		}
		comboBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SelAction action = (SelAction) comboBox.getSelectedItem();
				action.performAction();
				updatePaneExample();
			}
		});
		
		int selectedFont = 0;
		
		String fonts[] = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
		SelAction setFontVec[] = new SelAction[fonts.length];
		for(int i = 0; i<fonts.length;i++) {
			setFontVec[i] = new SelAction(fonts[i]) {
				@Override
				public void performAction() {
					ClaireSDK.settings.setFontFamily(this.toString());
				}
			};
			if(fonts[i].equals(ClaireSDK.settings.getFontFamily())) selectedFont = i;
		}
		
		
		codeFontBox = new JComboBox<SelAction>();
		codeFontBox.setModel(new DefaultComboBoxModel<SelAction>(setFontVec));
		codeFontBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SelAction action = (SelAction) codeFontBox.getSelectedItem();
				action.performAction();
				updatePaneExample();
			}
		});
		
		codeFontBox.setSelectedIndex(selectedFont);
		
		
		colorSchemeBox = new JComboBox<>();
		colorSchemeBox.setModel(new DefaultComboBoxModel<SelAction>(new SelAction[] { 
				new SelAction("Plain Text") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.plainTextCode);
					}
				},
				new SelAction("Boolean values") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c1);
					}
				},
				new SelAction("Numeric values") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c2);
					}
				},
				new SelAction("Strings") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c3);
					}
				},
				new SelAction("Device's IDs") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c4);
					}
				},new SelAction("Keywords 1") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c5);
					}
				},new SelAction("Keywords 2") {
					@Override
					public void performAction() {
						colorLabel.setBackground(ClaireSDK.settings.c6);
					}
				}}));
		colorSchemeBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SelAction action = (SelAction) colorSchemeBox.getSelectedItem();
				action.performAction();
				updatePaneExample();
			}
		});
		colorSchemeBox.setSelectedIndex(0);
		SelAction action = (SelAction) colorSchemeBox.getSelectedItem();
		action.performAction();
		
		JLabel lblNewLabel_3 = new JLabel("Code font");
		lblNewLabel_3.setForeground(ClaireSDK.settings.plainText);
		
		JLabel lblNewLabel_4 = new JLabel("Font size");
		lblNewLabel_4.setForeground(ClaireSDK.settings.plainText);
		
		spinner = new JSpinner(new SpinnerNumberModel(ClaireSDK.settings.getFontSize(), 11, 35, 1));
		spinner.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				ClaireSDK.settings.changeFontSize((Integer) spinner.getValue());
				updatePaneExample();
			}
		});
		
		JLabel lblNewLabel_2 = new JLabel("Color scheme");
		lblNewLabel_2.setForeground(ClaireSDK.settings.plainText);
		
		JPanel panel_2 = new JPanel();
		panel_2.setOpaque(false);
		panel_2.setBackground(ClaireSDK.settings.bkgc1);
	
		
		JButton changeColorBtn = new JButton("Choose Color");
		changeColorBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Color c = JColorChooser.showDialog((JFrame)SwingUtilities.getWindowAncestor(AppearancePanel.this),"Choose Color", Color.WHITE);
				if(c!=null) {
					setNewColor(c);
					colorLabel.setBackground(newColor);
					switch(colorSchemeBox.getSelectedIndex()) {
					case 0: ClaireSDK.settings.plainTextCode = newColor; break;
					case 1: ClaireSDK.settings.c1 = newColor; break;
					case 2: ClaireSDK.settings.c2 = newColor; break;
					case 3: ClaireSDK.settings.c3 = newColor; break;
					case 4: ClaireSDK.settings.c4 = newColor; break;
					case 5: ClaireSDK.settings.c5 = newColor; break;
					case 6: ClaireSDK.settings.c6 = newColor; break;
					}
					updatePaneExample();
				}
			}
		});
		panel_2.add(colorLabel);
		panel_2.add(changeColorBtn);
		
		codPane = new CodePane();
		
		/* Adding elements to panel*/
		gbc_panel_3 = new GridBagConstraints();
		gbc_panel_3.insets = new Insets(0, 0, 5, 5);
		gbc_panel_3.fill = GridBagConstraints.BOTH;
		gbc_panel_3.gridx = 1;
		gbc_panel_3.gridy = 5;
		add(codPane, gbc_panel_3);
		
		GridBagConstraints gbc_comboBox = new GridBagConstraints();
		gbc_comboBox.insets = new Insets(0, 0, 5, 5);
		gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
		gbc_comboBox.gridx = 1;
		gbc_comboBox.gridy = 0;
		add(comboBox, gbc_comboBox);
		
		GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
		gbc_lblNewLabel_1.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_1.gridx = 0;
		gbc_lblNewLabel_1.gridy = 0;
		add(lblNewLabel_1, gbc_lblNewLabel_1);
		
		GridBagConstraints gbc_lblNewLabel_3 = new GridBagConstraints();
		gbc_lblNewLabel_3.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_3.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_3.gridx = 0;
		gbc_lblNewLabel_3.gridy = 1;
		add(lblNewLabel_3, gbc_lblNewLabel_3);
		
		GridBagConstraints gbc_panel_2 = new GridBagConstraints();
		gbc_panel_2.anchor = GridBagConstraints.WEST;
		gbc_panel_2.insets = new Insets(0, 0, 5, 5);
		gbc_panel_2.fill = GridBagConstraints.VERTICAL;
		gbc_panel_2.gridx = 1;
		gbc_panel_2.gridy = 4;
		add(panel_2, gbc_panel_2);
		
		GridBagConstraints gbc_codeFontBox = new GridBagConstraints();
		gbc_codeFontBox.insets = new Insets(0, 0, 5, 5);
		gbc_codeFontBox.fill = GridBagConstraints.HORIZONTAL;
		gbc_codeFontBox.gridx = 1;
		gbc_codeFontBox.gridy = 1;
		add(codeFontBox, gbc_codeFontBox);
		
		GridBagConstraints gbc_lblNewLabel_4 = new GridBagConstraints();
		gbc_lblNewLabel_4.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_4.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_4.gridx = 0;
		gbc_lblNewLabel_4.gridy = 2;
		add(lblNewLabel_4, gbc_lblNewLabel_4);
		
		GridBagConstraints gbc_spinner = new GridBagConstraints();
		gbc_spinner.anchor = GridBagConstraints.WEST;
		gbc_spinner.insets = new Insets(0, 0, 5, 5);
		gbc_spinner.gridx = 1;
		gbc_spinner.gridy = 2;
		add(spinner, gbc_spinner);
		
		GridBagConstraints gbc_lblNewLabel_2 = new GridBagConstraints();
		gbc_lblNewLabel_2.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_2.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_2.gridx = 0;
		gbc_lblNewLabel_2.gridy = 3;
		add(lblNewLabel_2, gbc_lblNewLabel_2);
		
		GridBagConstraints gbc_colorSchemeBox = new GridBagConstraints();
		gbc_colorSchemeBox.insets = new Insets(0, 0, 5, 5);
		gbc_colorSchemeBox.fill = GridBagConstraints.HORIZONTAL;
		gbc_colorSchemeBox.gridx = 1;
		gbc_colorSchemeBox.gridy = 3;
		add(colorSchemeBox, gbc_colorSchemeBox);
		
		updatePaneExample();
	}
	
	public void updatePaneExample() {
		SwingUtilities.invokeLater(new Runnable() {
		    public void run() {
		    	remove(codPane);
				codPane = new CodePane();
				codPane.getTp().setText("connect dev1 #XA123;\nexamplevar is 32.1;\nexamplevar?\n\tif 15, var2 is f(examplevar);\n\tif 0 var3 is \"hello\";\nend;\nf(x) is\n\twhile x<100 do\n\t\treturn yes;\n\tend;\nend;");
				codPane.getTp().setEditable(false);
				add(codPane, gbc_panel_3);
				codPane.revalidate();
				codPane.repaint();
				revalidate();
				repaint();
		    }
		  });
	}
	

	public Color getNewColor() {
		return newColor;
	}

	public void setNewColor(Color newColor) {
		this.newColor = newColor;
	}

}

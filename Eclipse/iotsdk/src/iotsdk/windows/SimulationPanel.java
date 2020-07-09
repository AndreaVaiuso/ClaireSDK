package iotsdk.windows;

import java.io.File;

import javax.swing.JPanel;

import iotsdk.ClaireSDK;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

import java.awt.Font;
import javax.swing.event.CaretListener;
import javax.swing.event.CaretEvent;

public class SimulationPanel extends JPanel {


	private JTextField textField;
	private JLabel unstableLabel;
	private JLabel sensorCountLabel;
	private JTextField projectPathField;

	public SimulationPanel(int sensorNumber) {
		setOpaque(false);
		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{156, 205, 18, 0};
		gbl_panel.rowHeights = new int[]{0, 0, 0, 20, 0, 0, 0, 0, 10, 0};
		gbl_panel.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, Double.MIN_VALUE};
		setLayout(gbl_panel);

		JLabel sclab = new JLabel("Sensor count");
		sclab.setForeground(ClaireSDK.settings.plainText);
		GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
		gbc_lblNewLabel.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel.gridx = 0;
		gbc_lblNewLabel.gridy = 1;
		add(sclab, gbc_lblNewLabel);

		JButton btnNewButton = new JButton("Clear sensor directory");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				clearSensorDirectory(sensorNumber);
			}
		});

		sensorCountLabel = new JLabel(sensorNumber+"");
		sensorCountLabel.setForeground(ClaireSDK.settings.plainText);
		GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
		gbc_lblNewLabel_1.anchor = GridBagConstraints.WEST;
		gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_1.gridx = 1;
		gbc_lblNewLabel_1.gridy = 1;
		add(sensorCountLabel, gbc_lblNewLabel_1);
		GridBagConstraints gbc_btnNewButton = new GridBagConstraints();
		gbc_btnNewButton.anchor = GridBagConstraints.WEST;
		gbc_btnNewButton.insets = new Insets(0, 0, 5, 5);
		gbc_btnNewButton.gridx = 1;
		gbc_btnNewButton.gridy = 2;
		add(btnNewButton, gbc_btnNewButton);

		JLabel lblNewLabel_2 = new JLabel("Refresh rate (ms)");
		lblNewLabel_2.setForeground(ClaireSDK.settings.plainText);
		GridBagConstraints gbc_lblNewLabel_2 = new GridBagConstraints();
		gbc_lblNewLabel_2.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_2.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_2.gridx = 0;
		gbc_lblNewLabel_2.gridy = 3;
		add(lblNewLabel_2, gbc_lblNewLabel_2);

		unstableLabel = new JLabel("Simulation could be unstable");
		unstableLabel.setForeground(ClaireSDK.settings.plainText2);
		unstableLabel.setVisible(false);
		if(ClaireSDK.settings.refreshRate<50) {
			unstableLabel.setVisible(true);
		}

		textField = new JTextField();
		textField.addCaretListener(new CaretListener() {
			public void caretUpdate(CaretEvent e) {
				try {
					int val = Integer.valueOf(textField.getText());
					if(val>0) {
						ClaireSDK.settings.refreshRate = val;
					}
				} catch (NumberFormatException ex) {} finally {
					if(ClaireSDK.settings.refreshRate<50) {
						unstableLabel.setVisible(true);
					} else {
						unstableLabel.setVisible(false);
					}
				}

			}
		});

		textField.setText(ClaireSDK.settings.refreshRate+"");
		GridBagConstraints gbc_textField = new GridBagConstraints();
		gbc_textField.insets = new Insets(0, 0, 5, 5);
		gbc_textField.fill = GridBagConstraints.HORIZONTAL;
		gbc_textField.gridx = 1;
		gbc_textField.gridy = 3;
		add(textField, gbc_textField);
		textField.setColumns(10);

		unstableLabel.setFont(new Font("Lucida Grande", Font.PLAIN, 10));
		GridBagConstraints gbc_lblNewLabel_3 = new GridBagConstraints();
		gbc_lblNewLabel_3.anchor = GridBagConstraints.WEST;
		gbc_lblNewLabel_3.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_3.gridx = 1;
		gbc_lblNewLabel_3.gridy = 4;
		add(unstableLabel, gbc_lblNewLabel_3);

		JLabel lblNewLabel = new JLabel("Project path");
		lblNewLabel.setBackground(ClaireSDK.settings.plainText);
		GridBagConstraints gbc_lblNewLabel2 = new GridBagConstraints();
		gbc_lblNewLabel2.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel2.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel2.gridx = 0;
		gbc_lblNewLabel2.gridy = 5;
		add(lblNewLabel, gbc_lblNewLabel2);

		projectPathField = new JTextField();
		projectPathField.setEditable(false);
		projectPathField.setText(ClaireSDK.settings.getSrcPath());
		GridBagConstraints gbc_projectPathField = new GridBagConstraints();
		gbc_projectPathField.insets = new Insets(0, 0, 5, 5);
		gbc_projectPathField.fill = GridBagConstraints.HORIZONTAL;
		gbc_projectPathField.gridx = 1;
		gbc_projectPathField.gridy = 5;
		add(projectPathField, gbc_projectPathField);
		projectPathField.setColumns(10);

		JButton btnNewButton_1 = new JButton("Browse");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser = new JFileChooser();
				chooser.setCurrentDirectory(new File(ClaireSDK.settings.getSrcPath()));
				chooser.setDialogTitle("Choose a directory");
				chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
				//chooser.setAcceptAllFileFilterUsed(false);  
				if (chooser.showOpenDialog((JFrame)SwingUtilities.getWindowAncestor(SimulationPanel.this)) == JFileChooser.APPROVE_OPTION) { 
					ClaireSDK.settings.setSrcPath(chooser.getSelectedFile().getAbsolutePath());
					projectPathField.setText(ClaireSDK.settings.getSrcPath());
				}
			}
		});
		GridBagConstraints gbc_btnNewButton_1 = new GridBagConstraints();
		gbc_btnNewButton_1.anchor = GridBagConstraints.WEST;
		gbc_btnNewButton_1.insets = new Insets(0, 0, 5, 5);
		gbc_btnNewButton_1.gridx = 1;
		gbc_btnNewButton_1.gridy = 6;
		add(btnNewButton_1, gbc_btnNewButton_1);
	}

	private void clearSensorDirectory(int count) {
		if(ClaireSDK.app.getSimulation().getSensorList().isEmpty()) {
			File dir = new File(ClaireSDK.settings.getSrcPath()+"sensor");
			for(File file: dir.listFiles()) 
				if (!file.isDirectory()) 
					file.delete();
			ClaireSDK.app.alert("Deleted " + count + " sensor information");
			sensorCountLabel.setText("0");
		} else {
			ClaireSDK.app.alert("Your sensor list must be empty before you can delete all files");
		}

	}
}

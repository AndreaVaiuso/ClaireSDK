package iotsdk.windows;

import javax.swing.JFrame;
import java.awt.Window.Type;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import java.awt.GridBagConstraints;
import java.awt.Font;
import javax.swing.JPanel;

import iotsdk.Application;
import iotsdk.ClaireSDK;
import iotsdk.CodePane;
import iotsdk.SelAction;
import iotsdk.Settings;

import java.awt.Insets;
import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.BorderFactory;
import javax.swing.DefaultComboBoxModel;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.io.File;
import java.awt.event.ActionEvent;
import javax.swing.JTabbedPane;
import javax.swing.SpinnerNumberModel;
import javax.swing.JSpinner;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class SettingsWindow extends JFrame {
	
	
	public SettingsWindow() {
		setType(Type.UTILITY);
		setResizable(false);
		setBounds(300,300,560,444);
		setTitle("Preferences");
		GridBagLayout gridBagLayout = new GridBagLayout();
		gridBagLayout.columnWidths = new int[]{0, 0};
		gridBagLayout.rowHeights = new int[]{42, 0, 0, 0};
		gridBagLayout.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gridBagLayout.rowWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		getContentPane().setLayout(gridBagLayout);
		getContentPane().setBackground(ClaireSDK.settings.bkgc1);
		
		JLabel lblNewLabel = new JLabel("Preferences");
		
		lblNewLabel.setForeground(ClaireSDK.settings.plainText);
		lblNewLabel.setFont(new Font("Helvetica Neue", Font.BOLD, 15));
		GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
		gbc_lblNewLabel.insets = new Insets(0, 0, 5, 0);
		gbc_lblNewLabel.gridx = 0;
		gbc_lblNewLabel.gridy = 0;
		getContentPane().add(lblNewLabel, gbc_lblNewLabel);
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		GridBagConstraints gbc_tabbedPane = new GridBagConstraints();
		gbc_tabbedPane.insets = new Insets(0, 5, 5, 0);
		gbc_tabbedPane.fill = GridBagConstraints.BOTH;
		gbc_tabbedPane.gridx = 0;
		gbc_tabbedPane.gridy = 1;
		getContentPane().add(tabbedPane, gbc_tabbedPane);
		
		AppearancePanel appearancePanel = new AppearancePanel();
		tabbedPane.addTab("Appearance", null, appearancePanel, null);
		
		SimulationPanel simulationPanel = new SimulationPanel(countSensors());
		tabbedPane.addTab("Simulation", null, simulationPanel, null);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(ClaireSDK.settings.bkgc2);
		GridBagConstraints gbc_panel_1 = new GridBagConstraints();
		gbc_panel_1.fill = GridBagConstraints.BOTH;
		gbc_panel_1.gridx = 0;
		gbc_panel_1.gridy = 2;
		getContentPane().add(panel_1, gbc_panel_1);
		panel_1.setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
		
		JButton applyBtn = new JButton("Apply");
		applyBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				applyAndClose();
			}
		});
		panel_1.add(applyBtn);
		

	}
	
	private void applyAndClose() {
		dispose();
		ClaireSDK.settings.save();
		ClaireSDK.app.getFrame().dispose();
		ClaireSDK.app = new Application();
		ClaireSDK.app.getFrame().setVisible(true);
	}

	private int countSensors() {
		File dir = new File(ClaireSDK.settings.getSrcPath()+"sensor");
		return dir.listFiles().length;
	}

}

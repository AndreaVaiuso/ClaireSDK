package iotsdk.windows;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import iotsdk.ClaireSDK;
import iotsdk.sensors.ButtonSensor;
import iotsdk.sensors.Display;
import iotsdk.sensors.RGBLight;
import iotsdk.sensors.ProximitySensor;
import iotsdk.sensors.SimpleLight;
import iotsdk.sensors.SwitchSensor;
import iotsdk.sensors.TemperatureSensor;

import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.FlowLayout;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import java.awt.Dialog.ModalExclusionType;
import java.awt.Dimension;
import java.awt.Window.Type;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JTextArea;
import javax.swing.JSeparator;

public class AddSensorWindow extends JFrame {

	private JPanel contentPane;
	private JPanel settingsPane;
	private JComboBox<String> comboBox;
	private JTextField nm;

	private JTextArea textArea;

	private int sensibilitySensor = 10;

	private final String[] availableSensors = new String[] {"Button","RGB Light", "Proximity Sensor","Display","Temperature sensor","Switch sensor","Light"};

	public AddSensorWindow() {
		getContentPane().setBackground(ClaireSDK.settings.bkgc2);
		setResizable(true);
		setType(Type.UTILITY);
		setTitle("Add new sensor");
		setModalExclusionType(ModalExclusionType.APPLICATION_EXCLUDE);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(300, 300, 428, 281);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(15, 15, 0, 15));
		setContentPane(contentPane);
		GridBagLayout gbl_contentPane = new GridBagLayout();
		gbl_contentPane.columnWidths = new int[]{0, 0};
		gbl_contentPane.rowHeights = new int[]{37, 0, 0, 0};
		gbl_contentPane.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_contentPane.rowWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		contentPane.setLayout(gbl_contentPane);
		contentPane.setBackground(ClaireSDK.settings.bkgc2);

		JPanel topPanel = new JPanel();
		topPanel.setBackground(ClaireSDK.settings.bkgc2);
		GridBagConstraints gbc_topPanel = new GridBagConstraints();
		gbc_topPanel.anchor = GridBagConstraints.WEST;
		gbc_topPanel.insets = new Insets(0, 0, 10, 0);
		gbc_topPanel.fill = GridBagConstraints.VERTICAL;
		gbc_topPanel.gridx = 0;
		gbc_topPanel.gridy = 0;
		contentPane.add(topPanel, gbc_topPanel);
		topPanel.setLayout(new BoxLayout(topPanel, BoxLayout.Y_AXIS));

		JLabel lblNewLabel = new JLabel("Add a new sensor to the simulation");
		lblNewLabel.setForeground(ClaireSDK.settings.plainText);
		lblNewLabel.setFont(new Font("Helvetica Neue", Font.BOLD, 19));
		topPanel.add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("Select the sensor and click Add to insert it into your simulation");
		lblNewLabel_1.setForeground(ClaireSDK.settings.plainText);
		lblNewLabel_1.setFont(new Font("Helvetica Neue", Font.PLAIN, 13));
		topPanel.add(lblNewLabel_1);

		JPanel panel = new JPanel();
		panel.setBackground(ClaireSDK.settings.bkgc2);
		GridBagConstraints gbc_panel = new GridBagConstraints();
		gbc_panel.insets = new Insets(0, 0, 0, 0);
		gbc_panel.fill = GridBagConstraints.BOTH;
		gbc_panel.gridx = 0;
		gbc_panel.gridy = 1;
		contentPane.add(panel, gbc_panel);
		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{0, 0};
		gbl_panel.rowHeights = new int[]{0, 0, 0, 31, 0};
		gbl_panel.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 1.0, Double.MIN_VALUE};
		panel.setLayout(gbl_panel);

		comboBox = new JComboBox<>();
		comboBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				updatePanel();
			}
		});
		comboBox.setModel(new DefaultComboBoxModel<String>(availableSensors));
		GridBagConstraints gbc_comboBox = new GridBagConstraints();
		gbc_comboBox.anchor = GridBagConstraints.WEST;
		gbc_comboBox.insets = new Insets(0, 0, 5, 0);
		gbc_comboBox.gridx = 0;
		gbc_comboBox.gridy = 0;
		panel.add(comboBox, gbc_comboBox);

		textArea = new JTextArea();
		textArea.setEditable(false);
		GridBagConstraints gbc_textArea = new GridBagConstraints();
		gbc_textArea.fill = GridBagConstraints.HORIZONTAL;
		gbc_textArea.insets = new Insets(0, 0, 5, 0);
		gbc_textArea.gridx = 0;
		gbc_textArea.gridy = 1;
		panel.add(textArea, gbc_textArea);
		textArea.setWrapStyleWord(true);
		textArea.setLineWrap(true);
		textArea.setBackground(ClaireSDK.settings.bkgc2);
		textArea.setForeground(ClaireSDK.settings.plainText2);

		JSeparator separator = new JSeparator();
		GridBagConstraints gbc_separator = new GridBagConstraints();
		gbc_separator.insets = new Insets(0, 0, 5, 0);
		gbc_separator.gridx = 0;
		gbc_separator.gridy = 2;
		panel.add(separator, gbc_separator);

		settingsPane = new JPanel();
		settingsPane.setBackground(ClaireSDK.settings.bkgc2);
		GridBagConstraints gbc_settingsPane = new GridBagConstraints();
		gbc_settingsPane.fill = GridBagConstraints.BOTH;
		gbc_settingsPane.gridx = 0;
		gbc_settingsPane.gridy = 3;
		panel.add(settingsPane, gbc_settingsPane);



		JPanel bottomPane = new JPanel();
		bottomPane.setBackground(ClaireSDK.settings.bkgc2);
		GridBagConstraints gbc_bottomPane = new GridBagConstraints();
		gbc_bottomPane.anchor = GridBagConstraints.EAST;
		gbc_bottomPane.fill = GridBagConstraints.VERTICAL;
		gbc_bottomPane.gridx = 0;
		gbc_bottomPane.gridy = 2;
		contentPane.add(bottomPane, gbc_bottomPane);

		JButton btnNewButton = new JButton("Add");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				addSensor();
			}
		});
		bottomPane.add(btnNewButton);

		JButton btnNewButton_1 = new JButton("Cancel");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		bottomPane.add(btnNewButton_1);
		updatePanel();
	}

	protected void updatePanel() {
		clearSettingsPane();
		JLabel l = new JLabel("Device name: ");
		nm = new JTextField();
		nm.setPreferredSize(new Dimension(100,25));
		nm.setText("Device");
		l.setForeground(ClaireSDK.settings.plainText);
		String item = (String) comboBox.getSelectedItem();
		if(item.equals(availableSensors[0])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(ButtonSensor.desc);
		}
		else if (item.equals(availableSensors[1])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(RGBLight.desc);
		}	
		else if (item.equals(availableSensors[2])) {
			
			JLabel lab = new JLabel("Sensibility: ");
			lab.setForeground(ClaireSDK.settings.plainText);
			JTextField tf = new JTextField();
			tf.setText(sensibilitySensor+"");
			JButton bt = new JButton("Set");
			bt.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					try {
						sensibilitySensor = Integer.parseInt(tf.getText());
					} catch(Exception ex) {
						tf.setText(sensibilitySensor+"");
					}
				}
			});
			settingsPane.add(l);
			settingsPane.add(nm);
			settingsPane.add(new JSeparator());
			settingsPane.add(lab);
			settingsPane.add(tf);
			settingsPane.add(bt);
			textArea.setText(ProximitySensor.desc);
		}
		else if (item.equals(availableSensors[3])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(Display.desc);
		}
		else if (item.equals(availableSensors[4])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(TemperatureSensor.desc);
		}
		else if (item.equals(availableSensors[5])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(SwitchSensor.desc);
		}
		else if (item.equals(availableSensors[6])) {
			settingsPane.add(l);
			settingsPane.add(nm);
			textArea.setText(SimpleLight.desc);
		}
		getContentPane().revalidate();
		getContentPane().repaint();


	}

	private static final String ALPHA_NUMERIC_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	public static String randomAlphaNumeric(int count) {
		StringBuilder builder = new StringBuilder();
		while (count-- != 0) {
			int character = (int)(Math.random()*ALPHA_NUMERIC_STRING.length());
			builder.append(ALPHA_NUMERIC_STRING.charAt(character));
		}
		return builder.toString();
	}

	private void clearSettingsPane() {
		settingsPane.removeAll();
	}

	private void addSensor() {
		try{
			String item = (String) comboBox.getSelectedItem();
			if(item.equals(availableSensors[0]))
				ClaireSDK.app.getSimulation().addSensor(new ButtonSensor(randomAlphaNumeric(6),nm.getText()));
			else if (item.equals(availableSensors[1]))
				ClaireSDK.app.getSimulation().addSensor(new RGBLight(randomAlphaNumeric(6),nm.getText()));
			else if (item.equals(availableSensors[2]))
				ClaireSDK.app.getSimulation().addSensor(new ProximitySensor(randomAlphaNumeric(6),sensibilitySensor,nm.getText()));
			else if (item.equals(availableSensors[3]))
				ClaireSDK.app.getSimulation().addSensor(new Display(randomAlphaNumeric(6),nm.getText()));
			else if (item.equals(availableSensors[4]))
				ClaireSDK.app.getSimulation().addSensor(new TemperatureSensor(randomAlphaNumeric(6),nm.getText()));
			else if (item.equals(availableSensors[5]))
				ClaireSDK.app.getSimulation().addSensor(new SwitchSensor(randomAlphaNumeric(6),nm.getText()));
			else if (item.equals(availableSensors[6]))
				ClaireSDK.app.getSimulation().addSensor(new SimpleLight(randomAlphaNumeric(6),nm.getText()));
			dispose();
		} catch (IOException e) {
			ClaireSDK.app.getTerminal().printException(e);
		}
	}

}

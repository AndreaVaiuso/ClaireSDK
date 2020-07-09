package iotsdk;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Simulation {
	
	private JPanel devicePanel;
	private ModernScrollPane scrollPane_device;
	private ArrayList<Sensor> sensorList = new ArrayList<>();
	
	public Simulation() {

		scrollPane_device = new ModernScrollPane(devicePanel);
		scrollPane_device.setOpaque(false);
		scrollPane_device.getViewport().setOpaque(false);
		scrollPane_device.setBorder(BorderFactory.createEmptyBorder());
		GridBagConstraints gbc_scrollPane_device = new GridBagConstraints();
		gbc_scrollPane_device.fill = GridBagConstraints.BOTH;
		gbc_scrollPane_device.gridx = 0;
		gbc_scrollPane_device.gridy = 1;


		devicePanel = new JPanel();
		devicePanel.setBackground(ClaireSDK.settings.bkgc1);
		devicePanel.setOpaque(false);
		scrollPane_device.setViewportView(devicePanel);
		devicePanel.setLayout(new BoxLayout(devicePanel, BoxLayout.Y_AXIS));
	}
	

	public void addSensor(Sensor sensor) {
		for(int i=0;i<sensorList.size();i++) {
			if(sensorList.get(i).getId().equals(sensor.getId())) {
				Toolkit.getDefaultToolkit().beep();
				JOptionPane.showMessageDialog(ClaireSDK.app.getFrame(),"Error: a sensor with id: " + sensor.getId() + " already exists");
				return;
			}
		}
		sensorList.add(sensor);
		devicePanel.add(sensor);
	}

	public void removeSensor(int index) {
		sensorList.get(index).destroy();
		sensorList.remove(index);
	}

	public void updateSensorList() {
		devicePanel.removeAll();
		for(int i=0;i<sensorList.size();i++) {
			devicePanel.add(sensorList.get(i));
		}
		devicePanel.revalidate();
		devicePanel.repaint();
	}

	public ModernScrollPane getSimPanel() {
		return scrollPane_device;
	}

	public ArrayList<Sensor> getSensorList() {
		return sensorList;
	}

	public void setSensorList(ArrayList<Sensor> sensorList) {
		this.sensorList = sensorList;
	}

}

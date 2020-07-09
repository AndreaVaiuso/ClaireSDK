package iotsdk.sensors;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import iotsdk.ClaireSDK;
import iotsdk.Sensor;

public class ProximitySensor extends Sensor {

	private int sensibility = 0;
	
	public static String desc = "The output of this device is 1 if the value stored in input is greather than the sensibility, else is 0";
	private JLabel outputLabel;
	
	public ProximitySensor(String id,int sensibility,String name) throws IOException {
		super(id, "Proximity Sensor","0",name);
		setSensibility(sensibility);
		outputLabel = new JLabel("",JLabel.CENTER);
		outputLabel.setBounds(32, 20, 60, 60);
		outputLabel.setFont(new Font("Courier New", Font.PLAIN, 55));
		outputLabel.setForeground(ClaireSDK.settings.plainText);
		getGuiPanel().add(outputLabel);
	}

	@Override
	public void updateGui() {
		if(isTurnedOn()) {
			outputLabel.setText(getOutput());
			try {
				if(Double.valueOf(getInput())>= sensibility) {
					writeOutput("0");
				} else {
					writeOutput("1");
				}
			} catch (NumberFormatException e) {
				
			}
		} else {
			outputLabel.setText("-");
		}
		
	}

	public int getSensibility() {
		return sensibility;
	}

	public void setSensibility(int sensibility) {
		this.sensibility = sensibility;
	}

}

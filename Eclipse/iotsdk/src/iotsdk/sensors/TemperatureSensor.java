package iotsdk.sensors;

import java.awt.Color;
import java.awt.Font;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JLabel;

import iotsdk.ClaireSDK;
import iotsdk.Sensor;

public class TemperatureSensor extends Sensor {
	
	private JLabel outputLabel;
	public static String desc = "The output of this device is the temperature in Celsius of what it get in input";

	public TemperatureSensor(String id, String name) throws IOException {
		super(id, "Temperature sensor", "1",name);
		outputLabel = new JLabel("",JLabel.CENTER);
		outputLabel.setBounds(0, 20, 120, 60);
		outputLabel.setOpaque(true);
		outputLabel.setBackground(Color.LIGHT_GRAY);
		outputLabel.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.GRAY));
		outputLabel.setFont(new Font("PT Mono", Font.BOLD, 20));
		outputLabel.setForeground(Color.BLACK);
		getGuiPanel().add(outputLabel);
	}

	@Override
	public void updateGui() {
		
		if(isTurnedOn()) {
			outputLabel.setText(getOutput()+"C");
			try {
				double d = Double.parseDouble(getInput());
				writeOutput(d+"");
			} catch (NumberFormatException e) {
				writeOutput("0");
			}
		} else {
			outputLabel.setText("-");
		}
		
	}

}

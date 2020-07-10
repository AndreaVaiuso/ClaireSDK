package iotsdk.sensors;

import iotsdk.Sensor;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;

public class SwitchSensor extends Sensor {

	private static final long serialVersionUID = -825086977351250185L;
	private JLabel button;
	private boolean isClicked = false;
	public static String desc = "The output of this device is 1 if the switch is on, else is 0. Input is always 0. You can switch it by changing output value";

	public SwitchSensor(String id, String name) throws IOException {
		super(id,"Switch","0", name);
		hideInput();
		button = new JLabel("");
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				if(isTurnedOn()) {
					if(!isClicked) {
						isClicked = true;
						click();
					} else {
						isClicked = false;
						release();
					}
				}
			}
		});
		button.setIcon(new ImageIcon(SwitchSensor.class.getResource("/resources/switch.png")));
		button.setBounds(32, 20, 60, 60);
		getGuiPanel().add(button);;
	}
	
	private void click() {
		button.setIcon(new ImageIcon(SwitchSensor.class.getResource("/resources/switch.pressed.png")));
		revalidate();
		repaint();
		super.setOutput("1");
	}
	
	private void release() {
		button.setIcon(new ImageIcon(SwitchSensor.class.getResource("/resources/switch.png")));
		revalidate();
		repaint();
		super.setOutput("0");
	}

	@Override
	public void updateGui() {
		int out = (int) Math.round(Double.parseDouble(super.getOutput()));
		if(out == 0) {
			button.setIcon(new ImageIcon(SwitchSensor.class.getResource("/resources/switch.png")));
			revalidate();
		}  else if(out == 1) {
			button.setIcon(new ImageIcon(SwitchSensor.class.getResource("/resources/switch.pressed.png")));
			revalidate();
			repaint();
		}
	}
}

package iotsdk.sensors;

import iotsdk.Sensor;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;

public class ButtonSensor extends Sensor {

	private static final long serialVersionUID = -825086977351250185L;
	private JLabel button;
	public static String desc = "The output of this device is 1 if the button is clicked, else is 0. Input is always 0 and is not editable";

	public ButtonSensor(String id,String name) throws IOException {
		super(id,"Button","0",name);
		hideInput();
		button = new JLabel("");
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				if(isTurnedOn()) {
					click();
				}
			}
			@Override
			public void mouseReleased(MouseEvent e) {
				if(isTurnedOn()) {
					button.setIcon(new ImageIcon(ButtonSensor.class.getResource("/resources/button.png")));
					release();
				}
			}
		});
		button.setIcon(new ImageIcon(ButtonSensor.class.getResource("/resources/button.png")));
		button.setBounds(32, 20, 60, 60);
		getGuiPanel().add(button);;
	}
	
	private void click() {
		button.setIcon(new ImageIcon(ButtonSensor.class.getResource("/resources/button.pressed.png")));
		revalidate();
		repaint();
		super.setOutput("1");
	}
	
	private void release() {
		button.setIcon(new ImageIcon(ButtonSensor.class.getResource("/resources/button.png")));
		revalidate();
		repaint();
		super.setOutput("0");
	}

	@Override
	public void updateGui() {
	}
}

package iotsdk;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TopPanel extends JPanel {
	
	private static final long serialVersionUID = 1305330651310748577L;
	private JButton runBtn;
	private JButton stopBtn;
	
	private MouseAdapter listener = new MouseAdapter() {
		@Override
		public void mouseClicked(MouseEvent e) {
			ClaireSDK.app.runSim();
		}
	};
	
	public MouseAdapter getListener() {
		return listener;
	}

	public void setListener(MouseAdapter listener) {
		this.listener = listener;
	}

	public JButton getRunBtn() {
		return runBtn;
	}

	public void setRunBtn(JButton runBtn) {
		this.runBtn = runBtn;
	}

	public JButton getStopBtn() {
		return stopBtn;
	}

	public void setStopBtn(JButton stopBtn) {
		this.stopBtn = stopBtn;
	}

	public TopPanel() {
		setLayout(new FlowLayout(FlowLayout.LEFT));
		setBackground(ClaireSDK.settings.bkgc2);
		JButton addBtn = new JButton("Add sensor");
		addBtn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				ClaireSDK.app.addSensor();
			}
		});
		addBtn.setIcon(new ImageIcon(Application.class.getResource("/resources/add2.png")));

		add(addBtn);

		JButton removeBtn = new JButton("Remove sensor");
		removeBtn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				ClaireSDK.app.removeSensor();
			}
		});
		removeBtn.setIcon(new ImageIcon(Application.class.getResource("/resources/remove1.png")));
		add(removeBtn);

		JLabel lbSep = new JLabel("|");
		lbSep.setFont(new Font("Lucida Grande", Font.PLAIN, 21));
		lbSep.setForeground(Color.LIGHT_GRAY);
		add(lbSep);
		runBtn = new JButton("Run");
		runBtn.addMouseListener(listener);
		runBtn.setIcon(new ImageIcon(Application.class.getResource("/resources/run2.png")));
		add(runBtn);

		stopBtn = new JButton("Stop");
		stopBtn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				ClaireSDK.app.stopSim();
			}
		});
		stopBtn.setIcon(new ImageIcon(Application.class.getResource("/resources/remove.png")));
		add(stopBtn);
		
		JLabel lbSep_1 = new JLabel("|");
		lbSep_1.setForeground(Color.LIGHT_GRAY);
		lbSep_1.setFont(new Font("Lucida Grande", Font.PLAIN, 21));
		add(lbSep_1);
		
		JButton btnNewButton = new JButton("");
		btnNewButton.setToolTipText("Save script");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.saveCurrentCode();
			}
		});
		btnNewButton.setIcon(new ImageIcon(TopPanel.class.getResource("/resources/save.png")));
		add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("");
		btnNewButton_1.setToolTipText("Open script");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.openCode();
			}
		});
		btnNewButton_1.setIcon(new ImageIcon(TopPanel.class.getResource("/resources/open.png")));
		add(btnNewButton_1);
		
		JButton btnNewButton_2 = new JButton("");
		btnNewButton_2.setToolTipText("New script");
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.addCodeTab(new CodePane());
			}
		});
		btnNewButton_2.setIcon(new ImageIcon(TopPanel.class.getResource("/resources/new.png")));
		add(btnNewButton_2);
	}
}

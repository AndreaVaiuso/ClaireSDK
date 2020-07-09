package iotsdk;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;
import javax.swing.KeyStroke;

public class AppMenuBar extends JMenuBar {
	
	private JMenuItem runSimMenuBtn;
	private JMenuItem stopSimMenuBtn;
	private KeyStroke key1;
	private KeyStroke key2;
	
	
	public KeyStroke getKey1() {
		return key1;
	}

	public void setKey1(KeyStroke key1) {
		this.key1 = key1;
	}

	public KeyStroke getKey2() {
		return key2;
	}

	public void setKey2(KeyStroke key2) {
		this.key2 = key2;
	}

	public JMenuItem getRunSimMenuBtn() {
		return runSimMenuBtn;
	}

	public void setRunSimMenuBtn(JMenuItem runSimMenuBtn) {
		this.runSimMenuBtn = runSimMenuBtn;
	}

	public JMenuItem getStopSimMenuBtn() {
		return stopSimMenuBtn;
	}

	public void setStopSimMenuBtn(JMenuItem stopSimMenuBtn) {
		this.stopSimMenuBtn = stopSimMenuBtn;
	}

	public AppMenuBar(){
		setBackground(ClaireSDK.settings.bkgc1);
		setForeground(ClaireSDK.settings.plainText);
		JMenu mnNewMenu = new JMenu("File");
		add(mnNewMenu);
		
		
		JMenuItem mntmNewMenuItem_8 = new JMenuItem(new AbstractAction("New Script") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.addCodeTab(new CodePane());
			}
		});
		mnNewMenu.add(mntmNewMenuItem_8);
		
		JMenuItem mntmNewMenuItem_9 = new JMenuItem(new AbstractAction("Remove current script") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.removeCurrentTab();
			}
		});
		mnNewMenu.add(mntmNewMenuItem_9);
		
		JSeparator separator_2 = new JSeparator();
		mnNewMenu.add(separator_2);
		
		JMenuItem mntmNewMenuItem_10 = new JMenuItem(new AbstractAction("Save") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.saveCurrentCode();
			}
		});
		mnNewMenu.add(mntmNewMenuItem_10);
		
		JMenuItem mntmNewMenuItem_11 = new JMenuItem(new AbstractAction("Open") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.openCode();
			}
		});
		mnNewMenu.add(mntmNewMenuItem_11);

		JSeparator separator = new JSeparator();
		mnNewMenu.add(separator);
		
		JMenu mnNewMenu_4 = new JMenu("Developer tools");
		mnNewMenu.add(mnNewMenu_4);
		
		JMenuItem recompile = new JMenuItem(new AbstractAction("Recompile source") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.recompileSource();
			}
		});
		mnNewMenu_4.add(recompile);

		JMenuItem mntmNewMenuItem_4 = new JMenuItem(new AbstractAction("Preferences...") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.settings();
			}
		});
		mnNewMenu.add(mntmNewMenuItem_4);

		JMenu mnNewMenu_3 = new JMenu("Edit");
		add(mnNewMenu_3);

		JMenuItem mntmNewMenuItem_6 = new JMenuItem(new AbstractAction("Undo") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.getCurrentCodeTab().undo();
			}
		});
		mnNewMenu_3.add(mntmNewMenuItem_6);

		JMenuItem mntmNewMenuItem_7 = new JMenuItem(new AbstractAction("Redo") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.getCurrentCodeTab().redo();
			}
		});
		mnNewMenu_3.add(mntmNewMenuItem_7);

		JMenu mnNewMenu_1 = new JMenu("Simulation");
		add(mnNewMenu_1);
		
		JMenuItem mntmNewMenuItem = new JMenuItem(new AbstractAction("Add sensor") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.addSensor();
			}
		});

		mnNewMenu_1.add(mntmNewMenuItem);

		JMenuItem mntmNewMenuItem_1 = new JMenuItem(new AbstractAction("Remove sensor") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.removeSensor();
			}
		});
		mnNewMenu_1.add(mntmNewMenuItem_1);
		
		JSeparator separator_2_1 = new JSeparator();
		mnNewMenu_1.add(separator_2_1);

		runSimMenuBtn = new JMenuItem(new AbstractAction("Run current script") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.runSim();
			}
		});
		mnNewMenu_1.add(runSimMenuBtn);

		stopSimMenuBtn = new JMenuItem(new AbstractAction("Stop simulations") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.stopSim();
			}
		});
		mnNewMenu_1.add(stopSimMenuBtn);

		JMenu mnNewMenu_2 = new JMenu("Help");
		add(mnNewMenu_2);

		JMenuItem mntmNewMenuItem_5 = new JMenuItem(new AbstractAction("About and guide") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.showHelp();
			}
		});
		mnNewMenu_2.add(mntmNewMenuItem_5);
		
		JSeparator separator_1 = new JSeparator();
		mnNewMenu_1.add(separator_1);
		
		JMenuItem mntmNewMenuItem_2 = new JMenuItem(new AbstractAction("Clear terminal") {
			private static final long serialVersionUID = -5683052080604808061L;
			public void actionPerformed(ActionEvent e) {
				ClaireSDK.app.getTerminal().clear();
			}
		});
		mnNewMenu_1.add(mntmNewMenuItem_2);

		key1 = KeyStroke.getKeyStroke("meta R");
		runSimMenuBtn.setAccelerator(key1);

		key2 = KeyStroke.getKeyStroke("meta X");
		stopSimMenuBtn.setAccelerator(key2);

		KeyStroke key3 = KeyStroke.getKeyStroke("meta Z");
		mntmNewMenuItem_6.setAccelerator(key3);

		KeyStroke key4 = KeyStroke.getKeyStroke("meta Y");
		mntmNewMenuItem_7.setAccelerator(key4);

		KeyStroke key5 = KeyStroke.getKeyStroke("meta shift N");
		mntmNewMenuItem.setAccelerator(key5);

		KeyStroke key6 = KeyStroke.getKeyStroke("meta P");
		mntmNewMenuItem_4.setAccelerator(key6);
		
		KeyStroke key7 = KeyStroke.getKeyStroke("meta N");
		mntmNewMenuItem_8.setAccelerator(key7);
		
		KeyStroke key8 = KeyStroke.getKeyStroke("meta shift R");
		mntmNewMenuItem_9.setAccelerator(key8);
		
		KeyStroke key9 = KeyStroke.getKeyStroke("meta shift S");
		mntmNewMenuItem_10.setAccelerator(key9);
		
		KeyStroke key10 = KeyStroke.getKeyStroke("meta shift O");
		mntmNewMenuItem_11.setAccelerator(key10);
		
		KeyStroke key11 = KeyStroke.getKeyStroke("meta shift B");
		recompile.setAccelerator(key11);
	}

}

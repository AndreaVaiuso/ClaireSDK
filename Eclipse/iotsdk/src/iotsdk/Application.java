package iotsdk;

import java.awt.Color;
import java.awt.Component;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import java.awt.GridBagLayout;
import javax.swing.JPanel;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import iotsdk.windows.AddSensorWindow;
import iotsdk.windows.HelpWindow;
import iotsdk.windows.SettingsWindow;

import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.JFileChooser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.concurrent.ScheduledExecutorService;
import java.awt.Toolkit;

import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.JOptionPane;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;

public class Application {


	private Process process = null;
	private Thread runThread;
	private JFrame frame;
	private TopPanel topPanel;
	private String currentRunningScript;

	private AppMenuBar menuBar;
	public AppMenuBar getMenuBar() {
		return menuBar;
	}

	public void setMenuBar(AppMenuBar menuBar) {
		this.menuBar = menuBar;
	}

	public TopPanel getTopPanel() {
		return topPanel;
	}

	public void setTopPanel(TopPanel topPanel) {
		this.topPanel = topPanel;
	}

	private Simulation simulation;
	private JFileChooser chooser;

	private JPanel codeSidePanel;
	private ArrayList<CodePane> codePanels = new ArrayList<>();

	private ModernScrollPane scrollPane_terminal;
	public ModernScrollPane getScrollPane_terminal() {
		return scrollPane_terminal;
	}

	public void setScrollPane_terminal(ModernScrollPane scrollPane_terminal) {
		this.scrollPane_terminal = scrollPane_terminal;
	}

	private Terminal terminal = new Terminal();
	private Terminal console = new Terminal();

	private BufferedReader reader;
	private JPanel sepPanel;
	private JPanel terminalSidePanel;
	private JSplitPane splitPane;
	private JSplitPane splitPane_1;
	private JTabbedPane tabbedPane;
	private JTabbedPane tabbedPaneSim;
	private JTabbedPane tabbedPane_1;
	private JPanel consoleSidePanel;
	private ModernScrollPane scrollPane_console;


	public Application() {
		createGUI();
	}
	/*
	public Application(String file) {
		createGUI();

		try {
			File f = new File(file);
			CodePane cp = new CodePane();
			BufferedReader reader = new BufferedReader(new FileReader(f));
			String strCurrentLine = "";
			String code = "";
			while ((strCurrentLine = reader.readLine()) != null) {
				code += strCurrentLine;
			}
			cp.setText(code);
			this.addCodeTab(cp,f.getName());
			reader.close();
		} catch (IOException e){
			getTerminal().appendError("Unable to open file");
		}

	}
	 */

	public void createGUI() {
		/**
		 * @wbp.parser.constructor
		 */
		simulation = new Simulation();
		frame = new JFrame();
		frame.setIconImage(Toolkit.getDefaultToolkit().getImage(Application.class.getResource("/resources/Logo.png")));
		frame.setBounds(100, 100, 961, 584);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridBagLayout gridBagLayout = new GridBagLayout();
		gridBagLayout.columnWidths = new int[]{0, 0};
		gridBagLayout.rowHeights = new int[]{50, 7, 0, 0};
		gridBagLayout.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gridBagLayout.rowWeights = new double[]{0.0, 0.0, 1.0, Double.MIN_VALUE};
		frame.getContentPane().setLayout(gridBagLayout);

		frame.getContentPane().setBackground(ClaireSDK.settings.bkgc1);

		topPanel = new TopPanel();
		GridBagConstraints gbc_topPanel = new GridBagConstraints();
		gbc_topPanel.insets = new Insets(0, 0, 0, 0);
		gbc_topPanel.fill = GridBagConstraints.BOTH;
		gbc_topPanel.gridx = 0;
		gbc_topPanel.gridy = 0;
		frame.getContentPane().add(topPanel, gbc_topPanel);

		sepPanel = new JPanel();
		sepPanel.setBackground(ClaireSDK.settings.bkgc1);
		sepPanel.setBorder(BorderFactory.createMatteBorder(1, 0, 0, 0, Color.GRAY));
		GridBagConstraints gbc_sepPanel = new GridBagConstraints();
		gbc_sepPanel.insets = new Insets(0, 0, 0, 0);
		gbc_sepPanel.fill = GridBagConstraints.BOTH;
		gbc_sepPanel.gridx = 0;
		gbc_sepPanel.gridy = 1;
		frame.getContentPane().add(sepPanel, gbc_sepPanel);

		splitPane_1 = new JSplitPane();
		splitPane_1.setResizeWeight(1);
		splitPane_1.setDividerSize(3);
		splitPane_1.setBackground(ClaireSDK.settings.bkgc1);
		splitPane_1.setBorder(BorderFactory.createEmptyBorder());
		splitPane_1.setContinuousLayout(true);
		splitPane_1.setDividerLocation(300);
		splitPane_1.setOrientation(JSplitPane.VERTICAL_SPLIT);
		GridBagConstraints gbc_splitPane_1 = new GridBagConstraints();
		gbc_splitPane_1.insets = new Insets(0, 5, 0, 0);
		gbc_splitPane_1.fill = GridBagConstraints.BOTH;
		gbc_splitPane_1.gridx = 0;
		gbc_splitPane_1.gridy = 2;
		frame.getContentPane().add(splitPane_1, gbc_splitPane_1);

		splitPane = new JSplitPane();
		splitPane.setDividerSize(3);
		splitPane.setBackground(ClaireSDK.settings.bkgc1);
		splitPane.setBorder(BorderFactory.createEmptyBorder());
		splitPane_1.setLeftComponent(splitPane);
		splitPane.setDividerLocation(500);
		splitPane.setContinuousLayout(true);
		splitPane.setOrientation(JSplitPane.HORIZONTAL_SPLIT);



		codeSidePanel = new JPanel();
		splitPane.setRightComponent(codeSidePanel);
		codeSidePanel.setBackground(ClaireSDK.settings.bkgc1);
		GridBagLayout gbl_codeSidePanel = new GridBagLayout();
		gbl_codeSidePanel.columnWidths = new int[]{38, 0};
		gbl_codeSidePanel.rowHeights = new int[]{0, 0};
		gbl_codeSidePanel.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_codeSidePanel.rowWeights = new double[]{1.0, Double.MIN_VALUE};
		codeSidePanel.setLayout(gbl_codeSidePanel);

		tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		GridBagConstraints gbc_tabbedPane = new GridBagConstraints();
		gbc_tabbedPane.fill = GridBagConstraints.BOTH;
		gbc_tabbedPane.gridx = 0;
		gbc_tabbedPane.gridy = 0;
		codeSidePanel.add(tabbedPane, gbc_tabbedPane);

		addCodeTab(new CodePane());

		tabbedPaneSim = new JTabbedPane(JTabbedPane.TOP);
		splitPane.setLeftComponent(tabbedPaneSim);
		tabbedPaneSim.addTab("Simulation", null, simulation.getSimPanel(), "Simulation");

		tabbedPane_1 = new JTabbedPane(JTabbedPane.TOP);
		splitPane_1.setRightComponent(tabbedPane_1);


		terminalSidePanel = new JPanel();
		tabbedPane_1.addTab("Terminal", null, terminalSidePanel, null);
		terminalSidePanel.setBackground(ClaireSDK.settings.bkgc3);
		GridBagLayout gbl_terminalSidePanel = new GridBagLayout();
		gbl_terminalSidePanel.columnWidths = new int[]{0, 0};
		gbl_terminalSidePanel.rowHeights = new int[]{0, 0};
		gbl_terminalSidePanel.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_terminalSidePanel.rowWeights = new double[]{1.0, Double.MIN_VALUE};
		terminalSidePanel.setLayout(gbl_terminalSidePanel);

		scrollPane_terminal = new ModernScrollPane(terminal);
		GridBagConstraints gbc_scrollPane_terminal = new GridBagConstraints();
		gbc_scrollPane_terminal.fill = GridBagConstraints.BOTH;
		gbc_scrollPane_terminal.gridx = 0;
		gbc_scrollPane_terminal.gridy = 0;
		terminalSidePanel.add(scrollPane_terminal, gbc_scrollPane_terminal);

		terminal = new Terminal();
		scrollPane_terminal.setBackground(new Color(64, 64, 64));
		scrollPane_terminal.setViewportView(terminal);

		consoleSidePanel = new JPanel();
		tabbedPane_1.addTab("Console", null, consoleSidePanel, null);
		consoleSidePanel.setBackground(ClaireSDK.settings.bkgc3);
		GridBagLayout gbl_consoleSidePanel = new GridBagLayout();
		gbl_consoleSidePanel.columnWidths = new int[]{0, 0};
		gbl_consoleSidePanel.rowHeights = new int[]{0, 0};
		gbl_consoleSidePanel.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_consoleSidePanel.rowWeights = new double[]{1.0, Double.MIN_VALUE};
		consoleSidePanel.setLayout(gbl_consoleSidePanel);

		scrollPane_console = new ModernScrollPane(console);
		GridBagConstraints gbc_scrollPane_console = new GridBagConstraints();
		gbc_scrollPane_console.fill = GridBagConstraints.BOTH;
		gbc_scrollPane_console.gridx = 0;
		gbc_scrollPane_console.gridy = 0;
		consoleSidePanel.add(scrollPane_console, gbc_scrollPane_console);

		console = new Terminal();
		scrollPane_console.setBackground(new Color(64, 64, 64));
		scrollPane_console.setViewportView(console);

		menuBar = new AppMenuBar();
		frame.setJMenuBar(menuBar);


	}


	public void runSim() {
		runThread = new Thread("Run") {
			public void run(){
				try {
					getTopPanel().getRunBtn().setEnabled(false);
					getTopPanel().getRunBtn().removeMouseListener(getTopPanel().getListener());
					getMenuBar().getRunSimMenuBtn().setEnabled(false);
					currentRunningScript = ClaireSDK.settings.getSrcPath()+"build/code/"+getScriptName();
					File tmpscr = new File(currentRunningScript);
					getTerminal().append("Compiling " + currentRunningScript + "...");
					if(!tmpscr.exists()) {
						tmpscr.createNewFile();
					}
					BufferedWriter w = new BufferedWriter(new FileWriter(tmpscr));
					w.write(getCode());
					w.close();
					ProcessBuilder builder = new ProcessBuilder(ClaireSDK.settings.getSrcPath()+"build/claire", currentRunningScript);
					builder.redirectErrorStream(true);
					process = builder.start();
					InputStream is = process.getInputStream();
					reader = new BufferedReader(new InputStreamReader(is));
					String line = null;
					while((line = reader.readLine())!= null) {
						getConsole().append(line);
					}
					getTopPanel().getRunBtn().setEnabled(true);
					getTopPanel().getRunBtn().addMouseListener(getTopPanel().getListener());
					getMenuBar().getRunSimMenuBtn().setEnabled(true);
					getTerminal().append("Running ended");
				} catch (IOException | NullPointerException e1) {
					alert("Workspace error: Cannot run "+ClaireSDK.settings.getSrcPath()+"build/claire. Be sure the compiler is inside your workspace folder");
				}
			}
		};
		runThread.start();
	}

	public void stopSim() {
		Thread stop = new Thread("stop") {
			@Override
			public void run() {
				try {
					getTerminal().append("Stopping " + currentRunningScript + "...");
					process.destroy();
					File tmpscr = new File(currentRunningScript);
					tmpscr.delete();
					reader.close();
					if(!process.isAlive()) {
						throw new NullPointerException();
					}
				} catch (IOException | NullPointerException e) {
					getTerminal().appendError("No process to stop");
				} catch (IllegalMonitorStateException e1) {
					getTerminal().appendError("No process to stop");
				}
			}
		};
		stop.start();
	}

	protected void removeSensor() {
		boolean found = false;
		for(int i = 0;i<simulation.getSensorList().size();i++) {
			if(simulation.getSensorList().get(i).isSelected()) {
				simulation.removeSensor(i);
				found = true;
				i = -1;
			} 
		}
		if(!found) {
			alert("Error: You should select at least one sensor");
		}
		simulation.updateSensorList();
	}

	public void alert(String s) {
		Toolkit.getDefaultToolkit().beep();
		JOptionPane.showMessageDialog(ClaireSDK.app.getFrame(),s);
	}

	protected void addSensor() {
		AddSensorWindow w = new AddSensorWindow();
		w.setVisible(true);
	}

	public void settings() {
		SettingsWindow sw = new SettingsWindow();
		sw.setVisible(true);
	}

	protected void showHelp() {
		HelpWindow hw = new HelpWindow();
		hw.setVisible(true);
	}

	public Terminal getTerminal() {
		return terminal;
	}

	public void setTerminal(Terminal terminal) {
		this.terminal = terminal;
	}

	public CodePane getCurrentCodeTab(){
		return codePanels.get(tabbedPane.getSelectedIndex());
	}

	private String getScriptName() {
		return tabbedPane.getTitleAt(tabbedPane.getSelectedIndex());
	}

	public void addCodeTab(CodePane scrollPane_code) {
		codePanels.add(scrollPane_code);
		tabbedPane.addTab("Script_" + (codePanels.size()) + ".cla", null, scrollPane_code, null);
	}
	public void addCodeTab(CodePane scrollPane_code, String title) {
		codePanels.add(scrollPane_code);
		tabbedPane.addTab(title, null, scrollPane_code, null);
	}

	public void removeCurrentTab() {
		try {
			if(codePanels.isEmpty()) {
				return;
			}
			int dialogResult = JOptionPane.showConfirmDialog (ClaireSDK.app.getFrame(), "Do you want to delete "+tabbedPane.getTitleAt(tabbedPane.getSelectedIndex())+"?","Warning",0);
			if(dialogResult == JOptionPane.YES_OPTION){
				tabbedPane.removeTabAt(tabbedPane.getSelectedIndex());
				codePanels.remove(tabbedPane.getSelectedIndex());
			}
		} catch (Exception e) {
			Toolkit.getDefaultToolkit().beep();
		}
	}

	public void saveCurrentCode() {
		chooser = new JFileChooser();
		chooser.setDialogTitle("Save " + getScriptName());
		FileNameExtensionFilter cla = new FileNameExtensionFilter("Claire file script (*.cla)", "cla");
		chooser.addChoosableFileFilter(cla);
		chooser.setFileFilter(cla);
		int result = chooser.showSaveDialog(getFrame());
		if(result == JFileChooser.APPROVE_OPTION) {
			File file = new File(chooser.getSelectedFile().toString()+".cla");
			try {
				BufferedWriter writer = new BufferedWriter(new FileWriter(file));
				writer.write(getCode());
				writer.close();
			} catch (IOException e) {
				getTerminal().appendError("Cannot save the script");
			}
		}
	}

	public void openCode() {
		chooser = new JFileChooser();
		chooser.setDialogTitle("Open new script");
		FileNameExtensionFilter cla = new FileNameExtensionFilter("Claire file script (*.cla)", "cla");
		chooser.addChoosableFileFilter(cla);
		chooser.setFileFilter(cla);
		int result = chooser.showOpenDialog(getFrame());
		if(result == JFileChooser.APPROVE_OPTION) {
			try {
				CodePane cp = new CodePane();
				BufferedReader reader = new BufferedReader(new FileReader(chooser.getSelectedFile()));
				String strCurrentLine = "";
				String code = "";
				while ((strCurrentLine = reader.readLine()) != null) {
					code += strCurrentLine;
				}
				cp.setText(code);
				this.addCodeTab(cp,chooser.getSelectedFile().getName());
				reader.close();
			} catch (IOException e){
				getTerminal().appendError("Unable to open file");
			}
		}
	}

	public String getCode() {
		return codePanels.get(tabbedPane.getSelectedIndex()).toString();
	}

	public JFrame getFrame() {
		return frame;
	}

	public void setFrame(JFrame frame) {
		this.frame = frame;
	}

	public Simulation getSimulation() {
		return simulation;
	}

	public void setSimulation(Simulation simulation) {
		this.simulation = simulation;
	}

	public void recompileSource() {
		Thread t = new Thread("Compile") {
			public void run(){
				try {
					ProcessBuilder builder = new ProcessBuilder(ClaireSDK.settings.getSrcPath()+"build/compile");
					builder.redirectErrorStream(true);
					process = builder.start();
					InputStream is = process.getInputStream();
					reader = new BufferedReader(new InputStreamReader(is));
					String line = null;
					while((line = reader.readLine())!= null) {
						getConsole().append(line);
					}
				} catch (IOException | NullPointerException e1) {
					alert("Workspace error: Cannot run /build/compile. Be sure the compiler is inside your workspace folder");
				}
			}
		};
		t.start();



	}

	public Terminal getConsole() {
		return console;
	}

	public void setConsole(Terminal console) {
		this.console = console;
	}

}

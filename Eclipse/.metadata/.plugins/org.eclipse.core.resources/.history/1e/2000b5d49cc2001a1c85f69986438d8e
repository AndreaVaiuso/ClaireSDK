package iotsdk;

import java.awt.EventQueue;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.SplashScreen;
import java.awt.Taskbar;
import java.awt.Toolkit;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URL;

import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.UIManager;

public class ClaireSDK {
	
	public static Application app;
	public static Settings settings = Settings.getSettings();
	public static String version = "0.9.2";
	
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				File f1 = new File(ClaireSDK.settings.getSrcPath());
				System.out.println(f1.getAbsolutePath());
				f1.mkdirs();
				File f2 = new File(ClaireSDK.settings.getSrcPath()+"build");
				if(!f2.exists()) f2.mkdirs();
				File f3 = new File(ClaireSDK.settings.getSrcPath()+"sensor");
				if(!f3.exists()) f3.mkdirs();
		        try {
		        	System.setProperty("apple.laf.useScreenMenuBar", "true");
					System.setProperty("com.apple.mrj.application.apple.menu.about.name", "ClaireSDK");
			        final Image image = Toolkit.getDefaultToolkit().getImage(Application.class.getResource("/resources/Logo.png"));
			        final Taskbar taskbar = Taskbar.getTaskbar(); 
		            taskbar.setIconImage(image);
		        } catch (final UnsupportedOperationException e) {
		            System.out.println("The os does not support: 'taskbar.setIconImage'");
		        } catch (final SecurityException e) {
		            System.out.println("There was a security exception for: 'taskbar.setIconImage'");
		        } catch (Exception e) {
		        	
		        }
		        UIManager.put("TabbedPane.contentOpaque", false);
		        app = new Application();
				app.getFrame().setVisible(true);
			}
		});
	}
}

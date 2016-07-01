
package soundsamplinggui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class EqualizerSliderGUI extends JFrame implements ActionListener, ChangeListener {
    //Floats to put out to the hardware
    public static float lowMax = 320;
    public static float medMin = 320;
    public static float medMax = 1280;
    public static float highMin = 1280;
    
    //Floats for the power value for the frequency sliders
    public static float powerLow;
    public static float powerMed;
    public static float powerHigh;
    
    //Creating buttons for changing frequency interval.
    private JButton LowInterval = new JButton("Change intervals");
    private JButton MedInterval = new JButton("Change intervals");
    private JButton HighInterval = new JButton("Change intervals");
    
    //Creating JLabels for filling out GUI  
    private JLabel fill1 = new JLabel("<html>Low frequencies<br>(Default interval:0-320). Current interval: 0- " +lowMax+"(hz)</html>", JLabel.CENTER);
    private JLabel fill2 = new JLabel("<html>Medium frequencies<br>(Default interval:320-1280). Current interval: "+medMin+"-"+medMax+"(hz)</html>", JLabel.CENTER);
    private JLabel fill3 = new JLabel ("<html>High frequencies<br>(Default interval:1280 - 20840)<br>"+highMin+" - 20840(hz)</html>)", JLabel.CENTER);
    
    //Creating the sliders
    private JSlider LowFreq = new JSlider (JSlider.VERTICAL, -10, 10, 0);
    private JSlider MedFreq = new JSlider (JSlider.VERTICAL, -10, 10, 0);
    private JSlider HighFreq = new JSlider (JSlider.VERTICAL, -10, 10, 0);
    
    //Making the constructor that creates the frame.   
    public EqualizerSliderGUI() {
        setLayout (new GridLayout(3,3));
        //Adding the JLabels to the first row to create some text
        add(fill1); add(fill2); add(fill3);
        //Adding buttons for changing frequency intervals.
        add(LowInterval); add(MedInterval); add(HighInterval);
        //Adding the Sliders
        add(LowFreq); add(MedFreq); add(HighFreq);
        
        //Setting the properties for the GUI
        fill1.setFont(new Font("Arial", Font.BOLD, 13));
        fill2.setFont(new Font("Arial", Font.BOLD, 13));
        fill3.setFont(new Font("Arial", Font.BOLD, 13));
        setVisible(true);
        setSize (600, 400);
        
        //Adding ActionListeners for our buttons
        LowInterval.addActionListener(this);
        MedInterval.addActionListener(this);
        HighInterval.addActionListener(this);
        
        //Changing button colors
        LowInterval.setBackground(Color.LIGHT_GRAY);
        MedInterval.setBackground(Color.LIGHT_GRAY);
        HighInterval.setBackground(Color.LIGHT_GRAY);
        
        //Adding properties for the sliders
        
        LowFreq.setPaintTicks(true);
        LowFreq.setPaintLabels(true);
        LowFreq.setMinorTickSpacing(1);
        LowFreq.setMajorTickSpacing(5);
        
        MedFreq.setPaintTicks(true);
        MedFreq.setPaintLabels(true);
        MedFreq.setMinorTickSpacing(1);
        MedFreq.setMajorTickSpacing(5);
        
        HighFreq.setPaintTicks(true);
        HighFreq.setPaintLabels(true);
        HighFreq.setMinorTickSpacing(1);
        HighFreq.setMajorTickSpacing(5);
        
        //Adding changelisteners to the sliders
        LowFreq.addChangeListener(this);
        MedFreq.addChangeListener(this);
        HighFreq.addChangeListener(this);
}
        //Class method that performs changes made by the user
        public void actionPerformed(ActionEvent a){
            
            if (a.getSource() == LowInterval){
                lowMax = Float.parseFloat(JOptionPane.showInputDialog("Set new maximum frequecy for your low interval(Default value:320)"));
                fill1.setText("<html>Low frequencies<br>(Default interval:0-400). Current interval: 0- " +lowMax+"</html>");
                GUIlog.updateText("New low frequency interval set to: 0 - " + lowMax);
            }
            else if (a.getSource()== MedInterval){
                medMin = Float.parseFloat(JOptionPane.showInputDialog("Set new minimum frequency for your medium frequency intervalDefault value:320)"));
                medMax = Float.parseFloat(JOptionPane.showInputDialog("Set new maximum frequency for your medium frequency interval(Default value:1280)"));
                fill2.setText("<html>Medium frequencies<br>(Default interval:320-1280). Current interval: "+medMin+"-"+medMax+"</html>");
                GUIlog.updateText("New medium frequency interval set to: " +medMin + " - " + medMax);
            }
            else if (a.getSource()== HighInterval){
                highMin = Float.parseFloat(JOptionPane.showInputDialog("Set new minimum frequency for your high frequency interval(Default value:1280)"));
                fill3.setText("<html>High frequencies<br>(Default interval:1280 - 20840)<br>"+highMin+" - ∞</html>)");
                GUIlog.updateText("New high frequency interval set to: " + highMin + "- infinity");
            }
        }
        //Class method that registers changes in sliders
        public void stateChanged(ChangeEvent e){
            powerLow = (LowFreq.getValue());
            GUIlog.updateText("Set new volume for low frequency interval to: " + powerLow);
            
            powerMed = (MedFreq.getValue());
            GUIlog.updateText("Set new volume for medium frequency interval to: " + powerMed);
            
            powerHigh = (HighFreq.getValue());
            GUIlog.updateText("Set new volume for high frequency interval to: " + powerHigh);
        }
}

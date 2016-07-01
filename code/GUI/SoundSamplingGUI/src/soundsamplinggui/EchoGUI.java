package soundsamplinggui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class EchoGUI extends JFrame implements ActionListener, ChangeListener{
    //Floats to put out to the hardware
    //Volume of our echo
    public static float echoPower;
    //Time between echo
    public static float delayTime;
    
    //Creating JLabels for descriptions of the frame's functions.
    private JLabel modeLabel = new JLabel("<html>Choose your deired mode</html>", JLabel.CENTER);
    private JLabel delayLabel = new JLabel("<html>Set your desired delay<html>", JLabel.CENTER);
    private JLabel powerLabel = new JLabel("<html>Set your desired volume on your echo(dB)<html>", JLabel.CENTER);
    
    //Creating the components to our frame.
    private JComboBox<String> modes = new JComboBox<>();
    private JButton delay = new JButton("Choose delay");
    private JSlider power = new JSlider(JSlider.VERTICAL,-12,12,0);
    
    public EchoGUI(){
        //Creating our layout and giving properties to our frame
        setLayout(new GridLayout(2,3));
        add(modeLabel); add(delayLabel); add(powerLabel);
        add(modes); add(delay); add(power);
        //Adding choices to our modes
        modes.addItem("Mode 1");
        modes.addItem("Mode 2");
        modes.addItem("Mode 3");
        modes.setMaximumRowCount(3);
        //Adding some color
        modes.setOpaque(true);
        modes.setBackground(Color.WHITE);
        delay.setBackground(Color.LIGHT_GRAY);
        //Setting rules for our JSlider
        power.setPaintTicks(true);
        power.setPaintLabels(true);
        power.setMinorTickSpacing(1);
        power.setMajorTickSpacing(3);
        //ChangeListener listens to changes in the slider.
        power.addChangeListener(this);
        //Settings for our JLabels
        modeLabel.setFont(new Font("Arial", Font.BOLD, 15));
        delayLabel.setFont(new Font("Arial", Font.BOLD, 15));
        powerLabel.setFont(new Font("Arial", Font.BOLD, 15));
        //Setting properties for our frame
        setVisible(true);
        setSize(600, 400);
        //Adding ActionListeners to allow for interaction
        modes.addActionListener(this);
        delay.addActionListener(this);
        
    }
    
    //Method for the that tells the combobox and the button what to do.
    public void actionPerformed(ActionEvent a){
        if(a.getSource() == delay){
            delayTime = Float.parseFloat(JOptionPane.showInputDialog("Write a number for your desired delay (seconds)"));
            GUIlog.updateText("New delay time is now: " + delayTime);
        }
        else if(modes.getSelectedIndex()==0){
            power.setValue(3);
            GUIlog.updateText("Echo mode set to 1.");
        }
        else if(modes.getSelectedIndex()==1){
            GUIlog.updateText("Echo mode set to 2.");
        }
        else if(modes.getSelectedIndex()==2){
            GUIlog.updateText("Echo mode set to 3.");
        }
    }
    //Method that tells the slider what to do when value changes.
    public void stateChanged(ChangeEvent e){
        //modeLabel.setText(Integer.toString(power.getValue()));
        //echoPower = (float)(power.getValue()) * (float) 10;
        echoPower = (power.getValue());
        GUIlog.updateText("New value for Echo power is: " + echoPower);
            
        }
    
    
}
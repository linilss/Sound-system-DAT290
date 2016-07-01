package soundsamplinggui;

import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class VolumeGUI extends JFrame implements ChangeListener{
    //Floats to put out to the hardware
    public float newVolume;
    //Creating the components for the Volume control that will be implemented in the frame
    private JSlider VolumeSlider = new JSlider(JSlider.HORIZONTAL,-10,10,0);
    private JLabel VolumeText = new JLabel ("Adjust the volume (dB)", JLabel.CENTER);
        
     //Creating the frame and the properties for it   
    public VolumeGUI(){
        setLayout(new GridLayout(2,1));
        add(VolumeText);add(VolumeSlider);
        setSize(400, 200);
        VolumeText.setFont(new Font("Arial", Font.BOLD, 18));
        //Adding all the properties for the slider
        VolumeSlider.setPaintTicks(true);
        VolumeSlider.setPaintLabels(true);
        VolumeSlider.setMinorTickSpacing(1);
        VolumeSlider.setMajorTickSpacing(5);        
        VolumeSlider.addChangeListener(this);
        setVisible(true);
    }
    
    public void stateChanged(ChangeEvent e){
        newVolume = (VolumeSlider.getValue());
        GUIlog.updateText("New Volume is now:" + newVolume);
    }
   
}

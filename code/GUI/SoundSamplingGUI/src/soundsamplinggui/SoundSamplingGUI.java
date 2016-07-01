package soundsamplinggui;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SoundSamplingGUI extends JFrame implements ActionListener {
    // Creating the buttons that will add the effects
    private JButton Echo = new JButton("Eko-effekt");
    private JButton Equalizer = new JButton ("Equalizer-effekt");
    private JButton Volume = new JButton ("GUI log");

    public SoundSamplingGUI() {
        //Setting our layout for the GUI, this will create att 1 by 3 grid as our layout for the GUI.
        setLayout(new GridLayout(1,3));
        //Adding the components (buttons) to the GUI
        add(Echo);
        add(Equalizer);
        add (Volume);
        //Adding properties to the buttons, adding ActionListener enables the buttons to recognize when you push them.)
        Echo.setFont(new Font("Arial", Font.BOLD, 20));
        Equalizer.setFont(new Font("Arial", Font.BOLD, 20));
        Volume.setFont(new Font("Arial", Font.BOLD, 20));
        
        Echo.addActionListener(this);
        Equalizer.addActionListener(this);
        Volume.addActionListener(this);
        
        //Creating the properties for the GUI window.
        getContentPane().setBackground(Color.lightGray);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(600, 200);
    }

    //This method implements the actions the buttons take when pushed.
    public void actionPerformed(ActionEvent a){
        if (a.getSource() == Echo){
            JFrame d =(new EchoGUI());
        }
        if (a.getSource() == Equalizer){
            JFrame c = (new EqualizerSliderGUI());
        }
        if (a.getSource() == Volume){
            JFrame b = (new GUIlog());
        }
    }

    public static void main(String[] args) {
        SoundSamplingGUI a = new SoundSamplingGUI();
    }
    
}

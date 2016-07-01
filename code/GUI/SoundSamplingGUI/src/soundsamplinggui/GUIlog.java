
package soundsamplinggui;

import javax.swing.*;
import java.awt.*;

public class GUIlog extends JFrame{
    //These Strings will be updated and printed in the changelog
    public static String i = "<html><i>Your actions will be shown here</i></html>";
    public static String v;
    //Creating three labels that will show the three most recent changes made
    public static JLabel log1 = new JLabel(i);
    public static JLabel log2 = new JLabel();
    public static JLabel log3 = new JLabel();
    
    //Creating our window
    public GUIlog(){
        setLayout(new GridLayout(3,1));
        add(log3); add(log2); add(log1);
        setVisible(true);
        setSize(600,300);
        
        //Adding protperties for the labels
        log1.setBackground(Color.BLACK);
        log2.setBackground(Color.BLACK);
        log3.setBackground(Color.BLACK);
        
        log1.setForeground(Color.WHITE);
        log2.setForeground(Color.WHITE);
        log3.setForeground(Color.WHITE);
        
        
        log1.setFont(new Font("Arial",Font.ITALIC,14));
        log2.setFont(new Font("Arial",Font.ITALIC,14));
        log3.setFont(new Font("Arial",Font.ITALIC,14));
        
        log1.setOpaque(true);
        log2.setOpaque(true);
        log3.setOpaque(true);
        
    }
    //Class method that can be called from other classfiles to update the text and send it to the changelog.
    public static void updateText(String t){
        log3.setText(v);
        log2.setText(i);
        v = i;
        i = (t);
        log1.setText(i);
    }
}

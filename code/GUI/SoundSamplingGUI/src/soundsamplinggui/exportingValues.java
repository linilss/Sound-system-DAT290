
package soundsamplinggui;

public class exportingValues {
    //Returning float values for the echo's power and it's delay time
    public static float echoPowerExport(){
        return EchoGUI.echoPower;
    }
    
    public static float delayTimeExport(){
        return EchoGUI.delayTime;
        
    }
    
    //Returning float values for the equalizer frequency intervals
    public static float lowMaxExport(){
        return EqualizerSliderGUI.lowMax;
    }
    
    public static float medMinExport(){
        return EqualizerSliderGUI.medMin;
    }
    
    public static float medMaxExport(){
        return EqualizerSliderGUI.medMax;
    }
    
    public static float highMinExport(){
        return EqualizerSliderGUI.highMin;
    }
    
    //Returning float values for the equalizer power sliders
    public static float powerLowExport(){
        return EqualizerSliderGUI.powerLow;
    }
    
    public static float powerMedExport(){
        return EqualizerSliderGUI.powerMed;
    }
    
    public static float powerHighExport(){
        return EqualizerSliderGUI.powerHigh;
    }
}

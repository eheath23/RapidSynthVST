/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RapidSynthVstAudioProcessorEditor::RapidSynthVstAudioProcessorEditor (RapidSynthVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
   
    setSize (800, 600);
    
    addAndMakeVisible(scene);
    
    //OSC 1
    scene.oscScene.osc1.dial1.setName("osc1FilterCutoff");
    scene.oscScene.osc1.dial1.addListener (this);
    
    scene.oscScene.osc1.dial2.setName("osc1Detune");
    scene.oscScene.osc1.dial2.addListener (this);

    scene.oscScene.osc1.dial3.setName("osc1Gain");
    scene.oscScene.osc1.dial3.addListener (this);

    scene.oscScene.osc1.sineButton.setName("osc1Sine");
    scene.oscScene.osc1.sineButton.addListener(this);
    
    scene.oscScene.osc1.sawButton.setName("osc1Saw");
    scene.oscScene.osc1.sawButton.addListener(this);
    
    scene.oscScene.osc1.squareButton.setName("osc1Square");
    scene.oscScene.osc1.squareButton.addListener(this);
    
    //OSC 2
    scene.oscScene.osc2.dial1.setName("osc2FilterCutoff");
    scene.oscScene.osc2.dial1.addListener (this);
    
    scene.oscScene.osc2.dial2.setName("osc2Detune");
    scene.oscScene.osc2.dial2.addListener (this);
    
    scene.oscScene.osc2.dial3.setName("osc2Gain");
    scene.oscScene.osc2.dial3.addListener (this);
    
    scene.oscScene.osc2.sineButton.setName("osc2Sine");
    scene.oscScene.osc2.sineButton.addListener(this);
    
    scene.oscScene.osc2.sawButton.setName("osc2Saw");
    scene.oscScene.osc2.sawButton.addListener(this);
    
    scene.oscScene.osc2.squareButton.setName("osc2Square");
    scene.oscScene.osc2.squareButton.addListener(this);
    
    //OSC 3
    scene.oscScene.osc3.dial1.setName("osc3FilterCutoff");
    scene.oscScene.osc3.dial1.addListener (this);
    
    scene.oscScene.osc3.dial2.setName("osc3Detune");
    scene.oscScene.osc3.dial2.addListener (this);
    
    scene.oscScene.osc3.dial3.setName("osc3Gain");
    scene.oscScene.osc3.dial3.addListener (this);
    
    scene.oscScene.osc3.sineButton.setName("osc3Sine");
    scene.oscScene.osc3.sineButton.addListener(this);
    
    scene.oscScene.osc3.sawButton.setName("osc3Saw");
    scene.oscScene.osc3.sawButton.addListener(this);
    
    scene.oscScene.osc3.squareButton.setName("osc3Square");
    scene.oscScene.osc3.squareButton.addListener(this);

    //LFO 1
    scene.modScene.lfo.dial1.setName("LFO1Freq");
    scene.modScene.lfo.dial1.addListener (this);
    
    scene.modScene.lfo.dial2.setName("LFO1Gain");
    scene.modScene.lfo.dial2.addListener (this);

    scene.modScene.lfo.dial3.setName("masterGain");
    scene.modScene.lfo.dial3.addListener (this);
    
    scene.modScene.lfo.sineButton.setName("LFO1Sine");
    scene.modScene.lfo.sineButton.addListener(this);
    
    scene.modScene.lfo.sawButton.setName("LFO1Saw");
    scene.modScene.lfo.sawButton.addListener(this);
    
    scene.modScene.lfo.squareButton.setName("LFO1Square");
    scene.modScene.lfo.squareButton.addListener(this);

    //FILTER
    scene.modScene.filter.dial1.setName("VCOCutoff");
    scene.modScene.filter.dial1.addListener(this);
    
    scene.modScene.filter.dial2.setName("VCORes");
    scene.modScene.filter.dial2.addListener(this);
    
    //ENVELOPE
    scene.modScene.envelope.ADSR1Attack.setName("ADSR1Attack");
    scene.modScene.envelope.ADSR1Attack.addListener(this);
    
    scene.modScene.envelope.ADSR1Decay.setName("ADSR1Decay");
    scene.modScene.envelope.ADSR1Decay.addListener(this);
    
    scene.modScene.envelope.ADSR1Sustain.setName("ADSR1Sustain");
    scene.modScene.envelope.ADSR1Sustain.addListener(this);
    
    scene.modScene.envelope.ADSR1Release.setName("ADSR1Release");
    scene.modScene.envelope.ADSR1Release.addListener(this);
    
    //MACHINE LEARNING
    scene.XY.button1.setName("MLButton1");
    scene.XY.button1.addListener(this);
    
    scene.XY.button2.setName("MLButton2");
    scene.XY.button2.addListener(this);
    
    scene.XY.button3.setName("MLButton3");
    scene.XY.button3.addListener(this);
    
    scene.XY.button4.setName("MLButton4");
    scene.XY.button4.addListener(this);
    
    scene.XY.button5.setName("MLButtonMix");
    scene.XY.button5.addListener(this);
    
    addAndMakeVisible(targetShape);
    
    //MACHINE LEARNING SETUP
    //BUTTON 1
    trainingExample1.input = { (double)scene.XY.button1.getX(), (double)scene.XY.button1.getY() };
    trainingExample1.output = { osc1FilterCutoff,
         osc1Detune,
         osc1Gain,
         osc2FilterCutoff,
         osc2Detune,
         osc2Gain,
         osc3FilterCutoff,
         osc3Detune,
         osc3Gain,
         LFO1Freq,
         LFO1Gain,
         VCOCutoff,
         masterGain,
         ADSR1Attack,
         ADSR1Decay,
         ADSR1Sustain,
         ADSR1Release,
         VCORes };
    
    //BUTTON 2
    trainingExample2.input = { (double)scene.XY.button2.getX(), (double)scene.XY.button2.getY() };
    trainingExample2.output = { osc1FilterCutoff,
        osc1Detune,
        osc1Gain,
        osc2FilterCutoff,
        osc2Detune,
        osc2Gain,
        osc3FilterCutoff,
        osc3Detune,
        osc3Gain,
        LFO1Freq,
        LFO1Gain,
        VCOCutoff,
        masterGain,
        ADSR1Attack,
        ADSR1Decay,
        ADSR1Sustain,
        ADSR1Release,
        VCORes };
    
    //BUTTON 3
    trainingExample3.input = { (double)scene.XY.button3.getX(), (double)scene.XY.button3.getY() };
    trainingExample3.output = { osc1FilterCutoff,
        osc1Detune,
        osc1Gain,
        osc2FilterCutoff,
        osc2Detune,
        osc2Gain,
        osc3FilterCutoff,
        osc3Detune,
        osc3Gain,
        LFO1Freq,
        LFO1Gain,
        VCOCutoff,
        masterGain,
        ADSR1Attack,
        ADSR1Decay,
        ADSR1Sustain,
        ADSR1Release,
        VCORes };
    
    //BUTTON 4
    trainingExample4.input = { (double)scene.XY.button4.getX(), (double)scene.XY.button4.getY() };
    trainingExample4.output = { osc1FilterCutoff,
        osc1Detune,
        osc1Gain,
        osc2FilterCutoff,
        osc2Detune,
        osc2Gain,
        osc3FilterCutoff,
        osc3Detune,
        osc3Gain,
        LFO1Freq,
        LFO1Gain,
        VCOCutoff,
        masterGain,
        ADSR1Attack,
        ADSR1Decay,
        ADSR1Sustain,
        ADSR1Release,
        VCORes };
    
    trainingSet.resize(4);
    trainingSet = { trainingExample1, trainingExample2, trainingExample3, trainingExample4 };
    
    targetShape.setBounds(200, 200, 25, 25);
}

RapidSynthVstAudioProcessorEditor::~RapidSynthVstAudioProcessorEditor()
{
}

//==============================================================================
void RapidSynthVstAudioProcessorEditor::paint (Graphics& g)
{

}

void RapidSynthVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    if(targetShape.myDragger.isDragging)
    {
        process = true;
        targetMoved();
    }
    
    auto r = getLocalBounds();
    scene.setBounds(r);
}

//=======================================================================
AudioProcessorParameter* RapidSynthVstAudioProcessorEditor::getParameter (const String& paramId)
{
    if (AudioProcessor* processor = getAudioProcessor())
    {
        const OwnedArray<AudioProcessorParameter>& params = processor->getParameters();

        for (int i = 0; i < params.size(); ++i)
        {
            if (AudioProcessorParameterWithID* param = dynamic_cast<AudioProcessorParameterWithID*> (params[i]))
            {
                if (param->paramID == paramId)
                    return param;
            }
        }
    }

    return nullptr;
}

//=======================================================================
float RapidSynthVstAudioProcessorEditor::getParameterValue (const String& paramId)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        return param->getValue();

    return 0.0f;
}

//=======================================================================
void RapidSynthVstAudioProcessorEditor::setParameterValue (const String& paramId, float value)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        param->setValueNotifyingHost (value);
}

//=======================================================================
void RapidSynthVstAudioProcessorEditor::sliderValueChanged(Slider* slider){
    
    //OSC 1
    if (slider->getName() == "osc1FilterCutoff")
    {
        setParameterValue("osc1FilterCutoff", scene.oscScene.osc1.dial1.getValue());
    }
    if (slider->getName() == "osc1Detune")
    {
        setParameterValue("osc1Detune", scene.oscScene.osc1.dial2.getValue());
    }
    if (slider->getName() == "osc1Gain")
    {
        setParameterValue("osc1Gain", scene.oscScene.osc1.dial3.getValue());
    }
    
    //OSC 2
    if (slider->getName() == "osc2FilterCutoff")
    {
        setParameterValue("osc2FilterCutoff", scene.oscScene.osc2.dial1.getValue());
    }
    if (slider->getName() == "osc2Detune")
    {
        setParameterValue("osc2Detune", scene.oscScene.osc2.dial2.getValue());
    }
    if (slider->getName() == "osc2Gain")
    {
        setParameterValue("osc2Gain", scene.oscScene.osc2.dial3.getValue());
    }

    //OSC 3
    if (slider->getName() == "osc3FilterCutoff")
    {
        setParameterValue("osc3FilterCutoff", scene.oscScene.osc3.dial1.getValue());
    }

    if (slider->getName() == "osc3Detune")
    {
        setParameterValue("osc3Detune", scene.oscScene.osc3.dial2.getValue());
    }
    if (slider->getName() == "osc3Gain")
    {
        setParameterValue("osc3Gain", scene.oscScene.osc3.dial3.getValue());
    }

    //LFO
    if (slider->getName() == "LFO1Freq")
    {
        setParameterValue("LFO1Freq", scene.modScene.lfo.dial1.getValue());
    }
    if (slider->getName() == "LFO1Gain")
    {
        setParameterValue("LFO1Gain", scene.modScene.lfo.dial2.getValue());
    }
    
    //GAIN
    if (slider->getName() == "masterGain")
    {
        setParameterValue("masterGain", scene.modScene.lfo.dial3.getValue());
    }
    
    //FILTER
    if (slider->getName() == "VCOCutoff")
    {
        setParameterValue("VCOCutoff", scene.modScene.filter.dial1.getValue());
    }
    if (slider->getName() == "VCORes")
    {
        setParameterValue("VCORes", scene.modScene.filter.dial2.getValue());
    }
    
    //ENVELOPE
    if (slider->getName() == "ADSR1Attack")
    {
        setParameterValue("ADSR1Attack", scene.modScene.envelope.ADSR1Attack.getValue());
        std::cout << "attack" << std::endl; 
    }
    if (slider->getName() == "ADSR1Decay")
    {
        setParameterValue("ADSR1Decay", scene.modScene.envelope.ADSR1Decay.getValue());
    }
    if (slider->getName() == "ADSR1Sustain")
    {
        setParameterValue("ADSR1Sustain", scene.modScene.envelope.ADSR1Sustain.getValue());
    }
    if (slider->getName() == "ADSR1Release")
    {
        setParameterValue("ADSR1Release", scene.modScene.envelope.ADSR1Release.getValue());
    }
    
}

//** BUTTONS **//
//=============================================================================
void RapidSynthVstAudioProcessorEditor:: buttonClicked (Button* button)
{
    //OSC 1
    if (button->getName() == "osc1Sine")
    {
        setParameterValue("osc1Sine", true);
        setParameterValue("osc1Saw", false);
        setParameterValue("osc1Square", false);

    } else if (button->getName() == "osc1Saw")
    {
        setParameterValue("osc1Saw", true);
        setParameterValue("osc1Sine", false);
        setParameterValue("osc1Square", false);
        
    } else if (button->getName() == "osc1Square")
    {
        setParameterValue("osc1Square", true);
        setParameterValue("osc1Saw", false);
        setParameterValue("osc1Sine", false);

    }
    
    //OSC 2
    if (button->getName() == "osc2Sine")
    {
        setParameterValue("osc2Sine", true);
        setParameterValue("osc2Saw", false);
        setParameterValue("osc2Square", false);


    } else if (button->getName() == "osc2Saw")
    {
        setParameterValue("osc2Saw", true);
        setParameterValue("osc2Sine", false);
        setParameterValue("osc2Square", false);

    } else if (button->getName() == "osc2Square")
    {
        setParameterValue("osc2Square", true);
        setParameterValue("osc2Saw", false);
        setParameterValue("osc2Sine", false);

    }
    
    //OSC 3
    if (button->getName() == "osc3Sine")
    {
        setParameterValue("osc3Sine", true);
        setParameterValue("osc3Saw", false);
        setParameterValue("osc3Square", false);
        
    } else if (button->getName() == "osc3Saw")
    {
        setParameterValue("osc3Saw", true);
        setParameterValue("osc3Sine", false);
        setParameterValue("osc3Square", false);

    } else if (button->getName() == "osc3Square")
    {
        setParameterValue("osc3Square", true);
        setParameterValue("osc3Saw", false);
        setParameterValue("osc3Sine", false);

    }
    
    //LFO 1
    if (button->getName() == "LFO1Sine")
    {
        setParameterValue("LFO1Sine", true);
        setParameterValue("LFO1Saw", false);
        setParameterValue("LFO1Square", false);
    } else if (button->getName() == "LFO1Saw")
    {
        setParameterValue("LFO1Saw", true);
        setParameterValue("LFO1Sine", false);
        setParameterValue("LFO1Square", false);
    } else if (button->getName() == "LFO1Square")
    {
        setParameterValue("LFO1Square", true);
        setParameterValue("LFO1Sine", false);
        setParameterValue("LFO1Saw", false);
    }
    
    //MACHINE LEARNING
    if (button->getName() == "MLButton1")
    {
        trained = true;
//        trainingSet[0][1][] =
        trainingExample1.output = { osc1FilterCutoff,
            osc1Detune,
            osc1Gain,
            osc2FilterCutoff,
            osc2Detune,
            osc2Gain,
            osc3FilterCutoff,
            osc3Detune,
            osc3Gain,
            LFO1Freq,
            LFO1Gain,
            VCOCutoff,
            masterGain,
            ADSR1Attack,
            ADSR1Decay,
            ADSR1Sustain,
            ADSR1Release,
            VCORes };
        
        trainingSet[0] = trainingExample1;
        
    } else if (button->getName() == "MLButton2")
    {
        trained = true;
        
        trainingExample2.output = { osc1FilterCutoff,
            osc1Detune,
            osc1Gain,
            osc2FilterCutoff,
            osc2Detune,
            osc2Gain,
            osc3FilterCutoff,
            osc3Detune,
            osc3Gain,
            LFO1Freq,
            LFO1Gain,
            VCOCutoff,
            masterGain,
            ADSR1Attack,
            ADSR1Decay,
            ADSR1Sustain,
            ADSR1Release,
            VCORes };
        
        trainingSet[1] = trainingExample2;
   
    } else if (button->getName() == "MLButton3")
    {
        trained = true;
        
        trainingExample3.output = { osc1FilterCutoff,
            osc1Detune,
            osc1Gain,
            osc2FilterCutoff,
            osc2Detune,
            osc2Gain,
            osc3FilterCutoff,
            osc3Detune,
            osc3Gain,
            LFO1Freq,
            LFO1Gain,
            VCOCutoff,
            masterGain,
            ADSR1Attack,
            ADSR1Decay,
            ADSR1Sustain,
            ADSR1Release,
            VCORes };
        
        trainingSet[2] = trainingExample3;
        
    } else if (button->getName() == "MLButton4")
    {
        trained = true;

        trainingExample4.output = { osc1FilterCutoff,
            osc1Detune,
            osc1Gain,
            osc2FilterCutoff,
            osc2Detune,
            osc2Gain,
            osc3FilterCutoff,
            osc3Detune,
            osc3Gain,
            LFO1Freq,
            LFO1Gain,
            VCOCutoff,
            masterGain,
            ADSR1Attack,
            ADSR1Decay,
            ADSR1Sustain,
            ADSR1Release,
            VCORes };
        
        trainingSet[3] = trainingExample4;
        
    } else if (button->getName() == "MLButtonMix")
    {
        
    }
}

void RapidSynthVstAudioProcessorEditor::targetMoved()
{
    if (process)
    {
        if (trained)
        {
            std::vector<double> input =  { (double)targetShape.getX(), (double)targetShape.getY() };
            std::vector<double> output = rapidRegression.process(input);
            
            //        targetModulationFrequency = output[0];
            //        targetModulationDepth     = output[1];
            //        targetCentreFrequency     = output[2];
            //        targetResonance           = output[3];
            
            osc1FilterCutoff = output[0];
            osc1Detune = output[1];
            osc1Gain = output[2];
            osc2FilterCutoff = output[3];
            osc2Detune = output[4];
            osc2Gain = output[5];
            osc3FilterCutoff = output[6];
            osc3Detune = output[7];
            osc3Gain = output[8];
            LFO1Freq = output[9];
            LFO1Gain = output[10];
            VCOCutoff = output[11];
            masterGain = output[12];
            ADSR1Attack = output[13];
            ADSR1Decay = output[14];
            ADSR1Sustain = output[15];
            ADSR1Release = output[16];
            VCORes = output[17];
            
            //        modulationFrequencySlider.setValue(targetModulationFrequency, dontSendNotification);
            //        modulationIndexSlider.setValue(targetModulationDepth, dontSendNotification);
            //        filterFrequencySlider.setValue(targetCentreFrequency, dontSendNotification);
            //        filterResonanceSlider.setValue(targetResonance, dontSendNotification);
            
            scene.oscScene.osc1.dial1.setValue(osc1FilterCutoff);
            scene.oscScene.osc1.dial2.setValue(osc1Detune);
            scene.oscScene.osc1.dial3.setValue(osc1Gain);
            
            //OSC 2
            scene.oscScene.osc2.dial1.setValue(osc2FilterCutoff);
            scene.oscScene.osc2.dial2.setValue(osc2Detune);
            scene.oscScene.osc2.dial3.setValue(osc2Gain);
            
            //OSC 3
            scene.oscScene.osc3.dial1.setValue(osc3FilterCutoff);
            scene.oscScene.osc3.dial2.setValue(osc3Detune);
            scene.oscScene.osc3.dial3.setValue(osc3Gain);
            
            //LFO 1
            scene.modScene.lfo.dial1.setValue(LFO1Freq);
            scene.modScene.lfo.dial2.setValue(LFO1Gain);
            scene.modScene.lfo.dial3.setValue(masterGain);
            
            //FILTER
            scene.modScene.filter.dial1.setValue(VCOCutoff);
            scene.modScene.filter.dial2.setValue(VCORes);
            
            //ENVELOPE
            scene.modScene.envelope.ADSR1Attack.setValue(ADSR1Attack);
            scene.modScene.envelope.ADSR1Decay.setValue(ADSR1Decay);
            scene.modScene.envelope.ADSR1Sustain.setValue(ADSR1Sustain);
            scene.modScene.envelope.ADSR1Release.setValue(ADSR1Release);
        }
    }
}

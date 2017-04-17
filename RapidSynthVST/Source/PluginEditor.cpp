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
    
    scene.XY.button1.addListener(this);
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
//        if(scene.modScene.lfo.dial2.getValue() > 0)
//        {
//            processor.LFO1ModVCOCutoff = true;
//        }
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
}

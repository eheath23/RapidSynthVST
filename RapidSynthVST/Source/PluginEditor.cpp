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
//    scene.oscScene.osc1.dial1.setSliderStyle (Slider::RotaryVerticalDrag);
//    scene.oscScene.osc1.dial1.setRange(0.0, 1.0);
//    scene.oscScene.osc1.dial1.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
//    scene.oscScene.osc1.dial1.setPopupDisplayEnabled(true, this);
//    scene.oscScene.osc1.dial1.setTextValueSuffix("Hz");
//    scene.oscScene.osc1.dial1.setValue(1.0);
//    
    
    scene.oscScene.osc1.dial2.setName("osc1Detune");
    scene.oscScene.osc1.dial2.addListener (this);
//    scene.oscScene.osc1.dial2.setSliderStyle (Slider::RotaryVerticalDrag);
//    scene.oscScene.osc1.dial2.setRange(-12, 12, 1);
//    scene.oscScene.osc1.dial2.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
//    scene.oscScene.osc1.dial2.setPopupDisplayEnabled(true, this);
//    scene.oscScene.osc1.dial2.setTextValueSuffix("Semitones");
//    scene.oscScene.osc1.dial2.setValue(0.0);

    
    scene.oscScene.osc1.dial3.setName("osc1Gain");
    scene.oscScene.osc1.dial3.addListener (this);
//    scene.oscScene.osc1.dial3.setSliderStyle (Slider::RotaryVerticalDrag);
//    scene.oscScene.osc1.dial3.setRange(0.0, 1.0);
//    scene.oscScene.osc1.dial3.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
//    scene.oscScene.osc1.dial3.setPopupDisplayEnabled(true, this);
//    scene.oscScene.osc1.dial3.setTextValueSuffix("Gain");
//    scene.oscScene.osc1.dial3.setValue(1.0);

    
    //OSC 2
    scene.oscScene.osc2.dial1.setName("osc2FilterCutoff");
    scene.oscScene.osc2.dial1.addListener (this);
    
    scene.oscScene.osc2.dial2.setName("osc2Detune");
    scene.oscScene.osc2.dial2.addListener (this);
    
    scene.oscScene.osc2.dial3.setName("osc2Gain");
    scene.oscScene.osc2.dial3.addListener (this);
    
    //OSC 3
    scene.oscScene.osc3.dial1.setName("osc3FilterCutoff");
    scene.oscScene.osc3.dial1.addListener (this);
    
    scene.oscScene.osc3.dial2.setName("osc3Detune");
    scene.oscScene.osc3.dial2.addListener (this);
    
    scene.oscScene.osc3.dial3.setName("osc3Gain");
    scene.oscScene.osc3.dial3.addListener (this);

    //LFO 1
    scene.modScene.lfo.dial1.setName("LFO1Freq");
    scene.modScene.lfo.dial1.addListener (this);
    
    scene.modScene.lfo.dial2.setName("LFO1Gain");
    scene.modScene.lfo.dial2.addListener (this);

    scene.modScene.lfo.dial3.setName("masterGain");
    scene.modScene.lfo.dial3.addListener (this);

    //FILTER
    scene.modScene.filter.cutoffFrequencySlider.setName("VCOcutoff");
    scene.modScene.filter.cutoffFrequencySlider.addListener(this);
    
    //ENVELOPE
    scene.modScene.envelope.MLSlider.addListener(this);
    scene.modScene.envelope.trainButton.addListener(this);
    scene.modScene.envelope.addButton.addListener(this);
    
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
    else if (slider->getName() == "osc2Detune")
    {
        setParameterValue("osc2Detune", scene.oscScene.osc2.dial2.getValue());
    }
    else if (slider->getName() == "osc2Gain")
    {
        setParameterValue("osc2Gain", scene.oscScene.osc2.dial3.getValue());
    }

    //OSC 3
    else if (slider->getName() == "osc3FilterCutoff")
    {
        setParameterValue("osc3FilterCutoff", scene.oscScene.osc3.dial1.getValue());
    }

    else if (slider->getName() == "osc3Detune")
    {
        setParameterValue("osc3Detune", scene.oscScene.osc3.dial2.getValue());
    }
    else if (slider->getName() == "osc3Gain")
    {
        setParameterValue("osc3Gain", scene.oscScene.osc3.dial3.getValue());
    }

    //LFO
    else if (slider->getName() == "LFO1Freq")
    {
        setParameterValue("LFO1Freq", scene.modScene.lfo.dial1.getValue());
    }
    else if (slider->getName() == "LFO1Gain")
    {
        setParameterValue("LFO1Gain", scene.modScene.lfo.dial2.getValue());
    }
    
    //FILTER
//    else if (slider->getName() == "VCOcutoff")
//    {
//        setParameterValue("VCOcutoff", scene.modScene.filter.cutoffFrequencySlider.getValue());
//    }
    
    //GAIN
    else if (slider->getName() == "masterGain")
    {
        setParameterValue("masterGain", scene.modScene.lfo.dial3.getValue());
    }
}

//** BUTTONS **//
//=============================================================================
void RapidSynthVstAudioProcessorEditor:: buttonClicked (Button* button)
{
    //    if(button == &scene.modScene.envelope.trainButton)
    //    {
    ////        if (trainingSet.size() > 2)
    ////        {
    ////            trained = rapidRegression.train(trainingSet);
    ////            std::cout << "trained" << std::endl;
    ////        }
    //    }
    //
    //    if(button == &scene.modScene.envelope.addButton)
    //    {
    ////        trainingExample example;
    ////        example.input = {MLSliderVal};
    ////        example.output = { };
    ////        trainingSet.push_back(example);
    //    }
}

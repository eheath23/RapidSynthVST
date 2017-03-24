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
    
//    scene.oscScene.osc1.dial1.addListener (this);
//    scene.oscScene.osc1.dial2.addListener (this);
//    scene.oscScene.osc1.dial3.addListener (this);
//    
//    scene.oscScene.osc2.dial1.addListener (this);
//    scene.oscScene.osc2.dial2.addListener (this);
//    scene.oscScene.osc2.dial3.addListener (this);
//    
//    scene.oscScene.osc3.dial1.addListener (this);
//    scene.oscScene.osc3.dial2.addListener (this);
//    scene.oscScene.osc3.dial3.addListener (this);
//    
//    scene.modScene.lfo.dial1.addListener (this);
//    scene.modScene.lfo.dial2.addListener (this);
//    scene.modScene.lfo.dial3.addListener (this);
//    
//    scene.modScene.filter.cutoffFrequencySlider.addListener(this);
//    
//    scene.modScene.envelope.MLSlider.addListener(this);
//    scene.modScene.envelope.trainButton.addListener(this);
//    scene.modScene.envelope.addButton.addListener(this);
//    
//    scene.XY.button1.addListener(this);
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

void RapidSynthVstAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
//    //==============================================================================
//    //OSC 1 Dials
//    if (slider == &scene.oscScene.osc1.dial1)
//    {
////        osc1FilterCutoff[cVoice] = scene.oscScene.osc1.dial1.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc1.dial2)
//    {
////        osc1Detune[cVoice] = scene.oscScene.osc1.dial2.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc1.dial3)
//    {
////        osc1Gain[cVoice] = scene.oscScene.osc1.dial3.getValue();
//    }
//    
//    //==============================================================================
//    //OSC 2 Dials
//    if (slider == &scene.oscScene.osc2.dial1)
//    {
////        osc2FilterCutoff[cVoice] = scene.oscScene.osc2.dial1.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc2.dial2)
//    {
////        osc2Detune[cVoice] = scene.oscScene.osc2.dial2.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc2.dial3)
//    {
////        osc2Gain[cVoice] = scene.oscScene.osc2.dial3.getValue();
//    }
//    
//    //==============================================================================
//    //OSC 3 Dials
//    if (slider == &scene.oscScene.osc3.dial1)
//    {
////        osc3FilterCutoff[cVoice] = scene.oscScene.osc3.dial1.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc3.dial2)
//    {
////        osc3Detune[cVoice] = scene.oscScene.osc3.dial2.getValue();
//    }
//    
//    if (slider == &scene.oscScene.osc3.dial3)
//    {
////        osc3Gain[cVoice] = scene.oscScene.osc3.dial3.getValue();
//    }
//    
//    //==============================================================================
//    //LFO 1 Dials
//    if (slider == &scene.modScene.lfo.dial1)
//    {
////        LFO1Freq[cVoice] = scene.modScene.lfo.dial1.getValue();
//    }
//    
//    if (slider == &scene.modScene.lfo.dial2){
//    
////        LFO1Gain[cVoice] = scene.modScene.lfo.dial2.getValue();
//    }
//    
//    if (slider == &scene.modScene.lfo.dial3)
//    {
////        masterGain = scene.modScene.lfo.dial3.getValue();
//    }
//    
//    //==============================================================================
//    //VCO Slider
//    if (slider == &scene.modScene.filter.cutoffFrequencySlider)
//    {
////        VCOcutoff[cVoice] = scene.modScene.filter.cutoffFrequencySlider.getValue();
//    }
//    
//    //==============================================================================
//    //MACHINE LEARNING SLIDER
//    if(slider == &scene.modScene.envelope.MLSlider)
//    {
////        MLSliderVal = scene.modScene.envelope.MLSlider.getValue();
//    }
}

//** BUTTONS **//
//==============================================================================
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

/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "RapidLib/src/regression.h"
#include <array>
#include <math.h>

#include "SceneComponent.h"


//==============================================================================
/**
*/

////////////////////////////////////////
class RapidSynthVstAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Slider::Listener,
                                           public Button::Listener,
                                           private Timer
{
public:
    RapidSynthVstAudioProcessorEditor (RapidSynthVstAudioProcessor&);
    ~RapidSynthVstAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* button) override;
    void timerCallback() override;
    void targetMoved ();
    std::vector<double> normaliseMouseSpace(const juce::Point<int>& _position, const juce::Rectangle<int>& _area);
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProcessorParameter* getParameter (const String& paramId);
    float                    getParameterValue (const String& paramId);
    void                     setParameterValue (const String& paramId, float value);
    
    /*** MACHINE LEARNING ***/
    // Rapid regression
    regression                   rapidRegression;
    std::vector<trainingExample> trainingSet;
    trainingExample              trainingExample1;
    trainingExample              trainingExample2;
    trainingExample              trainingExample3;
    trainingExample              trainingExample4;
    
    std::vector<double> example1Input, example2Input, example3Input, example4Input;
    
    std::vector<double> example1Output, example2Output, example3Output, example4Output;
    
    // Output Params
    double osc1FilterCutoff;
    double osc1Detune;
    double osc1Gain;
    double osc2FilterCutoff;
    double osc2Detune;
    double osc2Gain;
    double osc3FilterCutoff;
    double osc3Detune;
    double osc3Gain;
    double LFO1Freq;
    double LFO1Gain;
    double VCOCutoff;
    double masterGain;
    double ADSR1Attack;
    double ADSR1Decay;
    double ADSR1Sustain;
    double ADSR1Release;
//    bool osc1Sine;
//    bool osc1Saw;
//    bool osc1Square;
//    bool osc2Sine;
//    bool osc2Saw;
//    bool osc2Square;
//    bool osc3Sine;
//    bool osc3Saw;
//    bool osc3Square;
//    bool LFO1Sine;
//    bool LFO1Saw;
//    bool LFO1Square;
    double VCORes;
    
    // Program state
    bool                         button1Trained = false, button2Trained = false, button3Trained = false, button4Trained = false, trained = false;
    bool                         process;
    bool run = false; 

    juce::Rectangle<int>         drawingArea;
    SceneComponent scene;
    
    RapidSynthVstAudioProcessor& processor;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RapidSynthVstAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED

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


//==============================================================================
/**
*/
class VstexampleAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener
{
public:
    VstexampleAudioProcessorEditor (VstexampleAudioProcessor&);
    ~VstexampleAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider*) override;
    
    Slider modulationIndex, modulationFrequency;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProcessorParameter* getParameter (const String& paramId);
    float                    getParameterValue (const String& paramId);
    void                     setParameterValue (const String& paramId, float value);
    
    VstexampleAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstexampleAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED

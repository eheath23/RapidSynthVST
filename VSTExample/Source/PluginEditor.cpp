/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VstexampleAudioProcessorEditor::VstexampleAudioProcessorEditor (VstexampleAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    modulationIndex.setName("modIndex");
    modulationIndex.addListener(this);
    modulationIndex.setSliderStyle(Slider::LinearBarVertical);
    modulationIndex.setRange(0.0, 1000.0, 0.0);
    modulationIndex.setPopupDisplayEnabled(true, this);
    modulationIndex.setTextValueSuffix("% radness");
    modulationIndex.setValue(0);
    
    addAndMakeVisible(modulationIndex);
    
    modulationFrequency.addListener(this);
    modulationFrequency.setName("modFreq");
    modulationFrequency.setSliderStyle(Slider:: LinearBarVertical);
    modulationFrequency.setRange(0, 100);
    modulationFrequency.setPopupDisplayEnabled(true, this);
    modulationFrequency.setTextValueSuffix("Hz");
    modulationFrequency.setValue(0);
    
    addAndMakeVisible(modulationFrequency);
                                
}

VstexampleAudioProcessorEditor::~VstexampleAudioProcessorEditor()
{
}

//==============================================================================
void VstexampleAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void VstexampleAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    modulationIndex.setBounds(40, 10, 20, getHeight()-60);
    modulationFrequency.setBounds(getWidth()-40, 30, 20, getHeight()-60);
}

AudioProcessorParameter* VstexampleAudioProcessorEditor::getParameter (const String& paramId)
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

float VstexampleAudioProcessorEditor::getParameterValue (const String& paramId)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        return param->getValue();
    
    return 0.0f;
}

void VstexampleAudioProcessorEditor::setParameterValue (const String& paramId, float value)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        param->setValueNotifyingHost (value);
}

void VstexampleAudioProcessorEditor::sliderValueChanged(Slider* slider){
    if (slider->getName() == "modIndex")
    {
        setParameterValue("modIndex", modulationIndex.getValue());
    }
    else if (slider->getName() == "modFreq")
    {
        setParameterValue("modFreq", modulationFrequency.getValue());
    }
}


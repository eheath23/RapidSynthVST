/*
  ==============================================================================

    EnvelopeComponent.h
    Created: 6 Mar 2017 5:18:26pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef ENVELOPECOMPONENT_H_INCLUDED
#define ENVELOPECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class EnvelopeComponent    : public Component
{
public:
    EnvelopeComponent()
    {
        
        addAndMakeVisible(ADSR1Attack);
        ADSR1Attack.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Attack.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Attack.setRange(0.0, 1);
        ADSR1Attack.setValue(0.1);
        
        addAndMakeVisible (attackDial);
        attackDial.setText ("Attack", dontSendNotification);
        attackDial.setJustificationType(Justification::centredBottom);
        attackDial.setInterceptsMouseClicks(false, false);

        addAndMakeVisible(ADSR1Decay);
        ADSR1Decay.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Decay.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Decay.setRange(0.0, 1);
        ADSR1Decay.setValue(0.1);
        
        addAndMakeVisible (decayDial);
        decayDial.setText ("Decay", dontSendNotification);
        decayDial.setJustificationType(Justification::centredBottom);
        decayDial.setInterceptsMouseClicks(false, false);
        
        addAndMakeVisible(ADSR1Sustain);
        ADSR1Sustain.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Sustain.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Sustain.setRange(0.0, 1.0);
        ADSR1Sustain.setValue(1);
        
        addAndMakeVisible (sustainDial);
        sustainDial.setText ("Sustain", dontSendNotification);
        sustainDial.setJustificationType(Justification::centredBottom);
        sustainDial.setInterceptsMouseClicks(false, false);
        
        addAndMakeVisible(ADSR1Release);
        ADSR1Release.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Release.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Release.setRange(0.0, 1);
        ADSR1Release.setValue(0.1);
        
        addAndMakeVisible (releaseDial);
        releaseDial.setText ("Release", dontSendNotification);
        releaseDial.setJustificationType(Justification::centredBottom);
        releaseDial.setInterceptsMouseClicks(false, false);
        
    }

    ~EnvelopeComponent()
    {
    }

    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        auto r = getLocalBounds();
        int divisor = (r.getHeight()/4);
        
        auto attack = r.removeFromTop(divisor).reduced(1);
        auto decay = r.removeFromTop(divisor).reduced(1);
        auto sustain = r.removeFromTop(divisor).reduced(1);
        auto release = r.reduced(1);
        
        ADSR1Attack.setBounds(attack);
        ADSR1Decay.setBounds(decay);
        ADSR1Sustain.setBounds(sustain);
        ADSR1Release.setBounds(release);
        
        attackDial.setBounds(attack);
        decayDial.setBounds(decay);
        sustainDial.setBounds(sustain);
        releaseDial.setBounds(release);
        
    }
    
    Slider ADSR1Attack, ADSR1Decay, ADSR1Sustain, ADSR1Release;
    Label attackDial, decayDial, sustainDial, releaseDial;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
};


#endif  // ENVELOPECOMPONENT_H_INCLUDED

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

#include "ADSRComponent.h"

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
        ADSR1Attack.setRange(0.0, 10000.0);
        
        addAndMakeVisible (attackDial);
        attackDial.setText ("Attack", dontSendNotification);
        attackDial.attachToComponent (&ADSR1Attack, false);
        attackDial.setJustificationType(Justification::centredBottom);

        addAndMakeVisible(ADSR1Decay);
        ADSR1Decay.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Decay.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Decay.setRange(0.0, 10000.0);

        addAndMakeVisible (decayDial);
        decayDial.setText ("Decay", dontSendNotification);
        decayDial.attachToComponent (&ADSR1Decay, false);
        
        addAndMakeVisible(ADSR1Sustain);
        ADSR1Sustain.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Sustain.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Sustain.setRange(0.0, 1.0);
        
        addAndMakeVisible (sustainDial);
        sustainDial.setText ("Sustain", dontSendNotification);
        sustainDial.attachToComponent (&ADSR1Sustain, false);
        
        addAndMakeVisible(ADSR1Release);
        ADSR1Release.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Release.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Release.setRange(0.0, 10000.0);
        
        addAndMakeVisible (releaseDial);
        releaseDial.setText ("Release", dontSendNotification);
        releaseDial.attachToComponent (&ADSR1Release, false);
        
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
        
        ADSR1Attack.setBounds(r.removeFromTop(divisor).reduced(10));
        ADSR1Decay.setBounds(r.removeFromTop(divisor).reduced(10));
        ADSR1Sustain.setBounds(r.removeFromTop(divisor).reduced(10));
        ADSR1Release.setBounds(r.reduced(10));
    }
    
    Slider ADSR1Attack, ADSR1Decay, ADSR1Sustain, ADSR1Release;
    Label attackDial, decayDial, sustainDial, releaseDial;

//    TextButton trainButton, addButton;
//    ADSRComponent ADSR;
//    ADSRComponent ADSR;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
};


#endif  // ENVELOPECOMPONENT_H_INCLUDED

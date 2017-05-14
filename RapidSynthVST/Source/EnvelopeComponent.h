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
        //Attack Dial
        addAndMakeVisible(ADSR1Attack); //Add and make visible
        ADSR1Attack.setTextBoxStyle(Slider::NoTextBox, true, 0, 0); //Hide the text box
        ADSR1Attack.setSliderStyle(Slider::RotaryVerticalDrag); //Set the slider style to rotary with vertical drag
        ADSR1Attack.setRange(0.0, 1); //Set the range to 0 - 1
        ADSR1Attack.setValue(0.1); //Set initial value to 0.1
        
        //Attack Label
        addAndMakeVisible (attackDial); //Add and make visible
        attackDial.setText ("Attack", dontSendNotification); //Set the label text
        attackDial.setJustificationType(Justification::centredBottom); //Set the justification to bottom centre
        attackDial.setInterceptsMouseClicks(false, false); //Prevent the label from recieving mouse events, v. important

        //Decay Dial
        addAndMakeVisible(ADSR1Decay);
        ADSR1Decay.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Decay.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Decay.setRange(0.0, 1);
        ADSR1Decay.setValue(0.1);
        
        //Decay Label
        addAndMakeVisible (decayDial);
        decayDial.setText ("Decay", dontSendNotification);
        decayDial.setJustificationType(Justification::centredBottom);
        decayDial.setInterceptsMouseClicks(false, false);
        
        //Sustain Dial
        addAndMakeVisible(ADSR1Sustain);
        ADSR1Sustain.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Sustain.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Sustain.setRange(0.0, 1.0);
        ADSR1Sustain.setValue(1);
        
        //Sustain Label
        addAndMakeVisible (sustainDial);
        sustainDial.setText ("Sustain", dontSendNotification);
        sustainDial.setJustificationType(Justification::centredBottom);
        sustainDial.setInterceptsMouseClicks(false, false);
        
        //Release Dial
        addAndMakeVisible(ADSR1Release);
        ADSR1Release.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        ADSR1Release.setSliderStyle(Slider::RotaryVerticalDrag);
        ADSR1Release.setRange(0.0, 1);
        ADSR1Release.setValue(0.1);
        
        //Release Label
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
        //This divides the full area and sets the bounds for each of the components
        auto r = getLocalBounds();
        int divisor = (r.getHeight()/4); //Size of each section
        
        //Each component takes the top portion of r, until all that is left is the bottom quarter
        auto attack = r.removeFromTop(divisor).reduced(1);
        auto decay = r.removeFromTop(divisor).reduced(1);
        auto sustain = r.removeFromTop(divisor).reduced(1);
        auto release = r.reduced(1);
        
        ADSR1Attack.setBounds(attack);
        ADSR1Decay.setBounds(decay);
        ADSR1Sustain.setBounds(sustain);
        ADSR1Release.setBounds(release);
        
        //I found that using the same positions for the labels was the easiest way to get them in the position I wanted
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

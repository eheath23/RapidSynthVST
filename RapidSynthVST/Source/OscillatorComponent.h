/*
  ==============================================================================

    OscillatorComponent.h
    Created: 6 Mar 2017 5:18:11pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef OSCILLATORCOMPONENT_H_INCLUDED
#define OSCILLATORCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class OscillatorComponent    : public Component
{
public:
    OscillatorComponent()
    {
        dial1.setSliderStyle (Slider::RotaryVerticalDrag);
        dial1.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial1.setRange (0, 1);
        dial1.setValue(0.5);
        addAndMakeVisible(dial1);
        
        addAndMakeVisible (dial1Label);
        dial1Label.setText ("Filter Cutoff", dontSendNotification);
        dial1Label.attachToComponent (&dial1, false);
        
        dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        dial2.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial2.setRange (0, 1);
        dial2.setValue(0.5);
        addAndMakeVisible(dial2);
        
        addAndMakeVisible (dial2Label);
        dial2Label.setText ("Detune", dontSendNotification);
        dial2Label.attachToComponent (&dial2, false);
        
        dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        dial3.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial3.setRange (0, 1.0);
        dial3.setValue(1);
        addAndMakeVisible(dial3);
        
        addAndMakeVisible (dial3Label);
        dial3Label.setText ("Gain", dontSendNotification);
        dial3Label.attachToComponent (&dial3, false);
        
        addAndMakeVisible(sineButton);
        sineButton.setButtonText ("Si");
        
        addAndMakeVisible(sawButton);
        sawButton.setButtonText ("Sa");
        
        addAndMakeVisible(squareButton);
        squareButton.setButtonText ("Sq");
        
    }

    ~OscillatorComponent()
    {
    }

    void paint (Graphics& g) override
    {

//        g.fillAll (Colours::darkred);   // clear the background

//        g.setColour (Colours::white);
//        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    }

    void resized() override
    {
        
        int border = 7;
        auto r = getLocalBounds();
        auto titleArea = r.removeFromTop(50);
        int divisor = r.getHeight() / 3;
        int titleDivisor = titleArea.getWidth() / 3;
        auto dialArea = r;
        
        dial1.setBounds(dialArea.removeFromTop(divisor).reduced(border));
        dial3.setBounds(dialArea.removeFromBottom(divisor).reduced(border));
        dial2.setBounds(dialArea.reduced(border));
        
        sineButton.setBounds(titleArea.removeFromLeft(titleDivisor).reduced(border));
        squareButton.setBounds(titleArea.removeFromRight(titleDivisor).reduced(border));
        sawButton.setBounds(titleArea.reduced(border));
        
    }

    Slider dial1;
    Slider dial2;
    Slider dial3;
    
    Label dial1Label;
    Label dial2Label;
    Label dial3Label;
    
    TextButton sineButton;
    TextButton sawButton;
    TextButton squareButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};


#endif  // OSCILLATORCOMPONENT_H_INCLUDED

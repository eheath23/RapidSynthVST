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
        dial1.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        dial1.setRange (50, 5000.0);
        dial1.setValue(440);
        addAndMakeVisible (dial1);
        
        dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        dial2.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        dial2.setRange (-12.0, 12.0, 1);
        dial2.setValue(0);
        addAndMakeVisible (dial2);
        
        dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        dial3.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        dial3.setRange (0, 1.0);
        dial3.setValue(0);
        addAndMakeVisible (dial3);
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
        
        int border = 10;
        auto r = getLocalBounds();
        auto titleArea = r.removeFromTop(50);
        int divisor = r.getHeight() / 3;
        auto dialArea = r;
        
        dial1.setBounds(dialArea.removeFromTop(divisor).reduced(border));
        dial3.setBounds(dialArea.removeFromBottom(divisor).reduced(border));
        dial2.setBounds(dialArea.reduced(border));
        
    }

    Slider dial1;
    Slider dial2;
    Slider dial3;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};


#endif  // OSCILLATORCOMPONENT_H_INCLUDED

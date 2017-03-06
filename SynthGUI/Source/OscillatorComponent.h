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
        dial1.setSliderStyle (Slider::Rotary);
        dial1.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible (dial1);
        
        dial2.setSliderStyle (Slider::Rotary);
        dial2.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible (dial2);
    }

    ~OscillatorComponent()
    {
    }

    void paint (Graphics& g) override
    {

        g.fillAll (Colours::white);   // clear the background

        g.setColour (Colours::black);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    }

    void resized() override
    {
        int border = 10;
        auto r = getLocalBounds();
        auto titleArea = r.removeFromTop(50);
        auto dialArea = r;
        
        dial1.setBounds(dialArea.removeFromTop (dialArea.getHeight() / 2).reduced (border));
        dial2.setBounds(dialArea.reduced(border));

    }

private:
    Slider dial1;
    Slider dial2;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};


#endif  // OSCILLATORCOMPONENT_H_INCLUDED

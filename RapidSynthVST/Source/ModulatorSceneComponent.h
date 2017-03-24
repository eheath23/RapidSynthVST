/*
  ==============================================================================

    ModulatorSceneComponent.h
    Created: 7 Mar 2017 1:21:59pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef MODULATORSCENECOMPONENT_H_INCLUDED
#define MODULATORSCENECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "FilterComponent.h"
#include "EnvelopeComponent.h"
#include "OscillatorComponent.h"

//==============================================================================
/*
*/
class ModulatorSceneComponent    : public Component
{
public:
    ModulatorSceneComponent()
    {

        addAndMakeVisible(lfo);
        addAndMakeVisible(envelope);
        addAndMakeVisible(filter);
        
        lfo.dial1.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial1.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial1.setRange (0, 20.0);
        lfo.dial1.setValue(1);
        
        lfo.dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial2.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial2.setRange (0, 1.0);
        lfo.dial2.setValue(0);
        
        lfo.dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial3.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial3.setRange (0, 1.0);
        lfo.dial3.setValue(0);
    }
    
    ~ModulatorSceneComponent()
    {
    }

    void paint (Graphics& g) override
    {
        g.setColour (Colours::white);
        g.drawRect (getLocalBounds(), 2);
        g.drawLine(lfo.getWidth(), lfo.getHeight(), lfo.getWidth(), 0, 2);
        g.drawLine(envelope.getWidth()*2, envelope.getHeight(), envelope.getWidth()*2, 0, 2);
    }

    void resized() override
    {
        int divisor = getWidth()/3;
        auto r = getLocalBounds();
        
        lfo.setBounds(r.removeFromLeft(divisor));
        envelope.setBounds(r.removeFromRight(divisor));
        filter.setBounds(r);
        
    }
    
        OscillatorComponent lfo;
        FilterComponent filter;
        EnvelopeComponent envelope;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulatorSceneComponent)
};


#endif  // MODULATORSCENECOMPONENT_H_INCLUDED

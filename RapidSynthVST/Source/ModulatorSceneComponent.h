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

#include "EnvelopeComponent.h"
#include "OscillatorComponent.h"

//I started to implement tabs in this component so that I could add more modulators, but haven't yet got round to it

//==============================================================================
class ModulatorSceneComponent    : public TabbedComponent

{
public:
    ModulatorSceneComponent()
    : TabbedComponent (TabbedButtonBar::TabsAtTop)
    {
        addAndMakeVisible(lfo);
        addAndMakeVisible(envelope);
        addAndMakeVisible(filter);
        
        //LFO and Filter both use Oscillator Component, but they override the values of the dials and labels
        
        //LFO Dial 1
        lfo.dial1.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial1.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial1.setRange (0, 1);
        lfo.dial1.setValue(0);
        lfo.dial1Label.setText ("LFO Rate", dontSendNotification);
        
        //LFO Dial 2
        lfo.dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial2.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial2.setRange (0, 1.0);
        lfo.dial2.setValue(0);
        lfo.dial2Label.setText ("LFO Amount", dontSendNotification);
        
        //LFO Dial 3
        lfo.dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        lfo.dial3.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        lfo.dial3.setRange (0, 1.0);
        lfo.dial3.setValue(1.0);
        lfo.dial3Label.setText ("Master Gain", dontSendNotification);
        
        //Filter Dial 2
        filter.dial2.setRange(0, 1.0);
        filter.dial2.setValue(0.1);
        
        //Filter Dial 1 & 2 Labels
        filter.dial1Label.setText ("Filter Cutoff", dontSendNotification);
        filter.dial2Label.setText ("Filter Resonance", dontSendNotification);
        
        //Remove Unused Dials 
        filter.removeChildComponent(&filter.dial3);
        filter.removeChildComponent(&filter.dial3Label);
        filter.removeChildComponent(filter.radioButtons[0]);
        filter.removeChildComponent(filter.radioButtons[1]);
        filter.removeChildComponent(filter.radioButtons[2]);
        
    }
    
    ~ModulatorSceneComponent()
    {
    }

    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        int divisor = getWidth()/3;
        auto r = getLocalBounds();
        
        lfo.setBounds(r.removeFromLeft(divisor));
        envelope.setBounds(r.removeFromRight(divisor));
        filter.setBounds(r);
        
    }
    
        OscillatorComponent lfo,filter;
        EnvelopeComponent envelope;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulatorSceneComponent)
};


#endif  // MODULATORSCENECOMPONENT_H_INCLUDED

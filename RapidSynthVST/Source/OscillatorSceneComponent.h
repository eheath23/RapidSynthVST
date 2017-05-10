/*
  ==============================================================================

    OscillatorSceneComponent.h
    Created: 7 Mar 2017 1:20:31pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef OSCILLATORSCENECOMPONENT_H_INCLUDED
#define OSCILLATORSCENECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "OscillatorComponent.h"


//==============================================================================
/*
*/
class OscillatorSceneComponent    : public Component
{
public:
    OscillatorSceneComponent()
    {
        addAndMakeVisible(osc1);
        addAndMakeVisible(osc2);
        addAndMakeVisible(osc3);

    }

    ~OscillatorSceneComponent()
    {
    }

    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        int divisor = getWidth()/3;
        auto r = getLocalBounds();
        
        osc1.setBounds(r.removeFromLeft(divisor));
        osc3.setBounds(r.removeFromRight(divisor));
        osc2.setBounds(r);
        
    }
    
    OscillatorComponent osc1, osc2, osc3;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorSceneComponent)
};


#endif  // OSCILLATORSCENECOMPONENT_H_INCLUDED

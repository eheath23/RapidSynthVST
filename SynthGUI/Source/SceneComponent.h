/*
  ==============================================================================

    SceneComponent.h
    Created: 6 Mar 2017 5:17:50pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef SCENECOMPONENT_H_INCLUDED
#define SCENECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "OscillatorComponent.h"
#include "FilterComponent.h"
#include "EnvelopeComponent.h"
#include "XYComponent.h"

//==============================================================================
/*
*/
class SceneComponent    : public Component
{
public:
    SceneComponent()
    {

        addAndMakeVisible(osc1);
        addAndMakeVisible(osc2);
        addAndMakeVisible(osc3);
        addAndMakeVisible(lfo);
        addAndMakeVisible(XY);
        addAndMakeVisible(envelope);
        addAndMakeVisible(filter);

    }

    ~SceneComponent()
    {
    }

    void paint (Graphics& g) override
    {
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        g.fillAll (Colours::black);   // clear the background

        g.setColour (Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
        
    }

    void resized() override
    {
        auto r = getLocalBounds();
        auto bottomSection = r.removeFromBottom(250);
        auto oscSection = bottomSection.removeFromLeft(400);
        
        XY.setBounds(r.reduced(5));
        
        osc1.setBounds(oscSection.removeFromLeft(133));
        osc3.setBounds(oscSection.removeFromRight(133));
        osc2.setBounds(oscSection);
        
        lfo.setBounds(bottomSection.removeFromLeft(133));
        envelope.setBounds(bottomSection.removeFromRight(133));
        filter.setBounds(bottomSection);
        

    }

private:
    OscillatorComponent osc1, osc2, osc3, lfo;
    FilterComponent filter;
    EnvelopeComponent envelope;
    XYComponent XY;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};


#endif  // SCENECOMPONENT_H_INCLUDED

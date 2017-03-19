/*
  ==============================================================================

    ADSRComponent.h
    Created: 13 Mar 2017 4:08:45pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef ADSRCOMPONENT_H_INCLUDED
#define ADSRCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ADSRComponent    : public Component
{
public:
    ADSRComponent()
    {
        

    }

    ~ADSRComponent()
    {
    }

    void paint (Graphics& g) override
    {

        g.fillAll (Colours::white);   // clear the background

        g.setColour (Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

        g.setColour (Colours::lightblue);
        g.setFont (14.0f);
        g.drawText ("ADSRComponent", getLocalBounds(),
                    Justification::centred, true);   // draw some placeholder text
    }

    void resized() override
    {

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};


#endif  // ADSRCOMPONENT_H_INCLUDED

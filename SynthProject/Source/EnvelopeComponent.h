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
        addAndMakeVisible(ADSR);

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
        ADSR.setBounds(r.removeFromBottom(200));

    }

    ADSRComponent ADSR;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
};


#endif  // ENVELOPECOMPONENT_H_INCLUDED

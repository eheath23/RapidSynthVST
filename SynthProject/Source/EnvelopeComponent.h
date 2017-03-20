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
//        addAndMakeVisible(ADSR);

        addAndMakeVisible (MLSlider);
        MLSlider.setSliderStyle(Slider::LinearVertical);
        MLSlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
        MLSlider.setRange(0, 5000);
        MLSlider.setValue(0);
        
        addAndMakeVisible(trainButton);
        trainButton.setButtonText ("Train");
        
        addAndMakeVisible(addButton);
        addButton.setButtonText("Add Data");
        
    }

    ~EnvelopeComponent()
    {
    }

    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
//        auto r = getLocalBounds();
//        ADSR.setBounds(r.removeFromBottom(200));

        auto r = getLocalBounds();
        auto sliderArea = r.removeFromBottom(200);
        
        MLSlider.setBounds(sliderArea.reduced(10));
        trainButton.setBounds(r.removeFromTop(r.getHeight()/2).reduced(1));
        addButton.setBounds(r.reduced(1));
        
    }

    Slider MLSlider;
    TextButton trainButton, addButton;
//    ADSRComponent ADSR;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
};


#endif  // ENVELOPECOMPONENT_H_INCLUDED

/*
  ==============================================================================

    FilterComponent.h
    Created: 6 Mar 2017 5:18:36pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef FILTERCOMPONENT_H_INCLUDED
#define FILTERCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FilterComponent    : public Component
{
public:
    FilterComponent()
    {
        addAndMakeVisible (cutoffFrequencySlider);
        cutoffFrequencySlider.setSliderStyle(Slider::RotaryVerticalDrag);
        cutoffFrequencySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
        cutoffFrequencySlider.setRange(0, 5000);
        cutoffFrequencySlider.setValue(5000);
    }

    ~FilterComponent()
    {
    }

    void paint (Graphics& g) override
    {

//        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    }

    void resized() override
    {
        auto r = getLocalBounds();
        auto sliderArea = r.removeFromBottom(200);
        
        cutoffFrequencySlider.setBounds(sliderArea.reduced(10));

    }

    Slider cutoffFrequencySlider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};


#endif  // FILTERCOMPONENT_H_INCLUDED

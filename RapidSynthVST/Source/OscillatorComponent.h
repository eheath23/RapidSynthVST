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
        dial1.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial1.setRange (0, 1);
        dial1.setValue(0.5);
        addAndMakeVisible(dial1);
        
        addAndMakeVisible (dial1Label);
        dial1Label.setText ("Modulator Frequency", dontSendNotification);
        dial1Label.setInterceptsMouseClicks(false, false);
        dial1Label.setJustificationType(Justification::centredBottom);
        
        dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        dial2.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial2.setRange (0, 1);
        dial2.setValue(0.5);
        addAndMakeVisible(dial2);
        
        addAndMakeVisible (dial2Label);
        dial2Label.setText ("Detune", dontSendNotification);
        dial2Label.setInterceptsMouseClicks(false, false);
        dial2Label.setJustificationType(Justification::centredBottom);
        
        dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        dial3.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial3.setRange (0, 1.0);
        dial3.setValue(1);
        addAndMakeVisible(dial3);
        
        addAndMakeVisible (dial3Label);
        dial3Label.setText ("Gain", dontSendNotification);
        dial3Label.setInterceptsMouseClicks(false, false);
        dial3Label.setJustificationType(Justification::centredBottom);
        
        
        for (int i = 0; i < 3; ++i)
        {
            TextButton* b = radioButtons.add (new TextButton());
            addAndMakeVisible (b);
            b->setRadioGroupId (42);
            b->setClickingTogglesState (true);
            if(i == 0)
            {
                b->setButtonText ("Sine");
            } else if (i == 1)
            {
                b->setButtonText ("Saw");
            } else if (i == 2)
            {
                b->setButtonText ("Square");
            }
            
            switch (i)
            {
                case 0:     b->setConnectedEdges (Button::ConnectedOnRight);                            break;
                case 1:     b->setConnectedEdges (Button::ConnectedOnRight + Button::ConnectedOnLeft);  break;
                case 2:     b->setConnectedEdges (Button::ConnectedOnLeft);                             break;
                default:    break;
            }
            
        }
        
        radioButtons.getUnchecked (2)->setToggleState (true, dontSendNotification);
        
    }

    ~OscillatorComponent()
    {
    }

    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        
        int border1 = 1;
        auto r = getLocalBounds();
        auto titleArea = r.removeFromTop(50).reduced(10);
        int divisor = r.getHeight() / 3;
        int titleDivisor = titleArea.getWidth() / 3;
        auto dialArea = r;
        
        auto dial1Area = dialArea.removeFromTop(divisor).reduced(border1);
        auto dial3Area = dialArea.removeFromBottom(divisor).reduced(border1);
        auto dial2Area = dialArea.reduced(border1);
        
        
        dial1.setBounds(dial1Area);
        dial3.setBounds(dial3Area);
        dial2.setBounds(dial2Area);
        
        dial1Label.setBounds(dial1Area);
        dial3Label.setBounds(dial3Area);
        dial2Label.setBounds(dial2Area);
        
        
        for (int i = 0; i < radioButtons.size(); ++i)
        {
            radioButtons.getUnchecked (i)->setBounds (titleArea.removeFromLeft(titleDivisor));
        }
        
    }

    Slider dial1;
    Slider dial2;
    Slider dial3;
    
    Label dial1Label;
    Label dial2Label;
    Label dial3Label;
    
    TextButton sineButton;
    TextButton sawButton;
    TextButton squareButton;
    
    OwnedArray<TextButton> radioButtons;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};


#endif  // OSCILLATORCOMPONENT_H_INCLUDED

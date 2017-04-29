/*
  ==============================================================================

    XYComponent.h
    Created: 6 Mar 2017 5:18:49pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef XYCOMPONENT_H_INCLUDED
#define XYCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class XYComponent    : public Component
{
public:
    XYComponent()
    {
        button1.setButtonText ("1");
        addAndMakeVisible (button1);
        
        button2.setButtonText ("2");
        addAndMakeVisible (button2);
        
        button3.setButtonText ("3");
        addAndMakeVisible (button3);
        
        button4.setButtonText ("4");
        addAndMakeVisible (button4);
        
        button5.setButtonText ("Train");
        addAndMakeVisible (button5);
        
        button6.setButtonText ("Run");
        addAndMakeVisible (button6);
        
        addAndMakeVisible(targetShape);
        targetShape.setBounds(200, 200, 25, 25);
        
    }

    ~XYComponent()
    {
    }

    void paint (Graphics& g) override
    {

        g.fillAll (Colours::slategrey);   // clear the background

        g.setColour (Colours::white);
        g.drawRect (getLocalBounds(), 2);
        
    }

    void resized() override
    {
        auto r = getLocalBounds();

        button1.setBounds(10, 10, 25, 25);
        button2.setBounds(110, 60, 25, 25);
        button3.setBounds(210, 110, 25, 25);
        button4.setBounds(310, 160, 25, 25);
        button5.setBounds(410, 210, 25, 25);
        button6.setBounds(510, 260, 25, 25);
        
    }
    
    class TargetShape : public Component
    {
    public:
        ComponentDragger myDragger;
        
        void paint(Graphics& g) override
        {
            g.fillAll(Colours::red);
        }
        
        void mouseDown(const MouseEvent& _event) override
        {
            myDragger.startDraggingComponent (this, _event);
        }
        
        void mouseDrag (const MouseEvent& _event) override
        {
            myDragger.dragComponent (this, _event, nullptr);
        }
    };
    
    TargetShape targetShape;
    
    TextButton button1, button2, button3, button4, button5, button6;
        
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYComponent)
};


#endif  // XYCOMPONENT_H_INCLUDED

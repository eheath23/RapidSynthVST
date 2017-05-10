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
        targetShape.setBounds(300, 200, 25, 25);
        
    }

    ~XYComponent()
    {
    }

    void paint (Graphics& g) override
    {

        g.fillAll (Colours::lightblue);

        g.setColour (Colours::darkblue);
        g.drawRect (getLocalBounds(), 2);
        
    }

    void resized() override
    {
        auto r = getLocalBounds();

        button1.setBounds(10, 10, 25, 25);
        button2.setBounds(750, 10, 25, 25);
        button3.setBounds(10, 300, 25, 25);
        button4.setBounds(750, 300, 25, 25);
        button5.setBounds(350, 10, 40, 25);
        button6.setBounds(350, 70, 40, 25);
    
    }
    
    class TargetShape : public Component
    {
    public:
        ComponentDragger myDragger;
        
        void paint(Graphics& g) override
        {
            g.fillAll(Colours::darkslateblue);
            g.drawEllipse(this->getX(), this->getY(), 25, 25, 1);
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

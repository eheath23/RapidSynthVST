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
        //Button 1 - Training Example 1
        button1.setButtonText ("1");
        addAndMakeVisible (button1);
        
        //Button 2 - Training Example 2
        button2.setButtonText ("2");
        addAndMakeVisible (button2);
        
        //Button 3 - Training Example 3
        button3.setButtonText ("3");
        addAndMakeVisible (button3);
        
        //Button 4 - Training Example 4
        button4.setButtonText ("4");
        addAndMakeVisible (button4);
        
        //Button 5 - Train
        button5.setButtonText ("Train");
        addAndMakeVisible (button5);
        
        //Button 6 - Run
        button6.setButtonText ("Run");
        addAndMakeVisible (button6);
        
        //Target Shape - IML Square
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
    
    //Target Shape class to make the IML Square
    class TargetShape : public Component
    {
    public:
        ComponentDragger myDragger; //Create Component Dragger to handle
        
        void paint(Graphics& g) override
        {
            g.fillAll(Colours::darkslateblue); //Fill colour
        }
        
        void mouseDown(const MouseEvent& _event) override
        {
            myDragger.startDraggingComponent (this, _event); //When the mouse is down on the shape, start dragging
        }
        
        void mouseDrag (const MouseEvent& _event) override
        {
            myDragger.dragComponent (this, _event, nullptr); //When mouse is dragger, drag this shape
        }
    };
    
    TargetShape targetShape;
    
    TextButton button1, button2, button3, button4, button5, button6;    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYComponent)
};


#endif  // XYCOMPONENT_H_INCLUDED

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
        
        button5.setButtonText ("5");
        addAndMakeVisible (button5);

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
        int divisor = getWidth()/5;
        auto r = getLocalBounds();

        button1.setBounds(button1PosX, button1PosY, 25, 25);
        button2.setBounds(110, 10, 25, 25);
        button3.setBounds(210, 10, 25, 25);
        button4.setBounds(310, 10, 25, 25);
        button5.setBounds(410, 10, 25, 25);
    }
    
    void myUpdate(int framesPerSecond){
        
        
    }
        
//    void mouseDrag(const MouseEvent& event) override
//    {
//        std::cout << "true" << std::endl;
//        
//        if(button1.isDown()){
//            button1PosX = event.getMouseDownPosition().getX();
//            button1PosY = event.getMouseDownPosition().getY();
//            button1.setBounds(button1PosX, button1PosY, 25, 25);
//
//           
//            std::cout << "yes" << std::endl;
//        }
//    }
    

    TextButton button1, button2, button3, button4, button5;
    int button1PosX = 10, button1PosY = 10;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYComponent)
};


#endif  // XYCOMPONENT_H_INCLUDED

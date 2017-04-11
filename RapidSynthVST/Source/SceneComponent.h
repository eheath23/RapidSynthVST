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

#include "XYComponent.h"
#include "OscillatorSceneComponent.h"
#include "ModulatorSceneComponent.h"

//==============================================================================
/*
*/
class SceneComponent    : public Component
{
public:
    SceneComponent()
    {

        addAndMakeVisible(XY);
        addAndMakeVisible(oscScene);
        addAndMakeVisible(modScene);
        
    }

    ~SceneComponent()
    {
    }
    

    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);   // clear the background
        
        g.setColour (Colours::white);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    }

    void resized() override
    {
        auto r = getLocalBounds();
        auto bottomSection = r.removeFromBottom(250);
        auto oscSection = bottomSection.removeFromLeft(400);
        XY.setBounds(r.reduced(5));
        oscScene.setBounds(oscSection);
        modScene.setBounds(bottomSection);
                
    }

    OscillatorSceneComponent oscScene;
    ModulatorSceneComponent modScene;
    XYComponent XY;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SceneComponent)
};


#endif  // SCENECOMPONENT_H_INCLUDED

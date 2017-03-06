#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "SceneComponent.h"

class MainContentComponent   : public Component
{
public:
    MainContentComponent()
    {
        addAndMakeVisible (scene);
        setSize (800, 600);
    }
    
    ~MainContentComponent()
    {
    }
    
    void paint (Graphics&) override
    {
    }
    
    void resized() override
    {
        scene.setBounds (0, 0, getWidth(), getHeight());
    }
    
private:
    SceneComponent scene;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED

/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "MaxiLib/maximilian.h"
#include "RapidLib/regression.h"
#include <random>
#include <array>
#include "../JuceLibraryCode/JuceHeader.h"

#include "SceneComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                               public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible(scene);
        scene.oscScene.osc1.dial1.addListener (this);
        scene.oscScene.osc1.dial2.addListener (this);
        
        scene.oscScene.osc2.dial1.addListener (this);
        scene.oscScene.osc2.dial2.addListener (this);
        
        scene.oscScene.osc3.dial1.addListener (this);
        scene.oscScene.osc3.dial2.addListener (this);
        
        scene.modScene.lfo.dial1.addListener (this);
        scene.modScene.lfo.dial2.addListener (this);
        
        scene.modScene.filter.cutoffFrequencySlider.addListener(this);

        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        maxiSettings::setup(std::round(sampleRate), 2, samplesPerBlockExpected);
        
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Get the buffers for both output channels
        float* const bufferL = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        float* const bufferR = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
        
        ADSR.setAttack(500);
        ADSR.setDecay(3);
        ADSR.setSustain(1);
        ADSR.setRelease(200);
        
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            ADSRout = ADSR.adsr(1.0, ADSR.trigger);
            
            osc1out = osc1.saw(freq);
            osc2out = osc2.square(freq*1.5);
            
            VCFout = VCF.lores(osc1out + osc2out * 0.5, cutoff, 0);
            
            cSample = VCFout * gain;
            
            mixer.stereo(cSample, outputs, 0.5);
            
            bufferL[sample] = float(outputs[0]);
            bufferR[sample] = float(outputs[1]);
        }
    }
    
    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
    }

    //==============================================================================
    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
        scene.setBounds (0, 0, getWidth(), getHeight());
        
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        if (slider == &scene.oscScene.osc1.dial1){
            freq = scene.oscScene.osc1.dial1.getValue();
        }
        
        if (slider == &scene.oscScene.osc1.dial2){
            gain = scene.oscScene.osc2.dial2.getValue();
        }
        
        if (slider == &scene.modScene.filter.cutoffFrequencySlider){
            cutoff = scene.modScene.filter.cutoffFrequencySlider.getValue();
        }
    }
    
    
    //==============================================================================
    //GUI
    SceneComponent scene;
    
    //AUDIO
    double cSample, freq, ADSRout, osc1out, osc2out, VCFout, gain, cutoff;
    double                       outputs[2];
    
    // Maximilian objects
    maxiOsc                      osc1;
    maxiOsc                      osc2;
    maxiFilter                   VCF;
    maxiMix                      mixer;
    maxiEnv                      ADSR;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED

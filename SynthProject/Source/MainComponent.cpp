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
                               public Slider::Listener,
                               public Button::Listener
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
        
        scene.XY.button1.addListener(this);

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
            osc2out = osc2.saw(freq);
            osc3out = osc3.saw(freq);
            
            osc1FilterOut = osc1Filter.lores(osc1out, osc1FilterCutoff, 0);
            osc2FilterOut = osc2Filter.lores(osc2out, osc2FilterCutoff, 0);
            osc3FilterOut = osc3Filter.lores(osc3out, osc3FilterCutoff, 0);
            
            VCFout = VCF.lores(osc1FilterOut + osc2FilterOut + osc3FilterOut * 0.3, VCOcutoff, 0);
            
            cSample = VCFout * masterGain;
            
            mixer.stereo(cSample, outputs, 0.5);
            
            bufferL[sample] = float(outputs[0]);
            bufferR[sample] = float(outputs[1]);
        }
        
    }
    
    void releaseResources() override
    {
        
    }
    
    //==============================================================================
    void paint (Graphics& g) override
    {

    }

    void resized() override
    {
        
        scene.setBounds (0, 0, getWidth(), getHeight());
        
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        //OSC 1 Dials
        if (slider == &scene.oscScene.osc1.dial1){
            osc1FilterCutoff = scene.oscScene.osc1.dial1.getValue();
            std::cout << osc1FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc1.dial2){
            osc1Gain = scene.oscScene.osc1.dial2.getValue();
            std::cout << osc1Gain << std::endl;
        }
        
        //OSC 2 Dials
        if (slider == &scene.oscScene.osc2.dial1){
            osc2FilterCutoff = scene.oscScene.osc2.dial1.getValue();
            std::cout << osc2FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc2.dial2){
            osc2Gain = scene.oscScene.osc2.dial2.getValue();
            std::cout << osc2Gain << std::endl;
        }
        
        //OSC 3 Dials
        if (slider == &scene.oscScene.osc3.dial1){
            osc3FilterCutoff = scene.oscScene.osc3.dial1.getValue();
            std::cout << osc3FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc3.dial2){
            osc3Gain = scene.oscScene.osc3.dial2.getValue();
            std::cout << osc3Gain << std::endl;
        }
        
        //VCO Slider
        if (slider == &scene.modScene.filter.cutoffFrequencySlider){
            VCOcutoff = scene.modScene.filter.cutoffFrequencySlider.getValue();
            std::cout << VCOcutoff << std::endl;
        }
    }
    
    void buttonClicked (Button* button) override
    {
        if(button == &scene.XY.button1){
            ADSR.trigger;
        }
    }
    
    
//==============================================================================
//GUI
    SceneComponent scene;
    
    //AUDIO
    double                       cSample;
    double                       freq = 440;
    double                       masterGain = 0.7;
    double                       osc1Gain, osc2Gain, osc3Gain;
    double                       ADSRout;
    double                       osc1out, osc2out, osc3out;
    double                       osc1FilterOut, osc2FilterOut, osc3FilterOut, VCFout;
    double                       osc1FilterCutoff, osc2FilterCutoff, osc3FilterCutoff, VCOcutoff;
    double                       outputs[2];
    
    // Maximilian objects
    maxiOsc                      osc1;
    maxiOsc                      osc2;
    maxiOsc                      osc3;
    maxiFilter                   osc1Filter;
    maxiFilter                   osc2Filter;
    maxiFilter                   osc3Filter;
    maxiFilter                   VCF;
    maxiMix                      mixer;
    maxiEnv                      ADSR;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED

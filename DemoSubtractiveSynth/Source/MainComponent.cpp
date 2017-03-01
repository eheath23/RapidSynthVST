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

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent,
                               public Button::Listener,
                               public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent()
    {
        addAndMakeVisible (playSound);
        playSound.setButtonText ("Play Sound");
        playSound.addListener (this);
        
        addAndMakeVisible (frequencySlider);
        frequencySlider.setRange (50, 1000.0);
        frequencySlider.setTextValueSuffix (" Hz");
        frequencySlider.addListener (this);
        
        addAndMakeVisible (frequencyLabel);
        frequencyLabel.setText ("Frequency", dontSendNotification);
        frequencyLabel.attachToComponent (&frequencySlider, true);
        
        addAndMakeVisible (volumeSlider);
        volumeSlider.setRange (0, 1.0);
        volumeSlider.addListener (this);
        
        addAndMakeVisible (volumeLabel);
        volumeLabel.setText ("Volume", dontSendNotification);
        volumeLabel.attachToComponent (&volumeSlider, true);
        
        frequencySlider.setValue (500.0);
        volumeSlider.setValue (0.0);
        
        setSize (600, 110);
        
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
            
            VCFout = VCF.lores(osc1out + osc2out * 0.5, 200, 0);
            
            cSample = VCFout * gain;
            
            mixer.stereo(cSample, outputs, 0.5);
            
            bufferL[sample] = float(outputs[0]);
            bufferR[sample] = float(outputs[1]);
        }
        
//        bufferToFill.clearActiveBufferRegion();
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
        playSound.setBounds (10, 10, getWidth() - 20, 40);
        frequencySlider.setBounds (10, 50, getWidth() - 20, 40);
        volumeSlider.setBounds (10, 80, getWidth() - 20, 40);
    }
    
    //==============================================================================
    void buttonClicked (Button* button) override
    {
        if (button == &playSound)
        {
            ADSR.trigger = 1;
        }else{
            ADSR.trigger = 0;
        }
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        if (slider == &frequencySlider){
            freq = frequencySlider.getValue();
        }
        
        if (slider == &volumeSlider){
            gain = volumeSlider.getValue();
        }
    }
    
    
private:
    //==============================================================================
    /*** AUDIO ***/
    
    double cSample, freq, ADSRout, osc1out, osc2out, VCFout, gain;
    double                       outputs[2];
    
    // Maximilian objects
    maxiOsc                      osc1;
    maxiOsc                      osc2;
    maxiFilter                   VCF;
    maxiMix                      mixer;
    maxiEnv ADSR;
    
    TextButton playSound;
    Slider frequencySlider;
    Label frequencyLabel;
    Slider volumeSlider;
    Label volumeLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED

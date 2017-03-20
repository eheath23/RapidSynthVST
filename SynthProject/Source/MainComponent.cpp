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
        scene.oscScene.osc1.dial3.addListener (this);
        
        scene.oscScene.osc2.dial1.addListener (this);
        scene.oscScene.osc2.dial2.addListener (this);
        scene.oscScene.osc2.dial3.addListener (this);
        
        scene.oscScene.osc3.dial1.addListener (this);
        scene.oscScene.osc3.dial2.addListener (this);
        scene.oscScene.osc3.dial3.addListener (this);
    
        scene.modScene.lfo.dial1.addListener (this);
        scene.modScene.lfo.dial2.addListener (this);
        scene.modScene.lfo.dial3.addListener (this);
    
        scene.modScene.filter.cutoffFrequencySlider.addListener(this);
        
        scene.XY.button1.addListener(this);

        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
        
        setWantsKeyboardFocus(true);
    }

    //==============================================================================
    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        
        maxiSettings::setup(std::round(sampleRate), 2, samplesPerBlockExpected);
        
    }
    
    //==============================================================================
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
            
            osc1out = osc1.saw(freq) * osc1Gain;
            osc2out = osc2.saw(freq * 2) * osc2Gain;
            osc3out = osc3.saw(freq * 1.5) * osc3Gain;
            
            LFO1Out = LFO1.sinebuf(LFO1Freq) * LFO1Gain;
            
            osc1FilterOut = osc1Filter.lores(osc1out, osc1FilterCutoff, 0);
            osc2FilterOut = osc2Filter.lores(osc2out, osc2FilterCutoff, 0);
            osc3FilterOut = osc3Filter.lores(osc3out, osc3FilterCutoff, 0);
            
            VCFout = VCF.lores(osc1FilterOut + osc2FilterOut + osc3FilterOut * 0.3, VCOcutoff * LFO1Out, 0);
            
            cSample = (VCFout * ADSRout) * masterGain;
            
            mixer.stereo(cSample, outputs, 0.5);
            
            bufferL[sample] = float(outputs[0]);
            bufferR[sample] = float(outputs[1]);
        }
    }
    
    //==============================================================================
    void releaseResources() override
    {
        
    }
    
    //==============================================================================
    void paint (Graphics& g) override
    {

    }

    //==============================================================================
    void resized() override
    {
        
        scene.setBounds (0, 0, getWidth(), getHeight());
        
    }
    
    //==============================================================================
    void sliderValueChanged (Slider* slider) override
    {
        //==============================================================================
        //OSC 1 Dials
        if (slider == &scene.oscScene.osc1.dial1)
        {
            osc1FilterCutoff = scene.oscScene.osc1.dial1.getValue();
            std::cout << "osc1FilterCutoff = " << osc1FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc1.dial2)
        {
            osc1Detune = scene.oscScene.osc1.dial2.getValue();
            std::cout << "osc1Detune = " << osc1Detune << std::endl;
        }
        
        if (slider == &scene.oscScene.osc1.dial3)
        {
            osc1Gain = scene.oscScene.osc1.dial3.getValue();
            std::cout << "osc1Gain = " << osc1Gain << std::endl;
        }
        
        //==============================================================================
        //OSC 2 Dials
        if (slider == &scene.oscScene.osc2.dial1)
        {
            osc2FilterCutoff = scene.oscScene.osc2.dial1.getValue();
            std::cout << "osc2FilterCutoff = " << osc2FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc2.dial2)
        {
            osc2Detune = scene.oscScene.osc2.dial2.getValue();
            std::cout << "osc2Detune = " << osc2Detune << std::endl;
        }
        
        if (slider == &scene.oscScene.osc2.dial3)
        {
            osc2Gain = scene.oscScene.osc2.dial3.getValue();
            std::cout << "osc2Gain = " << osc2Gain << std::endl;
        }
        
        //==============================================================================
        //OSC 3 Dials
        if (slider == &scene.oscScene.osc3.dial1)
        {
            osc3FilterCutoff = scene.oscScene.osc3.dial1.getValue();
            std::cout << "osc3FilterCutoff = " << osc3FilterCutoff << std::endl;
        }
        
        if (slider == &scene.oscScene.osc3.dial2)
        {
            osc3Detune = scene.oscScene.osc3.dial2.getValue();
            std::cout << "osc3Detune = " << osc3Detune << std::endl;
        }
        
        if (slider == &scene.oscScene.osc3.dial3)
        {
            osc3Gain = scene.oscScene.osc3.dial3.getValue();
            std::cout << "osc3Gain = " << osc3Gain << std::endl;
        }
        
        //==============================================================================
        //LFO 1 Dials
        if (slider == &scene.modScene.lfo.dial1)
        {
            LFO1Freq = scene.modScene.lfo.dial1.getValue();
            std::cout << "LFO Dial 1" << std::endl;
        }
        
        if (slider == &scene.modScene.lfo.dial2)
        {
            LFO1Gain = scene.modScene.lfo.dial2.getValue();
            std::cout << "LFO Dial 2" << std::endl;
        }
        
        if (slider == &scene.modScene.lfo.dial3)
        {
            masterGain = scene.modScene.lfo.dial3.getValue();
            std::cout << "LFO Dial 3" << std::endl;
        }
        
        //==============================================================================
        //VCO Slider
        if (slider == &scene.modScene.filter.cutoffFrequencySlider)
        {
            VCOcutoff = scene.modScene.filter.cutoffFrequencySlider.getValue();
            std::cout << VCOcutoff << std::endl;
        }
    }
    
    //==============================================================================
    void buttonClicked (Button* button) override
    {
        if(button == &scene.XY.button1)
        {

        }
    }
    

    //==============================================================================
    bool keyPressed(const KeyPress& keyPress) override
    {
        if(keyPress.getTextCharacter() == 'a')
        {
            ADSR.trigger = 1;
            freq = 130.81;
            std::cout << "a key" << std::endl;
        }
        
        
        if(keyPress.getTextCharacter() == 's')
        {
            ADSR.trigger = 1;
            freq = 146.83;
            std::cout << "s key" << std::endl;
        }
        
        
        if(keyPress.getTextCharacter() == 'd')
        {
            ADSR.trigger = 1;
            freq = 164.81;
            std::cout << "d key" << std::endl;
        }
        
        if(keyPress.getTextCharacter() == 'f')
        {
            ADSR.trigger = 1;
            freq = 174.61;
            std::cout << "f key" << std::endl;
        }
        
        if(keyPress.getTextCharacter() == 'g')
        {
            ADSR.trigger = 1;
            freq = 196.00;
            std::cout << "g key" << std::endl;
        }
        
        if(keyPress.getTextCharacter() == 'h')
        {
            ADSR.trigger = 1;
            freq = 220.00;
            std::cout << "h key" << std::endl;
        }
    
        if(keyPress.getTextCharacter() == 'j')
        {
            ADSR.trigger = 1;
            freq = 246.94;
            std::cout << "j key" << std::endl;
        }
        
        if(keyPress.getTextCharacter() == 'k')
        {
            ADSR.trigger = 1;
            freq = 261.63;
            std::cout << "k key" << std::endl;
        }
        
        return "";
    }
    
    
//==============================================================================
    //GUI
    SceneComponent scene;
    
    //AUDIO
    double                       cSample;
    double                       freq, LFO1Freq;
    double                       masterGain;
    double                       osc1Detune, osc2Detune, osc3Detune;
    double                       osc1Gain, osc2Gain, osc3Gain, LFO1Gain;
    double                       osc1out, osc2out, osc3out, LFO1Out;
    double                       osc1FilterOut, osc2FilterOut, osc3FilterOut, VCFout;
    double                       osc1FilterCutoff, osc2FilterCutoff, osc3FilterCutoff, VCOcutoff;
    double                       ADSRout;
    double                       outputs[2];
    
    //Maximilian objects
    maxiOsc                      osc1;
    maxiOsc                      osc2;
    maxiOsc                      osc3;
    maxiOsc                      LFO1;
    maxiFilter                   osc1Filter;
    maxiFilter                   osc2Filter;
    maxiFilter                   osc3Filter;
    maxiFilter                   VCF;
    maxiMix                      mixer;
    maxiEnv                      ADSR;
    
//==============================================================================
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }

#endif  // MAINCOMPONENT_H_INCLUDED

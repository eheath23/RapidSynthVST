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
        
        scene.modScene.envelope.MLSlider.addListener(this);
        scene.modScene.envelope.trainButton.addListener(this);
        scene.modScene.envelope.addButton.addListener(this);
        
        scene.XY.button1.addListener(this);

        setSize (800, 600);

        for(int i = 0; i < 6; i++)
        {
            ADSR[i].setAttack(500);
            ADSR[i].setDecay(3);
            ADSR[i].setSustain(1);
            ADSR[i].setRelease(200);
        }
        
        setAudioChannels (0, 2);
        
        setWantsKeyboardFocus(true);
    }

    //==============================================================================
    ~MainContentComponent()
    {
        shutdownAudio();
    }
    
    //** AUDIO **//
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
        
        cSample = 0;
        
        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            /**
            currentCount = (int)timer.phasor(8);
            
            if(lastCount!=currentCount)
            {
                if(voice == 6)
                {
                    voice = 0;
                }
                
                ADSR[voice].trigger=1;//trigger the envelope from the start
                pitch[voice]=voice+1;
                
                voice++;
            }**/
            
            for (int i = 0; i < 6; i++)
            {
                cVoice = i;
                
                ADSRout[i] = ADSR[i].adsr(1.0, ADSR[i].trigger);
            
                osc1out[i] = osc1[i].saw(freq[i]) * osc1Gain[i];
                osc2out[i] = osc2[i].saw(freq[i]) * osc2Gain[i];
                osc3out[i] = osc3[i].saw(freq[i]) * osc3Gain[i];
            
                LFO1Out[i] = LFO1[i].sinebuf(LFO1Freq[i]) * LFO1Gain[i];
            
                osc1FilterOut[i] = osc1Filter[i].lores(osc1out[i], osc1FilterCutoff[i], 0);
                osc2FilterOut[i] = osc2Filter[i].lores(osc2out[i], osc2FilterCutoff[i], 0);
                osc3FilterOut[i] = osc3Filter[i].lores(osc3out[i], osc3FilterCutoff[i], 0);
            
                VCFout[i] = VCF[i].lores(osc1FilterOut[i] + osc2FilterOut[i] + osc3FilterOut[i] * 0.3, VCOcutoff[i], 0);
            
                cSample += ((VCFout[i] * ADSRout[i]) * masterGain)/6;
                
                mixer.stereo(cSample, outputs, 0.5);
            }
            
            
            bufferL[sample] = float(outputs[0]);
            bufferR[sample] = float(outputs[1]);
            
            for (int i = 0; i < 6; i++) {
                ADSR[i].trigger = 0;
            }
        }
    }
    
    //==============================================================================
    void releaseResources() override
    {
        
    }
    
    //** DRAWING **//
    //==============================================================================
    void paint (Graphics& g) override
    {

    }

    //==============================================================================
    void resized() override
    {
        scene.setBounds (0, 0, getWidth(), getHeight());
    }
    
    //** INPUT CONTROL **//
    //==============================================================================
    
    //** SLIDERS AND DIALS **//
    void sliderValueChanged (Slider* slider) override
    {
//        for(int i = 0; i < 6; i++)

        //==============================================================================
        //OSC 1 Dials
        if (slider == &scene.oscScene.osc1.dial1)
        {

            osc1FilterCutoff[cVoice] = scene.oscScene.osc1.dial1.getValue();
        }
        
        if (slider == &scene.oscScene.osc1.dial2)
        {
            osc1Detune[cVoice] = scene.oscScene.osc1.dial2.getValue();
        }
        
        if (slider == &scene.oscScene.osc1.dial3)
        {
            osc1Gain[cVoice] = scene.oscScene.osc1.dial3.getValue();
        }
        
        //==============================================================================
        //OSC 2 Dials
        if (slider == &scene.oscScene.osc2.dial1)
        {
            osc2FilterCutoff[cVoice] = scene.oscScene.osc2.dial1.getValue();
        }
        
        if (slider == &scene.oscScene.osc2.dial2)
        {
            osc2Detune[cVoice] = scene.oscScene.osc2.dial2.getValue();
        }
        
        if (slider == &scene.oscScene.osc2.dial3)
        {
            osc2Gain[cVoice] = scene.oscScene.osc2.dial3.getValue();
        }
        
        //==============================================================================
        //OSC 3 Dials
        if (slider == &scene.oscScene.osc3.dial1)
        {
            osc3FilterCutoff[cVoice] = scene.oscScene.osc3.dial1.getValue();
        }
        
        if (slider == &scene.oscScene.osc3.dial2)
        {
            osc3Detune[cVoice] = scene.oscScene.osc3.dial2.getValue();
        }
        
        if (slider == &scene.oscScene.osc3.dial3)
        {
            osc3Gain[cVoice] = scene.oscScene.osc3.dial3.getValue();
        }
        
        //==============================================================================
        //LFO 1 Dials
        if (slider == &scene.modScene.lfo.dial1)
        {
            LFO1Freq[cVoice] = scene.modScene.lfo.dial1.getValue();
        }
        
        if (slider == &scene.modScene.lfo.dial2)
        {
            LFO1Gain[cVoice] = scene.modScene.lfo.dial2.getValue();
        }
        
        if (slider == &scene.modScene.lfo.dial3)
        {
            masterGain = scene.modScene.lfo.dial3.getValue();
        }
        
        //==============================================================================
        //VCO Slider
        if (slider == &scene.modScene.filter.cutoffFrequencySlider)
        {
            VCOcutoff[cVoice] = scene.modScene.filter.cutoffFrequencySlider.getValue();
        }
        
        //==============================================================================
        //MACHINE LEARNING SLIDER
        if(slider == &scene.modScene.envelope.MLSlider)
        {
            MLSliderVal = scene.modScene.envelope.MLSlider.getValue();
        }
    }
    
    //** BUTTONS **//
    //==============================================================================
    void buttonClicked (Button* button) override
    {
        if(button == &scene.modScene.envelope.trainButton)
        {
            if (trainingSet.size() > 2)
            {
                trained = rapidRegression.train(trainingSet);
                std::cout << "trained" << std::endl;
            }
        }
        
        if(button == &scene.modScene.envelope.addButton)
        {
            trainingExample example;
            example.input = {MLSliderVal};
            example.output = { };
            trainingSet.push_back(example);
        }
    }
    

    /** KEYBOARD **/
    //==============================================================================
    bool keyPressed(const KeyPress& keyPress) override
    {
        
        if(keyPress.getTextCharacter() == 'a')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 130.81;
        }
        
        
        if(keyPress.getTextCharacter() == 's')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 146.83;
        }
        
        
        if(keyPress.getTextCharacter() == 'd')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 164.81;
        }
        
        if(keyPress.getTextCharacter() == 'f')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 174.61;
        }
        
        if(keyPress.getTextCharacter() == 'g')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 196.00;
        }
        
        if(keyPress.getTextCharacter() == 'h')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 220.00;
        }
    
        if(keyPress.getTextCharacter() == 'j')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 246.94;
        }
        
        if(keyPress.getTextCharacter() == 'k')
        {
            ADSR[cVoice].trigger = 1;
            freq[cVoice] = 261.63;
        }
        
        return "";
    }
    
//** VARIABLES **/
//==============================================================================
    //GUI
    SceneComponent               scene;
    
    /** AUDIO **/
    /**
    int                          currentCount = 0;
    int                          lastCount = 0;
    int                          voice = 0;
     **/
    int                          cVoice;
    int                          pitch[6];
    double                       cSample;
    double                       freq[6], LFO1Freq[6];
    double                       masterGain;
    double                       osc1Detune[6], osc2Detune[6], osc3Detune[6];
    double                       osc1Gain[6], osc2Gain[6], osc3Gain[6], LFO1Gain[6];
    double                       osc1out[6], osc2out[6], osc3out[6], LFO1Out[6];
    double                       osc1FilterOut[6], osc2FilterOut[6], osc3FilterOut[6], VCFout[6];
    double                       osc1FilterCutoff[6], osc2FilterCutoff[6], osc3FilterCutoff[6], VCOcutoff[6];
    double                       ADSRout[6];
    double                       outputs[2];
    
    maxiOsc                      osc1[6];
    maxiOsc                      osc2[6];
    maxiOsc                      osc3[6];
    maxiOsc                      LFO1[6];
    maxiOsc                      timer;
    maxiFilter                   osc1Filter[6];
    maxiFilter                   osc2Filter[6];
    maxiFilter                   osc3Filter[6];
    maxiFilter                   VCF[6];
    maxiEnv                      ADSR[6];
    maxiMix                      mixer;
    
    /** RAPID **/
    regression                   rapidRegression;
    std::vector<trainingExample> trainingSet;
    bool                         trained;
    double                       MLSliderVal;
    
//==============================================================================
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }

#endif  // MAINCOMPONENT_H_INCLUDED

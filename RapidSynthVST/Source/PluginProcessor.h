/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "maximilian.h"

//==================================================================================
struct SimpleSound : public SynthesiserSound
{
    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};

//==================================================================================
class SimpleVoice : public SynthesiserVoice
{
public:
    SimpleVoice() :
    mMasterGain(1),
    mOsc1Detune(0),
    mOsc2Detune(0),
    mOsc3Detune(0),
    mOsc1Gain(1),
    mOsc2Gain(1),
    mOsc3Gain(1),
    mLFO1Gain(1),
    mOsc1FilterCutoff(5000),
    mOsc2FilterCutoff(5000),
    mOsc3FilterCutoff(5000),
    mVCOcutoff(500),
    mVCORes(0),
    mADSR1Attack(0),
    mADSR1Decay(1),
    mADSR1Sustain(0),
    mADSR1Release(0),
    mLFO1Freq(0),
    mOsc1Sine(true),
    mOsc1Saw(false),
    mOsc1Square(false),
    mOsc2Sine(true),
    mOsc2Saw(false),
    mOsc2Square(false),
    mOsc3Sine(true),
    mOsc3Saw(false),
    mOsc3Square(false)
    
    
    {
        std::cout << "Instanciated SimpleVoice" << std::endl;
    }

    void setParameters (double osc1FilterCutoff,
                        double osc1Detune,
                        double osc1Gain,
                        double osc2FilterCutoff,
                        double osc2Detune,
                        double osc2Gain,
                        double osc3FilterCutoff,
                        double osc3Detune,
                        double osc3Gain,
                        double LFO1Freq,
                        double LFO1Gain,
                        double VCOcutoff,
                        double masterGain,
                        double ADSR1Attack,
                        double ADSR1Decay,
                        double ADSR1Sustain,
                        double ADSR1Release,
                        bool osc1Sine,
                        bool osc1Saw,
                        bool osc1Square,
                        bool osc2Sine,
                        bool osc2Saw,
                        bool osc2Square,
                        bool osc3Sine,
                        bool osc3Saw,
                        bool osc3Square,
                        double VCORes)
    {
        mOsc1FilterCutoff = osc1FilterCutoff;
        mOsc1Detune = osc1Detune;
        mOsc1Gain = osc1Gain;
        mOsc1Sine = osc1Sine;
        mOsc1Saw = osc1Saw;
        mOsc1Square = osc1Square;
        
        mOsc2FilterCutoff = osc2FilterCutoff;
        mOsc2Detune = osc2Detune;
        mOsc2Gain = osc2Gain;
        mOsc2Sine = osc2Sine;
        mOsc2Saw = osc2Saw;
        mOsc2Square = osc2Square;
        
        mOsc3FilterCutoff = osc3FilterCutoff;
        mOsc3Detune = osc3Detune;
        mOsc3Gain = osc3Gain;
        mOsc3Sine = osc3Sine;
        mOsc3Saw = osc3Saw;
        mOsc3Square = osc3Square;
        
        mLFO1Freq = LFO1Freq;
        mLFO1Gain = LFO1Gain;
        
        mVCOcutoff = VCOcutoff;
        mMasterGain = masterGain;
        mVCORes = VCORes;
        
        mADSR1Attack = ADSR1Attack;
        mADSR1Decay = ADSR1Decay;
        mADSR1Sustain = ADSR1Sustain;
        mADSR1Release = ADSR1Release;
        
        ADSR1.setAttack(mADSR1Attack);
        ADSR1.setDecay(mADSR1Decay);
        ADSR1.setSustain(mADSR1Sustain);
        ADSR1.setRelease(mADSR1Release);
    }
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SimpleSound*> (sound) != nullptr;
    }
    
    void startNote (int midiNoteNumber,
                    float velocity,
                    SynthesiserSound*,
                    int) override
    {
        mFreq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
        ADSR1.trigger = 1;
    }
    
    void stopNote (float, bool) override
    {
        ADSR1.trigger = 0;
        level = 0;
        clearCurrentNote();
    }
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer,
                          int                startSample,
                          int                numberSamples) override
    {
        while (--numberSamples >= 0)
        {
            
            mADSR1Out = ADSR1.adsr(1.0, ADSR1.trigger);
            
            //OSC 1 Waveform
            if(mOsc1Sine && !mOsc1Saw && !mOsc1Square)
            {
                mOsc1Out = osc1.sinebuf(mFreq) * mOsc1Gain;
            } else if (mOsc1Saw && !mOsc1Sine && !mOsc1Square)
            {
                mOsc1Out = osc1.saw(mFreq) * mOsc1Gain;
            } else if (mOsc1Square && !mOsc1Sine && !mOsc1Saw)
            {
                mOsc1Out = osc1.square(mFreq) * mOsc1Gain;
            }
            
            //OSC 2 WAVEFORM
            if(mOsc2Sine && !mOsc2Saw && !mOsc2Square)
            {
                mOsc2Out = osc2.sinebuf(mFreq) * mOsc2Gain;
            } else if (mOsc2Saw && !mOsc2Sine && !mOsc2Square)
            {
                mOsc2Out = osc2.saw(mFreq) * mOsc2Gain;
            } else if (mOsc2Square && !mOsc2Sine && !mOsc2Saw)
            {
                mOsc2Out = osc2.square(mFreq) * mOsc2Gain;
            }
            
            //OSC 3 WAVEFORM
            if(mOsc3Sine && !mOsc3Saw && !mOsc3Square)
            {
                mOsc3Out = osc3.sinebuf(mFreq) * mOsc3Gain;
            } else if (mOsc3Saw && !mOsc3Sine && !mOsc3Square)
            {
                mOsc3Out = osc3.saw(mFreq) * mOsc3Gain;
            } else if (mOsc3Square && !mOsc3Sine && !mOsc3Saw)
            {
                mOsc3Out = osc3.square(mFreq) * mOsc3Gain;
            }
            
            //LFO 1 WAVEFORM
            if(mLFO1Sine && !mLFO1Saw && !mLFO1Square)
            {
                mLFO1Out = LFO1.sinebuf(mLFO1Freq) * mLFO1Gain;
            } else if (mLFO1Saw && !mLFO1Sine && !mLFO1Square)
            {
                mLFO1Out = LFO1.saw(mLFO1Freq) * mLFO1Gain;
            } else if (mLFO1Square && !mLFO1Sine && !mLFO1Saw)
            {
                mLFO1Out = LFO1.square(mLFO1Freq) * mLFO1Gain;
            }
            
            //LFO 2 WAVEFORM
            if(mLFO2Sine && !mLFO2Saw && !mLFO2Square)
            {
                mLFO2Out = LFO2.sinebuf(mLFO2Freq) * mLFO2Gain;
            } else if (mLFO1Saw && !mLFO1Sine && !mLFO1Square)
            {
                mLFO2Out = LFO2.saw(mLFO2Freq) * mLFO2Gain;
            } else if (mLFO2Square && !mLFO2Sine && !mLFO2Saw)
            {
                mLFO2Out = LFO2.square(mLFO2Freq) * mLFO2Gain;
            }
            
            mOsc1FilterOut = osc1Filter.lores(mOsc1Out, mOsc1FilterCutoff, 0);
            mOsc2FilterOut = osc2Filter.lores(mOsc2Out, mOsc2FilterCutoff, 0);
            mOsc3FilterOut = osc3Filter.lores(mOsc3Out, mOsc3FilterCutoff, 0);
            
            mVCFout = VCF.lores((mOsc1FilterOut + mOsc2FilterOut + mOsc3FilterOut) * 0.3, mVCOcutoff, mVCORes);
            
            mCSample = mVCFout * mMasterGain * mADSR1Out;
            
            double audioFrame = mCSample;
            
            const float currentSample = float(audioFrame) * level;
            
            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
            {
                outputBuffer.addSample (i, startSample, currentSample);
            }
            
            ++startSample;
        }
    }

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}
    
    private:
    double                       level;
    double                       mCSample;
    double                       mFreq;
    double                       mMasterGain;
    double                       mOsc1Detune, mOsc2Detune, mOsc3Detune;
    double                       mOsc1Gain, mOsc2Gain, mOsc3Gain, mLFO1Gain, mLFO2Gain;
    double                       mOsc1Out, mOsc2Out, mOsc3Out, mLFO1Out, mLFO2Out;
    double                       mOsc1FilterOut, mOsc2FilterOut, mOsc3FilterOut, mVCFout;
    double                       mOsc1FilterCutoff, mOsc2FilterCutoff, mOsc3FilterCutoff, mVCOcutoff, mVCORes;
    double                       mADSR1Out, mADSR1Attack, mADSR1Decay, mADSR1Sustain, mADSR1Release;
    double                       mLFO1Freq, mLFO2Freq;
    double                       mOutputs[2];
    
    bool mOsc1Sine, mOsc1Saw, mOsc1Square;
    bool mOsc2Sine, mOsc2Saw, mOsc2Square;
    bool mOsc3Sine, mOsc3Saw, mOsc3Square;
    bool mLFO1Sine, mLFO1Saw, mLFO1Square;
    bool mLFO2Sine, mLFO2Saw, mLFO2Square;
    
    maxiOsc                      osc1, osc2, osc3, LFO1, LFO2;
    maxiFilter                   osc1Filter, osc2Filter, osc3Filter, VCF;
    maxiEnv                      ADSR1, ADSR2;
    maxiMix                      mixer;
};
//==============================================================================

class RapidSynthVstAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    RapidSynthVstAudioProcessor();
    ~RapidSynthVstAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


    double lastSampleRate;
    AudioParameterFloat* osc1FilterCutoff;
    AudioParameterFloat* osc1Detune;
    AudioParameterFloat* osc1Gain;
    
    AudioParameterFloat* osc2FilterCutoff;
    AudioParameterFloat* osc2Detune;
    AudioParameterFloat* osc2Gain;
    
    AudioParameterFloat* osc3FilterCutoff;
    AudioParameterFloat* osc3Detune;
    AudioParameterFloat* osc3Gain;
    
    AudioParameterFloat* LFO1Freq;
    AudioParameterFloat* LFO1Gain;
    
    AudioParameterFloat* VCOcutoff;
    AudioParameterFloat* masterGain;
    
    AudioParameterFloat* ADSR1Attack;
    AudioParameterFloat* ADSR1Decay;
    AudioParameterFloat* ADSR1Sustain;
    AudioParameterFloat* ADSR1Release;
    
    AudioParameterBool* osc1Sine;
    AudioParameterBool* osc1Saw;
    AudioParameterBool* osc1Square;
    
    AudioParameterBool* osc2Sine;
    AudioParameterBool* osc2Saw;
    AudioParameterBool* osc2Square;
    
    AudioParameterBool* osc3Sine;
    AudioParameterBool* osc3Saw;
    AudioParameterBool* osc3Square;
    
    AudioParameterFloat* VCORes;
    
    Synthesiser synth;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RapidSynthVstAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
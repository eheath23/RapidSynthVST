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
    mVCOcutoff(5000),
    mLFO1Freq(0)
    
    {
        std::cout << "Instanciated SimpleVoice" << std::endl;
    }

    void setParameters (double osc1Detune, double osc2Detune, double osc3Detune, double osc1Gain, double osc2Gain, double osc3Gain, double LFO1Gain, double osc1FilterCutoff, double osc2FilterCutoff, double osc3FilterCutoff, double VCOcutoff, double LFO1Freq, double masterGain)
    {
        mOsc1Detune = osc1Detune;
        mOsc2Detune = osc2Detune;
        mOsc3Detune = osc3Detune;
        mOsc1Gain = osc1Gain;
        mOsc2Gain = osc2Gain;
        mOsc3Gain = osc3Gain;
        mLFO1Gain = LFO1Gain;
        mOsc1FilterCutoff = osc1FilterCutoff;
        mOsc2FilterCutoff = osc2FilterCutoff;
        mOsc3FilterCutoff = osc3FilterCutoff;
        mVCOcutoff = VCOcutoff;
        mLFO1Freq = LFO1Freq;
        mMasterGain = masterGain;
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
//        ADSR.trigger = 1;
    }
    
    void stopNote (float, bool) override
    {
//        ADSR.trigger = 0;
        level = 0;
        clearCurrentNote();
    }
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer,
                          int                startSample,
                          int                numberSamples) override
    {
        while (--numberSamples >= 0)
        {
            
//            mADSRout = ADSR.adsr(1.0, ADSR.trigger);
            
            mOsc1out = osc1.saw(mFreq) * mOsc1Gain;
            mOsc2out = osc2.saw(mFreq) * mOsc2Gain;
            mOsc3out = osc3.saw(mFreq) * mOsc3Gain;
            
            mLFO1Out = LFO1.sinebuf(mLFO1Freq) * mLFO1Gain;
            
            mOsc1FilterOut = osc1Filter.lores(mOsc1out, mOsc1FilterCutoff, 0);
            mOsc2FilterOut = osc2Filter.lores(mOsc2out, mOsc2FilterCutoff, 0);
            mOsc3FilterOut = osc3Filter.lores(mOsc3out, mOsc3FilterCutoff, 0);
            
            mVCFout = VCF.lores((mOsc1FilterOut + mOsc2FilterOut + mOsc3FilterOut) * 0.3, mVCOcutoff, 0);
            
            mCSample = mVCFout * mMasterGain;
            
            double audioFrame = mCSample;
            
            const float currentSample = float(audioFrame) * level;
            
            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample (i, startSample, currentSample);
                
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
    double                       mOsc1Gain, mOsc2Gain, mOsc3Gain, mLFO1Gain;
    double                       mOsc1out, mOsc2out, mOsc3out, mLFO1Out;
    double                       mOsc1FilterOut, mOsc2FilterOut, mOsc3FilterOut, mVCFout;
    double                       mOsc1FilterCutoff, mOsc2FilterCutoff, mOsc3FilterCutoff, mVCOcutoff;
    double                       mADSRout;
    double mLFO1Freq;
    double                       mOutputs[2];
    
    maxiOsc                      osc1, osc2, osc3, LFO1;
    maxiFilter                   osc1Filter, osc2Filter, osc3Filter, VCF;
    maxiEnv                      ADSR;
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

private:
    double lastSampleRate;
    AudioParameterFloat* masterGain;
    AudioParameterFloat* osc1Detune;
    AudioParameterFloat* osc2Detune;
    AudioParameterFloat* osc3Detune;
    AudioParameterFloat* osc1Gain;
    AudioParameterFloat* osc2Gain;
    AudioParameterFloat* osc3Gain;
    AudioParameterFloat* LFO1Gain;
    AudioParameterFloat* osc1FilterCutoff;
    AudioParameterFloat* osc2FilterCutoff;
    AudioParameterFloat* osc3FilterCutoff;
    AudioParameterFloat* VCOcutoff;
    AudioParameterFloat* LFO1Freq;
    Synthesiser synth;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RapidSynthVstAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED

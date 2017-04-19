/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
RapidSynthVstAudioProcessor::RapidSynthVstAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif

{
    synth.clearVoices();
    synth.clearSounds();
    synth.addSound(new SimpleSound());
    
    for(int i = 0; i < 7; i++){
        synth.addVoice(new SimpleVoice()); 
    }
    
    addParameter(osc1FilterCutoff = new AudioParameterFloat("osc1FilterCutoff", "osc1 Filter Cutoff", 0, 5000, 5000));
    addParameter(osc1Detune = new AudioParameterInt("osc1Detune", "Osc1 Detune", -12, 12, 0));
    addParameter(osc1Gain = new AudioParameterFloat("osc1Gain", "Osc1 Gain", 0, 1, 1));
    
    addParameter(osc2FilterCutoff = new AudioParameterFloat("osc2FilterCutoff", "osc2 Filter Cutoff", 0, 5000, 5000));
    addParameter(osc2Detune = new AudioParameterInt("osc2Detune", "Osc2 Detune", -12, 12, 0));
    addParameter(osc2Gain = new AudioParameterFloat("osc2Gain", "Osc2 Gain", 0, 1, 1));
    
    addParameter(osc3FilterCutoff = new AudioParameterFloat("osc3FilterCutoff", "osc3 Filter Cutoff", 0, 5000, 5000));
    addParameter(osc3Detune = new AudioParameterInt("osc3Detune", "Osc3 Detune", -12, 12, 0));
    addParameter(osc3Gain = new AudioParameterFloat("osc3Gain", "Osc3 Gain", 0, 1, 1));
    
    addParameter(LFO1Freq = new AudioParameterFloat("LFO1Freq", "LFO1 Freq", 0, 20, 0));
    addParameter(LFO1Gain = new AudioParameterFloat("LFO1Gain", "LFO1 Gain", 0, 1, 0));
    
    addParameter(VCOCutoff = new AudioParameterFloat("VCOCutoff", "VCO Cutoff", 1, 5000, 5000));
    addParameter(masterGain = new AudioParameterFloat("masterGain", "Master Gain", 0, 1, 1));
    
    addParameter(ADSR1Attack = new AudioParameterFloat("ADSR1Attack", "ADSR1 Attack", 0, 10000, 1000));
    addParameter(ADSR1Decay = new AudioParameterFloat("ADSR1Decay", "ADSR1 Decay", 1, 10000, 1));
    addParameter(ADSR1Sustain = new AudioParameterFloat("ADSR1Sustain", "ADSR1 Sustain", 0, 1, 1));
    addParameter(ADSR1Release = new AudioParameterFloat("ADSR1Release", "ADSR1 Release", 0, 10000, 1000));
    
    addParameter(osc1Sine = new AudioParameterBool("osc1Sine", "osc1 Sine", true, "osc1 sine"));
    addParameter(osc1Saw = new AudioParameterBool("osc1Saw", "osc1 Saw", false, "osc1 saw"));
    addParameter(osc1Square = new AudioParameterBool("osc1Square", "osc1 Square", false, "osc1 square"));
    
    addParameter(osc2Sine = new AudioParameterBool("osc2Sine", "osc2 Sine", true, "osc2 sine"));
    addParameter(osc2Saw = new AudioParameterBool("osc2Saw", "osc2 Saw", false, "osc2 saw"));
    addParameter(osc2Square = new AudioParameterBool("osc2Square", "osc2 Square", false, "osc2 square"));
    
    addParameter(osc3Sine = new AudioParameterBool("osc3Sine", "osc3 Sine", true, "osc3 sine"));
    addParameter(osc3Saw = new AudioParameterBool("osc3Saw", "osc3 Saw", false, "osc3 saw"));
    addParameter(osc3Square = new AudioParameterBool("osc3Square", "osc3 Square", false, "osc3 square"));
    
    addParameter(LFO1Sine = new AudioParameterBool("LFO1Sine", "LFO1 Sine", true, "LFO1 sine"));
    addParameter(LFO1Saw = new AudioParameterBool("LFO1Saw", "LFO1 Saw", false, "LFO1 saw"));
    addParameter(LFO1Square = new AudioParameterBool("LFO1Square", "LFO1 Square", false, "LFO1 square"));
    
    addParameter(VCORes = new AudioParameterFloat("VCORes", "VCO Res", 0, 1, 0));
    
}

RapidSynthVstAudioProcessor::~RapidSynthVstAudioProcessor()
{
}

//==============================================================================
const String RapidSynthVstAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool RapidSynthVstAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool RapidSynthVstAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double RapidSynthVstAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int RapidSynthVstAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int RapidSynthVstAudioProcessor::getCurrentProgram()
{
    return 0;
}

void RapidSynthVstAudioProcessor::setCurrentProgram (int index)
{
}

const String RapidSynthVstAudioProcessor::getProgramName (int index)
{
    return String();
}

void RapidSynthVstAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void RapidSynthVstAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    ignoreUnused(samplesPerBlock);
    
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
    maxiSettings:: setup(lastSampleRate, getTotalNumOutputChannels(), samplesPerBlock);
    
}

void RapidSynthVstAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool RapidSynthVstAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void RapidSynthVstAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for(int i = synth.getNumVoices(); --i >= 0;){
        auto currentVoice = synth.getVoice(i);
        SimpleVoice* derivedVoice = dynamic_cast<SimpleVoice*>(currentVoice);
        bool isLegit = derivedVoice != nullptr;
        if(isLegit){
            derivedVoice->setParameters(osc1FilterCutoff->get(),
                                        osc1Detune->get(),
                                        osc1Gain->get(),
                                        osc2FilterCutoff->get(),
                                        osc2Detune->get(),
                                        osc2Gain->get(),
                                        osc3FilterCutoff->get(),
                                        osc3Detune->get(),
                                        osc3Gain->get(),
                                        LFO1Freq->get(),
                                        LFO1Gain->get(),
                                        VCOCutoff->get(),
                                        masterGain->get(),
                                        ADSR1Attack->get(),
                                        ADSR1Decay->get(),
                                        ADSR1Sustain->get(),
                                        ADSR1Release->get(),
                                        osc1Sine->get(),
                                        osc1Saw->get(),
                                        osc1Square->get(),
                                        osc2Sine->get(),
                                        osc2Saw->get(),
                                        osc2Square->get(),
                                        osc3Sine->get(),
                                        osc3Saw->get(),
                                        osc3Square->get(),
                                        LFO1Sine->get(),
                                        LFO1Saw->get(),
                                        LFO1Square->get(),
                                        VCORes->get());
        }
    }
    
    buffer.clear();
    
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool RapidSynthVstAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* RapidSynthVstAudioProcessor::createEditor()
{
    return new RapidSynthVstAudioProcessorEditor (*this);
}

//==============================================================================
void RapidSynthVstAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void RapidSynthVstAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new RapidSynthVstAudioProcessor();
}

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
    addParameter(osc1Detune = new AudioParameterFloat("osc1Detune", "Osc1 Detune", -12, 12, 0));
    addParameter(osc1Gain = new AudioParameterFloat("osc1Gain", "Osc1 Gain", 0, 1, 1));
    
    addParameter(osc2FilterCutoff = new AudioParameterFloat("osc2FilterCutoff", "osc2 Filter Cutoff", 0, 5000, 5000));
    addParameter(osc2Detune = new AudioParameterFloat("osc2Detune", "Osc2 Detune", -12, 12, 0));
    addParameter(osc2Gain = new AudioParameterFloat("osc2Gain", "Osc2 Gain", 0, 1, 1));
    
    addParameter(osc3FilterCutoff = new AudioParameterFloat("osc3FilterCutoff", "osc3 Filter Cutoff", 0, 5000, 5000));
    addParameter(osc3Detune = new AudioParameterFloat("osc3Detune", "Osc3 Detune", -12, 12, 0));
    addParameter(osc3Gain = new AudioParameterFloat("osc3Gain", "Osc3 Gain", 0, 1, 1));
    
    addParameter(LFO1Freq = new AudioParameterFloat("LFO1Freq", "LFO1 Freq", 0, 20, 0));
    addParameter(LFO1Gain = new AudioParameterFloat("LFO1Gain", "LFO1 Gain", 0, 1, 0));
    
    addParameter(VCOcutoff = new AudioParameterFloat("VCOcutoff", "VCO Cutoff", 0, 5000, 5000));
    addParameter(masterGain = new AudioParameterFloat("masterGain", "Master Gain", 0, 1, 1));
    
    addParameter(ADSRAttack = new AudioParameterFloat("ADSRAttack", "ADSR Attack", 0, 10000, 1000));
    addParameter(ADSRDecay = new AudioParameterFloat("ADSRDecay", "ADSR Decay", 1, 10000, 1));
    addParameter(ADSRSustain = new AudioParameterFloat("ADSRSustain", "ADSR Sustain", 0, 1, 1));
    addParameter(ADSRRelease = new AudioParameterFloat("ADSRRelease", "ADSR Release", 0, 10000, 1000));
    
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
                                        VCOcutoff->get(),
                                        masterGain->get(),
                                        ADSRAttack->get(),
                                        ADSRDecay->get(),
                                        ADSRSustain->get(),
                                        ADSRRelease->get());
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

/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstexampleAudioProcessor::VstexampleAudioProcessor()
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
    
    addParameter(modFreq = new AudioParameterFloat("modFreq", "Modulation Frequency", 0, 100, 50));
    addParameter(modIndex = new AudioParameterFloat("modIndex", "Modulation Index", 0, 1000, 500));
    
}

VstexampleAudioProcessor::~VstexampleAudioProcessor()
{
}

//==============================================================================
const String VstexampleAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VstexampleAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VstexampleAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double VstexampleAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VstexampleAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VstexampleAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VstexampleAudioProcessor::setCurrentProgram (int index)
{
}

const String VstexampleAudioProcessor::getProgramName (int index)
{
    return String();
}

void VstexampleAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VstexampleAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    ignoreUnused(samplesPerBlock);
    
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
    maxiSettings:: setup(lastSampleRate, getTotalNumOutputChannels(), samplesPerBlock);
    
}

void VstexampleAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VstexampleAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void VstexampleAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for(int i = synth.getNumVoices(); --i >= 0;){
        auto currentVoice = synth.getVoice(i);
        SimpleVoice* derivedVoice = dynamic_cast<SimpleVoice*>(currentVoice);
        bool isLegit = derivedVoice != nullptr;
        if(isLegit){
            derivedVoice->setParameters(modFreq->get(), modIndex->get());
        }
    }
    
    buffer.clear();
    
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool VstexampleAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VstexampleAudioProcessor::createEditor()
{
    return new VstexampleAudioProcessorEditor (*this);
}

//==============================================================================
void VstexampleAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VstexampleAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VstexampleAudioProcessor();
}

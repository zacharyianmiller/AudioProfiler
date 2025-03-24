/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <atomic>

#include "DSP/DemoEffect.h"
#include "utils/StandardIncludes.h"
#include "utils/Timer.h"
#include "utils/ScopedTimer.h"

//==============================================================================
/**
*/
class AudioProfilerDemoAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    AudioProfilerDemoAudioProcessor();
    ~AudioProfilerDemoAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================    
    std::atomic<std::array<AudioProfiler::Profile, MAX_NUM_PROFILES>*> getProfiles()
    {
        localProfiles = effect.getProfiles();
        return std::atomic<std::array<AudioProfiler::Profile, MAX_NUM_PROFILES>*>(&localProfiles);
    }
    
    /* APVTS */
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    juce::AudioProcessorValueTreeState apvts { *this, nullptr, "Parameters", createParameterLayout() };

private:
    
    DemoEffect effect;
    std::array<AudioProfiler::Profile, MAX_NUM_PROFILES> localProfiles;
        
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProfilerDemoAudioProcessor)
};

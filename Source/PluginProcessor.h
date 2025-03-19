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
    std::atomic<double> getElapsedTime()
    {
        return std::atomic(timer.getElapsedMilliseconds(true));
    }
    
    std::atomic<AudioProfiler::Profile> getProfile()
    {
        return std::atomic<AudioProfiler::Profile>(effect.getProfile());
    }
    
private:
    
    // Base effect
    DemoEffect effect;
    
    // Standard timer
    Timer timer;
    bool hasStarted = true; // ignore call after init start
    double elapsedTime = 0.0; // default ms
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProfilerDemoAudioProcessor)
};

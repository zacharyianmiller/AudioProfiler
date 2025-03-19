/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AudioProfilerDemoAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                             public juce::Timer
{
public:
    AudioProfilerDemoAudioProcessorEditor (AudioProfilerDemoAudioProcessor&);
    ~AudioProfilerDemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    //==============================================================================
    void timerCallback() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProfilerDemoAudioProcessor& audioProcessor;
    
    // Standard timer
    juce::String getFormattedTime (double timeMs);
    double elapsedTime = 0.0; // received from processor
    
    // Scoped timer
    bool showScoped = true;
    double profileTime = 0.0;
    juce::String profileLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProfilerDemoAudioProcessorEditor)
};

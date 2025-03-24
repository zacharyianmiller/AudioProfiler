/*
  ==============================================================================

    ProfileDisplayComponent.h
    Created: 19 Mar 2025 9:16:02pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

class ProfileDisplayComponent : public juce::Component, public juce::Timer
{
public:
    ProfileDisplayComponent (AudioProfilerDemoAudioProcessor&);
    ~ProfileDisplayComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    //==============================================================================
    void timerCallback() override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProfilerDemoAudioProcessor& audioProcessor;
    
    juce::String getFormattedTime (double timeMs);
    
    std::array<double, MAX_NUM_PROFILES> profileTime;
    std::array<std::string, MAX_NUM_PROFILES> profileLabel;
    
    std::array<AudioProfiler::Profile, MAX_NUM_PROFILES> profileList;
    
    juce::Viewport profilesViewport;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProfileDisplayComponent)
};

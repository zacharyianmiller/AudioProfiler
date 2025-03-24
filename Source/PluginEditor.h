/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/ProfileDisplayComponent.h"

//==============================================================================
/**
*/
class AudioProfilerDemoAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AudioProfilerDemoAudioProcessorEditor (AudioProfilerDemoAudioProcessor&);
    ~AudioProfilerDemoAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:

    AudioProfilerDemoAudioProcessor& audioProcessor;
    
    /* Load simulation (thread sleep) slider */
    juce::Slider loadSimulationSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> loadSimulationSliderAttachment;
    
    /* Scroll window for profiles */
    juce::Viewport profilesViewport;
    ProfileDisplayComponent profileDisplayComponent;
    
    /* Colors */
    const juce::Colour darkgrey = juce::Colour(35, 35, 35);
    const juce::Colour grey = juce::Colour(74, 74, 74);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProfilerDemoAudioProcessorEditor)
};

/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cmath>

//==============================================================================
AudioProfilerDemoAudioProcessorEditor::AudioProfilerDemoAudioProcessorEditor (AudioProfilerDemoAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), profileDisplayComponent(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
    
    /* Slider */
    addAndMakeVisible(loadSimulationSlider);
    loadSimulationSlider.setBounds(50, 25, 300, 50);
    
    loadSimulationSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (audioProcessor.apvts,
                                                                                                             "SLEEP",
                                                                                                             loadSimulationSlider);

    /* Viewport */
    addAndMakeVisible (profilesViewport);
    profilesViewport.setBounds (50, 75, 300, 100);
    profilesViewport.setViewedComponent (&profileDisplayComponent, false);
   
    /* ...look and feel */
    profilesViewport.setScrollBarsShown (true, false); // horizontal scroll off
    profilesViewport.setScrollBarPosition (false, false);
    profilesViewport.setScrollBarThickness (6);
    getLookAndFeel().setColour (juce::ScrollBar::thumbColourId, grey);
}

AudioProfilerDemoAudioProcessorEditor::~AudioProfilerDemoAudioProcessorEditor()
{
}

//==============================================================================
void AudioProfilerDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (darkgrey); // background
    g.setColour (grey);
    g.drawRect (profilesViewport.getBounds());
}

void AudioProfilerDemoAudioProcessorEditor::resized()
{
}

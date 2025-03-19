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
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    startTimerHz (150);
}

AudioProfilerDemoAudioProcessorEditor::~AudioProfilerDemoAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void AudioProfilerDemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
    if (!showScoped)
        g.drawFittedText (getFormattedTime(elapsedTime),
                          getLocalBounds(),
                          juce::Justification::centred, 1);
    
    if (showScoped)
        g.drawFittedText (juce::String(profileLabel + ": " + getFormattedTime(profileTime)),
                          getLocalBounds(),
                          juce::Justification::centred, 1);
}

void AudioProfilerDemoAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AudioProfilerDemoAudioProcessorEditor::timerCallback()
{
    elapsedTime = audioProcessor.getElapsedTime().load();
    
    profileTime = audioProcessor.getProfile().load().value;
    profileLabel = *(audioProcessor.getProfile().load()).label;
    
    repaint();
}

juce::String AudioProfilerDemoAudioProcessorEditor::getFormattedTime (double timeMs)
{
    double outnum = std::round((timeMs * 10.0)) / 10.0; // one sig fig
    return (std::round(outnum) - outnum == 0) ? juce::String(outnum) + ".0" : juce::String(outnum);
}

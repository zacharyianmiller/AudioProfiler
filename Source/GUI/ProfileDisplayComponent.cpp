/*
  ==============================================================================

    ProfileDisplayComponent.cpp
    Created: 19 Mar 2025 9:16:02pm
    Author:  Zachary Miller

  ==============================================================================
*/

#include "ProfileDisplayComponent.h"
#include <cmath>

//==============================================================================
ProfileDisplayComponent::ProfileDisplayComponent (AudioProfilerDemoAudioProcessor& p)
    : audioProcessor (p)
{
    setSize(300, 21 * NUM_ALGORITHMS_FOR_TESTING);
    startTimerHz (150);
}

ProfileDisplayComponent::~ProfileDisplayComponent()
{
    stopTimer();
}

//==============================================================================
void ProfileDisplayComponent::paint (juce::Graphics& g)
{
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
       
    for (size_t n = 0; n < NUM_ALGORITHMS_FOR_TESTING; ++n)
    {
        int offsetY = n == 0 ? 5 : 5 + 20 * (int)n;
        g.drawFittedText(juce::String(juce::String(profileLabel[n]) + ": " + getFormattedTime(profileTime[n]) + "ms"),
                         getLocalBounds().getX(),
                         getLocalBounds().getY() + offsetY,
                         getLocalBounds().getWidth(),
                         getLocalBounds().getHeight(),
                         juce::Justification::centredTop,
                         1);
    }
}

void ProfileDisplayComponent::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void ProfileDisplayComponent::timerCallback()
{
    auto N = (*audioProcessor.getProfiles()).size();
    auto prf = *audioProcessor.getProfiles();
    for (size_t n = 0; n < N; ++n)
    {
        profileTime.at(n) = (*audioProcessor.getProfiles())[n].value;
        profileLabel.at(n) = (*audioProcessor.getProfiles())[n].label;
    }
        
    repaint();
}

juce::String ProfileDisplayComponent::getFormattedTime (double timeMs)
{
    double outnum = std::round((timeMs * 10.0)) / 10.0; // one sig fig
    return (std::round(outnum) - outnum == 0) ? juce::String(outnum) + ".0" : juce::String(outnum);
}

/*
  ==============================================================================

    StandardIncludes.h
    Created: 18 Mar 2025 4:12:14pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <chrono>
#include <string>

namespace AudioProfiler
{

struct Profile
{
    double value;
    juce::String* label;
};

}; // namespace AudioProfiler

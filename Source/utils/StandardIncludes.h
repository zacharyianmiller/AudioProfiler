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

inline void allocateResources (AudioProfiler::Profile* targetProfilePtr,
                               juce::String targetName = "DEFAULT")
{
    (*targetProfilePtr).label = new juce::String (targetName);
}

inline void releaseResources (AudioProfiler::Profile* targetProfilePtr)
{
    delete (*targetProfilePtr).label;
    (*targetProfilePtr).label = nullptr; // prevent dangling ptr
}

}; // namespace AudioProfiler

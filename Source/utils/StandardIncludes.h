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

#define MAX_NUM_PROFILES 15

namespace AudioProfiler
{

struct Profile
{
    double value;
    std::string label;
};

}; // namespace AudioProfiler

/*
  ==============================================================================

    ScopedTimer.h
    Created: 17 Mar 2025 3:10:46pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include "Timer.h"

class ScopedTimer
{
public:
    
    explicit ScopedTimer (AudioProfiler::Profile* targetProfilePtr, juce::String targetName) : profilePtr(targetProfilePtr), name(targetName)
    {
        timer.start();
        AudioProfiler::allocateResources(profilePtr, name); // raw
    };
    
    ~ScopedTimer()
    {
        timer.stop();
        
        /* Assign values to ScopedTimer's unique profile struct */
        if (profilePtr != nullptr)
        {
            (*profilePtr).value = timer.getElapsedMilliseconds (false);
            *(*profilePtr).label = name;
            
            AudioProfiler::releaseResources(profilePtr); // raw
        }
    };
        
private:
    
    Timer timer;
    
    AudioProfiler::Profile* profilePtr;
    const juce::String name = "DEFAULT";
        
    // ===================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScopedTimer);
};

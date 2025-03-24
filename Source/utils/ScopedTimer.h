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
    
    explicit ScopedTimer (AudioProfiler::Profile* targetProfilePtr,
                          std::string targetName) : profilePtr(targetProfilePtr)
    {
        name = targetName.c_str();
        
        timer.start();
        (*targetProfilePtr).label = targetName;
    };
    
    ~ScopedTimer()
    {
        timer.stop();
        
        /* Assign values to ScopedTimer's unique profile struct */
        if (profilePtr != nullptr)
        {
            (*profilePtr).value = timer.getElapsedMilliseconds (false);
            (*profilePtr).label = name;
        }
    };
        
private:
    
    Timer timer;
    
    AudioProfiler::Profile* profilePtr;
    const char* name;
        
    // ===================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScopedTimer);
};

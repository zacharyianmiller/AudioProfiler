/*
  ==============================================================================

    Timer.h
    Created: 17 Mar 2025 1:01:07pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include "StandardIncludes.h"

class Timer
{
public:

    Timer() = default;
    ~Timer() {};
    
    void start()
    {
        startTime = std::chrono::system_clock::now(); // tag start
        isRunning = true;
    }

    void stop()
    {
        endTime = std::chrono::system_clock::now(); // tag end
        isRunning = false;
    }

    double getElapsedMilliseconds (bool roundToSeconds)
    {
        endTime = isRunning ? std::chrono::system_clock::now() : endTime;
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        return !roundToSeconds ? elapsedTime : elapsedTime / 1000.0;
    }
    
private:
    
    std::chrono::time_point<std::chrono::system_clock> startTime, endTime;
    bool isRunning = false;
    
    // ===================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Timer);
};

/*
  ==============================================================================

    DemoEffect.h
    Created: 18 Mar 2025 10:36:58am
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <thread>
#include "../utils/ScopedTimer.h"
#include "../utils/StandardIncludes.h"

class DemoEffect
{
public:
    
    DemoEffect() = default;
    ~DemoEffect() {};
    
    void prepare (double targetFs, size_t targetBufferSize);
    
    float processSample (float input);
    void processBuffer (const float* input, float* output, size_t numSamples);
        
    AudioProfiler::Profile getProfile(); // scoped only
    
private:
    
    double Fs = -1.0;
    size_t bufferSize;
    
    AudioProfiler::Profile effectProfile;
        
    // ===================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DemoEffect);
};

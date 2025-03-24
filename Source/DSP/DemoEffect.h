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

#define NUM_ALGORITHMS_FOR_TESTING 8

class DemoEffect
{
public:
    
    DemoEffect(juce::AudioProcessorValueTreeState& apvts)
    {
        sleepAtomic = apvts.getRawParameterValue("SLEEP");
    };
    
    ~DemoEffect()
    {
    };
    
    void prepare (double targetFs, size_t targetBufferSize);
    
    float processSample (float input);
    void processBuffer (const float* input, float* output, size_t numSamples);
        
    void updateParameters();
    
    std::array<AudioProfiler::Profile, MAX_NUM_PROFILES> getProfiles();
    
private:
    
    double Fs = -1.0;
    size_t bufferSize;
    
    std::atomic<float>* sleepAtomic;
    float sleepValue = 0.f;
    
    AudioProfiler::Profile algorithmProfile[MAX_NUM_PROFILES];
    std::array<AudioProfiler::Profile, MAX_NUM_PROFILES> effectProfiles;
        
    // ===================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DemoEffect);
};

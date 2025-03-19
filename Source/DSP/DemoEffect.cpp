/*
  ==============================================================================

    DemoEffect.cpp
    Created: 18 Mar 2025 10:40:10am
    Author:  Zachary Miller

  ==============================================================================
*/

#include "DemoEffect.h"

void DemoEffect::prepare (double targetFs,
                          size_t targetBufferSize)
{
    this->Fs = targetFs;
    this->bufferSize = targetBufferSize;
}

float DemoEffect::processSample (float input)
{
    /* Simulate work */
    std::this_thread::sleep_for(std::chrono::nanoseconds(100000)); // 1e5ns
    return input;
}

void DemoEffect::processBuffer (const float *input,
                                float *output,
                                size_t numSamples)
{
    ScopedTimer sTimer (&effectProfile, juce::String("SleepThreadAlgorithm"));
    for (size_t n = 0; n < numSamples; ++n)
    {
        output[n] = processSample (input[n]);
    }
}

AudioProfiler::Profile DemoEffect::getProfile() { return effectProfile; }

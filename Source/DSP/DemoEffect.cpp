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

void DemoEffect::processBuffer (const float *input,
                                float *output,
                                size_t numSamples)
{
    updateParameters();
    
    // Algorithm #1
    {
        ScopedTimer sTimer (&algorithmProfile[0], std::string("SleepThread1"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 52)));
    }
    effectProfiles.at(0) = algorithmProfile[0];

    // Algorithm #2
    {
        ScopedTimer sTimer (&algorithmProfile[1], std::string("SleepThread2"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 80)));
    }
    effectProfiles.at(1) = algorithmProfile[1];

    // Algorithm #3
    {
        ScopedTimer sTimer (&algorithmProfile[2], std::string("SleepThread3"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 5)));
    }
    effectProfiles.at(2) = algorithmProfile[2];

    // Algorithm #4
    {
        ScopedTimer sTimer (&algorithmProfile[3], std::string("SleepThread4"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 19)));
    }
    effectProfiles.at(3) = algorithmProfile[3];

    // Algorithm #5
    {
        ScopedTimer sTimer (&algorithmProfile[4], std::string("SleepThread5"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 98)));
    }
    effectProfiles.at(4) = algorithmProfile[4];

    // Algorithm #6
    {
        ScopedTimer sTimer (&algorithmProfile[5], std::string("SleepThread6"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 11)));
    }
    effectProfiles.at(5) = algorithmProfile[5];

    // Algorithm #7
    {
        ScopedTimer sTimer (&algorithmProfile[6], std::string("SleepThread7"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 7)));
    }
    effectProfiles.at(6) = algorithmProfile[6];

    // Algorithm #8
    {
        ScopedTimer sTimer (&algorithmProfile[7], std::string("SleepThread8"));
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(sleepValue * 2)));
    }
    effectProfiles.at(7) = algorithmProfile[7];
}

void DemoEffect::updateParameters()
{
    if (*sleepAtomic != sleepValue) { sleepValue = *sleepAtomic; }
}

std::array<AudioProfiler::Profile, MAX_NUM_PROFILES> DemoEffect::getProfiles()
{
    return effectProfiles;
}

# AudioProfiler
An example of an integrated audio DSP algorithm profiler for full-scale software. The main API includes a **ScopedTimer** class that should be instantiated within the overall scope of a **processBuffer**-type function to accumulate and store the running time needed to complete a single buffer's processing time.
The **ScopedTimer** and base **Timer** classes are dependent on **std::chrono** date and time library.

## Integration Example
```objective-C++
void BasicAudioEffect::processBuffer (const float *input,
                                      float *output,
                                      size_t numSamples)
{
    ScopedTimer sTimer (&effectProfile, juce::String("AlgorithmName"));
    for (size_t n = 0; n < numSamples; ++n)
    {
        // Process individual samples...
    }
}
```
The ``&effectProfile`` should be instantiated once per algorithm - most easily stored as a private member of a DSP effect class. In this example, ``effectProfile`` is accessed via the main API as ``AudioProfiler::Profile audioProfile`` and is necessary to passed by reference in your **ScopedTimer** constructor.

## Future Additions
* Multiple algorithm support
* Separate profiling window rather than using the JUCE project's **Editor** window 

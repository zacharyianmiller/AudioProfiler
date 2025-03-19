# AudioProfiler
An example of an integrated audio DSP algorithm profiler for full-scale software. The main API includes a **ScopedTimer** class that should be instantiated within the overall scope of a **processBuffer**-type function to accumulate and store the running time needed to complete a single buffer's processing time.
The **ScopedTimer** and base **Timer** classes are dependent on **std::chrono** date and time library.


## Future Additions
* Multiple algorithm support
* Separate profiling window rather than using the JUCE project's **Editor** window 

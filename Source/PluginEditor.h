/*
  ==============================================================================

    Author: Matt Hill

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class PluginTemplateAudioProcessorEditor  : public AudioProcessorEditor,
                                            private Slider::Listener
{
public:
    PluginTemplateAudioProcessorEditor (PluginTemplateAudioProcessor&);
    ~PluginTemplateAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    float noteOnVel;

private:
    PluginTemplateAudioProcessor& processor;
    void sliderValueChanged (Slider* slider) ;

    
    Slider midiVolume;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginTemplateAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED

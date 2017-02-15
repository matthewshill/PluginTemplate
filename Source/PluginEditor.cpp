/*
  ==============================================================================

    Author: Matt Hill
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PluginTemplateAudioProcessorEditor::PluginTemplateAudioProcessorEditor (PluginTemplateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (200, 200);
    
    // these define the parameters of our slider object
    midiVolume.setSliderStyle (Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, this);
    midiVolume.setTextValueSuffix (" Volume");
    midiVolume.setValue(1.0);
    
    // this function adds the slider to the editor
    addAndMakeVisible (&midiVolume);
    
    midiVolume.addListener(this);
}

PluginTemplateAudioProcessorEditor::~PluginTemplateAudioProcessorEditor()
{
}

//==============================================================================
void PluginTemplateAudioProcessorEditor::paint (Graphics& g)
{
    // fill the whole window white
    g.fillAll (Colours::white);
    
    // set the current drawing colour to black
    g.setColour (Colours::black);
    
    // set the font size and draw text to the screen
    g.setFont (15.0f);
    
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void PluginTemplateAudioProcessorEditor::resized()
{
    // sets the position and size of the slider with arguments (x, y, width, height)
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
}

void PluginTemplateAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
}
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "RapidLib/src/regression.h"
#include <array>
#include <math.h>

#include "SceneComponent.h"
#include "CustomLookAndFeel.h"


//==============================================================================
/**
*/

//struct CustomLookAndFeel    : public LookAndFeel_V1
//{
//    ///////////////////
//    void drawRoundThumb (Graphics& g, const float x, const float y,
//                         const float diameter, const Colour& colour, float outlineThickness)
//    {
//        const Rectangle<float> a (x, y, diameter, diameter);
//        const float halfThickness = outlineThickness * 0.5f;
//        
//        Path p;
//        p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);
//        
//        const DropShadow ds (Colours::black, 1, Point<int> (0, 0));
//        ds.drawForPath (g, p);
//        
//        g.setColour (colour);
//        g.fillPath (p);
//        
//        g.setColour (colour.brighter());
//        g.strokePath (p, PathStrokeType (outlineThickness));
//    }
//    
//    /////////////////////////
////    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
////                               bool isMouseOverButton, bool isButtonDown) override
////    {
////        Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
////                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));
////        
////        if (isButtonDown || isMouseOverButton)
////            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);
////        
////        const bool flatOnLeft   = button.isConnectedOnLeft();
////        const bool flatOnRight  = button.isConnectedOnRight();
////        const bool flatOnTop    = button.isConnectedOnTop();
////        const bool flatOnBottom = button.isConnectedOnBottom();
////        
////        const float width  = button.getWidth() - 1.0f;
////        const float height = button.getHeight() - 1.0f;
////        
////        if (width > 0 && height > 0)
////        {
////            const float cornerSize = jmin (15.0f, jmin (width, height) * 0.45f);
////            const float lineThickness = cornerSize * 0.1f;
////            const float halfThickness = lineThickness * 0.5f;
////            
////            Path outline;
////            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
////                                         cornerSize, cornerSize,
////                                         ! (flatOnLeft  || flatOnTop),
////                                         ! (flatOnRight || flatOnTop),
////                                         ! (flatOnLeft  || flatOnBottom),
////                                         ! (flatOnRight || flatOnBottom));
////            
////            const Colour outlineColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
////                                                           : TextButton::textColourOffId));
////            
////            g.setColour (baseColour);
////            g.fillPath (outline);
////            
////            if (! button.getToggleState())
////            {
////                g.setColour (outlineColour);
////                g.strokePath (outline, PathStrokeType (lineThickness));
////            }
////        }
////    }
//    
//    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
//                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
//    {
//        const auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
//        const auto fill    = slider.findColour (Slider::rotarySliderFillColourId);
//        
//        const auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);
//        
//        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
//        const auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
//        auto lineW = jmin (3.0f, radius * 0.5f);
//        auto arcRadius = radius - lineW * 0.1f;
//        
//        Path backgroundArc;
//        backgroundArc.addCentredArc (bounds.getCentreX(),
//                                     bounds.getCentreY(),
//                                     arcRadius,
//                                     arcRadius,
//                                     0.0f,
//                                     rotaryStartAngle,
//                                     rotaryEndAngle,
//                                     true);
//        
//        g.setColour (outline);
//        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
//        
//        if (slider.isEnabled())
//        {
//            Path valueArc;
//            valueArc.addCentredArc (bounds.getCentreX(),
//                                    bounds.getCentreY(),
//                                    arcRadius,
//                                    arcRadius,
//                                    0.0f,
//                                    rotaryStartAngle,
//                                    toAngle,
//                                    true);
//            
//            g.setColour (fill);
//            g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
//        }
//        
//        const auto thumbWidth = lineW * 2.0f;
//        const Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - float_Pi * 0.5f),
//                                       bounds.getCentreY() + arcRadius * std::sin (toAngle - float_Pi * 0.5f));
//        
//        g.setColour (slider.findColour (Slider::thumbColourId));
//        g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
//    }
//    
//};


////////////////////////////////////////
class RapidSynthVstAudioProcessorEditor  : public AudioProcessorEditor,
public Slider::Listener,
public Button::Listener,
private Timer
{
public:
    RapidSynthVstAudioProcessorEditor (RapidSynthVstAudioProcessor&);
    ~RapidSynthVstAudioProcessorEditor();

    //==============================================================================
    CustomLookAndFeel customLookAndFeel;
    
    
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* button) override;
    void timerCallback() override;
    void targetMoved ();
    std::vector<double> normaliseMouseSpace(const juce::Point<int>& _position, const juce::Rectangle<int>& _area);
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioProcessorParameter* getParameter (const String& paramId);
    float                    getParameterValue (const String& paramId);
    void                     setParameterValue (const String& paramId, float value);
    
    /*** MACHINE LEARNING ***/
    // Rapid regression
    regression                   rapidRegression;
    std::vector<trainingExample> trainingSet;
    trainingExample              trainingExample1;
    trainingExample              trainingExample2;
    trainingExample              trainingExample3;
    trainingExample              trainingExample4;
    
    std::vector<double> example1Input, example2Input, example3Input, example4Input;
    
    std::vector<double> example1Output, example2Output, example3Output, example4Output;
    
    // Output Params
    double osc1FilterCutoff;
    double osc1Detune;
    double osc1Gain;
    double osc1ModFreq;
    double osc2FilterCutoff;
    double osc2Detune;
    double osc2Gain;
    double osc2ModFreq;
    double osc3FilterCutoff;
    double osc3Detune;
    double osc3Gain;
    double osc3ModFreq;
    double LFO1Freq;
    double LFO1Gain;
    double VCOCutoff;
    double masterGain;
    double ADSR1Attack;
    double ADSR1Decay;
    double ADSR1Sustain;
    double ADSR1Release;
//    bool osc1Sine;
//    bool osc1Saw;
//    bool osc1Square;
//    bool osc2Sine;
//    bool osc2Saw;
//    bool osc2Square;
//    bool osc3Sine;
//    bool osc3Saw;
//    bool osc3Square;
//    bool LFO1Sine;
//    bool LFO1Saw;
//    bool LFO1Square;
    double VCORes;
    
    // Program state
    bool                         button1Trained = false,
                                 button2Trained = false,
                                 button3Trained = false,
                                 button4Trained = false,
                                 trained = false;
    
    bool                         process;
    bool                         run = false; 

    juce::Rectangle<int>         drawingArea;
    SceneComponent scene;

    RapidSynthVstAudioProcessor& processor;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RapidSynthVstAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED

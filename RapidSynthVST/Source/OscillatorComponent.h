/*
  ==============================================================================

    OscillatorComponent.h
    Created: 6 Mar 2017 5:18:11pm
    Author:  Eliot Heath

  ==============================================================================
*/

#ifndef OSCILLATORCOMPONENT_H_INCLUDED
#define OSCILLATORCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
//==============================================================================
/** Custom Look And Feel subclasss.
 
 Simply override the methods you need to, anything else will be inherited from the base class.
 It's a good idea not to hard code your colours, use the findColour method along with appropriate
 ColourIds so you can set these on a per-component basis.
 */
struct CustomLookAndFeel    : public LookAndFeel_V1
{
    ///////////////////
    void drawRoundThumb (Graphics& g, const float x, const float y,
                         const float diameter, const Colour& colour, float outlineThickness)
    {
        const Rectangle<float> a (x, y, diameter, diameter);
        const float halfThickness = outlineThickness * 0.5f;
        
        Path p;
        p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);
        
        const DropShadow ds (Colours::black, 1, Point<int> (0, 0));
        ds.drawForPath (g, p);
        
        g.setColour (colour);
        g.fillPath (p);
        
        g.setColour (colour.brighter());
        g.strokePath (p, PathStrokeType (outlineThickness));
    }
    
    /////////////////////////
    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));
        
        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);
        
        const bool flatOnLeft   = button.isConnectedOnLeft();
        const bool flatOnRight  = button.isConnectedOnRight();
        const bool flatOnTop    = button.isConnectedOnTop();
        const bool flatOnBottom = button.isConnectedOnBottom();
        
        const float width  = button.getWidth() - 1.0f;
        const float height = button.getHeight() - 1.0f;
        
        if (width > 0 && height > 0)
        {
            const float cornerSize = jmin (15.0f, jmin (width, height) * 0.45f);
            const float lineThickness = cornerSize * 0.1f;
            const float halfThickness = lineThickness * 0.5f;
            
            Path outline;
            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
                                         cornerSize, cornerSize,
                                         ! (flatOnLeft  || flatOnTop),
                                         ! (flatOnRight || flatOnTop),
                                         ! (flatOnLeft  || flatOnBottom),
                                         ! (flatOnRight || flatOnBottom));
            
            const Colour outlineColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                                           : TextButton::textColourOffId));
            
            g.setColour (baseColour);
            g.fillPath (outline);
            
            if (! button.getToggleState())
            {
                g.setColour (outlineColour);
                g.strokePath (outline, PathStrokeType (lineThickness));
            }
        }
    }
    
    
    ////////////////
    void drawTickBox (Graphics& g, Component& component,
                      float x, float y, float w, float h,
                      bool ticked,
                      bool isEnabled,
                      bool isMouseOverButton,
                      bool isButtonDown) override
    {
        const float boxSize = w * 0.7f;
        
        bool isDownOrDragging = component.isEnabled() && (component.isMouseOverOrDragging() || component.isMouseButtonDown());
        const Colour colour (component.findColour (TextButton::buttonColourId).withMultipliedSaturation ((component.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                             .withMultipliedAlpha (component.isEnabled() ? 1.0f : 0.7f));
        
        drawRoundThumb (g, x, y + (h - boxSize) * 0.5f, boxSize, colour,
                        isEnabled ? ((isButtonDown || isMouseOverButton) ? 1.1f : 0.5f) : 0.3f);
        
        if (ticked)
        {
            const Path tick (LookAndFeel_V1::getTickShape (6.0f));
            g.setColour (isEnabled ? findColour (TextButton::buttonOnColourId) : Colours::grey);
            
            const float scale = 9.0f;
            const AffineTransform trans (AffineTransform::scale (w / scale, h / scale)
                                         .translated (x - 2.5f, y + 1.0f));
            g.fillPath (tick, trans);
        }
    }
    
    
    //////////////////////////
    void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) override
    {
        const float sliderRadius = (float) (getSliderThumbRadius (slider) - 2);
        
        bool isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
        Colour knobColour (slider.findColour (Slider::thumbColourId).withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f));
        
        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;
            
            if (style == Slider::LinearVertical)
            {
                kx = x + width * 0.5f;
                ky = sliderPos;
            }
            else
            {
                kx = sliderPos;
                ky = y + height * 0.5f;
            }
            
            const float outlineThickness = slider.isEnabled() ? 0.8f : 0.3f;
            
            drawRoundThumb (g,
                            kx - sliderRadius,
                            ky - sliderRadius,
                            sliderRadius * 2.0f,
                            knobColour, outlineThickness);
        }
        else
        {
            // Just call the base class for the demo
            LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    /////////////////////
    void drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle style, Slider& slider) override
    {
        g.fillAll (slider.findColour (Slider::backgroundColourId));
        
        if (style == Slider::LinearBar || style == Slider::LinearBarVertical)
        {
            const float fx = (float) x, fy = (float) y, fw = (float) width, fh = (float) height;
            
            Path p;
            
            if (style == Slider::LinearBarVertical)
                p.addRectangle (fx, sliderPos, fw, 1.0f + fh - sliderPos);
            else
                p.addRectangle (fx, fy, sliderPos - fx, fh);
            
            
            Colour baseColour (slider.findColour (Slider::rotarySliderFillColourId)
                               .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
                               .withMultipliedAlpha (0.8f));
            
            g.setColour (baseColour);
            g.fillPath (p);
            
            const float lineThickness = jmin (15.0f, jmin (width, height) * 0.45f) * 0.1f;
            g.drawRect (slider.getLocalBounds().toFloat(), lineThickness);
        }
        else
        {
            drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
            drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }
    
    //////////////////////////////
    void drawLinearSliderBackground (Graphics& g, int x, int y, int width, int height,
                                     float /*sliderPos*/,
                                     float /*minSliderPos*/,
                                     float /*maxSliderPos*/,
                                     const Slider::SliderStyle /*style*/, Slider& slider) override
    {
        const float sliderRadius = getSliderThumbRadius (slider) - 5.0f;
        Path on, off;
        
        if (slider.isHorizontal())
        {
            const float iy = y + height * 0.5f - sliderRadius * 0.5f;
            Rectangle<float> r (x - sliderRadius * 0.5f, iy, width + sliderRadius, sliderRadius);
            const float onW = r.getWidth() * ((float) slider.valueToProportionOfLength (slider.getValue()));
            
            on.addRectangle (r.removeFromLeft (onW));
            off.addRectangle (r);
        }
        else
        {
            const float ix = x + width * 0.5f - sliderRadius * 0.5f;
            Rectangle<float> r (ix, y - sliderRadius * 0.5f, sliderRadius, height + sliderRadius);
            const float onH = r.getHeight() * ((float) slider.valueToProportionOfLength (slider.getValue()));
            
            on.addRectangle (r.removeFromBottom (onH));
            off.addRectangle (r);
        }
        
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId));
        g.fillPath (on);
        
        g.setColour (slider.findColour (Slider::trackColourId));
        g.fillPath (off);
    }
    
    ////////////////////
//    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
//                           float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
//    {
//        const float radius = jmin (width / 2, height / 2) - 2.0f;
//        const float centreX = x + width * 0.5f;
//        const float centreY = y + height * 0.5f;
//        const float rx = centreX - radius;
//        const float ry = centreY - radius;
//        const float rw = radius * 2.0f;
//        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
//        const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
//        
//        if (slider.isEnabled())
//            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
//        else
//            g.setColour (Colour (0x80808080));
//        
//        {
//            Path filledArc;
//            filledArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, angle, 0.0);
//            g.fillPath (filledArc);
//        }
//        
//        {
//            const float lineThickness = jmin (15.0f, jmin (width, height) * 0.45f) * 0.1f;
//            Path outlineArc;
//            outlineArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, 0.0);
//            g.strokePath (outlineArc, PathStrokeType (lineThickness));
//        }
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
    {
        const auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        const auto fill    = slider.findColour (Slider::rotarySliderFillColourId);
        
        const auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);
        
        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        const auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin (8.0f, radius * 0.5f);
        auto arcRadius = radius - lineW * 0.5f;
        
        Path backgroundArc;
        backgroundArc.addCentredArc (bounds.getCentreX(),
                                     bounds.getCentreY(),
                                     arcRadius,
                                     arcRadius,
                                     0.0f,
                                     rotaryStartAngle,
                                     rotaryEndAngle,
                                     true);
        
        g.setColour (outline);
        g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        
        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc (bounds.getCentreX(),
                                    bounds.getCentreY(),
                                    arcRadius,
                                    arcRadius,
                                    0.0f,
                                    rotaryStartAngle,
                                    toAngle,
                                    true);
            
            g.setColour (fill);
            g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }
        
        const auto thumbWidth = lineW * 2.0f;
        const Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - float_Pi * 0.5f),
                                       bounds.getCentreY() + arcRadius * std::sin (toAngle - float_Pi * 0.5f));
        
        g.setColour (slider.findColour (Slider::thumbColourId));
        g.fillEllipse (Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    }
    
    
    
   
};




class OscillatorComponent    : public Component
{
public:
    OscillatorComponent()
    {
        setLookAndFeel(&customLookAndFeel);
        
        dial1.setSliderStyle (Slider::RotaryVerticalDrag);
        dial1.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial1.setRange (0, 1);
        dial1.setValue(0.5);
        addAndMakeVisible(dial1);
        
        addAndMakeVisible (dial1Label);
        dial1Label.setText ("Filter Cutoff", dontSendNotification);
        dial1Label.attachToComponent (&dial1, false);
        
        dial2.setSliderStyle (Slider::RotaryVerticalDrag);
        dial2.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial2.setRange (0, 1);
        dial2.setValue(0.5);
        addAndMakeVisible(dial2);
        
        addAndMakeVisible (dial2Label);
        dial2Label.setText ("Detune", dontSendNotification);
        dial2Label.attachToComponent (&dial2, false);
        
        dial3.setSliderStyle (Slider::RotaryVerticalDrag);
        dial3.setTextBoxStyle (Slider::TextBoxBelow, false, 0, 0);
        dial3.setRange (0, 1.0);
        dial3.setValue(1);
        addAndMakeVisible(dial3);
        
        addAndMakeVisible (dial3Label);
        dial3Label.setText ("Gain", dontSendNotification);
        dial3Label.attachToComponent (&dial3, false);
        
        addAndMakeVisible(sineButton);
        sineButton.setButtonText ("Si");
        
        addAndMakeVisible(sawButton);
        sawButton.setButtonText ("Sa");
        
        addAndMakeVisible(squareButton);
        squareButton.setButtonText ("Sq");
        
    }

    ~OscillatorComponent()
    {
    }

    void paint (Graphics& g) override
    {

//        g.fillAll (Colours::darkred);   // clear the background

//        g.setColour (Colours::white);
//        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    }

    void resized() override
    {
        
        int border = 7;
        auto r = getLocalBounds();
        auto titleArea = r.removeFromTop(50);
        int divisor = r.getHeight() / 3;
        int titleDivisor = titleArea.getWidth() / 3;
        auto dialArea = r;
        
        dial1.setBounds(dialArea.removeFromTop(divisor).reduced(border));
        dial3.setBounds(dialArea.removeFromBottom(divisor).reduced(border));
        dial2.setBounds(dialArea.reduced(border));
        
        sineButton.setBounds(titleArea.removeFromLeft(titleDivisor).reduced(border));
        squareButton.setBounds(titleArea.removeFromRight(titleDivisor).reduced(border));
        sawButton.setBounds(titleArea.reduced(border));
        
    }

    Slider dial1;
    Slider dial2;
    Slider dial3;
    
    Label dial1Label;
    Label dial2Label;
    Label dial3Label;
    
    TextButton sineButton;
    TextButton sawButton;
    TextButton squareButton;
    
    CustomLookAndFeel customLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};


#endif  // OSCILLATORCOMPONENT_H_INCLUDED

/*
 ==============================================================================
 
 CustomLookAndFeel.h
 Created: 30 Apr 2017 1:51:22am
 Author:  Eliot Heath
 
 ==============================================================================
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
struct CustomLookAndFeel : public LookAndFeel_V3
{
    static void drawButtonShape (Graphics& g, const Path& outline, Colour baseColour, float height)
    {
        const float mainBrightness = baseColour.getBrightness();
        const float mainAlpha = baseColour.getFloatAlpha();
        
        g.setGradientFill (ColourGradient (baseColour.brighter (0.2f), 0.0f, 0.0f,
                                           baseColour.darker (0.25f), 0.0f, height, false));
        g.fillPath (outline);
        
        g.setColour (Colours::white.withAlpha (0.4f * mainAlpha * mainBrightness * mainBrightness));
        g.strokePath (outline, PathStrokeType (1.0f), AffineTransform::translation (0.0f, 1.0f)
                      .scaled (1.0f, (height - 1.6f) / height));
        
        g.setColour (Colours::aliceblue.withAlpha (0.4f * mainAlpha));
        g.strokePath (outline, PathStrokeType (1.0f));
    }
    
//    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
//                                               bool isMouseOverButton, bool isButtonDown) override
//    {
//        Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
//                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));
//        
//        if (isButtonDown || isMouseOverButton)
//            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);
//        
//        const bool flatOnLeft   = button.isConnectedOnLeft();
//        const bool flatOnRight  = button.isConnectedOnRight();
//        const bool flatOnTop    = button.isConnectedOnTop();
//        const bool flatOnBottom = button.isConnectedOnBottom();
//        
//        const float width  = button.getWidth() - 1.0f;
//        const float height = button.getHeight() - 1.0f;
//        
//        if (width > 0 && height > 0)
//        {
//            const float cornerSize = 4.0f;
//            
//            Path outline;
//            outline.addRoundedRectangle (0.5f, 0.5f, width, height, cornerSize, cornerSize,
//                                         ! (flatOnLeft  || flatOnTop),
//                                         ! (flatOnRight || flatOnTop),
//                                         ! (flatOnLeft  || flatOnBottom),
//                                         ! (flatOnRight || flatOnBottom));
//            
//            drawButtonShape (g, outline, baseColour, height);
//        }
//    }
    
    //==============================================================================
//    void drawButtonBackground (Graphics& g,
//                               Button& button,
//                               const Colour& backgroundColour,
//                               bool isMouseOverButton,
//                               bool isButtonDown) override
//    {
//        const auto cornerSize = 6.0f;
//        const auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);
//        
//        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
//        .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);
//        
//        if (isButtonDown || isMouseOverButton)
//            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.05f);
//        
//        g.setColour (baseColour);
//        
//        if (button.isConnectedOnLeft() || button.isConnectedOnRight())
//        {
//            Path path;
//            path.addRoundedRectangle (bounds.getX(), bounds.getY(),
//                                      bounds.getWidth(), bounds.getHeight(),
//                                      cornerSize, cornerSize,
//                                      ! button.isConnectedOnLeft(),
//                                      ! button.isConnectedOnRight(),
//                                      ! button.isConnectedOnLeft(),
//                                      ! button.isConnectedOnRight());
//            
//            g.fillPath (path);
//            
////            g.setColour (button.findColour (ComboBox::outlineColourId));
//            g.strokePath (path, PathStrokeType (1.0f));
//        }
//        else
//        {
//            g.fillRoundedRectangle (bounds, cornerSize);
//            
////            g.setColour (button.findColour (ComboBox::outlineColourId));
//            g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
//        }
//    }
    
    void drawAlertBox (Graphics& g, AlertWindow& alert,
                       const Rectangle<int>& textArea, TextLayout& textLayout) override
    {
        const auto cornerSize = 4.0f;
        
        g.setColour (alert.findColour (AlertWindow::outlineColourId));
        g.drawRoundedRectangle (alert.getLocalBounds().toFloat(), cornerSize, 2.0f);
        
        const auto bounds = alert.getLocalBounds().reduced (1);
        g.reduceClipRegion (bounds);
        
        g.setColour (alert.findColour (AlertWindow::backgroundColourId));
        g.fillRoundedRectangle (bounds.toFloat(), cornerSize);
        
        auto iconSpaceUsed = 0;
        
        const auto iconWidth = 80;
        auto iconSize = jmin (iconWidth + 50, bounds.getHeight() + 20);
        
        if (alert.containsAnyExtraComponents() || alert.getNumButtons() > 2)
            iconSize = jmin (iconSize, textArea.getHeight() + 50);
        
        const Rectangle<int> iconRect (iconSize / -10, iconSize / -10,
                                       iconSize, iconSize);
        
        if (alert.getAlertType() != AlertWindow::NoIcon)
        {
            Path icon;
            char character;
            uint32 colour;
            
            if (alert.getAlertType() == AlertWindow::WarningIcon)
            {
                character = '!';
                
                icon.addTriangle (iconRect.getX() + iconRect.getWidth() * 0.5f, (float) iconRect.getY(),
                                  (float) iconRect.getRight(), (float) iconRect.getBottom(),
                                  (float) iconRect.getX(), (float) iconRect.getBottom());
                
                icon = icon.createPathWithRoundedCorners (5.0f);
                colour = 0x66ff2a00;
            }
            else
            {
                colour = Colour (0xff00b0b9).withAlpha (0.4f).getARGB();
                character = alert.getAlertType() == AlertWindow::InfoIcon ? 'i' : '?';
                
                icon.addEllipse (iconRect.toFloat());
            }
            
            GlyphArrangement ga;
            ga.addFittedText (Font (iconRect.getHeight() * 0.9f, Font::bold),
                              String::charToString ((juce_wchar) (uint8) character),
                              (float) iconRect.getX(), (float) iconRect.getY(),
                              (float) iconRect.getWidth(), (float) iconRect.getHeight(),
                              Justification::centred, false);
            ga.createPath (icon);
            
            icon.setUsingNonZeroWinding (false);
            g.setColour (Colour (colour));
            g.fillPath (icon);
            
            iconSpaceUsed = iconSize;
        }
        
        g.setColour (alert.findColour (AlertWindow::textColourId));
        
        const Rectangle<int> alertBounds (bounds.getX() + iconSpaceUsed,
                                          30,
                                          bounds.getWidth(),
                                          bounds.getHeight() - getAlertWindowButtonHeight() - 20);
        
        textLayout.draw (g, alertBounds.toFloat());
    }
    
    int getAlertWindowButtonHeight() override   { return 40; }
    Font getAlertWindowTitleFont() override    { return Font (18.0f, Font::FontStyleFlags::bold); }
    Font getAlertWindowMessageFont() override   { return Font (16.0f); }
    Font getAlertWindowFont() override       { return Font (14.0f); }
    
    
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        const auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
        const auto fill    = slider.findColour (Slider::rotarySliderFillColourId);
        
        const auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);
        
        auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
        const auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin (4.0f, radius * 0.5f);
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
    
    //==============================================================================
    Font getLabelFont (Label& label) override
    {
        return label.getFont();
    }
    
    void drawLabel (Graphics& g, Label& label) override
    {
        g.fillAll (label.findColour (Label::backgroundColourId));
        
        if (! label.isBeingEdited())
        {
            const float alpha = label.isEnabled() ? 1.0f : 0.5f;
            const Font font (getLabelFont (label));
            
            g.setColour (label.findColour (Label::textColourId).withMultipliedAlpha (alpha));
            g.setFont (font);
            
            Rectangle<int> textArea (label.getBorderSize().subtractedFrom (label.getLocalBounds()));
            
            g.drawFittedText (label.getText(), textArea, label.getJustificationType(),
                              jmax (1, (int) (textArea.getHeight() / font.getHeight())),
                              label.getMinimumHorizontalScale());
            
            
            g.setColour (label.findColour (Label::outlineColourId).withMultipliedAlpha (alpha));
        }
        else if (label.isEnabled())
        {
            g.setColour (label.findColour (Label::outlineColourId));
        }
        
        g.drawRect (label.getLocalBounds());
    }
    
};

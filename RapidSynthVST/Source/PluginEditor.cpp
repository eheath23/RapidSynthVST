/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
RapidSynthVstAudioProcessorEditor::RapidSynthVstAudioProcessorEditor (RapidSynthVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)

//masterGain(1),
//osc1Detune(0),
//osc2Detune(0),
//osc3Detune(0),
//osc1Gain(1),
//osc2Gain(1),
//osc3Gain(1),
//LFO1Gain(1),
//osc1FilterCutoff(0)
//osc2FilterCutoff(1),
//osc3FilterCutoff(1),
//VCOCutoff(1),
//VCORes(0),
//ADSR1Attack(0),
//ADSR1Decay(1),
//ADSR1Sustain(0),
//ADSR1Release(0),
//LFO1Freq(0)

{
    
    setSize (800, 600);
    
    addAndMakeVisible(scene);
    
    //OSC 1
    scene.oscScene.osc1.dial1.setName("osc1FilterCutoff");
    scene.oscScene.osc1.dial1.addListener (this);
    
    scene.oscScene.osc1.dial2.setName("osc1Detune");
    scene.oscScene.osc1.dial2.addListener (this);

    scene.oscScene.osc1.dial3.setName("osc1Gain");
    scene.oscScene.osc1.dial3.addListener (this);

    scene.oscScene.osc1.sineButton.setName("osc1Sine");
    scene.oscScene.osc1.sineButton.addListener(this);
    
    scene.oscScene.osc1.sawButton.setName("osc1Saw");
    scene.oscScene.osc1.sawButton.addListener(this);
    
    scene.oscScene.osc1.squareButton.setName("osc1Square");
    scene.oscScene.osc1.squareButton.addListener(this);
    
    //OSC 2
    scene.oscScene.osc2.dial1.setName("osc2FilterCutoff");
    scene.oscScene.osc2.dial1.addListener (this);
    
    scene.oscScene.osc2.dial2.setName("osc2Detune");
    scene.oscScene.osc2.dial2.addListener (this);
    
    scene.oscScene.osc2.dial3.setName("osc2Gain");
    scene.oscScene.osc2.dial3.addListener (this);
    
    scene.oscScene.osc2.sineButton.setName("osc2Sine");
    scene.oscScene.osc2.sineButton.addListener(this);
    
    scene.oscScene.osc2.sawButton.setName("osc2Saw");
    scene.oscScene.osc2.sawButton.addListener(this);
    
    scene.oscScene.osc2.squareButton.setName("osc2Square");
    scene.oscScene.osc2.squareButton.addListener(this);
    
    //OSC 3
    scene.oscScene.osc3.dial1.setName("osc3FilterCutoff");
    scene.oscScene.osc3.dial1.addListener (this);
    
    scene.oscScene.osc3.dial2.setName("osc3Detune");
    scene.oscScene.osc3.dial2.addListener (this);
    
    scene.oscScene.osc3.dial3.setName("osc3Gain");
    scene.oscScene.osc3.dial3.addListener (this);
    
    scene.oscScene.osc3.sineButton.setName("osc3Sine");
    scene.oscScene.osc3.sineButton.addListener(this);
    
    scene.oscScene.osc3.sawButton.setName("osc3Saw");
    scene.oscScene.osc3.sawButton.addListener(this);
    
    scene.oscScene.osc3.squareButton.setName("osc3Square");
    scene.oscScene.osc3.squareButton.addListener(this);

    //LFO 1
    scene.modScene.lfo.dial1.setName("LFO1Freq");
    scene.modScene.lfo.dial1.addListener (this);
    
    scene.modScene.lfo.dial2.setName("LFO1Gain");
    scene.modScene.lfo.dial2.addListener (this);

    scene.modScene.lfo.dial3.setName("masterGain");
    scene.modScene.lfo.dial3.addListener (this);
    
    scene.modScene.lfo.sineButton.setName("LFO1Sine");
    scene.modScene.lfo.sineButton.addListener(this);
    
    scene.modScene.lfo.sawButton.setName("LFO1Saw");
    scene.modScene.lfo.sawButton.addListener(this);
    
    scene.modScene.lfo.squareButton.setName("LFO1Square");
    scene.modScene.lfo.squareButton.addListener(this);

    //FILTER
    scene.modScene.filter.dial1.setName("VCOCutoff");
    scene.modScene.filter.dial1.addListener(this);
    
    scene.modScene.filter.dial2.setName("VCORes");
    scene.modScene.filter.dial2.addListener(this);
    
    //ENVELOPE
    scene.modScene.envelope.ADSR1Attack.setName("ADSR1Attack");
    scene.modScene.envelope.ADSR1Attack.addListener(this);
    
    scene.modScene.envelope.ADSR1Decay.setName("ADSR1Decay");
    scene.modScene.envelope.ADSR1Decay.addListener(this);
    
    scene.modScene.envelope.ADSR1Sustain.setName("ADSR1Sustain");
    scene.modScene.envelope.ADSR1Sustain.addListener(this);
    
    scene.modScene.envelope.ADSR1Release.setName("ADSR1Release");
    scene.modScene.envelope.ADSR1Release.addListener(this);
    
    //MACHINE LEARNING
    scene.XY.button1.setName("MLButton1");
    scene.XY.button1.addListener(this);
    
    scene.XY.button2.setName("MLButton2");
    scene.XY.button2.addListener(this);
    
    scene.XY.button3.setName("MLButton3");
    scene.XY.button3.addListener(this);
    
    scene.XY.button4.setName("MLButton4");
    scene.XY.button4.addListener(this);
    
    scene.XY.button5.setName("MLButtonTrain");
    scene.XY.button5.addListener(this);
    
    scene.XY.button6.setName("MLButtonRun");
    scene.XY.button6.addListener(this);
    
//    addAndMakeVisible(targetShape);
    
    //MACHINE LEARNING SETUP
    //BUTTON 1
//    trainingExample1.input = { (double)scene.XY.button1.getX(), (double)scene.XY.button1.getY() };
//    trainingExample1.output = { osc1FilterCutoff,
//         osc1Detune,
//         osc1Gain,
//         osc2FilterCutoff,
//         osc2Detune,
//         osc2Gain,
//         osc3FilterCutoff,
//         osc3Detune,
//         osc3Gain,
//         LFO1Freq,
//         LFO1Gain,
//         VCOCutoff,
//         masterGain,
//         ADSR1Attack,
//         ADSR1Decay,
//         ADSR1Sustain,
//         ADSR1Release,
//         VCORes };
//    
//    //BUTTON 2
//    trainingExample2.input = { (double)scene.XY.button2.getX(), (double)scene.XY.button2.getY() };
//    trainingExample2.output = { osc1FilterCutoff,
//        osc1Detune,
//        osc1Gain,
//        osc2FilterCutoff,
//        osc2Detune,
//        osc2Gain,
//        osc3FilterCutoff,
//        osc3Detune,
//        osc3Gain,
//        LFO1Freq,
//        LFO1Gain,
//        VCOCutoff,
//        masterGain,
//        ADSR1Attack,
//        ADSR1Decay,
//        ADSR1Sustain,
//        ADSR1Release,
//        VCORes };
//    
//    //BUTTON 3
//    trainingExample3.input = { (double)scene.XY.button3.getX(), (double)scene.XY.button3.getY() };
//    trainingExample3.output = { osc1FilterCutoff,
//        osc1Detune,
//        osc1Gain,
//        osc2FilterCutoff,
//        osc2Detune,
//        osc2Gain,
//        osc3FilterCutoff,
//        osc3Detune,
//        osc3Gain,
//        LFO1Freq,
//        LFO1Gain,
//        VCOCutoff,
//        masterGain,
//        ADSR1Attack,
//        ADSR1Decay,
//        ADSR1Sustain,
//        ADSR1Release,
//        VCORes };
//    
//    //BUTTON 4
//    trainingExample4.input = { (double)scene.XY.button4.getX(), (double)scene.XY.button4.getY() };
//    trainingExample4.output = { osc1FilterCutoff,
//        osc1Detune,
//        osc1Gain,
//        osc2FilterCutoff,
//        osc2Detune,
//        osc2Gain,
//        osc3FilterCutoff,
//        osc3Detune,
//        osc3Gain,
//        LFO1Freq,
//        LFO1Gain,
//        VCOCutoff,
//        masterGain,
//        ADSR1Attack,
//        ADSR1Decay,
//        ADSR1Sustain,
//        ADSR1Release,
//        VCORes };
    
//    trainingSet.resize(4);
//
//    trainingExample1.input.resize(2);
//    trainingExample1.output.resize(1);
//    trainingExample2.input.resize(2);
//    trainingExample2.output.resize(1);
//    trainingExample3.input.resize(2);
//    trainingExample3.output.resize(1);
//    trainingExample4.input.resize(2);
//    trainingExample4.output.resize(1);
    
//    trainingSet = { trainingExample1, trainingExample2, trainingExample3, trainingExample4 };
    
//    targetShape.setBounds(200, 200, 25, 25);
    
    startTimerHz(60);
    
    drawingArea = scene.XY.getLocalBounds();
}

RapidSynthVstAudioProcessorEditor::~RapidSynthVstAudioProcessorEditor()
{
}

//==============================================================================
void RapidSynthVstAudioProcessorEditor::paint (Graphics& g)
{

}

void RapidSynthVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto r = getLocalBounds();
    scene.setBounds(r);
}

//=======================================================================
AudioProcessorParameter* RapidSynthVstAudioProcessorEditor::getParameter (const String& paramId)
{
    if (AudioProcessor* processor = getAudioProcessor())
    {
        const OwnedArray<AudioProcessorParameter>& params = processor->getParameters();

        for (int i = 0; i < params.size(); ++i)
        {
            if (AudioProcessorParameterWithID* param = dynamic_cast<AudioProcessorParameterWithID*> (params[i]))
            {
                if (param->paramID == paramId)
                    return param;
            }
        }
    }

    return nullptr;
}

//=======================================================================
float RapidSynthVstAudioProcessorEditor::getParameterValue (const String& paramId)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        return param->getValue();

    return 0.0f;
}

//=======================================================================
void RapidSynthVstAudioProcessorEditor::setParameterValue (const String& paramId, float value)
{
    if (AudioProcessorParameter* param = getParameter (paramId))
        param->setValueNotifyingHost (value);
}

//=======================================================================
void RapidSynthVstAudioProcessorEditor::sliderValueChanged(Slider* slider){
    
    //OSC 1
    if (slider->getName() == "osc1FilterCutoff")
    {
//        double sliderVal = slider->getValue();
//        std::cout << sliderVal << std::endl;
        osc1FilterCutoff = (double)slider->getValue();
//        setParameterValue("osc1FilterCutoff", scene.oscScene.osc1.dial1.getValue());
//        setParameterValue("osc1FilterCutoff", osc1FilterCutoff);
    }
    if (slider->getName() == "osc1Detune")
    {
        osc1Detune = slider->getValue();
//        setParameterValue("osc1Detune", scene.oscScene.osc1.dial2.getValue());
        setParameterValue("osc1Detune", osc1Detune);
    }
    if (slider->getName() == "osc1Gain")
    {
        osc1Gain = slider->getValue();
//        setParameterValue("osc1Gain", scene.oscScene.osc1.dial3.getValue());
        setParameterValue("osc1Gain", osc1Gain);
    }
    
    //OSC 2
    if (slider->getName() == "osc2FilterCutoff")
    {
        osc2FilterCutoff = slider->getValue();
//        setParameterValue("osc2FilterCutoff", scene.oscScene.osc2.dial1.getValue());
        setParameterValue("osc2FilterCutoff", osc2FilterCutoff);
    }
    if (slider->getName() == "osc2Detune")
    {
        osc2Detune = slider->getValue();
//        setParameterValue("osc2Detune", scene.oscScene.osc2.dial2.getValue());
        setParameterValue("osc2Detune", osc2Detune);
    }
    if (slider->getName() == "osc2Gain")
    {
        osc2Gain = slider->getValue();
//        setParameterValue("osc2Gain", scene.oscScene.osc2.dial3.getValue());
        setParameterValue("osc2Gain", osc2Gain);
    }

    //OSC 3
    if (slider->getName() == "osc3FilterCutoff")
    {
        osc3FilterCutoff = slider->getValue();
//        setParameterValue("osc3FilterCutoff", scene.oscScene.osc3.dial1.getValue());
        setParameterValue("osc3FilterCutoff", osc3FilterCutoff);
    }

    if (slider->getName() == "osc3Detune")
    {
        osc3Detune = slider->getValue();
//        setParameterValue("osc3Detune", scene.oscScene.osc3.dial2.getValue());
        setParameterValue("osc3Detune", osc3Detune);
    }
    if (slider->getName() == "osc3Gain")
    {
        osc3Gain = slider->getValue();
//        setParameterValue("osc3Gain", scene.oscScene.osc3.dial3.getValue());
        setParameterValue("osc3Gain", osc3Gain);
    }

    //LFO
    if (slider->getName() == "LFO1Freq")
    {
        LFO1Freq = slider->getValue();
//        setParameterValue("LFO1Freq", scene.modScene.lfo.dial1.getValue());
        setParameterValue("LFO1Freq", LFO1Freq);
    }
    if (slider->getName() == "LFO1Gain")
    {
        LFO1Gain = slider->getValue();
//        setParameterValue("LFO1Gain", scene.modScene.lfo.dial2.getValue());
        setParameterValue("LFO1Gain", LFO1Gain);
    }
    
    //GAIN
    if (slider->getName() == "masterGain")
    {
        masterGain = slider->getValue();
//        setParameterValue("masterGain", scene.modScene.lfo.dial3.getValue());
        setParameterValue("masterGain", masterGain);
    }
    
    //FILTER
    if (slider->getName() == "VCOCutoff")
    {
        VCOCutoff = slider->getValue();
//        setParameterValue("VCOCutoff", scene.modScene.filter.dial1.getValue());
        setParameterValue("VCOCutoff", VCOCutoff);
    }
    if (slider->getName() == "VCORes")
    {
        VCORes = slider->getValue();
//        setParameterValue("VCORes", scene.modScene.filter.dial2.getValue());
        setParameterValue("VCORes", VCORes);
    }
    
    //ENVELOPE
    if (slider->getName() == "ADSR1Attack")
    {
        ADSR1Attack = slider->getValue();
//        setParameterValue("ADSR1Attack", scene.modScene.envelope.ADSR1Attack.getValue());
        setParameterValue("ADSR1Attack", ADSR1Attack);
    }
    if (slider->getName() == "ADSR1Decay")
    {
        ADSR1Decay = slider->getValue();
//        setParameterValue("ADSR1Decay", scene.modScene.envelope.ADSR1Decay.getValue());
        setParameterValue("ADSR1Decay", ADSR1Decay);
    }
    if (slider->getName() == "ADSR1Sustain")
    {
        ADSR1Sustain = slider->getValue();
//        setParameterValue("ADSR1Sustain", scene.modScene.envelope.ADSR1Sustain.getValue());
        setParameterValue("ADSR1Sustain", ADSR1Sustain);
    }
    if (slider->getName() == "ADSR1Release")
    {
        ADSR1Release = slider->getValue();
//        setParameterValue("ADSR1Release", scene.modScene.envelope.ADSR1Release.getValue());
        setParameterValue("ADSR1Release", ADSR1Release);
    }
    
}

//** BUTTONS **//
//=============================================================================
void RapidSynthVstAudioProcessorEditor:: buttonClicked (Button* button)
{
    //OSC 1
    if (button->getName() == "osc1Sine")
    {
        setParameterValue("osc1Sine", true);
        setParameterValue("osc1Saw", false);
        setParameterValue("osc1Square", false);

    } else if (button->getName() == "osc1Saw")
    {
        setParameterValue("osc1Saw", true);
        setParameterValue("osc1Sine", false);
        setParameterValue("osc1Square", false);
        
    } else if (button->getName() == "osc1Square")
    {
        setParameterValue("osc1Square", true);
        setParameterValue("osc1Saw", false);
        setParameterValue("osc1Sine", false);

    }
    
    //OSC 2
    if (button->getName() == "osc2Sine")
    {
        setParameterValue("osc2Sine", true);
        setParameterValue("osc2Saw", false);
        setParameterValue("osc2Square", false);


    } else if (button->getName() == "osc2Saw")
    {
        setParameterValue("osc2Saw", true);
        setParameterValue("osc2Sine", false);
        setParameterValue("osc2Square", false);

    } else if (button->getName() == "osc2Square")
    {
        setParameterValue("osc2Square", true);
        setParameterValue("osc2Saw", false);
        setParameterValue("osc2Sine", false);

    }
    
    //OSC 3
    if (button->getName() == "osc3Sine")
    {
        setParameterValue("osc3Sine", true);
        setParameterValue("osc3Saw", false);
        setParameterValue("osc3Square", false);
        
    } else if (button->getName() == "osc3Saw")
    {
        setParameterValue("osc3Saw", true);
        setParameterValue("osc3Sine", false);
        setParameterValue("osc3Square", false);

    } else if (button->getName() == "osc3Square")
    {
        setParameterValue("osc3Square", true);
        setParameterValue("osc3Saw", false);
        setParameterValue("osc3Sine", false);

    }
    
    //LFO 1
    if (button->getName() == "LFO1Sine")
    {
        setParameterValue("LFO1Sine", true);
        setParameterValue("LFO1Saw", false);
        setParameterValue("LFO1Square", false);
    } else if (button->getName() == "LFO1Saw")
    {
        setParameterValue("LFO1Saw", true);
        setParameterValue("LFO1Sine", false);
        setParameterValue("LFO1Square", false);
    } else if (button->getName() == "LFO1Square")
    {
        setParameterValue("LFO1Square", true);
        setParameterValue("LFO1Sine", false);
        setParameterValue("LFO1Saw", false);
    }
    
    //MACHINE LEARNING
    if (button->getName() == "MLButton1")
    {
//        trainingExample1.input = { (double)scene.XY.button1.getX(), (double)scene.XY.button1.getY() };
        std::vector<double> input =  normaliseMouseSpace(scene.XY.button1.getScreenPosition(), drawingArea);
        
        trainingExample1.input = {input[0], input[1]};
        trainingExample1.output = { (double)osc1FilterCutoff
//            osc1Detune,
//            osc1Gain,
//            osc2FilterCutoff,
//            osc2Detune,
//            osc2Gain,
//            osc3FilterCutoff,
//            osc3Detune,
//            osc3Gain,
//            LFO1Freq,
//            LFO1Gain,
//            VCOCutoff,
//            masterGain,
//            ADSR1Attack,
//            ADSR1Decay,
//            ADSR1Sustain,
//            ADSR1Release,
//            VCORes
        };
        
//        trainingSet[0] = trainingExample1;
        trainingSet.push_back(trainingExample1);
        button1Trained = true;
        
        std::cout << "Button 1 Stored" << std:: endl;

    }
    
    else if (button->getName() == "MLButton2")
    {
//        trainingExample2.input = { (double)scene.XY.button2.getX(), (double)scene.XY.button2.getY() };
        
        std::vector<double> input =  normaliseMouseSpace(scene.XY.button2.getScreenPosition(), drawingArea);
        
        trainingExample2.input = {input[0], input[1]};
        
        trainingExample2.output = { (double)osc1FilterCutoff
//            osc1Detune,
//            osc1Gain,
//            osc2FilterCutoff,
//            osc2Detune,
//            osc2Gain,
//            osc3FilterCutoff,
//            osc3Detune,
//            osc3Gain,
//            LFO1Freq,
//            LFO1Gain,
//            VCOCutoff,
//            masterGain,
//            ADSR1Attack,
//            ADSR1Decay,
//            ADSR1Sustain,
//            ADSR1Release,
//            VCORes
        };
        
//        trainingSet[1] = trainingExample2;
        trainingSet.push_back(trainingExample2);
        button2Trained = true;
        
        std::cout << "Button 2 Stored" << std:: endl;

   
    }
    
    else if (button->getName() == "MLButton3")
    {
//        trainingExample3.input = { (double)scene.XY.button3.getX(), (double)scene.XY.button3.getY() };
        
        std::vector<double> input =  normaliseMouseSpace(scene.XY.button3.getScreenPosition(), drawingArea);
        
        trainingExample3.input = {input[0], input[1]};
        
        trainingExample3.output = { (double)osc1FilterCutoff
//            osc1Detune,
//            osc1Gain,
//            osc2FilterCutoff,
//            osc2Detune,
//            osc2Gain,
//            osc3FilterCutoff,
//            osc3Detune,
//            osc3Gain,
//            LFO1Freq,
//            LFO1Gain,
//            VCOCutoff,
//            masterGain,
//            ADSR1Attack,
//            ADSR1Decay,
//            ADSR1Sustain,
//            ADSR1Release,
//            VCORes
        };
        
//        trainingSet[2] = trainingExample3;
        trainingSet.push_back(trainingExample3);
        button3Trained = true;
        
        std::cout << "Button 3 Stored" << std:: endl;

        
    }
    
    else if (button->getName() == "MLButton4")
    {
//        trainingExample4.input = { (double)scene.XY.button4.getX(), (double)scene.XY.button4.getY() };
        
        std::vector<double> input =  normaliseMouseSpace(scene.XY.button4.getScreenPosition(), drawingArea);
        
        trainingExample4.input = {input[0], input[1]};
        
        trainingExample4.output = { (double)osc1FilterCutoff
//            osc1Detune,
//            osc1Gain,
//            osc2FilterCutoff,
//            osc2Detune,
//            osc2Gain,
//            osc3FilterCutoff,
//            osc3Detune,
//            osc3Gain,
//            LFO1Freq,
//            LFO1Gain,
//            VCOCutoff,
//            masterGain,
//            ADSR1Attack,
//            ADSR1Decay,
//            ADSR1Sustain,
//            ADSR1Release,
//            VCORes
        };
        
//        trainingSet[3] = trainingExample4;
        trainingSet.push_back(trainingExample4);
        button4Trained = true;
        
        std::cout << "Button 4 Stored" << std:: endl;

        
    }
    
    else if (button->getName() == "MLButtonTrain")
    {
        if(button1Trained && button2Trained && button3Trained && button4Trained)
        {
//            trainingSet = { trainingExample1, trainingExample2, trainingExample3, trainingExample4 };
            trained = rapidRegression.train(trainingSet);
//            trained = true;
            std::cout << "Trained = " << trained << std::endl;

        }
    }
    
    else if (button->getName() == "MLButtonRun")
    {
        run = !run;
        std::cout << "running = " << run << std::endl;
    }
}

void RapidSynthVstAudioProcessorEditor::targetMoved()
{
    std::vector<double> input =  normaliseMouseSpace(scene.XY.targetShape.getScreenPosition(), drawingArea);

//    std::vector<double> input = { (double)scene.XY.targetShape.getX(), (double)scene.XY.targetShape.getY() };
    
    std::vector<double> output = rapidRegression.process(input);
    
    double nosc1FilterCutoff = output[0];
    //                double nosc1Detune = output[1];
    //                double nosc1Gain = output[2];
    //                double nosc2FilterCutoff = output[3];
    //                double nosc2Detune = output[4];
    //                double nosc2Gain = output[5];
    //                double nosc3FilterCutoff = output[6];
    //                double nosc3Detune = output[7];
    //                double nosc3Gain = output[8];
    //                double nLFO1Freq = output[9];
    //                double nLFO1Gain = output[10];
    //                double nVCOCutoff = output[11];
    //                double nmasterGain = output[12];
    //                double nADSR1Attack = output[13];
    //                double nADSR1Decay = output[14];
    //                double nADSR1Sustain = output[15];
    //                double nADSR1Release = output[16];
    //                double nVCORes = output[17];
    
    std::cout << "nosc1FilterCutoff = " << nosc1FilterCutoff << std::endl;
    
    //OSC 1
    if(!isnan(nosc1FilterCutoff))
    {
        scene.oscScene.osc1.dial1.setValue(nosc1FilterCutoff);
    }
    //                scene.oscScene.osc1.dial2.setValue(nosc1Detune, dontSendNotification);
    //                scene.oscScene.osc1.dial3.setValue(nosc1Gain, dontSendNotification);
    //
    //                //OSC 2
    //                scene.oscScene.osc2.dial1.setValue(nosc2FilterCutoff, dontSendNotification);
    //                scene.oscScene.osc2.dial2.setValue(nosc2Detune, dontSendNotification);
    //                scene.oscScene.osc2.dial3.setValue(nosc2Gain, dontSendNotification);
    //
    //                //OSC 3
    //                scene.oscScene.osc3.dial1.setValue(nosc3FilterCutoff, dontSendNotification);
    //                scene.oscScene.osc3.dial2.setValue(nosc3Detune, dontSendNotification);
    //                scene.oscScene.osc3.dial3.setValue(nosc3Gain, dontSendNotification);
    //
    //                //LFO 1
    //                scene.modScene.lfo.dial1.setValue(nLFO1Freq, dontSendNotification);
    //                scene.modScene.lfo.dial2.setValue(nLFO1Gain, dontSendNotification);
    //                scene.modScene.lfo.dial3.setValue(nmasterGain, dontSendNotification);
    //
    //                //FILTER
    //                scene.modScene.filter.dial1.setValue(nVCOCutoff, dontSendNotification);
    //                scene.modScene.filter.dial2.setValue(nVCORes, dontSendNotification);
    //
    //                //ENVELOPE
    //                scene.modScene.envelope.ADSR1Attack.setValue(nADSR1Attack, dontSendNotification);
    //                scene.modScene.envelope.ADSR1Decay.setValue(nADSR1Decay, dontSendNotification);
    //                scene.modScene.envelope.ADSR1Sustain.setValue(nADSR1Sustain, dontSendNotification);
    //                scene.modScene.envelope.ADSR1Release.setValue(nADSR1Release, dontSendNotification);
    
}

void RapidSynthVstAudioProcessorEditor::timerCallback()
{
    if(scene.XY.targetShape.myDragger.isDragging)
    {
        if(trained)
        {
            if(run)
            {
                targetMoved();
            }
        }
    }
}

std::vector<double> RapidSynthVstAudioProcessorEditor::normaliseMouseSpace(const juce::Point<int>& _position, const juce::Rectangle<int>& _area)
{
    juce::Point<int> pos = _area.getConstrainedPoint(_position);
    std::vector<double> temp;
    temp.resize(2);
    temp[0] = double(double(pos.getX() - _area.getX()) / _area.getWidth());
    temp[1] = double(double(pos.getY() - _area.getY()) / _area.getHeight());
    return temp;
}




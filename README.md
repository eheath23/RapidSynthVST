IS53043A Computing: Major Project
33333759 - Eliot Heath

Find included:
- Documentation
- RapidSynthVST

Dissertation report and Weekly Logs can be found in Documentation

RapidSynthVST is the final working software. 
In order to open the synthesiser:
- Open RapidSynthVST.jucer
- Choose XCode as the selected exporter
- Press Save and Open in IDE
- In XCode, the easiest way to compile and use the synth is by using JUCE Plugin Host, which can be found in the JUCE Examples, under audio plugin host
- Compile the audio plugin host
- In RapidSynthVST, change the build scheme to use Plugin Host as the executable
- When you run code, once the Plugin Host opens, scan for new or updated audio components
- Create plugin, choose RapidSynthVST
- Connect midi input, and audio outputs
- Double click on the RapidSynthVST to open the interface

All other files are included in the repository to show progress, but are non-essential. 

VSTExample was a collaboration with Leon Fedden. He showed me how to use VST with JUCE, and that was an example we built together so he could teach me how it works. 

# UniversalTransmitter

This is an open-source, Arduino-based handheld transmitter. This handheld transmitter can be used in any robotics application that requires user input (i.e., RC car, RC airplane, robotic arm, etc.) and includes the following features:

- Teensy 4.1 microcontroller
- 2.3" TFT touchscreen
- Lanyard clip
- 1 3.5mm buddy box signal jack
  - Only tested with a Flysky FS-i6X
- 2 RC joystick gimbals
- Joystick trim buttons
- 2 general analog knobs
- 5 toggle switches
- 1 tri-state switch
- 1 speaker
  - Can be controlled with a DFPlayerMini or I2S
  - 1 volume knob
- 2 power supplies
  - Can use battery pack or external power via 5.5mm barrel jack
  - 1 power supply select switch
- ESP866 WiFi module
- NRF24 2.4GHz RF module
- BLE or classic BT module slot
- RS485 external interface via 2 RJ45 jacks
  - Can use this to communicate with external serial radios (i.e., RFD900+ modules)
- Channel mixing
- Channel expo
- Channel reversing

For software examples, there is a sketch for testing basic functionality of the various features found at `.\examples\example`. Additionally, there is a much more complex sketch with advanced software and configuration features found at `.\examples\complex_example`.

Also, the case is 3D printed (ABS or ASA filament preferred). The 3D parts can be found in the `.\extras\print_files` folder. If you want to easily remix any of the pieces, you can use a copy of the original Blend file found at `.\extras\Universal_Transmitter.blend`.

Lastly, the PCBs can be made using the gerber files found at `.\extras\gerber_files`.

![1](extras/docs/1.jpg)
![2](extras/docs/2.jpg)
![3](extras/docs/3.jpg)
![5](extras/docs/5.jpg)
![6](extras/docs/6.jpg)
![Main PCB Schematic](extras/docs/Final_Main_PCB_Schematic-1.png "Main PCB Schematic")
![Main PCB Board](extras/docs/Final_Main_PCB_Board-1.png "Main PCB Board")
![RS485 Interface PCB Schematic](extras/docs/Final_RS485_PCB_Schematic-1.png "RS485 Interface PCB Schematic")
![RS485 Interface PCB Board](extras/docs/Final_RS485_PCB_Board-1.png "RS485 Interface PCB Board")

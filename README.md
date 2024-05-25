Fixed FFT Spectrum Analyzer
This project is a Fixed Fast Fourier Transform (FFT) Spectrum Analyzer built using an Arduino Nano, a 0.96" OLED display, and a MAX9814 microphone module. The analyzer visualizes audio frequencies captured by the microphone in real-time on the OLED display.

Table of Contents
Introduction
Components
Circuit Diagram
Code
How It Works
Installation
Usage
License
Introduction
The Fixed FFT Spectrum Analyzer is a tool that displays the frequency spectrum of audio signals captured by the MAX9814 microphone. This project leverages the FFT algorithm to convert the time-domain audio signal into its frequency components, which are then displayed on the OLED screen.

Components
Arduino Nano
0.96" OLED display (I2C)
MAX9814 microphone module
Breadboard and jumper wires
Capacitors and resistors (as needed for the microphone module)
Power supply (USB or battery)
Circuit Diagram
Below is the basic connection diagram for the project:

MAX9814:

VCC to 5V on Arduino
GND to GND on Arduino
OUT to A0 on Arduino
OLED Display:

VCC to 5V on Arduino
GND to GND on Arduino
SCL to A5 on Arduino
SDA to A4 on Arduino
Code
The Arduino code for this project includes setting up the FFT algorithm, capturing audio data from the MAX9814, processing it, and displaying the frequency spectrum on the OLED display.

Here's an outline of the code:

Include necessary libraries:

Adafruit_GFX.h and Adafruit_SSD1306.h for the OLED display
arduinoFFT.h for the FFT processing
Define pins and settings:

Pin definitions for the microphone and OLED
Constants for FFT settings (e.g., number of samples)
Setup function:

Initialize the OLED display
Configure the microphone input pin
Setup Serial for debugging (if needed)
Loop function:

Capture audio samples
Perform FFT on the samples
Map the FFT output to the display height
Display the frequency spectrum on the OLED
The full code is available in the repository. Make sure to download and install the required libraries before uploading the code to your Arduino Nano.

How It Works
Audio Signal Capture: The MAX9814 microphone captures audio signals and converts them to analog signals, which are read by the Arduino Nano through its analog input pin.

Sampling: The Arduino Nano samples the analog signal at a specific sampling rate. These samples are stored in an array for FFT processing.

FFT Processing: The FFT algorithm processes the time-domain audio samples to extract their frequency components. This converts the raw audio data into a frequency spectrum.

Display: The processed frequency data is then mapped to the height of bars on the OLED display, creating a visual representation of the audio frequency spectrum.

Installation
Clone the repository:

sh
Copy code
git clone https://github.com/yourusername/fft-spectrum-analyzer.git
Install required libraries:

Adafruit_GFX
Adafruit_SSD1306
arduinoFFT
These libraries can be installed via the Arduino Library Manager.

Upload the code:
Open the Arduino IDE, load the provided sketch (fft_spectrum_analyzer.ino), and upload it to your Arduino Nano.

Usage
Power the Arduino: Connect the Arduino Nano to your computer or power it using a battery.
Observe the Display: The OLED display will show the real-time frequency spectrum of the audio signals captured by the MAX9814 microphone.
License
This project is licensed under the MIT License. See the LICENSE file for more details.


# Fixed FFT Spectrum Analyzer

This project is a Fixed Fast Fourier Transform (FFT) Spectrum Analyzer built using an Arduino Nano, a 0.96" OLED display, and a MAX9814 microphone module. The analyzer visualizes audio frequencies captured by the microphone in real time on the OLED display.

## Table of Contents

- [Introduction](#introduction)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Code](#code)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

The Fixed FFT Spectrum Analyzer is a tool that displays the frequency spectrum of audio signals captured by the MAX9814 microphone. This project leverages the FFT algorithm to convert the time-domain audio signal into its frequency components, which are then displayed on the OLED screen.

## Components

- Arduino Nano
- 0.96" OLED display (I2C)
- MAX9814 microphone module
- Breadboard and jumper wires
- 1x Capacitor and resistors (as needed for the microphone module)
- Power supply (USB or battery)

## Circuit Diagram

Below is the basic connection diagram for the project:
![image](https://github.com/RattleBrattle/Fixed-FFT-Spectrum-Analyzer/assets/105577389/b1ecabe8-d506-494d-bcfa-d48acf13201f)


- **MAX9814**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - OUT to A0 on Arduino

- **OLED Display**:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - SCL to A5 on Arduino
  - SDA to A4 on Arduino

## Code

The Arduino code for this project includes setting up the FFT algorithm, capturing audio data from the MAX9814, processing it, and displaying the frequency spectrum on the OLED display.

Here's an outline of the code:

1. **Include necessary libraries**: 
   - `Adafruit_GFX.h` and `Adafruit_SSD1306.h` for the OLED display
   - `fix_fft.h` for the FFT processing

2. **Define pins and settings**:
   - Pin definitions for the microphone and OLED
   - Constants for FFT settings (e.g., number of samples)

3. **Setup function**:
   - Initialize the OLED display
   - Configure the microphone input pin
   - Setup Serial for debugging (if needed)

4. **Loop function**:
   - Capture audio samples
   - Perform the FFT library function on the samples
   - Map the FFT output to the display height
   - Display the frequency spectrum on the OLED

The full code is available in the repository. Make sure to download and install the required libraries before uploading the code to your Arduino Nano.

## How It Works

1. **Audio Signal Capture**: The MAX9814 microphone captures audio signals and converts them to analog signals, which are read by the Arduino Nano through its analog input pin.

2. **Sampling**: The Arduino Nano samples the analog signal at a specific sampling rate (at 9615 Hz to be specific). These samples are stored in an array for FFT processing.

3. **FFT Processing**: The FFT algorithm processes the time-domain audio samples to extract their frequency components. This converts the raw audio data into a frequency spectrum.

4. **Display**: The processed frequency data is then mapped to the height of bars on the OLED display, creating a visual representation (Vertical bars on the arduino) of the audio frequency spectrum.

## Installation

1. **Install required libraries**:
   - `Adafruit_GFX`
   - `Adafruit_SSD1306`
   - `fix_fft`
   - 'wire'

   These libraries can be installed via the Arduino Library Manager.

## Usage

1. **Power the Arduino**: Connect the Arduino Nano to your computer or power it using a battery.
2. **Observe the Display**: The OLED display will show the real-time frequency spectrum of the audio signals captured by the MAX9814 microphone.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

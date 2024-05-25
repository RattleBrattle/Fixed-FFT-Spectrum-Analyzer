  //Including the necessary libraries
  #include "fix_fft.h"
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>

  Adafruit_SSD1306 display(128, 64, &Wire, 4); //Initiliazing OLED display unit.
  
  //Defining necessary arrays for the fft function.
  char im[128], data[128]; char x = 0, ylim = 60; int i = 0, val;
 
  void setup()
  {
    Serial.begin(9600);
    pinMode(A0, INPUT);
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.clearDisplay();
    analogReference(DEFAULT);
  }

  void loop()
  {
    int min=1024, max=0;
    for (i=0; i <128; i++)     //take 128 samples
    {
      val = analogRead(A0);
      data[i] = val/4 - 128;
      im[i] = 0;
      if(val>max) max=val;    //store max & min sample
      if(val<min) min=val;
    }
  
  //Calling the fixed FFT function to perform the operation.
  fix_fft(data, im, 7, 0);   

  display.clearDisplay();

  //Loop to draw bars on OLED display
  for (i=1; i<64; i++) 
  {
    int dat = sqrt(data[i] * data[i] + im[i] * im[i]);
    display.drawLine(i*2 + x, ylim, i*2 + x, ylim - dat, WHITE);
  }
  display.setCursor(0,0); display.print("  Spectrum Analyzer");
  display.display();
}
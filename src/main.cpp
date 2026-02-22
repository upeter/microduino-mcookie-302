
//Include the required libraries to control the ColorLED
//Based on: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library
#include <Microduino_ColorLED.h>

#define buzzer_pin 4 //Define buzzer driving pin 
#define buzzer_fre 600 //Define buzzer output frequency 

//Define the pin the ColorLED is connected to
const int COLORLED_PIN = 6;


//Define the number of ColorLEDs daisy chained together
const int COLORLED_NUM = 1;

//Declare and initialize the ColorLED object
ColorLED strip = ColorLED(COLORLED_NUM, COLORLED_PIN);

void setup() {
  // put your setup code here, to run once:

  //Initial serial communication port at 9600 baud
  Serial.begin(9600);

 pinMode(buzzer_pin,OUTPUT);
  //Initialize the ColorLED class object
  strip.begin();

  //Initialize all ColorLEDs to 'off'
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

  //Configure the first ColorLED to maximum red
  strip.setPixelColor(0, 255, 0, 0);
  //Set the ColorLED
  strip.show();

  //wait 1 second
  delay(500);

  //Configure the first ColorLED to maximum green
  strip.setPixelColor(0, 0, 255, 0);
  //Set the ColorLED
  strip.show();

  //wait 1 second
  delay(500);

  //Configure the first ColorLED to maximum blue
  strip.setPixelColor(0, 0, 0, 255);
  //Set the ColorLED
  strip.show();

  //wait 1 second
//   delay(1000);
//    for(int i=200;i<=800;i++) { //Increase the frequency from 200HZ to 800HZ in a circular manner.   
//     tone(buzzer_pin,i);    //Output frequency in N0.6 port. 
//     delay(5);      //The frequency lasts for 5ms. 
//   }
//   delay(2000);     //The highest frequency lasts for 2s.
//   for(int i=800;i>=200;i--)
//   {
//     tone(buzzer_pin,i);
//     delay(10); //The frequency lasts for 10ms. 
//   }
}
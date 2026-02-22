/*
 1.The vibration motor works only when the battery gets connected.
 2.Here are the core modules supporting PWM control: Microduino Core+,Microduino Core USB,Microduino Core RF
 */

#include <Arduino.h>
#include <Microduino_ColorLED.h>

#define Pin_X A1
#define Pin_Y A0

const int COLORLED_PIN = 6;
const int COLORLED_NUM = 1;
const int JOY_TOLERANCE = 20;

const int CENTER_X = 1023;
const int CENTER_Y = 1023;
const int UP_X = 750;
const int UP_Y = 760;
const int DOWN_X = 340;
const int DOWN_Y = 350;
const int LEFT_X = 540;
const int LEFT_Y = 550;
const int RIGHT_X = 910;
const int RIGHT_Y = 920;

enum Direction {
  DIR_CENTER,
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT,
  DIR_UNKNOWN
};

ColorLED strip = ColorLED(COLORLED_NUM, COLORLED_PIN);
Direction lastDirection = DIR_UNKNOWN;

bool isNear(int value, int target) {
  return abs(value - target) <= JOY_TOLERANCE;
}

Direction detectDirection(int x, int y) {
  if (isNear(x, CENTER_X) && isNear(y, CENTER_Y)) return DIR_CENTER;
  if (isNear(x, UP_X) && isNear(y, UP_Y)) return DIR_UP;
  if (isNear(x, DOWN_X) && isNear(y, DOWN_Y)) return DIR_DOWN;
  if (isNear(x, LEFT_X) && isNear(y, LEFT_Y)) return DIR_LEFT;
  if (isNear(x, RIGHT_X) && isNear(y, RIGHT_Y)) return DIR_RIGHT;
  return DIR_UNKNOWN;
}

void setLedForDirection(Direction direction) {
  switch (direction) {
    case DIR_CENTER:
      strip.setPixelColor(0, 255, 255, 255);
      break;
    case DIR_UP:
      strip.setPixelColor(0, 0, 0, 255);
      break;
    case DIR_DOWN:
      strip.setPixelColor(0, 255, 255, 0);
      break;
    case DIR_LEFT:
      strip.setPixelColor(0, 0, 255, 0);
      break;
    case DIR_RIGHT:
      strip.setPixelColor(0, 255, 0, 0);
      break;
    default:
      strip.setPixelColor(0, 0, 0, 0);
      break;
  }
  strip.show();
}

void setup() {
  Serial.begin(115200);    //Serial initializing 
  pinMode(Pin_X,INPUT);
  pinMode(Pin_Y,INPUT);

  strip.begin();
  setLedForDirection(DIR_CENTER);
}

void loop() {
  int sensorValueX = analogRead(Pin_X);      //X-axis input 
  int sensorValueY = analogRead(Pin_Y);      //Y-axis input 
  Direction direction = detectDirection(sensorValueX, sensorValueY);

  if (direction != lastDirection) {
    setLedForDirection(direction);
    lastDirection = direction;
  }

  Serial.print("ValueX:");
  Serial.print(sensorValueX);
  Serial.print(",");
  Serial.print("ValueY:");
  Serial.print(sensorValueY);
  Serial.print(",Dir:");
  switch (direction) {
    case DIR_CENTER:
      Serial.println("CENTER");
      break;
    case DIR_UP:
      Serial.println("UP");
      break;
    case DIR_DOWN:
      Serial.println("DOWN");
      break;
    case DIR_LEFT:
      Serial.println("LEFT");
      break;
    case DIR_RIGHT:
      Serial.println("RIGHT");
      break;
    default:
      Serial.println("UNKNOWN");
      break;
  }
  delay(100);
}
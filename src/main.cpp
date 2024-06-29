#include <Arduino.h>

#include "M5Atom.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>

int pos0[] = {85,85,90,80};         //Trimming
int pos180[] = {525,530,535,525};   //Trimming

const uint16_t ServoMinTicks = 102; // ancho de pulso en ticks para pocicion 0°
const uint16_t ServoMaxTicks = 512; // ancho de pulso en ticks para la pocicion 180°

// #define POS0_0    102 
// #define POS0_180  512 
// #define POS1_0    102 
// #define POS1_180  542 

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0X40);

// Declaración de la función:
//void set_servo(int8_t n_servo, int angulo, int16_t pos0, int16_t pos180);
void set_servo(uint8_t n_servo, int angulo);

void setup() {
  // inicio puerto serie
  M5.begin(true, true,true);  // Init Atom-Matrix(Initialize serial port, LED matrix).
  Serial.begin(115200);
  
  Serial.print("Pruebas con PCA9685");

  servos.begin();
  servos.setPWMFreq(SERVO_FREQ);
}

void loop() {
  
  set_servo(0,0);
  set_servo(1,180);
  set_servo(2,0);
  set_servo(3,180);
  M5.dis.fillpix(0xFFFFFF);
  Serial.println("set_servo(x,0)");
  delay(1000);
  set_servo(0,90);
  set_servo(1,90);
  set_servo(2,90);
  set_servo(3,90);

  M5.dis.fillpix(0xFF0000);
  Serial.println("set_servo(0,90)");
  delay(1000);
  set_servo(0,180);
  set_servo(1,0);
  set_servo(2,180);
  set_servo(3,0);
  M5.dis.fillpix(0x00FF00);
  Serial.println("set_servo(0,180)");
  delay(1000);
  set_servo(0,90);
  set_servo(1,90);
  set_servo(2,90);
  set_servo(3,90);
  M5.dis.fillpix(0xFF0000);
  Serial.println("set_servo(0,90)");
  delay(1000);

  
  // Calibracion  
  //  servos.setPWM(0,0,102);
  //  delay(1000);
  //  servos.setPWM(0,0,525);
  //  delay(1000);

}

// Definición de la función:
void set_servo(uint8_t n_servo, int angulo) {
  
  int duty;
  duty=map(angulo,0,180,pos0[n_servo], pos180[n_servo]);
  servos.setPWM(n_servo, 0, duty);
  
  // for (uint16_t duty = pos0[n_servo]; duty < pos180[n_servo]; duty++){
  // servos.setPWM(n_servo, 0, duty);
  // delay(2);
  // }

}
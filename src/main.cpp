#include <Arduino.h>

#include "M5Atom.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>

#define POS0_0    102 
#define POS0_180  512 
#define POS1_0    102 
#define POS1_180  542 
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0X40);

// Declaración de la función:
void set_servo(int8_t n_servo, int angulo, int16_t pos0, int16_t pos180);

void setup() {
  // inicio puerto serie
  M5.begin(true, true,true);  // Init Atom-Matrix(Initialize serial port, LED matrix).
  //Wire.begin(25,21); 
  Serial.begin(115200);
  Serial.print("Pruebas con PCA9685");

  servos.begin();
  servos.setPWMFreq(SERVO_FREQ);


}

void loop() {
  set_servo(0,0,POS0_0,POS0_180);
  set_servo(1,0,POS1_0,POS1_180);
  M5.dis.fillpix(0xFFFFFF);
  Serial.println("set_servo(x,0)");
  delay(1000);
  set_servo(0,90,POS0_0,POS0_180);
  set_servo(1,90,POS1_0,POS1_180);
  M5.dis.fillpix(0xFF0000);
  Serial.println("set_servo(0,90)");
  delay(1000);
  set_servo(0,180,POS0_0,POS0_180);
  set_servo(1,180,POS1_0,POS1_180);
  M5.dis.fillpix(0x00FF00);
  Serial.println("set_servo(0,180)");
  delay(1000);
  set_servo(0,90,POS0_0,POS0_180);
  set_servo(1,90,POS1_0,POS1_180);
  M5.dis.fillpix(0xFF0000);
  Serial.println("set_servo(0,90)");
  delay(1000);
}

// Definición de la función:
void set_servo(int8_t n_servo, int angulo, int16_t pos0, int16_t pos180)
{
 int duty;
 duty = map (angulo, 0, 180, pos0, pos180);
 servos.setPWM(n_servo, 0, duty);
}

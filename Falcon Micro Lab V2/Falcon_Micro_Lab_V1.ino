//--------------------------------------------------------------
// Falcon Micro Lab V1 
// (c) All property and design belongs to SUTD
// Created by Declan Ng
//  
//  General Comments for next Iteration:
//  1. The BMS pin does not lie on an ADC
//  2.
//
//
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
// Library Imports:

#include <WiFi.h>               // WiFi Communication Library
#include <PubSubClient.h>       // MQTT Communication Library
#include <Adafruit_NeoPixel.h>  // LED Library

//--------------------------------------------------------------
// LED Definitions:

#define LED_PIN 32
#define LED_COUNT 2
#define BRIGHTNESS 200

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

//--------------------------------------------------------------
// Motor Driver Inputs on ESP32:

const int M1A = 25;
const int M1B = 33;
const int M2A = 22;
const int M2B = 21;
const int M3A = 19;
const int M3B = 18;
const int M4A = 27;
const int M4B = 26;

// Motor PWM Settings for Basic locomotion:

const int freq = 1000;
const int resolution = 8;

int motorState = 0;
int motorSpeed = 150;

// Motor PWM Settings for Lift:

int climbState = 0;
int climbSpeed1 = 190;
int climbSpeed2 = 250;

//---------------------------------------------------------------
// Network settings:

const char* ssid = "SUTD_LAB";
//const char* password = "sutd1234";
const char* mqttServer = "10.21.131.9";
const int   mqttPort = 1883;
const char* mqttUser = "sutd";
const char* mqttPassword = "sutdmqtt";

//---------------------------------------------------------------
// MQTT Communication Settings:

bool callback_status = false;
WiFiClient espClient;
PubSubClient client(espClient);

String cmd_vel;
String cmd_cli;


//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------

// Main Code:


void setup() {

  init_ser();
  init_vbat();
  init_led();
  init_md();
  init_wifi();

}

void loop() {

  client.loop();
  
  led_on();
  bms();
  motion();
  
  delay(100);

}


/*******************************************************************
 * 
 * Written by Mithi Sevilla | MAY 12, 2016 | http://mithi.xyz
 * 
 *******************************************************************/

#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

/********************************************
 * PIN CONSTANTS
 ********************************************/

#define PIN_PIXELS 5
#define PIN_PIEZO 13
#define PIN_TRIG 6
#define PIN_ECHO 7

const int PIN_LINE_LEFT = A8;
const int PIN_LINE_RIGHT = A9;
const int PIN_LIGHT_LEFT = A1;
const int PIN_LIGHT_RIGHT = A0;

/********************************************
 * PIXELS CONSTANTS
 ********************************************/

#define PIXEL_NUM 4

#define LEFT_MOST_PIX 0
#define LEFT_CENTER_PIX 1
#define RIGHT_CENTER_PIX 2
#define RIGHT_MOST_PIX 3

const byte RED = 0;         //200 
const byte ORANGE = 1;      //210 
const byte YELLOW = 2;      //220 
const byte GREEN = 3;       //020
const byte BLUE = 4;        //002
const byte PURPLE = 5;      //202 
const byte PINK = 6;        //201 
const byte AQUA = 7;        //021
const byte WHITE = 8;       //222 
const byte LIME = 9;        //120
const byte INDIGO = 10;     //102 
const byte TEAL = 11;       //012
const byte TURQUOISE = 12;  //022
const byte OFF_PIX = 13;    //000

const byte MAX_COLOR_NUM = 13;


/********************************************
 * PIEZO CONSTANTS
 ********************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NO_TONE 0

/********************************************
 * PIXELS
 ********************************************/

class Pixels{
  public:
    void enable();
    void set(byte p, byte r, byte g, byte b);
    void left_most(byte r, byte g, byte b);
    void left_center(byte r, byte g, byte b);
    void right_center(byte r, byte g, byte b);
    void right_most(byte r, byte g, byte b);
    void color(byte pixel_name, byte color_name);
};

/********************************************
 * PIEZO
 ********************************************/

class Piezo{
  public: 
    void enable();
    void play_tone(unsigned int frequency, unsigned int duration);
};

/********************************************
 * ANALOG READINGS 
 ********************************************/

class AnalogReadings{
  int left_pin;
  int right_pin;
   
  public: 
    void enable(int l, int r);
    int value(int p);
    int left();
    int right();
};

/********************************************
 * PING (distance) 
 ********************************************/

class Ping{
  
  public:
    void enable();
    long duration();
    long inches();
    long centimeters();
};

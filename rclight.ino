#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

uint32_t off = strip.Color(0,0,0);
uint32_t white = strip.Color(255,255,255);
uint32_t blue = strip.Color(0,0,255);
uint32_t red = strip.Color(255,0,0);
uint32_t orange = strip.Color(255,140,0);

int ch1;

void setup() {
  pinMode(2, INPUT);
  normal();
  strip.begin();
  strip.show();
}

void setp(int pix, uint32_t col) {
  strip.setPixelColor(pix-1, col);
}


void loop() {
    ch1 = pulseIn(2, HIGH, 25000); // Read the pulse width of 
    if (ch1 < 1200) {
      normal();
    } else if (ch1 < 1600) {
      strobo();
    } else {
      police();
    }

}


void normal() {
    setp(1,white);
    setp(2,white);
    setp(3,orange);
    setp(4,orange);
    setp(5,white);
    setp(6,white);
    setp(7,red);
    setp(8,orange);
    setp(9,orange);
    setp(10,red);
    strip.show();
    delay(500);
}


void strobo() {
    setp(1,white);
    setp(2,blue);
    setp(3,orange);
    setp(4,orange);
    setp(5,blue);
    setp(6,white);
    setp(7,red);
    setp(8,orange);
    setp(9,orange);
    setp(10,red);
    strip.show();
    delay(30);
    setp(1,off);
    setp(2,off);
    setp(3,off);
    setp(4,off);
    setp(5,off);
    setp(6,off);
    setp(7,off);
    setp(8,off);
    setp(9,off);
    setp(10,off);
    strip.show();
    delay(50);
}



void police() {
    setp(1,red);
    setp(2,white);
    setp(3,blue);
    setp(4,red);
    setp(5,white);
    setp(6,blue);
    setp(7,red);
    setp(8,red);
    setp(9,blue);
    setp(10,red);
    strip.show();
    delay(80);
    setp(3,blue);
    setp(8,red);
    setp(9,blue);
    setp(4,red);
        strip.show();
    delay(20);
    setp(3,off);
    setp(8,off);
    setp(9,off);
    setp(4,off);
        strip.show();
    delay(50);
    setp(3,blue);
    setp(8,red);
    setp(9,blue);
    setp(4,red);
        strip.show();
    delay(20);
    setp(3,off);
    setp(8,off);
    setp(9,off);
    setp(4,off);
    setp(1, blue);
    setp(6,red);
    strip.show();
    delay(80);
    setp(3,red);
    setp(8,blue);
    setp(9,red);
    setp(4,blue);
        strip.show();
    delay(20);
    setp(3,off);
    setp(8,off);
    setp(9,off);
    setp(4,off);
        strip.show();
    delay(80);
    setp(3,red);
    setp(8,blue);
    setp(9,red);
    setp(4,blue);
        strip.show();
    delay(20);
    setp(3,off);
    setp(8,off);
    setp(9,off);
    setp(4,off);
        strip.show();
}



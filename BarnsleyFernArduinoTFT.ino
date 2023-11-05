#include <SPI.h> // f.k. for Arduino-1.5.2
#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>

#define BLACK   0x0000
#define GREEN   0x07E0

#define W 240
#define H 320

MCUFRIEND_kbv tft;

float x = 0.0f, y = 0.0f;

void setup() {
  Serial.begin(9600);
  Serial.print("Barnsley fern on TFT with ID:0x");
  uint16_t id = tft.readID();
  Serial.println(id, HEX);

  tft.reset();
  tft.begin(id);

  tft.fillScreen(BLACK);
}

void loop() {
  long r = random(0, 100);
  float xn, yn;
  if (r<=1) {
    xn = 0.0f;
    yn = 0.16f * y;
  }
  else if (r<=86) {
    xn = 0.85f * x + 0.04f * y;
    yn = -0.04f * x + 0.85f * y + 1.6f;
  }
  else if (r<=93) {
    xn = 0.2f * x - 0.26f * y;
    yn = 0.23f * x + 0.22f * y + 1.6f;
  }
  else {
    xn = -0.15f * x + 0.28f * y;
    yn = 0.26f * x + 0.24f * y + 0.44f;
  }
  x = xn; y = yn;

  tft.drawPixel((int16_t)(W * (1.0f - (x + 2.2f) / 5.0f)), (int16_t)(H * y / 10.0f), GREEN);
}

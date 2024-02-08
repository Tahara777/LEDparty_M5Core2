#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>
#define PIN 26 
#define NUMPIXELS 10 //LEDの数を指定
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //800kHzでNeoPixelを駆動

void setup() {
  pixels.begin(); //NeoPixelの初期化
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(3);
}

void loop() {
  pixels.clear(); // NeoPixelのリセット

  for(int i=0; i<9;i++){
    pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // i番目に緑を設定
    pixels.show();   //LEDに色を反映
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("LED Sample %d",i);
    delay(1000); //1000ms待機
  }
}
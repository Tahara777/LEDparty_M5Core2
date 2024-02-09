#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>
#define PIN 26 
#define NUMPIXELS 5 //LEDの数を指定
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //800kHzでNeoPixelを駆動

int cnt = 0;

void setup() {
  pixels.begin(); //NeoPixelの初期化
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(3);

}

void loop() {

  for(int i=0; i<NUMPIXELS;i++){//光が流れる演出
    pixels.clear(); // NeoPixelのリセット
    pixels.setPixelColor(i, pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定
    pixels.setBrightness(60);// 0~255の範囲で明るさを設定 
    pixels.show();   //LEDに色を反映
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("LED Sample %d",i);
    delay(100); //100ms待機
    cnt +=1;
  }
}
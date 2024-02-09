#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>
#define PIN 26 
#define NUMPIXELS 21 //LEDの数を指定
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //800kHzでNeoPixelを駆動

int cnt = 0;

//LED番号再割り当て
int thumbLine[5] = {2,1,0};
int indexFingerLine[5] = {7,6,5,4,3};
int middleFingerLine[5] = {8,9,10,11,12};
int ringFingerLine[5] = {17,16,15,14,13};
int littleFingerLine[5] = {18,19,20};

void setup() {
  pixels.begin(); //NeoPixelの初期化
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(3);

}

void loop() {

  for(int i=0; i<NUMPIXELS;i++){//光が流れる演出
    pixels.clear(); // NeoPixelのリセット
    
    pixels.setPixelColor(thumbLine[i], pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定
    pixels.setPixelColor(indexFingerLine[i], pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定
    pixels.setPixelColor(middleFingerLine[i], pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定
    pixels.setPixelColor(ringFingerLine[i], pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定
    pixels.setPixelColor(littleFingerLine[i], pixels.Color(cnt/2, cnt/3, cnt)); // i番目の色を設定

    pixels.setBrightness(60);// 0~255の範囲で明るさを設定 
    pixels.show();   //LEDに色を反映
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("LED Sample %d",i);
    delay(100); //100ms待機
    cnt +=1;
  }
}
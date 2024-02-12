#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>
#define PIN 26 
#define NUMPIXELS 21 //LEDの数を指定
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //800kHzでNeoPixelを駆動

#define Fingertip2WristMode = 1
#define Wrist2FingertipMode = 2
#define ChargeMode = 3
void Fingertip2Wrist(int cntP, int cntL);

int mode = 1;

int cntL = 0;//光演出のカウント
int cntP = 0;//LEDの場所のカウント

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
    switch(mode){
      case 1:
        Fingertip2Wrist(cntP, cntL);
      break;
  
      default:
        break;
    }
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("LED Sample %d, %d",cntP,cntL);
    delay(100); //100ms待機

    cntL +=1;
    cntP +=1;
    if(cntP >= 5){
      cntP = 0;
    }
    if(cntL >= 250){
      cntL = 0;
    }  
}

void Fingertip2Wrist(int cntP_a, int cntL_a){
  pixels.clear(); // NeoPixelのリセット
  if(cntP_a < 2){
    pixels.setPixelColor(indexFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(middleFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(ringFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
  }
  else{
    pixels.setPixelColor(thumbLine[cntP_a - 2], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(indexFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(middleFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(ringFingerLine[cntP_a], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
    pixels.setPixelColor(littleFingerLine[cntP_a - 2], pixels.Color(cntL_a/2, cntL_a/3, cntL_a)); // i番目の色を設定
  }
    pixels.setBrightness(60);// 0~255の範囲で明るさを設定 
    pixels.show();   //LEDに色を反映

    delay(100);

}
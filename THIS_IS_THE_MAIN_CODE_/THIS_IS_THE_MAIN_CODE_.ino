#include <Adafruit_ILI9340.h>

// Henry's Bench
//  Adafruit GFX drawPixel

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

int16_t x = 220;
int16_t y = 176;
int sensorValue = 0;
int ByteReceived;
int lastnumber=0;
int beats=0;
Adafruit_ILI9340 tft = Adafruit_ILI9340(10,9, 8);

//void drawPixel(uint16_t x, uint16_t y, uint16_t color);


// Pallete - Where you assign names to colors you like
#define BACKCOLOR 0x000000 // Black
#define PIXELCOLOR 0x5dd6ee // White

#define CS 10
#define DC 9

void setup() {
  
  tft.begin();
  tft.fillScreen(BACKCOLOR);
  tft.drawPixel(50,50,PIXELCOLOR);
   Serial.begin(9600);  
}

void loop(){   
  // 128 represents screen width
  beats=0;
  for(int x = 0; x < 248; x++){
    lastnumber= sensorValue;
    sensorValue = analogRead(A0);
    if ((lastnumber<565) && (sensorValue>565))
    {
     beats=beats+1;
      }
    tft.drawPixel(x,300-(100+(150.0*(sensorValue/1024.0))), PIXELCOLOR);
    delay(5);  // increase to make the dot move slower.  Decrease to move faster
    //tft.drawPixel(x,100+(75.0*(sensorValue/1024.0)), BACKCOLOR);
    Serial.println(sensorValue); 
    delay(10);
    
  }
  tft.fillScreen(BACKCOLOR);//cut off =800
tft.setTextColor(ILI9340_GREEN);
tft.setTextSize(3);
tft.setCursor(89,200);
tft.println("BPM");
tft.setTextColor(ILI9340_WHITE);
tft.setCursor(95,230);
tft.println(beats*10);

if(beats*10<40) {
  tft.setCursor(35,270);
  tft.setTextColor(ILI9340_RED);
tft.setTextSize(2);
  tft.println("WHERE IS 911?!?");
}
if((beats*10>30) && (beats*10<60)) {
  tft.setCursor(25,270);
  tft.setTextColor(ILI9340_YELLOW);
tft.setTextSize(2);
  tft.println("YOU'RE QUITE FIT!");
}
if((beats*10>60) && (beats*10<90)) {
  tft.setCursor(55,270);
  tft.setTextColor(ILI9340_BLUE);
tft.setTextSize(2);
  tft.println("OH, LOOK WHO'S PERFECT...");
}
if((beats*10<120) && (beats*10>80)) {
  tft.setCursor(45,270);
  tft.setTextColor(ILI9340_BLUE);
tft.setTextSize(2);
  tft.println("BEEN DOING SOME RUNNING EH?");
} 
 if(beats*10>110) {
  tft.setCursor(25,270);
  tft.setTextColor(ILI9340_RED);
tft.setTextSize(1);
  tft.println("CUT DOWN ON THE COFFEE BUDDY!");
}
}

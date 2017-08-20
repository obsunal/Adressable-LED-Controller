#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
/* At default this code will open 1st fan red all leds instantly
 * then 2nd fan red with 0,25 sec delay between each led
 * after that 3rd fan turns into red with half second delay between each led
 * then all go black with the different delays
 * again opens green, closes again
 * opens blue, closes
 * After blue it closes fans with 1 sec delay between each one.
 * with the order of 3 -> 2 -> 1
 * 
 * Writen by obsunal. Can contact me via akirpi41@gmail.com.
 * Used adafruit's beautifull library. Check it out here: https://github.com/adafruit/Adafruit_NeoPixel
 * Any help appreciated. If you feel generous consider donating.
 * 
 * FUTURE UPGRADES
 * 1) Will add more animations.
 * 2) Will add switches for animation changes.
 * 3) Will add 2 more regular RGB support and fan support.
 * 5) We don't forth here. :)
 * 6) Will add lcd screen support. (If I could ever, make i2c to cooperate.)
 * 7) Will add software animation support. (May have to change to processing code.)
 * 
 * 
 */
#define PIN0 4        //Data in pin for fan 1
#define PIN1 5        //Data in pin for fan 2
#define PIN2 6        //Data in pin for fan 3
#define LED_COUNT 12 //Number of leds in a fan

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds0 = Adafruit_NeoPixel(LED_COUNT, PIN0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel leds1 = Adafruit_NeoPixel(LED_COUNT, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel leds2 = Adafruit_NeoPixel(LED_COUNT, PIN2, NEO_GRB + NEO_KHZ800);

void setup()  {
  leds0.begin();  // Call this to start up the LEDs in fan 1.
  leds1.begin();  // Call this to start up the LEDs in fan 2.
  leds2.begin();  // Call this to start up the LEDs in fan 3.
  Serial.begin(9600);
    clearLEDs(leds0);   // This function, defined below, turns all LEDs off...
    leds.show(leds0);   // ...but the LEDs don't actually update until you call this.
    clearLEDs(leds1);
    leds.show(leds1);
    clearLEDs(leds2);
    leds.show(leds2);
}
void loop() {
  onebyone(leds0, 0xff0000, 0);     //type of animation(which fan, color, delay time between each change)
  onebyone(leds1, 0xff0000, 250);   //last value 3rd and more values will be animation specific.
  onebyone(leds2, 0xff0000, 500);   //colors in form of standard html hex codes
  delay(1000);                      //find the color you want here;
  onebyone(leds0, 0x000000, 250);   //https://www.w3schools.com/colors/colors_picker.asp
  onebyone(leds1, 0x000000, 500);
  onebyone(leds2, 0x000000, 0);
  delay(1000);
  onebyone(leds0, 0x00ff00, 500);
  onebyone(leds1, 0x00ff00, 0);
  onebyone(leds2, 0x00ff00, 250);
  delay(1000);
  onebyone(leds0, 0x000000, 0);
  onebyone(leds1, 0x000000, 250);
  onebyone(leds2, 0x000000, 500);
  delay(1000);
  onebyone(leds0, 0x0000ff, 250);
  onebyone(leds1, 0x0000ff, 500);
  onebyone(leds2, 0x0000ff, 0);
  delay(1000);
  onebyone(leds0, 0x000000, 500);
  onebyone(leds1, 0x000000, 0);
  onebyone(leds2, 0x000000, 250);
  delay(1000);
  onebyone(leds0, 0xffffff, 500);
  onebyone(leds1, 0xffffff, 0);
  onebyone(leds2, 0xffffff, 250);
  delay(1000);
  clearLEDs(leds2);
  delay(1000);
  clearLEDs(leds1);
  delay(1000);
  clearLEDs(leds0);
  delay(1000);
}
void clearLEDs(int x)  {
  for (int i = 0; i < LED_COUNT; i++) {
    x.setPixelColor(i, 0);
  }
  Serial.println("Cleared" x);    //debug purposes
}
void onebyone (int x, int color,int wait) {
  Serial.println("onebyone start for " x "color: " color "delay: " wait);   //debug purposes
  for (int i = 0; i<LEDCOUNT; i++)  {
    Serial.println(i);
    x.setPixelColor(i, color);
    x.show();
    delay(wait);
  }
  Serial.println("onebyone done for " x "color: " color "delay: " wait);    //debug purpuses
}


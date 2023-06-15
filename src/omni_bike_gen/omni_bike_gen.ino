#include <singleLEDLibrary.h>
#include <OneButton.h>
#define BUTTON_PIN 4
#define LED_PIN 5

sllib led(LED_PIN);
sllib led2(LED_BUILTIN);
boolean clicked;
OneButton btn = OneButton(BUTTON_PIN, true);

void setup() {
  clicked = false;
  Serial.begin(9600);              
  pinMode(LED_PIN, OUTPUT);          
  pinMode(LED_BUILTIN, OUTPUT);
  btn.attachClick(clickEvent);
  btn.attachDoubleClick(doubleClickEvent);
  btn.attachLongPressStart(holdEvent);
}

void loop() {
  btn.tick();
  led.update();
  led2.update();
  delay(10);
}

//=================================================
// Events to trigger

void clickEvent() {
   Serial.println("short click");
   if (clicked==true) {
      Serial.println("state is true, setting it to false");
      clicked=false;
      led.setOffSingle();
      led2.setOffSingle();

   } else {
    Serial.println("state is false, setting it to true");
    clicked=true;
    led.setFlickerSingle();
    led2.setFlickerSingle();
   } 
}
void doubleClickEvent() {
   Serial.println("doubleclick");
   led.setBlinkSingle(100);
   led2.setBlinkSingle(100);
   clicked=true;
}
void holdEvent() {
   Serial.println("hold");
   led.setBreathSingle(1500);
   led2.setBreathSingle(1500);
   clicked=true;
}

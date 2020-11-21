
#include <Arduino.h>
#include <TM1637Display.h>
#define TEST_DELAY   2000
// Module connection pins (Digital Pins)
#define CLK 6
#define DIO 7
int speed1 = A0;
const int buttonPin = 2;     // the number of the pushbutton pin
int motor = 0;
int enB = 3;
int in3 = 5;
int in4 = 4;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };
  TM1637Display display(CLK, DIO);
void setup()
{
Serial.begin (9600);
  pinMode(speed1, INPUT);  
 pinMode(enB, OUTPUT);
  pinMode(buttonPin, INPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
}
void loop()
{
   int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
  display.setBrightness(0x0f);

 

    buttonState = digitalRead(buttonPin);
   speed1 = analogRead(A0);
  speed1 = speed1 * 0.2492668622;
  analogWrite(enB, speed1);
 display.showNumberDec(speed1, true);
     delay(200);
  
  if (buttonState != lastButtonState) {
  
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
            digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 
    
    } else {
          
           digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
   
    
            digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  } else {
 


  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }

}
  

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define trigPin 3
#define echoPin 2
// Define variables:
long duration;
int distance;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);
  Serial.begin(9600);
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
}
void loop() {

  int sensor=analogRead(A0); // Incoming analog signal read and appointed water depth sensor

  digitalWrite(echoPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(trigPin, HIGH);
  // Calculate the distance:
  distance = duration*0.034 / 2;
  
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  
  delay(1000);
  lcd.clear();

    if (sensor<200)
    {
      
      lcd.setCursor(0,0);
      lcd.print("Warning !!!");
      lcd.setCursor(0,1);
      lcd.print("Refill Sanitizer");
    }
    else{
      lcd.setCursor(0,0);
      lcd.print("Sanitizer level");
      lcd.setCursor(0,1);
      lcd.print("OK");
      
      
    }
  
  
}

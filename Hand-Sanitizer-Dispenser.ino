#include <LiquidCrystal_I2C.h>

#define trigPin 3
#define echoPin 2
#define npn 5
long duration;
int distanceCm, distanceInch;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(npn, OUTPUT);
  //initialize lcd screen
  lcd.init();
  // // turn on the backlight
  lcd.backlight();
}

void loop() {

  int sensor = analogRead(A0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  Serial.println(distanceCm);
  Serial.println(distanceCm);


  lcd.clear();

  if (sensor < 200)
  {

    lcd.setCursor(0, 0);
    lcd.print("Warning !!!");
    lcd.setCursor(0, 1);
    lcd.print("Refill Sanitizer");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("Sanitizer level");
    lcd.setCursor(0, 1);
    lcd.print("OK");


  }
  if (distanceCm <= 12 and distanceCm > 0)
  {
    digitalWrite(npn, HIGH);
    delay(1000);
    digitalWrite(npn, LOW);



  }
  else
  {
    digitalWrite(npn, LOW);
  }

  delay(100);
}

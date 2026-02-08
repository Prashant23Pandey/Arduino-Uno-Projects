#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 8;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;); 
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  Serial.begin(9600);
  Serial.println("ECOMITRA System Initialized...");
  delay(2000); 
}void loop() {
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  display.clearDisplay();
  display.setCursor(0, 0);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance >= 5 && distance <= 10) {
    display.setTextSize(1);
    display.println("MEDICINE DETECTED:PARACETAMOL Mgf.Date: AUG 2025 Expiry Date: JUL 2028");
    display.print("Dist: "); display.print(distance); display.println("cm");
    Serial.println("Dose Confirmed. The ECOMITRA system has successfully logged the administration of Paracetamol.");
    tone(buzzer, 1000, 200);
  } 
  else if (distance > 10 && distance <= 20) {
    display.setTextSize(1);
    display.println("MEDICINE DETECTED: ZERODOL-SP Mgf.Date: AUG 2025 Expiry Date: JUL 2028");
    display.print("Dist: "); display.print(distance); display.println("cm");
    Serial.println("Dose Confirmed. The ECOMITRA system has successfully logged the administration of Zerodol-SP.");
    tone(buzzer, 800, 200);
  } 
  else if (distance > 20 && distance <= 30) {
    display.println("OLD CLOTH DETECTED");
    display.print(distance); display.println(" cm");
    Serial.println("OLD CLOTH HAS BEEN DETECTED! These clothes have been verified and are officially ready to be delivered to our nearest NGO partners for the upcoming distribution drive.");
    tone(buzzer, 600, 200);
  }
  else if (distance > 30 && distance <= 40) {
    display.println("LEFTOVER FOOD DETECTED");
    display.print(distance); display.println(" cm");
    Serial.println("Using ECOMITRA , we’ve identified surplus food ready for relocation. Instead of letting it go to waste, we are routing it to those who need it most.");
    tone(buzzer, 400, 200);
  }
  else { 
    display.setTextSize(1);
    display.println("ECOMITRA Scanning...");
    display.print("Distance: "); display.println(distance); display.println("cm");
  }
  display.display();
  delay(500);
}
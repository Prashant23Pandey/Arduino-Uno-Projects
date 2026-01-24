int value = 0;  
int data = A0;   
void setup() { 
  pinMode(data, INPUT);
  Serial.begin(9600);   
} 
void loop() { 
  value = analogRead(data);   
  if (value<=100)
   { 
    Serial.println("Water Level: Empty"); 
  } 
  else if (value>100   && value<=400)
  { 
    Serial.println("Water Level: Low"); 
  } 
   else if (value>400 && value<=450)
  { 
    Serial.println("Water Level:   Medium"); 
  } 
  else if (value>450){ 
    Serial.println("Water Level:   High"); 
  }
  delay(1000); 
}
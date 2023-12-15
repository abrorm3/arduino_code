
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 32, 16 columns and 2 rows

  int PIRsensor= 12;
  int pirState = LOW;             // we start, assuming no motion detected
  int val = 0;  
  int streetLight1 = 9;
  int streetLight2 = 8;
  int streetLight3 = 7;

  int greenLight = 6;
  int yellowLight = 5;
  int redLight = 10;

  int button = 2;

  void setup() {
    delay(5000);
    lcd.init(); // Initialize lcd                    
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Initializing ...");
    delay(1000);
    lcd.clear();
    pinMode(PIRsensor, INPUT); // Set pin 11 as INPUT, where the PIR sensor is connected
    pinMode(streetLight1, OUTPUT);
    pinMode(streetLight2, OUTPUT);
    pinMode(streetLight3, OUTPUT); // Set pin 9 as OUTPUT, where an LED or another output device is connected
    pinMode(greenLight, OUTPUT); // Green light
    pinMode(yellowLight, OUTPUT); // Yellow light
    pinMode(redLight, OUTPUT); // Red light
    pinMode(button, INPUT) ; // Button
    Serial.begin(9600); //TESTING, DELETE LATER
  }
  void loop() {
    // Serial.println(digitalRead(button)); //TESTING, DELETE LATER
    // Serial.println(PIRsensor);
    val = digitalRead(PIRsensor);
    lcd.setCursor(0, 0); // Set the cursor to the first column and first row
    digitalWrite(greenLight, HIGH);
    // Serial.println("OUT"); //TESTING, DELETE LATER
    if(digitalRead(button) == HIGH){
      Serial.println("IN"); //TESTING, DELETE LATER
      digitalWrite(greenLight, LOW);
      digitalWrite(yellowLight, HIGH);
      delay(1000);
      digitalWrite(yellowLight, LOW);
      digitalWrite(redLight, HIGH);
      lcd.clear();
      for (int i = 15; i >=0; i--)
        {
        lcd.print(i);
        digitalWrite(streetLight1, HIGH);
        digitalWrite(streetLight2, HIGH);
        digitalWrite(streetLight3, HIGH);
        delay(1000);
        lcd.clear();
        };
      lcd.clear();
      digitalWrite(streetLight1, LOW);
      digitalWrite(streetLight2, LOW);
      digitalWrite(streetLight3, LOW);
      digitalWrite(redLight, LOW);
      digitalWrite(yellowLight, HIGH);
      delay(1000);
      digitalWrite(yellowLight, LOW);
      digitalWrite(greenLight, HIGH);
    }

    if (val == HIGH) {
      Serial.println("Motion detected");
      lcd.print("Pedestrian crossing! Motion detected");
      digitalWrite(streetLight1, HIGH);
      digitalWrite(streetLight2, HIGH);
      digitalWrite(streetLight3, HIGH);
      // If motion is detected, turn on the output 
      delay(1000);
      // delay(7000);
      digitalWrite(streetLight1, LOW);
      digitalWrite(streetLight2, LOW);
      digitalWrite(streetLight3, LOW);
      // delay(2000);
      if(pirState = LOW){
        pirState = HIGH;
      }
      lcd.clear();
      lcd.print("Speed Limit 70km/h");
    } else if(val == LOW) {
      // Serial.println(digitalRead(PIRsensor));
      lcd.print("Speed Limit 70km/h");
      if (pirState == HIGH){
        Serial.println("Motion ended!");
        pirState = LOW;
      }
    }


    lcd.setCursor(0, 0); // Set the cursor back to the first column and first row
    lcd.print(" "); // Print a space to clear the previous message without clearing the entire screen
  }
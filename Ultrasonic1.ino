// Ultrasonic Range Finder
// Maxbotix LV-MaxSonar-EZ2
// Small change to see how GIT works


// include the library code:
#include <LiquidCrystal.h>

int sensorPin = A2;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
volatile float mvolts = 0;
volatile float range = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 13);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
    
  // set the cursor to column 0, line 0
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  mvolts = sensorValue * 4.9;
  //temp = -1481.96 + sqrt(2.1962E06+(1.8639-volts)/3.88E-06);
  
  // Uses Analog mode. V=(Vcc/512) per Inch. Vcc=5V, 9.8mV/inch
  range = mvolts*2.592;
  lcd.print("Range = ");
  lcd.print(range);
  lcd.print("mm");
  Serial.print("Range = ");
  Serial.print(range);
  Serial.println("mm");
  delay(1000);

}


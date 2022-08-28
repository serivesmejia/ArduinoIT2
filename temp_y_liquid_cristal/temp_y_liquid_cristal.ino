#include <LiquidCrystal.h>

#define TEMP A5

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop() {
  float temp = (0.5 * analogRead(TEMP) * 100.0) / 1024.0;
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("La T es: ");
  lcd.print(temp);
  lcd.print(" C");

  Serial.println(temp);
  
  delay(5000);
}
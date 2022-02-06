#include <LiquidCrystal_I2C.h>

#define DISPLAY_HEIGHT 16
#define DISPLAY_WIDTH 2
#define DEVICE_ID 33 //I don't know how to use this just yet, lul
LiquidCrystal_I2C lcd(0x27, 16, 2);


byte filledChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; //this char actually makes stratified bars.
   //LC code is temp pending good LEDs anyways.


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.begin(9600);
  delay(2000);
    ;
}

int amplitude_to_height(int amplitude) {
  //return number of pixels to display from int amount
  return round((float(DISPLAY_HEIGHT * amplitude)) / float(244));
}

void display(int height) {
  lcd.clear();
  for (int x=0; x < DISPLAY_WIDTH; x++) {
    lcd.setCursor(0,x);
    for (int y=0; y < height; y++) {
      lcd.write(filledChar);
    };
  };
}

void loop() {
  while(!Serial.available())
    ; //hold for input
  int ser_Identifier = Serial.read();
  int amplitude = Serial.read();
  if(serIdentifier == DEVICE_ID)
    display(amplitude_to_height(rainbow));
} 

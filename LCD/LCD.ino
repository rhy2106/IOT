#include <LiquidCrystal.h>

int minutes = 0;
int seconds = 0;

bool contar = false;

LiquidCrystal lcd_1(12, 11, 7, 6, 5, 4);

void setup() {
  Serial.begin(9600);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  lcd_1.print("Cronometro:");
  lcd_1.setCursor(0, 1);
  lcd_1.print("                    ");
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2), comecar, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), parar, FALLING);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting
  // begins with 0):
  if(contar){
  	lcd_1.setCursor(0, 1);
    minutes = seconds / 60;
  	lcd_1.setCursor(0, 1);
    if(minutes >= 10){
      lcd_1.print(minutes);
    } else{
      lcd_1.print("0");
      lcd_1.setCursor(1, 1);
      lcd_1.print(minutes);
    }
  	lcd_1.setCursor(2, 1);
    lcd_1.print(":");
  	lcd_1.setCursor(3, 1);
    if(seconds%60 >= 10){
      lcd_1.print(seconds%60);
    } else{
      lcd_1.print("0");
      lcd_1.setCursor(4, 1);
      lcd_1.print(seconds%60);
    }
    delay(500);
    seconds += 1;
  }
}

void parar(){
    contar = false;
}

void comecar(){
  contar = true;
}


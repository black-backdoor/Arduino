int last_millis = 0;
bool dots_on = false;
// include the library
#include <LiquidCrystal_I2C.h>

// initialize the display
LiquidCrystal_I2C lcd(0x27, 16, 2); 
int s,m,h,a,d,state,state1,state2,dg;
int cnt = 0;
bool clock_activ = true;
// the 8 arrays that form each segment of the custom numbers
byte bar1[8] = {0b11100,0b11110,0b11110,0b11110,0b11110,0b11110,0b11110,0b11100};
byte bar2[8] = {0b00111,0b01111,0b01111,0b01111,0b01111,0b01111,0b01111,0b00111};
byte bar3[8] = {0b11111,0b11111,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111};
byte bar4[8] = {0b11110,0b11100,0b00000,0b00000,0b00000,0b00000,0b11000,0b11100};
byte bar5[8] = {0b01111,0b00111,0b00000,0b00000,0b00000,0b00000,0b00011,0b00111};
byte bar6[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111};
byte bar7[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00111,0b01111};
byte bar8[8] = {0b11111,0b11111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};



void setup()
{
  lcd.init(); //LCD Display init
  lcd.backlight(); //LCD Display activate 0backlight
  
  state=1;
  state1=1;
  state2=1;
  // sets the LCD's rows and colums:

  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  s=0;
  m=0;
  h=0;
  a=0;
  Serial.begin(9600);

  Serial.println(F("enter hour"));
  while (!Serial.available()){
    delay(1);
  }
  String temp = "";
  temp = Serial.readString();
  h = temp.toInt();
  
  Serial.println(F("enter minutes"));
  while (!Serial.available()){
    delay(1);
  }
  temp = Serial.readString();
  m = temp.toInt();
  
  Serial.println(F("enter seconds"));
  while (!Serial.available()){
    delay(1);
  }
  temp = Serial.readString();
  s = temp.toInt();
  
  Serial.println(F("enter am/pm"));
  while (!Serial.available()){
    delay(1);
  }
  temp = Serial.readString();
  a = temp.toInt();
  
  
}

void custom0(int col)
{ // uses segments to build the number 0
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom1(int col)
{
  lcd.setCursor(col,0);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col,1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom2(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

void custom3(int col)
{
  lcd.setCursor(col,0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

void custom4(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom5(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

void custom6(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

void custom7(int col)
{
  lcd.setCursor(col,0);
  lcd.write(2);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

void custom8(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

void custom9(int col)
{
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}

void printNumber(int value, int col) {
  // assignes each segment a write number
  lcd.createChar(1,bar1);
  lcd.createChar(2,bar2);
  lcd.createChar(3,bar3);
  lcd.createChar(4,bar4);
  lcd.createChar(5,bar5);
  lcd.createChar(6,bar6);
  lcd.createChar(7,bar7);
  lcd.createChar(8,bar8);
  
  if (value == 0) {
    custom0(col);
  } if (value == 1) {
    custom1(col);
  } if (value == 2) {
    custom2(col);
  } if (value == 3) {
    custom3(col);
  } if (value == 4) {
    custom4(col);
  } if (value == 5) {
    custom5(col);
  } if (value == 6) {
    custom6(col);
  } if (value == 7) {
    custom7(col);
  } if (value == 8) {
    custom8(col);
  } if (value == 9) {
    custom9(col);
  }      
}  



void loop() {
  switch(cnt){
  case 1:
    m=m+dg;
    dg=0;
    if(m>59){
      m=59;
    }
    if(m<0){
      m=0;
    }
    break;
  case 2:
    h=h+dg;
    dg=0;
    if(h>11){
      h=11;
    }
    if(h<0){
      h=0;
    }
    break;
  case 3:
    if(dg==1){
      a=1;
      dg=0;
    }
    if(dg==-1){
      a=0;
      dg=0;
    }
    break;
  }
  if(s>59){
    s=0;
    m++;
    if(m>59){
      m=0;
      h++;
      if(h>11){
        h=0;
        a=!a;
      } 
    }
  }
  if(clock_activ){
    d=h%10;
    printNumber(d, 3);
    d=h/10;
    printNumber(d, 0);
    d=m%10;
    printNumber(d, 10);
    d=m/10;
    printNumber(d, 7);
    lcd.setCursor(14, 0);
    if(a){
      lcd.print("AM");
    }
    else{
      lcd.print("PM");
    }
  }

  if((millis() - last_millis) > 499){
    if(!dots_on){
      if(cnt==0){
        lcd.setCursor(6, 0);
        lcd.print(".");
        lcd.setCursor(6, 1);
        lcd.print(".");
      }
      dots_on = true;
    }
    else{
      if(cnt==0){
        s++;
        lcd.setCursor(6, 0);
        lcd.print(" ");
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      dots_on = false;
    }
    last_millis = millis();
  }
}

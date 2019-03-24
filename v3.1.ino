/*
 * Created by Armaan, Brandon, Uttiya For hackaton 2019 (wolfhacks)
 * Group members: Armaan, Brandon, Uttiya, Vivek, Aizaz
 * Code for Universal Transalting Device (UTD)
 * Takes inputs from buttons and displays the corresponding word on the page
 * Can switch through different pages
 * Flashes and buzzes upon page switch
 * Powered by: Arduino Uno, 12*2 LCD display, Active buzzer and LED, as well as 6 buttons
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
unsigned char b1=1;
unsigned char b2=2;
unsigned char b3=3;
unsigned char b4=4;
unsigned char b5=5;
unsigned char b6=6;
unsigned char led_buzzer=7;
bool p1;
bool p2;
bool p3;
bool p4;
bool p5;
bool p6;
bool t1;
char i;
String b1_words[]={"Hello,whats up?","Have a nice day","Bye, for now"};
String b2_words[]={"Help me!","I am lost","Call the police"};
String b3_words[]={"Where's washroom","Grocery store?","Where's Hospital"};
String b4_words[]={"Customizable!","What you want","When you want it"};
signed char page=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
  lcd.home (); 
  lcd.print("Waiting for");
  lcd.setCursor(0,1);
  lcd.print("input...");
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(led_buzzer,OUTPUT);
  digitalWrite(led_buzzer,LOW);
  Serial.begin(9600);

  
}


bool pressCheck(int button){
  t1=false;
  i=0;
  while (i<15){
    if (digitalRead(button)!=1){
      t1=true;
      i=i+1;
      delay(1);
    }
    else{
      t1=false;
      break;
    }
    
  }
  return t1;
  
}

void beep(signed char beeps){
  i=0;  
  beeps=beeps-1;
  while (i <=beeps){
    i=i+1;
    digitalWrite(led_buzzer,HIGH);
    delay(100);
    digitalWrite(led_buzzer,LOW);   
    delay(100); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  p1=pressCheck(b1);
  p2=pressCheck(b2);
  p3=pressCheck(b3);
  p4=pressCheck(b4);
  p5=pressCheck(b5);
  p6=pressCheck(b6);
  lcd.clear();
  lcd.home();
  
  if (p1){
    lcd.print(b1_words[page]);
    lcd.setCursor(0,1);
    lcd.print("Page Number: "+String(page+1));
    delay(1500);  
  }

  else if(p2){
    lcd.print(b2_words[page]);
    lcd.setCursor(0,1);
    lcd.print("Page Number: "+String(page+1));
    delay(1500);  
    
    
  }
  
  else if(p3){
    lcd.print(b3_words[page]);
    lcd.setCursor(0,1);
    lcd.print("Page Number: "+String(page+1));
    delay(1500);  
  }
  else if(p4){
    lcd.print(b4_words[page]);
    lcd.setCursor(0,1);
    lcd.print("Page Number: "+String(page+1));
    delay(1500);  
  }
  else if(p5){
    page=page+1;
    if (page>=3){
      page=0;
    }
    lcd.print("Page: "+String(page+1));
    beep(page+1);
    delay(500);
  }
  else if(p6){
    page=page-1;
    if (page<=-1){
      page=2;
    }
    lcd.print("Page: "+String(page+1));
    beep(page+1);
    delay(500);
    
  }
  
  else{
    lcd.clear();
    lcd.print("Waiting for");
    lcd.setCursor(0,1);
    lcd.print("input...");
    delay(50);
  }

 
}


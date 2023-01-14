#include <LiquidCrystal.h>

LiquidCrystal lcd(22,24,26,28,30,32);
char* words4[4] = {"aber", "adel", "affe", "ahoi"};
BlinkLCD

int joy_x = 8; // analog 
int joy_y = 10; // analog
int joy_press = 34; // digital

char* current_word = "";
char chars[16] = {};
int offset = 6;
int blinking = -1;
int px = 8;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  for (auto i = 0; i < 16; i++) {
    chars[i] = " ";
  }
}

void loop() {
  lcd.
}

void getWord() {
  auto r = random(4);
  current_word = words4[r];
}

bool isCorrect() {
  for (auto i = 0; i < 16; i++) {
    if (chars[i] != " ") {
      if (current_word[i] != chars[i]) {
        return false;
      }
    }
  }
}


void select() {
  if (current_word[px] == " ") {
    return;
  }
  if (blinking == -1) {
    lcd.
  }
}







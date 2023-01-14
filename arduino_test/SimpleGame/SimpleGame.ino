#include <LiquidCrystal.h>

LiquidCrystal lcd(26, 22, 25, 27, 29, 31);

int led = 2;
int ponti = 2;
int y_cursor = 0;
int x_cursor = 0;
int sensorwert = 0;
int sx = 15;
int sy = 13;
const int row_len = 16;

int r1[row_len];
int r2[row_len];
int e = 1;  // enemy;
int p = 2;  // player;
int b = 3;  // empty block;
bool isPlaying = true;
int player_x = 2;
int player_y = 0;
int delay_time = 500;

void setup() {
  lcd.begin(row_len, 2);
  //lcd.clear();
  lcd.setCursor(player_x, player_y);
  //lcd.print("P");
  for (auto i = 0; i < row_len; i++) {
    r1[i] = b;
    r2[i] = b;
    lcd.setCursor(i, 0);
    lcd.print(1);
    lcd.setCursor(i, 1);
    lcd.print(1);
  }
}

void loop() {
  if (isPlaying) {
    auto syv = analogRead(sy);
    if (syv > 700) {
      player_y = 1;
    } else if (syv < 300) {
      player_y = 0;
    }
    moveBlock();
    generateBlock();
    delay(delay_time);
    //delay_time -= 50;
  } else {
    lcd.clear();
    lcd.print("You loose");
    lcd.setCursor(0, 1);
    lcd.print("You are worthless");
    delay(10000);
  }
}


void generateBlock() {
  for (auto i = 13; i < row_len; i++) {
    if (r1[i] == e || r2[i] == e) {
      return;
    }
  }

  auto row = random(2);
  lcd.setCursor(row_len - 1, row);
  if (row == 0) {
    r1[row_len - 1] = e;
  }
  else {
    r2[row_len] = e;
  }
  lcd.print("E");
}

void moveBlock() {
  lcd.clear();
  lcd.setCursor(player_x, player_y);
  lcd.print("P");
  for (auto i = 1; i < row_len; i++) {
    if (r1[i + 1] == e) {
      r1[i + 1] = b;
      r1[i] = e;
      lcd.setCursor(i, 0);
      lcd.print("E");
      if (player_y == 0 && player_x == i) {
        isPlaying = false;
      }
    }
    if (r2[i + 1] == e) {
      r2[i + 1] = b;
      r2[i] = e;
      lcd.setCursor(i, 1);
      lcd.print("E");
      if (player_y == 1 && player_x == i) {
        isPlaying = false;
      }
    }
  }
}

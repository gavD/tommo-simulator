#include <Arduboy2.h>

Arduboy2 arduboy;

int weight_in_tons = 1;
bool dead = false;
uint8_t y = 8;
String lastAction = "";

void setup() {
  arduboy.begin();
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }

  arduboy.clear();
  arduboy.setCursor(0,y);
  
  arduboy.println(F("TOMMO SIMULATOR 0.1"));
  String wt =" Weight: " + String(weight_in_tons);
  String wt2 = wt + " tons";
  arduboy.println(wt2);
  
  if (dead) {
    arduboy.println(F(" Tommo dedd m9!"));
  } else {arduboy.pollButtons();
    if (arduboy.justPressed(A_BUTTON)) {
      lastAction = "> Bounty eaten";
      weight_in_tons += 2;
    } else if (arduboy.justPressed(B_BUTTON)) {
      lastAction = "Cat burst";
      weight_in_tons--;
    }
    arduboy.println(lastAction);
    
    arduboy.println(F("A) Bounty B) catBurst"));    
  }

  if (weight_in_tons > 10) {
    dead = true;
  }

  arduboy.display();
}
#include "Dragon.h"

const int Dragon::ATTACK_POWER = 25;
const int Dragon::SPECIAL_ATTACK_POWER = 100;

Dragon::Dragon() {
}
Dragon::~Dragon() {}

int Dragon::attack() {
  std::cout << KILL_DIALOGUE << std::endl;
  return ATTACK_POWER;
}
void Dragon::intro() {
  std::cout << INTRO_DIALOGUE << std::endl;
}

int Dragon::specialAttack() {
  std::cout << SPECIAL_KILL_DIALOGUE << std::endl;
  return SPECIAL_ATTACK_POWER;
}

void Dragon::kill(int reduceHealth) {
  health -= reduceHealth;
  if (health > 0) {
    std::cout << NOT_SAVE_DIALOGUE << std::endl;
  } else {
    std::cout << DEFEAT_DIALOGUE << std::endl;
  }
}

#include "Lion.h"

const int Lion::ATTACK_DMG = 34;
const int Lion::SPECIAL_ATTACK_DMG = 100;


Lion::Lion() {
  std::cout << INTRO_DIALOGUE << std::endl;
}
Lion::~Lion() {}

int Lion::attack() {
  std::cout << ATTACK_DIALOGUE << std::endl;
  return ATTACK_DMG;
}

int Lion::specialAttack() {
  std::cout << WIN_DIALOGUE << std::endl;
  return SPECIAL_ATTACK_DMG;
}

void Lion::kill(int reduceHealth) {
  health -= reduceHealth;
  if (health > 0) {
    std::cout << WIN_DIALOGUE << std::endl;
  } else {
    std::cout << DEFEAT_DIALOGUE << std::endl;
  }
}

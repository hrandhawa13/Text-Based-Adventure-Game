#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED
#include <iostream>
#include <string>
#include "NPC.h"

class Dragon: public NPC {
 private:
  const std::string INTRO_DIALOGUE =
  "I am the MIGHTY Dragon. HAHAHA ";
  const std::string KILL_DIALOGUE =
  "I am going to KILL you. HAHAHA ";
  const std::string SPECIAL_KILL_DIALOGUE =
  "You are dead now. HAHAHA ";
  const std::string NOT_SAVE_DIALOGUE =
  "You cannot save your princess from me. HAHAHA ";
  const std::string DEFEAT_DIALOGUE =
  "OH NO, YOU defeated me ";
  int health = 100;


 public:
  static const int ATTACK_POWER;
  static const int SPECIAL_ATTACK_POWER;

  Dragon();
  ~Dragon();
  int getHealth() {return health;}
  int attack();
  int specialAttack();
  void intro();
  void kill(int reduceHealth);
};

#endif

#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED
#include <iostream>
#include <string>
#include "NPC.h"

class Lion: public NPC {
 private:
  const std::string INTRO_DIALOGUE =
  "I...AM the King of the jungle.";
  const std::string ATTACK_DIALOGUE =
  "RAWWRR";
  const std::string DEFEAT_DIALOGUE =
  "The jungle has a new king now.";
  const std::string WIN_DIALOGUE =
  "You're no match for the king of the jungle.";
  int health = 100;

 public:
  static const int ATTACK_DMG;
  static const int SPECIAL_ATTACK_DMG;

  Lion();
  ~Lion();
  int getHealth() {return health;}
  int attack();
  int specialAttack();
  void kill(int reduceHealth);
};

#endif

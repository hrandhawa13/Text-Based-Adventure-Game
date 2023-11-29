#include "NPC.h"
#include <iostream>

NPC::~NPC() {}
NPC::NPC(std::string aName) {
  name = aName;
}
std::string NPC::getName() { return name; }
char NPC::getSymbol() {
  //if name is empty, return space else first character
  return name.empty() ? ' ' : name.at(0);
}
std::string NPC::getDialogue() {
  //not the best implementation but will be improved in the next phase.
  //Either use map or enums
  if (name.compare("Messenger") == 0) {
    return "Princess has been kidnapped";
  }
  if (name.compare("Advisor") == 0) {
    return "Be careful, this adventure is risky. Would you like to exit?";
  }
  return "No Dialogues available";
}

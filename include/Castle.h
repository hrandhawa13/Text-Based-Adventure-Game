#ifndef CASTLE_H_INCLUDED
#define CASTLE_H_INCLUDED
#include <string>

#include "King.h"
#include "Environment.h"
#include "NPC.h"

class Castle: public Environment {
 public:
    Castle();
    explicit Castle(King* king);
    Castle(const Castle &castle);
    ~Castle() {}
    King* king;
    NPC* messenger;
    NPC* advisor;
    Object* key;
    Object* sword;
    Object* armor;
    Castle& operator=(const Castle& c);
    void startLevel() override;
    void printStory() override;
    void startUserInput() override;
    void moveKing() override;
    void startCurrentLocation() override;
    void printCurrentLocation() override;
    void printMsngrLocation();
    void printAdvisorLocation();
    void printKeyLocation();
    void printArmorLocation();
    void printSwordLocation();
    void completeNPCLocation();
    void completeObjLocation();
    void endLevel() override;
    void generalInputs(const std::string &input);
    void cleanUp();

 private:
    const int MSNGR_LOCATION = 1;
    const int ADVISOR_LOCATION = 3;
    const int KEY_LOCATION = 5;
    const int SWORD_LOCATION = 7;
    const int ARMOR_LOCATION = 8;
    bool levelCompleted = false;
    bool itemPicked = false;
    Object* currentLocationObj;
    NPC* currentLocationNpc;

  const std::string MESSENGER_LOC_MSG =
  "NPC character Messenger is standing in front of you. "
  "Enter speak to interact with the messenger";
  const std::string ADVISOR_LOC_MSG =
  "NPC character Advisor is standing in front of you. "
  "Enter speak to interact with the Advisor";
  const std::string NPC_DONE_MSG =
   "NPC character was in this location and "
  "you have already interacted with him.";
  const std::string KEY_LOC_MSG =
  "Object Key in front of you..";
  const std::string KEY_PICKED_MSG =
  "Object Key was in this location and you have picked it";
  const std::string SWORD_LOC_MSG =
  "Used Key to unlock the door. "
  "Object Sword in front of you..";
  const std::string SWORD_PICKED_MSG =
  "Object Sword was in this location and you have picked it";
  const std::string ARMOR_LOC_MSG =
  "Object Armor in front of you..";
  const std::string ARMOR_PICKED_MSG =
  "Object Armor was in this location and you have picked it";
  const std::string CASTLE_COMPLETE_MSG =
  "You have completed the castle stage. "
  "Entering forest, good luck....";

  void createCastleObjects();
  void pickItem();
  void dropItem();
};
#endif //CASTLE_H_INCLUDED

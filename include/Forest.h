#ifndef Forest_H_INCLUDED
#define Forest_H_INCLUDED
#include <string>

#include "King.h"
#include "Environment.h"
#include "NPC.h"
#include "Lion.h"
#include "Object.h"

class Forest: public Environment {
 public:
    Forest();
    explicit Forest(King *theKing);
    Forest(const Forest &forest);
    ~Forest() {}
    King* king;
    Lion* lion;
    NPC* forestLeader;
    Object* specialFruit;
    Object* map;
    Object* specialSword;
    Object* specialArmor;
    Forest& operator=(const Forest& c);
    void lionFight();
    void startLevel() override;
    void createPlayer();
    void startUserInput() override;
    void moveKing() override;
    void printNextLocation() override;
    void completeForestLeaderLocation();
    void printForestLeaderLocation();
    void printSpecialFruitLocation();
    void printSpecialArmorLocation();
    void printSpecialSwordLocation();
    void completeHorseLocation();
    void completeLionLocation();
    void completeObjLocation();
    void completeJungle();
    void endLevel() override;
    std::string getCurrentLocation(const int randomEmpty);
    void generalInputs(const std::string &input, const std::string &location);
    void pickItem();
  void dropItem();

 private:
    Object* currentLocationObj;
    bool forestCompleted = false;
    bool answeredRiddle = false;
    bool itemPicked = false;
    bool lionDefeated = false;
    const int HORSE_LOCATION = 1;
    const int FOREST_LEADER_LOCATION = 3;
    const int SPECIAL_FRUIT_LOCATION = 4;
    const int LION_LOCATION = 5;
    const int SPECIAL_ARMOR_LOCATION = 6;
    const int SPECIAL_SWORD_LOCATION = 7;
    const int BACK_TO_FIRST_LOCATION = 8;
    const std::string FOREST_STORY =
    "\n----------------------------------------- \n"
    + king->getName() + " has arrived at the forest."
"\nLegend has it that not a single soul has ever crossed this jungle"
"...Can the mighty and wise " + king->getName() +
" get through? Can he solve the riddle of this this mysterious jungle?\n"
"-----------------------------------------\n";
static constexpr const char* const HORSE_MSG = "You are at the jungle now.\n"
"It is easier to hitch your horse and explore the jungle on foot.\n"
"There is a nice tree over there; try to 'tie' the horse to it!";
    const std::string HORSE_TIED =
"You hitched your horse.";
static constexpr const char* const FOREST_LEADER_LOC_MSG =
"----------------------------------------- \n"
"I am the Forest Leader. Solve my riddle to gain passage through the jungle..."
"or return to your home as the road ahead is "
"impossible to navigate for the unwise.\n"
 "Which fish costs the most?\nA)Goldfish\nB)Trout\nC)Tuna\nD)Shark"
 "\nEnter a, b, c, d to answer";
static constexpr const char* const NPC_DONE_MSG =
  "NPC character was in this location and "
  "you have already interacted with him.";
static constexpr const char* const RIDDLE_NOT_ANSWERED_MSG =
  "You were not able to answer the riddle. Return to your castle";
  const std::string RIDDLE_ANSWERED_MSG =
  "Congratulations! You have been granted passage through the jungle.";
  const std::string MAP_RECEIVED_MSG =
  "You have been awarded a map";
  const std::string LION_DEFEATED =
  "Lion has been defeated";
  const std::string SPECIAL_FRUIT_MSG =
  "There is a special fruit in front of you. "
  "It has the ability to heal you after battles.";
  const std::string FRUIT_PICKED_MSG =
  "Fruit has already been picked.";
  const std::string LION_LOC_MSG =
  "----------------------------------------- \n"
  "You have entered the Lion's territory. "
  "The lion is wearing a body armor but NO helmet\n"
  "I am the King of the jungle... RAWWWRRRRRRRR";
static constexpr const char* const SPECIAL_ARMOR_MSG =
"There is a mystical special armor in front of you. "
"Much stronger than the one you currently have.";
static constexpr const char* const SPECIAL_ARMOR_PICKED_MSG =
"Special Armor has already been picked";
static constexpr const char* const SPECIAL_SWORD_MSG =
"There is a mystical special Sword in front of you."
"Much stronger than the one you currently have.";
static constexpr const char* const SPECIAL_SWORD_PICKED_MSG =
"Special Sword has already been picked";
static constexpr const char* const BACK_TO_FIRST_LOC_MSG =
   "----------------------------------------- \n"
   "How strange... you are somehow back where you entered the jungle."
   "\nYour horse is still tied to the tree."
   "\n'read' the map to find your way to the Dragon's Cave.";
static constexpr const char* const HEALTH_LOW_MSG =
   "Your health is low 'eat' that special fruit! Or 'move'";
};
#endif //Forest_H_INCLUDED

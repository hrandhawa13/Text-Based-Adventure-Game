#ifndef Cave_H_INCLUDED
#define Cave_H_INCLUDED
#include <string>

#include "King.h"
#include "Environment.h"
#include "Dragon.h"
#include "NPC.h"

class Cave: public Environment {
 public:
    Cave();
    explicit Cave(King *theKing);
    Cave(const Cave &Cave);
    ~Cave() {}
    King* king;
    Dragon* dragon;
    Cave& operator=(const Cave& c);
    void dragonFight();
    void emptyLocation(const int roomType);
    void startLevel() override;
    void startUserInput() override;
    void moveKing() override;
    void printNextLocation() override;
    void completeLocationOne();
    void completeLocationTwo();
    void princessSaved();
    int randomEmptyMsg();
    void dragonAttack();
    void kingAttack();
    void dragonFightStatus();
    std::string getCurrentLocation(const int randomEmpty);
    std::string getEmptyRoomOutput(const int roomType);
    void printHelp();
    void endLevel() override;
    int dragonAttackLogic(int breath);
    void generalInputs(const std::string &input, const std::string &location);

 private:
    bool caveCompleted = false;
    const int DRAGON_LOCATION = 7;
    const int PRINCESS_LOCATION = 8;
    const int HORSE_LOCATION = 1;
    const int POTION_LOCATION = 4;
    const std::string CAVE_STORY =
"----------------------------------------- \n"
"After a intense battle with the Lion, a wounded " + king->getName() +
"\ncan see the entrance to the Dragon's Cave in the distance\n"
"-----------------------------------------";
    const std::string DRAGON_STATUS =
    "Dragons health: ";
    const std::string KING_STATUS =
    "Kings health: ";
    const std::string DRAGON_HINT =
"The dragon begins his attack, what will you "
"'attack' or 'run'?";
    const std::string ATTACK_DIALOGUE =
"The Dragon swipes his claws at the King!";
    const std::string ENTER_DRAGON =
"--------You enter the dragons lair-------";
    const std::string FAIL_BREATH =
"AHHHHHH, the King was burnt to a crisp\n"
"------------GAME OVER---------";
    const std::string BREATH_DODGE =
king->run() + "to hide behind a rock "
"the rock takes the brunt of the breath saving you from "
"being burnt to a crisp";
    const std::string DRAGON_RUN =
"Why run are you afraid keep attacking!";
    const std::string DRAGON_SPECIAL =
"The dragon opens it's mouth preparing a breath attack\n"
"will you run and hide or will you keep attacking?";
    const std::string DRAGON_DEFEATED =
"The dragon has been defeated time to save the princess!";
    const std::string EMPTY_LOC_HINT =
"Maybe you can 'inspect' it?";
    const std::string EMPTY_LOCATION1 =
"You find yourself in a empty room in the cave? maybe try inspecting";
    const std::string EMPTY_LOCATION2 =
"You wander into a empty walkway of the cave, you see a message on the wall?";
    const std::string EMPTY_LOCATION3 =
"You walk into a empty passage in the cave with scratches on the wall?";
    const std::string WALL_MSG =
"After inspecting the wall you 'DEATH AHEAD' written on the wall with blood.\n";
    const std::string BURNT_GROUND_MSG =
"After inspecting the room you notice the burn marks all over the place.\n";
    const std::string SCRATCH_MSG =
"After inspecting the wall you see claw marks.\n";
    const std::string POTION_MSG =
"Traversing the cave you begin to notice the damage you took from the Lion!\n"
"Do you wish to drink the potion you found in the Forest? yes/no";
    const std::string HORSE_MSG =
"You are standing infront of the entrance to the cave\n your horse can't fit.\n"
"There is a nice tree over their try to 'tie' the horse to it!";
    const std::string HORSE_TIED =
"You tie up your horse to a nearby tree";
    const std::string BATTLE =
"You are in combat with the dragon, attack or run!";
    const std::string END =
"You have defeated the dragon and rescued the princess";
    const std::string DRINK_POTION_S =
"You drink the potion you regained your health";
    const std::string PRINCESS_SAVED =
"You enter the last room of the dragons cave "
"you see the princess hiding under the bed \n"
"you rush together and hug eachother "
"the princess thanks you for coming to save her \n"
"is there something you wish to say to the princess?";
    const std::string HAPPY_EVER =
"You and the princess return home to cheers from the kingdom "
"and live happily ever after!";
  const std::string INSPECT_HINT =
  "Enter inspect to check out empty rooms";
  const std::string TIE_HINT =
  "Enter tie to tie horse to tree";
  const std::string LINEBREAK =
  "--------------------------------------------";
};
#endif //Cave_H_INCLUDED

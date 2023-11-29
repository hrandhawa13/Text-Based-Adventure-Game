#ifndef ENVIRONMENT_H_INCLUDED
#define ENVIRONMENT_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "King.h"
class Environment{
 public:
    // King* king;
    Environment();
    // Environment(King& theKing): king(&theKing){};
    bool stageCompleted = true;
    ~Environment();
    virtual void printMsg(const std::string &msg);
    virtual void printStory() {}
    virtual void startUserInput() {}
    virtual void printCurrentLocation();
    virtual void printNextLocation() {}
    virtual void startPlaying() {}
    virtual void setupEnvironment() {}
    virtual void startLevel();
    virtual void endLevel() {}
    virtual void moveKing() {}
    virtual void startCurrentLocation() {}
    virtual std::string getInput();
    virtual void printHelp();
    const std::string MOVE_MSG =
    "Enter 'move' to move to next location";
    const std::string DONE_MSG =
    "Enter 'done' to complete this location";
    const std::string UNKNOWN =
    "You have entered unknown command. Enter help to list all options";
    const std::string EXIT_MSG =
    "You entered exit, good luck next time.";
    const std::string PICKED = "Picked a new object.";
    const std::string NOT_PICKED_YET =
    "You haven't picked object in this location yet.";
    const std::string INTERACT_WITH_NPC =
    "You cannot proceed without interacting with NPC.";
    const std::string ALREADY_PICKED =
    "You have already picked object in this location.";
    const std::string DROP_OBJ = "Enter drop to drop the new object.";
    const std::string DROPPED = "You dropped the new object.";
    const std::string EMPTY_LOC_MSG =
  "This location is empty.";
  const std::string OBJ_INTERACT_MSG =
  "Enter touch, look, examine to interact with this object. "
  "Enter pick to pick this item.";
    const std::string WINNER =
    "You win!!!";
};
#endif //ENVIRONMENT_H_INCLUDED

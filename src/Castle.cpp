#include <iostream>
#include <string>
#include "../include/Castle.h"
#include "../include/Environment.h"


// default constructor of a Castle
Castle::Castle() {
    king = new King();
    createCastleObjects();
}

// copy constructor of type Castle
Castle::Castle(const Castle &castle):king(castle.king) {
createCastleObjects();
}
// Constructor for Castle that sets the king
Castle::Castle(King* theKing):king(theKing) {
    createCastleObjects();
}
Castle& Castle::operator=(const Castle& c) {
    if (this == &c) {
        return *this;
    }
    this->king = c.king;
    this->key = c.key;
    this->messenger = c.messenger;
    this->advisor = c.advisor;
    this->armor = c.armor;
    this->sword = c.sword;
    this->currentLocationObj = c.currentLocationObj;
    this->currentLocationNpc = c.currentLocationNpc;
    return *this;
}

void Castle::createCastleObjects() {
    messenger = new NPC("Messenger");
    key = new Object("Key", "Special Key to Unlock doors");
    advisor = new NPC("Advisor");
    sword = new Object("Sword", "King's Mighty Sword");
    armor = new Object("Armor", "King's special Armor");
    currentLocationObj = new Object();
    currentLocationNpc = new NPC();
}

void Castle::startLevel() {
    printStory();
    startUserInput();
    Environment::startPlaying();
    endLevel();
}

void Castle::printStory() {
    std::cout << king->getName()
    << " is sitting in his castle "
    << "watching over his people"
    << std::endl;
}

void Castle::startUserInput() {
    std::string input;
    while ( !levelCompleted ) {
        if (stageCompleted) {
            Environment::printMsg(MOVE_MSG);
        }
        input = Environment::getInput();
        if ( stageCompleted && input == "move" ) {
            moveKing();
        } else {
            generalInputs(input);
        }
    }
}

void Castle::moveKing() {
    std::string moveStr = king->forward();
    stageCompleted = false;
    std::cout << moveStr << std::endl;
    startCurrentLocation();
}

void Castle::startCurrentLocation() {
    int currentLocation = king->getLocation();
    printCurrentLocation();
    if ( currentLocation == MSNGR_LOCATION ) {
        currentLocationNpc = messenger;
        completeNPCLocation();
        currentLocationNpc = nullptr;
    } else if (currentLocation == ADVISOR_LOCATION) {
        currentLocationNpc = advisor;
        completeNPCLocation();
        currentLocationNpc = nullptr;
    } else if (currentLocation == KEY_LOCATION) {
        currentLocationObj = key;
        completeObjLocation();
        currentLocationObj = nullptr;
    } else if (currentLocation == SWORD_LOCATION) {
        currentLocationObj = sword;
        completeObjLocation();
        currentLocationObj = nullptr;
    } else if (currentLocation == ARMOR_LOCATION) {
        currentLocationObj = armor;
        completeObjLocation();
        currentLocationObj = nullptr;
        levelCompleted = true;
    } else {
        stageCompleted = true;
    }
}
void Castle::printCurrentLocation() {
    int currentLocation = king->getLocation();
    if (currentLocation == 0) {
        printStory();
    } else if ( currentLocation == MSNGR_LOCATION ) {
        printMsngrLocation();
    } else if (currentLocation == ADVISOR_LOCATION) {
        printAdvisorLocation();
    } else if (currentLocation == KEY_LOCATION) {
        printKeyLocation();
    } else if (currentLocation == SWORD_LOCATION) {
        printSwordLocation();
    } else if (currentLocation == ARMOR_LOCATION) {
        printArmorLocation();
    } else {
        Environment::printMsg(EMPTY_LOC_MSG);
    }
}
void Castle::printMsngrLocation() {
    if (!stageCompleted)
        Environment::printMsg(MESSENGER_LOC_MSG);
    else
        Environment::printMsg(NPC_DONE_MSG);
}
void Castle::printAdvisorLocation() {
    if (!stageCompleted)
        Environment::printMsg(ADVISOR_LOC_MSG);
    else
        Environment::printMsg(NPC_DONE_MSG);
}
void Castle::printKeyLocation() {
    if (!itemPicked) {
        Environment::printMsg(KEY_LOC_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(KEY_PICKED_MSG);
    }
}
void Castle::printSwordLocation() {
    if (!itemPicked) {
        Environment::printMsg(SWORD_LOC_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(SWORD_PICKED_MSG);
    }
}
void Castle::printArmorLocation() {
    if (!itemPicked) {
        Environment::printMsg(ARMOR_LOC_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(ARMOR_PICKED_MSG);
    }
}
void Castle::completeNPCLocation() {
    std::string input;
    stageCompleted = false;
    bool interactedWithNpc = false;
    while (!stageCompleted) {
        input = Environment::getInput();
        if (input == "speak") {
            Environment::printMsg(currentLocationNpc->getDialogue());
            interactedWithNpc = true;
        } else if (input == "done") {
            if (interactedWithNpc)
                stageCompleted = true;
            else
                Environment::printMsg(INTERACT_WITH_NPC);
        } else {
            generalInputs(input);
        }
        if (!interactedWithNpc && input != "print" && input != "exit")
            printCurrentLocation();
        if (interactedWithNpc && !stageCompleted)
            Environment::printMsg(DONE_MSG);
    }
}

void Castle::generalInputs(const std::string &input) {
     if ( input == "help" ) {
        Environment::printHelp();
    } else if ( input == "print" ) {
        printCurrentLocation();
    } else if ( input == "exit" ) {
        Environment::printMsg(EXIT_MSG);
        king->setHp(100);
        levelCompleted = true;
        stageCompleted = true;
    } else if (input == "status") {
        king->printInfo();
    } else {
        Environment::printMsg(UNKNOWN);
    }
}

void Castle::completeObjLocation() {
    std::string input;
    stageCompleted = false;
    itemPicked = false;
    while (!stageCompleted) {
        input = Environment::getInput();
        if ( input == "touch" ) {
            Environment::printMsg(currentLocationObj->touch());
        } else if ( input == "examine" ) {
            Environment::printMsg(currentLocationObj->examine());
        } else if ( input == "look" ) {
            Environment::printMsg(currentLocationObj->look());
        } else if ( input == "pick" ) {
            pickItem();
        } else if (input == "drop") {
            dropItem();
        } else if (input == "done") {
            if (itemPicked)
                stageCompleted = true;
            else
                Environment::printMsg(NOT_PICKED_YET);
        } else {
            generalInputs(input);
        }
        if (!itemPicked && input != "print")
            printCurrentLocation();
        if (itemPicked && !stageCompleted)
            Environment::printMsg(DONE_MSG);
    }
    itemPicked = false;//reset for next location
}
void Castle::pickItem() {
    if (!itemPicked) {
        itemPicked = true;
        king->pickUpItem(currentLocationObj);
        Environment::printMsg(PICKED);
        Environment::printMsg(DROP_OBJ);
    } else {
        Environment::printMsg(ALREADY_PICKED);
    }
}
void Castle::dropItem() {
    if (itemPicked) {
        king->putDownItem(currentLocationObj);
        itemPicked = false;
        Environment::printMsg(DROPPED);
    } else {
        Environment::printMsg(NOT_PICKED_YET);
    }
}

void Castle::endLevel() {
    delete messenger;
    delete advisor;
    delete currentLocationObj;
    delete currentLocationNpc;
    if ( king->getHp() > 0 )
        Environment::printMsg(CASTLE_COMPLETE_MSG);
}

void Castle::cleanUp() {
    delete sword;
    delete armor;
    delete key;
}

#include <string>
#include "King.h"
#include "Cave.h"

Cave::Cave() {}

Cave::Cave(King *theKing):king(theKing) {
    dragon = new Dragon();
}

Cave::Cave(const Cave &cave) {}

Cave& Cave::operator=(const Cave& c) {
    if (this == &c) {
        return *this;
    }
    return *this;
}
void Cave::startLevel() {
    king -> setLocation(0);
    Environment::printMsg(CAVE_STORY);
    startUserInput();
}
    void Cave::princessSaved() {
        Environment::printMsg(PRINCESS_SAVED);
        Environment::getInput();
        Environment::printMsg(HAPPY_EVER);
        caveCompleted = true;
    }
// handles the logic/ player input for the dragon fight.
void Cave::dragonFight() {
    int breath = 0;
    bool startOfFight = true;
    std::string input;
    stageCompleted = false;
    while (!stageCompleted) {
        if (startOfFight) {
            Environment::printMsg(DRAGON_STATUS);
            std::cout << dragon->getHealth() <<std::endl;
            Environment::printMsg(KING_STATUS);
            std::cout << king->getHp() <<std::endl;
        }
        if (breath == 0) {
         Environment::printMsg(DRAGON_HINT);
        }
        input = Environment::getInput();
        if (input == "attack") {
            startOfFight = false;
            breath = dragonAttackLogic(breath);
        } else if (input == "run") {
            if (breath == 0) {
                dragonFightStatus();
                Environment::printMsg(DRAGON_RUN);
            } else {
                Environment::printMsg(BREATH_DODGE);
                breath = 0;
            }
        } else {
            if (breath == 1) {
                generalInputs(input, DRAGON_SPECIAL);
            }
            generalInputs(input, BATTLE);
        }
    }
}
    void Cave::kingAttack() {
            Environment::printMsg(king->attack("the Dragon"));
            Environment::printMsg(LINEBREAK);
            dragon->kill(25);
    }
    void Cave::dragonAttack() {
        Environment::printMsg(ATTACK_DIALOGUE);
        king->setHp(dragon ->attack());
    }
    void Cave::dragonFightStatus() {
            Environment::printMsg(LINEBREAK);
            Environment::printMsg(DRAGON_STATUS);
            std::cout << dragon->getHealth() <<std::endl;
            Environment::printMsg(KING_STATUS);
            std::cout << king->getHp() <<std::endl;
            Environment::printMsg(LINEBREAK);
    }
    int Cave::dragonAttackLogic(int breath) {
             //King attacks dragon
            Environment::printMsg(LINEBREAK);
            if (dragon->getHealth() > 0 && king->getHp() > 0) {
            kingAttack();
            dragonFightStatus();
            }
            //dragon attacks king
            if (dragon->getHealth() > 0 && king->getHp() > 0) {
            dragonAttack();
            dragonFightStatus();
            }
            if (king->getHp() <= 0) {
                Environment::printMsg(FAIL_BREATH);
                king ->heal(0);
                stageCompleted = true;
                caveCompleted = true;
            } else if (breath == 1) {
                Environment::printMsg(FAIL_BREATH);
                king ->heal(0);
                stageCompleted = true;
                caveCompleted = true;
            } else if (dragon->getHealth() == 0) {
                Environment::printMsg(DRAGON_DEFEATED);
                stageCompleted = true;
            } else if (dragon ->getHealth() == 50) {
                breath = 1;
                Environment::printMsg(DRAGON_SPECIAL);
            }
            return breath;
    }

    std::string Cave::getCurrentLocation(const int randomEmpty) {
        int currentLocation = king->getLocation();
        if (currentLocation == 0) {
            return CAVE_STORY;
        } else if (currentLocation == 1) {
            return HORSE_MSG;
        } else if (currentLocation == 4) {
            return POTION_MSG;
        } else if (currentLocation == 7) {
            return DRAGON_HINT;
        } else if (currentLocation == 8) {
            return PRINCESS_SAVED;
        } else {
            return getEmptyRoomOutput(randomEmpty);
        }
    }
void Cave::emptyLocation(const int roomType) {
    std::string input;
    stageCompleted = false;
    while (!stageCompleted) {
        Environment::printMsg(MOVE_MSG);
        input = Environment::getInput();
        if (input == "inspect" || input == "examine") {
            if (roomType == 1) {
                Environment::printMsg(BURNT_GROUND_MSG);
            } else if (roomType == 2) {
                Environment::printMsg(WALL_MSG);
            } else if (roomType == 3) {
                Environment::printMsg(SCRATCH_MSG);
            }
            stageCompleted = true;
        } else if ( input == "move" ) {
            moveKing();
        } else {
            generalInputs(input, getCurrentLocation(roomType));
        }
    }
}

std::string Cave::getEmptyRoomOutput(const int roomType) {
    if (roomType == 1) {
        return EMPTY_LOCATION1 + "\n" + EMPTY_LOC_HINT;
    } else if (roomType == 2) {
        return EMPTY_LOCATION2 + "\n" + EMPTY_LOC_HINT;
    } else {
        return EMPTY_LOCATION3 + "\n" + EMPTY_LOC_HINT;
    }
}
void Cave::startUserInput() {
    std::string input;
    while ( !caveCompleted ) {
        if (stageCompleted) {
            Environment::printMsg(MOVE_MSG);
        }
        input = Environment::getInput();
        if ( stageCompleted && input == "move" ) {
            moveKing();
        } else {
            generalInputs(input, getCurrentLocation(0));
        }
    }
}

void Cave::moveKing() {
    std::string moveStr = king->forward();
    stageCompleted = false;
    std::cout << moveStr << std::endl;
    printNextLocation();
}

void Cave::printNextLocation() {
    int currentLocation = king->getLocation();
    if (currentLocation == 0) {
        Environment::printMsg(CAVE_STORY);
    } else if ( currentLocation == HORSE_LOCATION ) {
        Environment::printMsg(HORSE_MSG);
        completeLocationOne();
    } else if (currentLocation == POTION_LOCATION) {
        Environment::printMsg(POTION_MSG);
        completeLocationTwo();
    } else if (currentLocation == DRAGON_LOCATION) {
        Environment::printMsg(ENTER_DRAGON);
        dragonFight();
    } else if (currentLocation == PRINCESS_LOCATION) {
        princessSaved();
    } else {
        int roomType = randomEmptyMsg();
        Environment::printMsg(getCurrentLocation(roomType));
        emptyLocation(roomType);
    }
}

int Cave::randomEmptyMsg() {
    // random number between one and 3
    int roomType = std::rand() % 3 + 1;
    return roomType;
}
void Cave::completeLocationOne() {
    std::string input;
    stageCompleted = false;
    while (!stageCompleted) {
        input = Environment::getInput();
        if ( input == "tie" ) {
            Environment::printMsg(HORSE_TIED);
            stageCompleted = true;
        } else {
            generalInputs(input, HORSE_MSG);
        }
    }
}
void Cave::completeLocationTwo() {
    std::string input;
    stageCompleted = false;
    while (!stageCompleted) {
        input = Environment::getInput();
        if ( input == "no" ) {
            stageCompleted = true;
        } else if ( input == "yes" ) {
            king -> heal(100);
            Environment::printMsg(DRINK_POTION_S);
            stageCompleted = true;
        } else {
            generalInputs(input, POTION_MSG);
        }
    }
}
    // handles all general player inputs.
    void Cave::generalInputs(const std::string &input
    , const std::string &location) {
     if ( input == "help" ) {
        printHelp();
        Environment::printMsg(location);
    } else if ( input == "print" ) {
        Environment::printMsg(location);
    } else if ( input == "exit" ) {
        Environment::printMsg(EXIT_MSG);
        caveCompleted = true;
        stageCompleted = true;
    } else if (input == "status") {
        king->printInfo();
        Environment::printMsg(location);
    } else {
        Environment::printMsg(UNKNOWN);
        Environment::printMsg(location);
    }
}
void Cave::printHelp() {
    Environment::printHelp();
    Environment::printMsg(INSPECT_HINT);
    Environment::printMsg(TIE_HINT);
    Environment::printMsg(LINEBREAK);
}
    void Cave::endLevel() {
        if (dragon->getHealth() <= 0) {
        Environment::printMsg(END);
        }
        delete dragon;
    }

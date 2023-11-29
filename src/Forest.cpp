#include <string>
#include "King.h"
#include "Forest.h"
#include "Lion.h"
#include "NPC.h"

    Forest::Forest() {}
    Forest::Forest(King *theKing):king(theKing) {
        lion = new Lion();
        forestLeader = new NPC("Forest Leader");
        specialFruit = new Object("Special Fruit", "I heal you.");
        map = new Object ("Map", "Shows you how to get to the cave.");
        specialSword = new Object("Special Sword",
        "A mystical Sword hidden in the lion's territory.");
        specialArmor = new Object("Special Armor",
        "A mystical Armor hidden in the lion's territory.");
    }
    Forest::Forest(const Forest &forest) {}
    Forest& Forest::operator=(const Forest& c) {
    if (this == &c) {
        return *this;
    }
    this->king = c.king;
    this->lion = c.lion;
    this->forestLeader = c.forestLeader;
    this->specialFruit = c.specialFruit;
    this->map = c.map;
    this->specialSword = c.specialSword;
    this->specialArmor = c.specialArmor;
    return *this;
    }
    void Forest::startLevel() {
        king -> setLocation(0);
        Environment::printMsg(FOREST_STORY);
        startUserInput();
    }
    void Forest::startUserInput() {
        std::string input;
        while ( forestCompleted != true ) {
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
    void Forest::moveKing() {
        std::string moveStr = king->forward();
        stageCompleted = false;
        std::cout << moveStr << std::endl;
        printNextLocation();
    }
    void Forest::printNextLocation() {
        int currLocation = king->getLocation();
        stageCompleted = false;
        if (currLocation == 0) {
            Environment::printMsg(FOREST_STORY);
        } else if (currLocation == HORSE_LOCATION) {
            Environment::printMsg(HORSE_MSG);
            completeHorseLocation();
        } else if (currLocation == FOREST_LEADER_LOCATION) {
            printForestLeaderLocation();
            if (!answeredRiddle) {
                completeForestLeaderLocation();
                if (!answeredRiddle) {
                Environment::printMsg(RIDDLE_NOT_ANSWERED_MSG);
                    stageCompleted = true;
                    forestCompleted = true;
                } else {
                Environment::printMsg(RIDDLE_ANSWERED_MSG);
                Environment::printMsg(MAP_RECEIVED_MSG);
                king->pickUpItem(map);
                }
            } else {
                Environment::printMsg(NPC_DONE_MSG);
            }
        } else if (currLocation == LION_LOCATION) {
            Environment::printMsg(LION_LOC_MSG);
            lionFight();
            completeLionLocation();
        } else if (currLocation == SPECIAL_FRUIT_LOCATION) {
            printSpecialFruitLocation();
            currentLocationObj = specialFruit;
            completeObjLocation();
            currentLocationObj = nullptr;
        } else if (currLocation == SPECIAL_ARMOR_LOCATION) {
            printSpecialArmorLocation();
            currentLocationObj = specialArmor;
            completeObjLocation();
            currentLocationObj = nullptr;
        } else if (currLocation == SPECIAL_SWORD_LOCATION) {
            printSpecialSwordLocation();
            currentLocationObj = specialSword;
            completeObjLocation();
            currentLocationObj = nullptr;
        } else if (currLocation == BACK_TO_FIRST_LOCATION) {
            completeJungle();
        } else {
            Environment::printMsg(EMPTY_LOC_MSG);
            stageCompleted = true;
        }
    }
    void Forest::completeJungle() {
        std::string input;
        stageCompleted = false;
        while (!stageCompleted) {
            if (king->getHp() < 100) {
                Environment::printMsg(HEALTH_LOW_MSG);
                std::cout << king->getName() <<
                " health: " << king->getHp() << std::endl;
                input = Environment::getInput();
                if (input == "eat") {
                    king->heal(100);
                    std::cout << king->getName()
                    << " health: " << king->getHp() << std::endl;
                    king->putDownItem(specialFruit);
                    } else {
                    generalInputs(input, HEALTH_LOW_MSG);
                }
            }
            Environment::printMsg(BACK_TO_FIRST_LOC_MSG);
            input = Environment::getInput();
            if (input == "read") {
                stageCompleted = true;
                king->putDownItem(map);
                forestCompleted = true;
            } else {
                generalInputs(input, BACK_TO_FIRST_LOC_MSG);
            }
    }
    }
    void Forest::printSpecialFruitLocation() {
    if (!itemPicked) {
        Environment::printMsg(SPECIAL_FRUIT_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(FRUIT_PICKED_MSG);
    }
}
void Forest::printSpecialArmorLocation() {
    if (!itemPicked) {
        Environment::printMsg(SPECIAL_ARMOR_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(SPECIAL_ARMOR_PICKED_MSG);
    }
}
void Forest::printSpecialSwordLocation() {
    if (!itemPicked) {
        Environment::printMsg(SPECIAL_SWORD_MSG);
        Environment::printMsg(OBJ_INTERACT_MSG);
    } else {
        Environment::printMsg(SPECIAL_SWORD_PICKED_MSG);
    }
}
void Forest::completeObjLocation() {
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
            generalInputs(input, getCurrentLocation(king->getLocation()));
        }
        if (!itemPicked && input != "print")
            getCurrentLocation(king->getLocation());
        if (itemPicked && !stageCompleted)
            Environment::printMsg(DONE_MSG);
    }
    itemPicked = false;//reset for next location
}
void Forest::dropItem() {
    if (itemPicked) {
        king->putDownItem(currentLocationObj);
        itemPicked = false;
        Environment::printMsg(DROPPED);
    } else {
        Environment::printMsg(NOT_PICKED_YET);
    }
}
void Forest::pickItem() {
    if (!itemPicked) {
        itemPicked = true;
        king->pickUpItem(currentLocationObj);
        Environment::printMsg(PICKED);
        Environment::printMsg(DROP_OBJ);
    } else {
        Environment::printMsg(ALREADY_PICKED);
    }
}


    void Forest::printForestLeaderLocation() {
    if (!stageCompleted)
        Environment::printMsg(FOREST_LEADER_LOC_MSG);
    else
        Environment::printMsg(NPC_DONE_MSG);
}
void Forest::completeForestLeaderLocation() {
    std::string input;
    stageCompleted = false;
    while (!stageCompleted) {
        input = Environment::getInput();
        if (input == "a" || input == "A") {
            stageCompleted = true;
            answeredRiddle = true;
        } else if (input == "b" || input == "B" || input == "c"
        || input == "C" || input == "d" || input == "D") {
            stageCompleted = true;
            king->setHp(100);
        } else {
            generalInputs(input, FOREST_LEADER_LOC_MSG);
        }
    }
}

    void Forest::lionFight() {
        std::string input;
        stageCompleted = false;
        while (!stageCompleted) {
            while (king->getHp() > 0 && lion->getHealth() > 0) {
                std::cout <<
                "\nEnter 'body' to hit the body,"
                <<"'head' to hit the head, exit to quit game.\n";
            input = Environment::getInput();
            if (input == "print") {
                std::cout << "Battling the lion" << std::endl;
            } else if (input == "exit") {
                Environment::printMsg(EXIT_MSG);
                forestCompleted = true;
                stageCompleted = true;
                king->setHp(100);
            } else if (input == "body") {
                std::cout << king->attack("the Lion ") << std::endl;
                std::cout << "--------------------------------------------"
                << std::endl;
                lion->kill(lion->ATTACK_DMG);
                king->setHp(25);
                std::cout <<
                "King's Health:" << king->getHp() << std::endl;
                std::cout <<
                "Lion's Health: "
                << lion->getHealth() << std::endl;
            } else if (input == "head") {
                std::cout << king->attack("the Lion ") << std::endl;
                std::cout <<
                "--------------------------------------------"
                << std::endl;
                lion->kill(lion->SPECIAL_ATTACK_DMG);
            }
            }
                if (lion->getHealth() <= 0) {
                    lionDefeated = true;
                }
                std::cout << "\n\nKing's Health: "
                << king->getHp() << std::endl;
                stageCompleted = true;
        }
    }
    void Forest::completeLionLocation() {
        if (lionDefeated) {
            Environment::printMsg(LION_DEFEATED);
        }
    }
    void Forest::completeHorseLocation() {
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

    void Forest::generalInputs(const std::string &input
    , const std::string &location) {
     if ( input == "help" ) {
        printHelp();
        Environment::printMsg(location);
    } else if ( input == "print" ) {
        Environment::printMsg(location);
    } else if ( input == "exit" ) {
        Environment::printMsg(EXIT_MSG);
        forestCompleted = true;
        stageCompleted = true;
        king->setHp(100);
    } else if (input == "status") {
        king->printInfo();
        Environment::printMsg(location);
    } else {
        Environment::printMsg(UNKNOWN);
        Environment::printMsg(location);
    }
}

std::string Forest::getCurrentLocation(const int randomEmpty) {
        int currentLocation = king->getLocation();
    if (currentLocation == 0) {
        Environment::printMsg(FOREST_STORY);
    } else if ( currentLocation == HORSE_LOCATION ) {
        Environment::printMsg(HORSE_MSG);
    } else if (currentLocation == FOREST_LEADER_LOCATION) {
        printForestLeaderLocation();
    } else if (currentLocation == SPECIAL_FRUIT_LOCATION) {
        printSpecialFruitLocation();
    } else if (currentLocation == SPECIAL_SWORD_LOCATION) {
        printSpecialSwordLocation();
    } else if (currentLocation == SPECIAL_ARMOR_LOCATION) {
        printSpecialArmorLocation();
    } else if (currentLocation == LION_LOCATION) {
        lionFight();
    } else {
        Environment::printMsg(EMPTY_LOC_MSG);
    }
    return "";
}

    void Forest::endLevel() {
        delete lion;
        delete forestLeader;
        delete map;
        delete specialFruit;
    }

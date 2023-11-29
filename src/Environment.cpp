
#include <iostream>
#include "../include/Environment.h"
#include "King.h"

Environment::Environment() {
}
Environment::~Environment() {}

void Environment::printMsg(const std::string &msg) {
    std::cout << msg << std::endl;
}

std::string Environment::getInput() {
    std::string input;
    std::cout << ">";
    std::cin >> input;
    return input;
}
void Environment::startLevel() {
    printStory();
    startPlaying();
    endLevel();
}

void Environment::printCurrentLocation() {}

void Environment::printHelp() {
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Help" << std::endl;
    std::cout << "Enter move to walk forward" << std::endl;
    std::cout << "Enter touch to touch object in current location" << std::endl;
    std::cout << "Enter examine to examine object in current location"
    << std::endl;
    std::cout << "Enter speak to interact to NPC in current location"
    << std::endl;
    std::cout << "Enter print to print current location" << std::endl;
    std::cout << "Enter status to print current status" << std::endl;
    std::cout << "Enter help to print all the options" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

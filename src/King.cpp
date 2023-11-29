#include <iostream>
#include <algorithm>
#include <iterator>
#include "../include/King.h"
#include "../include/Object.h"
    // King constructor setting the name to the provided name.
    King::King(const std::string &name)
:_name(name) {}
    // sets the name of the King
     void King::setName(const std::string &newName) {
        _name = newName;
    }
    void King::setLocation(int loc) {
        row = loc;
    }
// Default king constructor
King::King() {
}

void King::createPlayer() {
    std::string prefix = "King ";
    std::string name = "";
    std::cout << "Enter Player name: ";
    std::cin >> name;
    prefix += name;
    setName(prefix);
}
// returns the name of kings
    std::string King::getName() {
        return _name;
    }
    // deals damage to the kings hp
    void King::setHp(int damage) {
        _hp -= damage;
    }
    // heals the kings hp
    void King::heal(int heal) {
        _hp = heal;
    }
    // prints the current status of the king.
    void King::printInfo() {
        std::cout << "Name : " <<_name << std::endl;
        std::cout << "Health : " << _hp << std::endl;
        std::cout << "King's Satchel: ";
        for (Object* obj : satchel)
            std::cout << obj->getName() << " ";
        std::cout << std::endl;
    }
    // getter for health
    int King::getHp() {
        return _hp;
    }
    // puts the provided Object in the Kings satchels.
    void King::pickUpItem(Object *item) {
        satchel.push_back(item);
    }
    // searches satchel vector and puts down the provided Object
    void King::putDownItem(Object *item) {
        std::string itemName = item->getName();
        auto rm = std::remove_if(satchel.begin(), satchel.end()
        , [itemName](Object* object) {
            return object->getName() == itemName;
        });

        if (rm != satchel.end()) {
            satchel.erase(rm, satchel.end());
        }
    }
    //returns the object with the same name if it is in satchel
    // if not returns nullptr
    Object* King::getItem(const std::string &itemName) {
        for (int i = 0; i < satchel.size(); i++) {
            if (satchel.at(i)->getName() == itemName) {
                return satchel.at(i);
            }
        }
        return nullptr;
    }
    //returns true or false if satchel contains provided item
    bool King::hasItem(const std::string &itemName) {
        for (int i = 0; i < satchel.size(); i++) {
            if (satchel.at(i)->getName() == itemName) {
                return true;
            }
        }
        return false;
    }
    //returns a string of MSG_ATTACK + target
     std::string King::attack(const std::string &target) {
        std::string attack = MSG_ATTACK + target;
        return attack;
    }
    //returns the size of the satchel
    int King::getSatchelSize() {
        return satchel.size();
    }

     std::string King::persuade() {
        return PERSUADE_MSG;
    }
    int King::getLocation() {
        return row;
    }

     std::string King::forward() {
        if (row + 1 != 9) {
            row++;
            return FORWARD;
        } else {
            return "A wall Blocks your path";
        }
    }
    // returns string default run output
     std::string King::run() {
        return RUN;
    }

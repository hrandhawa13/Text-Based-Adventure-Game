
#ifndef King_H_INCLUDED
#define King_H_INCLUDED
#include <vector>
#include <string>
// #include <utility>
#include "./Object.h"


class King{
 private:
static constexpr const char* const EXAMINE =
"You examine ";
static constexpr const char* const TOUCH =
"You touch ";
static constexpr const char* const LOOK =
"You inspect ";
static constexpr const char* const RUN =
"You start running ";
static constexpr const char* const BLOCKED =
"A wall blocks Your path ";
static constexpr const char* const FORWARD =
"You moved forward ";
static constexpr const char* const MSG_ATTACK =
"You swing your sword at ";
static constexpr const char* const PERSUADE_MSG =
"Believe me i am telling the truth.";

 public:
King();
explicit King(const std::string &name);
void setName(const std::string &name);
virtual std::string getName();
void createPlayer();
int getHp();
int getLocation();
void setLocation(int n);
int getSatchelSize();
void pickUpItem(Object *item);
void putDownItem(Object *item);
bool hasItem(const std::string &itemName);
Object* getItem(const std::string &itemName);
void setHp(int healthDamage);
void heal(int heal);
void printInfo();
std::string attack(const std::string &target);
std::string persuade();
std::string forward();
std::string run();


 protected:
    int _hp = 100;
    std::string _name;
    int row = 0;
    mutable std::vector<Object*> satchel;
};
#endif

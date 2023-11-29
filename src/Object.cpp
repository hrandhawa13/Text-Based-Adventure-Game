#include "Object.h"

Object::~Object() {}
Object::Object() {}
Object::Object(const std::string &aName, const std::string &aDescription) {
    name = aName;
    description = aDescription;
}
std::string Object::getName() { return name; }
std::string Object::getDescription() { return description; }
std::string Object::look() {
  return "You are looking at " + name;
}

std::string Object::touch() {
  return "You touched " + name;
}

std::string Object::examine() {
  return "Examining " + name + ":" + description;
}
std::string Object::throwObject() {
  return "Throwing object :" + name;
}
char Object::getSymbol() {
  return name.empty() ? ' ' : name.at(0);
}

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <string>

class Object{
 public:
    virtual ~Object();
    Object();
    Object(const std::string &name, const std::string &description);
    virtual std::string getName();
    virtual std::string getDescription();
    virtual std::string look();
    virtual std::string touch();
    virtual std::string examine();
    virtual std::string throwObject();
    virtual char getSymbol();
 protected:
    std::string name;
    std::string description;
};
#endif

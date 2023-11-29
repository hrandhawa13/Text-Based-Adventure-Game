#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include <string>

class NPC{
 public:
    virtual ~NPC();
    NPC() {};
    explicit NPC(std::string name);
    virtual std::string getName();
    virtual std::string getDialogue();
    virtual char getSymbol();
 protected:
    std::string name;
};
#endif

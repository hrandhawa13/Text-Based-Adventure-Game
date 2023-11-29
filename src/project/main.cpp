#include <iostream>
// #include "../../include/King.h"

// #include "../../include/Object.h"
#include "../../include/Castle.h"
#include "Cave.h"
#include "Forest.h"

int main(int argc, char *argv[]) {
    King *king = new King();
    king->createPlayer();
    Castle castle(king);
    castle.startLevel();

    if (king->getHp() > 0) {
        Forest forest(king);
        forest.startLevel();
        if (king->getHp() > 0) {
            Cave cave(king);
            cave.startLevel();
            cave.endLevel();
        }
        forest.endLevel();
    }
    castle.cleanUp();

    delete king;
    return 0;
}

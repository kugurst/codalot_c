#include "test_codalot.h"

TestCodalot::TestCodalot() {
    for (int i = 0; i < 6; ++i) {
        Knight *knight = (Knight *)malloc(sizeof(Knight));
        new(knight) Knight;

        knights.push_back(knight);
    }
}

void TestCodalot::setKnight(int id, KnightPosition position) {
    Knight *knight = knights[id];
    knight->setInTavern(false);
    knight->setInTrainingYard(false);
    switch (position) {
        case TAVERN: {
            knight->setInTavern(true);
            break;
        }
        case TRAINING_YARD: {
            knight->setInTrainingYard(true);
            break;
        }
    }
}

int TestCodalot::calculateEarnedXp() {
    int total = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        total += knight->getXp();
    }
    return total;
}
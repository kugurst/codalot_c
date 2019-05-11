#include "test_codalot.h"

TestCodalot::TestCodalot(int numKnights) : Codalot(numKnights) {}

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

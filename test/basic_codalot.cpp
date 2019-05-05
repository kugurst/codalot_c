#include <vector>
#include <cstdlib>
#include "codalot.cpp"
#include "../src/Knight.h"

using namespace std;

class BasicCodalot : public Codalot {
private:
    vector<Knight *> knights;

public:
    BasicCodalot();

    void setKnight(int id, KnightPosition position);
    void process();
    int calculateEarnedXp();

    void clearKnights();
    void addKnightToTrainingYard(Knight *knight);
    void addKnightToTavern(Knight *knight);
    void grantBonusXp();
};

BasicCodalot::BasicCodalot() {
    for (int i = 0; i < 6; ++i) {
        Knight *knight = (Knight *)malloc(sizeof(Knight));
        new(knight) Knight;

        knights.push_back(knight);
    }
}

void BasicCodalot::setKnight(int id, KnightPosition position) {
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

void BasicCodalot::process() {
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        knight->incrementStamina(knight->isInTavern() ? 1 : -1);
        knight->incrementXp(knight->isInTrainingYard() ? 1 : 0);
    }
}

int BasicCodalot::calculateEarnedXp() {
    int total = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        total += knight->getXp();
    }
    return total;
}

void BasicCodalot::clearKnights() {
    knights.resize(0);
}

void BasicCodalot::addKnightToTrainingYard(Knight *knight) {
    knights.push_back(knight);
    knight->setInTrainingYard(true);
    knight->setInTavern(false);
}

void BasicCodalot::addKnightToTavern(Knight *knight) {
    knights.push_back(knight);
    knight->setInTavern(true);
    knight->setInTrainingYard(false);
}

void BasicCodalot::grantBonusXp() {
    int bonusKnights = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        if (knight->getXp() >= 3) {
            bonusKnights++;
        }
    }
    if (bonusKnights == 3) {
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight *knight = *it;
            if (knight->getXp() >= 3) {
                knight->setXp(knight->getXp() + 5);
            }
        }
    }
    if (bonusKnights == 5) {
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight *knight = *it;
            if (knight->getXp() >= 3) {
                knight->setXp(knight->getXp() + 10);
            }
        }
    }
    if (bonusKnights == 6) {
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight *knight = *it;
            if (knight->getXp() >= 3) {
                knight->setXp(knight->getXp() + 20);
            }
        }
    }
}
#include "Codalot.h"

Codalot::Codalot() : Codalot(12) {}

Codalot::Codalot(unsigned int numKnights) {
    for (int i = 0; i < numKnights; ++i) {
        Knight *knight = new Knight;
        knights.push_back(knight);
    }
}

Codalot::~Codalot() {
    Codalot::clearKnights();
}

void Codalot::clearKnights() {
    for(int i = 0; i < knights.size(); ++i) {
        delete knights[i];
    }
    knights.resize(0);
}

void Codalot::moveKnightToTrainingYard(Knight& knight) {
    knight.setInTrainingYard(true);
    knight.setInTavern(false);
}

void Codalot::moveKnightToTavern(Knight& knight) {
    knight.setInTavern(true);
    knight.setInTrainingYard(false);
}

void Codalot::timeInterval() {
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight& knight = **it;
        int randomVal = rand() % 2;
        if (randomVal == 0) {
            moveKnightToTrainingYard(knight);
        } 
        else if (randomVal == 1) {
            moveKnightToTavern(knight);
        }
    }
    process();
}

void Codalot::process() {
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        knight->incrementStamina(knight->isInTavern() ? 1 : -1);
        knight->incrementXp(knight->isInTrainingYard() ? 1 : 0);
    }
}

int Codalot::getNumberOfKnights() {
    return knights.size();
}

void Codalot::grantBonusXp() {
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

int Codalot::calculateEarnedXp() {
    int total = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        total += knight->getXp();
    }
    return total;
}
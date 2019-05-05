#include "Codalot.h"

void Codalot::clearKnights() {
    knights.resize(0);
}

void Codalot::addKnightToTrainingYard(Knight& knight) {
    knights.push_back(&knight);
    knight.setInTrainingYard(true);
    knight.setInTavern(false);
}

void Codalot::addKnightToTavern(Knight& knight) {
    knights.push_back(&knight);
    knight.setInTavern(true);
    knight.setInTrainingYard(false);
}

void Codalot::process() {
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight *knight = *it;
        knight->incrementStamina(knight->isInTavern() ? 1 : -1);
        knight->incrementXp(knight->isInTrainingYard() ? 1 : 0);
    }
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
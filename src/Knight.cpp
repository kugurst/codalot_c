#include "Knight.h"


Knight::Knight() {
    xp = 0;
    stamina = 0;
}

int Knight::getXp() {
    return xp;
}

void Knight::setXp(int xp) {
    this->xp = xp;
}

void Knight::incrementXp(int xp) {
    this->xp += xp;
}

int Knight::getStamina() {
    return stamina;
}

void Knight::setStamina(int stamina) {
    this->stamina = stamina;
}

void Knight::incrementStamina(int stamina) {
    this->stamina += stamina;
}

bool Knight::isInTavern() {
    return inTavern;
}

void Knight::setInTavern(bool inTavern) {
    this->inTavern = inTavern;
}

bool Knight::isInTrainingYard() {
    return inTrainingYard;
}

void Knight::setInTrainingYard(bool inTrainingYard) {
    this->inTrainingYard = inTrainingYard;
}

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Codalot.h"

using namespace std;

int main(int argc, char **argv) {
    Codalot *codalot = (Codalot *)malloc(sizeof(Codalot));
    new(codalot) Codalot;

    vector<Knight> knights;
    for (int i = 0; i < 6; ++i) {
        Knight *knight = (Knight *)malloc(sizeof(Knight));
        new(knight) Knight;

        knights.push_back(*knight);
    }

    for (int i = 0; i < 24; ++i) {
        codalot->clearKnights();
        for (auto it = knights.begin(); it != knights.end(); ++it) {
            Knight& knight = *it;
            int randomVal = rand() % 2;
            if (randomVal == 0) {
                codalot->addKnightToTrainingYard(knight);
            } else if (randomVal == 1) {
                codalot->addKnightToTavern(knight);
            }
        }
        codalot->process();
    }
    codalot->grantBonusXp();

    int totalXp = 0;
    for (auto it = knights.begin(); it != knights.end(); ++it) {
        Knight& knight = *it;
        totalXp += knight.getXp();
    }
    cout << "Total XP earned by all " << knights.size() << " knights: " << totalXp << endl;
}
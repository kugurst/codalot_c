#include <vector>

#include "Knight.h"

using namespace std;

class Codalot {
protected:
    vector<Knight *> knights;

public:
    Codalot() {}

    void clearKnights();
    void addKnightToTrainingYard(Knight& knight);
    void addKnightToTavern(Knight& knight);
    void process();
    void grantBonusXp();
};
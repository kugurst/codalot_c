#include <vector>

#include "Knight.h"

using namespace std;

class Codalot {

public:

    Codalot();
    Codalot(unsigned int numKnights);
    ~Codalot();

    void clearKnights();
    void timeInterval();
    void grantBonusXp();
    int calculateEarnedXp();
    void process();

    int getNumberOfKnights();

protected:
    vector<Knight *> knights;

private:
    void moveKnightToTrainingYard(Knight& knight);
    void moveKnightToTavern(Knight& knight);

};
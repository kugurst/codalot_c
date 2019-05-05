#include <vector>
#include <cstdlib>
#include "knight_position.h"
#include "../src/Codalot.h"

using namespace std;

class TestCodalot : public Codalot {

public:
    TestCodalot();

    void setKnight(int id, KnightPosition position);
    int calculateEarnedXp();

};
#include <iostream>
#include <cassert>
#include "test_codalot.h"

using namespace std;

int main(int argc, char **argv) {
    
    TestCodalot* codalot = new TestCodalot(6);

    codalot->setKnight(0, TAVERN);
    codalot->setKnight(1, TAVERN);
    codalot->setKnight(2, TRAINING_YARD);
    codalot->setKnight(3, TRAINING_YARD);
    codalot->setKnight(4, TRAINING_YARD);
    codalot->setKnight(5, TRAINING_YARD);
    codalot->process();

    assert(codalot->calculateEarnedXp() == 4);

    delete codalot;
}

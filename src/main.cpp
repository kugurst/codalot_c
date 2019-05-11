#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

#include "Codalot.h"

using namespace std;

int main(int argc, char **argv) {

    Codalot *codalot = nullptr; 

    if(argc > 1){
        string arg = argv[1];
        int numKnights;
        try {
            size_t pos;
            numKnights = std::stoi(arg, &pos);
            if (pos < arg.size()) {
                std::cerr << "Trailing characters after number: " << arg << '\n';
            }
        } 
        catch (std::invalid_argument const &ex) {
            std::cerr << "Invalid number: " << arg << '\n';
            return -1;
        } 
        catch (std::out_of_range const &ex) {
            std::cerr << "Number out of range: " << arg << '\n';
            return -1;
        }
        
        if( numKnights > -1 ) {
            codalot = new Codalot(numKnights);
        }
        else {
            std::cerr << "Number out of range: " << arg << '\n';
            return -1;
        }
    }
    
    if(codalot == nullptr) { 
        codalot = new Codalot();
    }

    for(int i = 0; i < 24; ++i) {
        codalot->timeInterval();
    }
    codalot->grantBonusXp();

    cout << "Total XP earned by all " << codalot->getNumberOfKnights() << " knights: " << codalot->calculateEarnedXp() << endl;

    delete codalot;
}
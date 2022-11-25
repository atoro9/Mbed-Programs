#include "mbed.h"
class Data
 {
    
    public:
    
    int winRatio(); // THis function returns the: timer value, total number of trials and the ein loss ratio
    void counter();
    void exit();
    
    
    
    private:
    int trialNum;
    int wins;
    int total;
    
    
    
};
    
    
    
    
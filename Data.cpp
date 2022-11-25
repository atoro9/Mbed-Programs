#include "uLCD_4DGL.h"
#include "mbed.h"
#include "Display.h"
#include "Speaker.h"
#include "Data.h"
#include "PinDetect.h"

extern uLCD_4DGL uLCD;
extern Speaker mySpeaker;
extern Display screen;
Timer t;


int Data :: winRatio()// THis function returns the: timer value, total number of trials and the ein loss ratio
{
    
    counter();
    uLCD.color(0xFFFFFFFF);
    uLCD.printf("Time %d ms \n",t.read_ms());
    uLCD.printf("Trial Number: %d  \n \n ",total);
    return uLCD.printf("Wins over losses: %d / %d \n",wins,total);

}

void Data :: counter()// This is a counter that tells you the amount of trials that have eleapsed
{
    total++;
    if (screen.getLR()==true)
        wins++;

}
void Data :: exit() // This is a function that is called when you hit the third button
{
/* These are set to -1 becasue I made it to where you can start the game again if you hit one of the other buttons
it starts the trials again and I wanted it to have an accurate number
*/
    uLCD.printf("Trial Number: %d  \n \n ",total);
    uLCD.printf("Wins over losses: %d / %d \n",wins,total);
    uLCD.printf("Press any Button to start new trial \n");

    trialNum =-1; 
    wins=-1; 
    total=-1;
}



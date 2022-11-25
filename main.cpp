#include "mbed.h"
#include "uLCD_4DGL.h"
#include "Speaker.h"
#include "PinDetect.h"
#include "Display.h"
#include "Data.h"
extern uLCD_4DGL uLCD;
extern Speaker mySpeaker;
extern Timer t;
PinDetect pb1(p21); //you can use different pins
PinDetect pb2(p22); //you can use different pins
PinDetect pb3(p23);
Display screen;
Data data;

int main()
{
    srand(time(0)); // This sets the seed for the random numbers 
    pb1.setSampleFrequency(); // Sets the sample frequency for the buttons 20ms
    pb2.setSampleFrequency();
    pb3.setSampleFrequency();
  

    screen.playJingle(); // This is the intital step of playing the jingle 
    screen.DisplayAll(); // This is the initial step of setting up the display
    pb1.mode(PullUp); // Sets each switch to pull up 
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    wait(.01);
    bool GETOUT = false;
    while (!GETOUT) // Taken from the prelab this detects a button press
     {
        if (!pb1) // This is the Button that exits the problem
        {
            GETOUT = true;
            uLCD.cls();
            t.stop();
            data.exit();
            wait(2.0);
        }//end if statement

        else if (!pb2) // This is the button that selects the left bin 
         { 
            GETOUT = true;
            t.stop();
            uLCD.cls();
            screen.CompareLR();
            data.winRatio();
            wait(2.0);
            screen.DisplayAll();
        }
        else if(!pb3) // This is the button that selects the right bin
        {
            t.stop();
            uLCD.cls();
            screen.CompareRL();
            data.winRatio();
            wait(2.0);
            screen.DisplayAll();
        } 
    }

}
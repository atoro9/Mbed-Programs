#include "uLCD_4DGL.h"
#include "mbed.h"
#include "Display.h"
#include "Speaker.h"
#include "Data.h"

uLCD_4DGL uLCD(p9, p10, p11);
Speaker mySpeaker(p25);
void Display :: playJingle()// This creates the intro screen and jingle
{
    uLCD.printf("\n Hello! \n"); // This is the introduction screen
    mySpeaker.PlayNote(261.63,0.25,0.1);
    mySpeaker.PlayNote(261.63,0.25,0.1);
    mySpeaker.PlayNote(261.63,0.25,0.1);
    mySpeaker.PlayNote(329.6,0.25,0.1);
    mySpeaker.PlayNote(197.78,0.25,0.1);
    mySpeaker.PlayNote(261.63,0.25,0.1);
    mySpeaker.PlayNote(329.6,0.25,0.1);
    mySpeaker.PlayNote(261.63,0.25,0.1);
    wait(1.0);

}
bool Display :: getLR() // Simple getter to get the value of LR
{
    return LR;
}
void Display :: clearArray()// Clears the Array after the function runs

{
    for(int i=0; i<(sizeof(test2)/sizeof(bool)); i++) {
        test2[i]=false;

    }
    for(int i=0; i<(sizeof(test)/sizeof(bool)); i++) {
        test[i]=false;

    }

}
void Display :: drawBIn()// Draws the lest and right bin
{
    uLCD.filled_rectangle(0, 0, 60, 120, 0xFFFFFF);
    uLCD.filled_rectangle(60, 0, 120,120, 0xFFFFFF);// 000000
    uLCD.line(60,0, 60,120, 0x000000);
}
void Display :: CompareLR()// compares the Left and Right values and sets LR to be T/F

{
    if (leftobjectNum > rightobjectNum) {
        uLCD.printf("You Were Correct\n");
        LR=true;
    } else {
        uLCD.printf("You Were Wrong\n");
        LR=false;
    }
}

void Display :: CompareRL() // compares the Right and left values and sets LR to be T/F

{
    if (rightobjectNum > leftobjectNum) {
        uLCD.color(0xFFFFFFFF);
        uLCD.printf("You Were Correct\n");
        LR=true;
    } else {
        uLCD.color(0xFFFFFFFF);
        uLCD.printf("You Were Wrong\n");
        LR=false;
    }
}




void Display :: drawObject() // This function Draws the objects in the bins
/* It uses two boolean arrays, one for each bin that tells you if there is an object there
if there is one it decrements the for loop and starts again usign new values
*/
{
    leftobjectNum=rand()%12 +1; // Objects in the Left bin
    rightobjectNum=rand()% 12+1; // Objects in the Right bin
    while(leftobjectNum==rightobjectNum) {
        // This ensures that the number of objects in each bin isn't equal
        leftobjectNum=rand()%12+1;
        rightobjectNum=rand()% 12+1;

    }
    for(int i=0; i<leftobjectNum; i++) {
        //
        int x_1=rand()%3 + 1; // This variable gives the x value in the 3 x 6 grid
        int y_1=rand()%6 + 1;// This variable gives the y value in the 3 x 6 grid
        int x=(x_1*20)-10; // This converts the x value into a pixel value
        int y=(y_1*20)-10; // this converts the y value into a pixel value
        int Btest=x_1*y_1; // This is used for the index of the boolean array
        

        if(test2[Btest]==false) {
            int selectObj=rand()%3 +1; // This selects the object to draw
            switch (selectObj) {
                case(1):
                    uLCD.filled_circle(x,y,(rand()%7+1),(rand()%0xFFFFFF + 1));
                    test2[Btest]=true;
                    break;

                case(2):

                    uLCD.filled_rectangle(x,y,(x)+(rand()%9+ 1),(y+rand()%10+1),(rand()%0xFFFFFF + 1) );
                    test2[Btest]=true;
                    break;

                case(3):
                    uLCD.triangle( x,y,x,y-10,x+10,y,(rand()%0xFFFFFF + 1) );
                    test2[Btest]=true;
            }
        } else {
            i--;
        }

    }
    for(int i=0; i<rightobjectNum; i++) { // This generates the objects in the rightbin
        int x_1=rand()%3 + 1; //  This variable gives the x value in the 3 x 6 grid
        int y_1=rand()%6 + 1; // This variable gives the y value in the 3 x 6 grid
        int x=(x_1*20)-10; // This converts the x value into a pixel value
        int y=(y_1*20)-10;// This converts the y value into a pixel value
        int Btest=x_1*y_1;// This gets the index for the boolean array
        if(test[Btest]==false) {

            int selectObj=rand()%3 +1;
            switch (selectObj) {
                case(1):
                    uLCD.filled_circle(x+60,y,(rand()%7+1),(rand()%0xFFFFFF + 1));// Same code as the leftbin but the x value is offset by 60
                    test[Btest]=true;
                    break;

                case(2):
                    uLCD.filled_rectangle(x+60,y,(x+60)+(rand()%9+ 1),(y+rand()%10+1),(rand()%0xFFFFFF + 1) );// Same code as the leftbin but the x value is offset by 60
                    test[Btest]=true;
                    break;

                case(3):
                    uLCD.triangle( x+60,y,x+60,y-10,x+70,y,(rand()%0xFFFFFF + 1) ); // Same code as the leftbin but the x value is offset by 60
                    test[Btest]=true;
                    break;



            }

        } else {
            i--;
        }

    }
    this->clearArray();




}






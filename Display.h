#include "mbed.h"
extern Timer t;
class Display
{
 public:
 
 void  drawBIn();// This draws the two Bins
 void  drawObject();// This draws The objects to the screen 
 void  playJingle();// This plays the jingle
 void clearArray(); // Clears the array
 void CompareLR(); // Compares The Left and Right values
 void CompareRL(); // Compares The Right and Left values
 bool getLR();// Gets the value of LR
 void DisplayAll() // function that brings everyhing together and Displays them 
 {
    t.reset();
    drawBIn();
    drawObject();
    t.start();
    
 }
 
 private:
 bool test2[19];
 bool test[19];
 bool LR;
 int leftobjectNum;
 int rightobjectNum;
 
 
 
 };
#ifndef _TRUCK_H
#define _TRUCK_H_

#include "Vehicle.h"

class Truck : public Vehicle {
public:
	Truck(){
       xPos = 0;
       yPos = 0;
     }
     
void draw(){
       drawPoint(mx+1,my);
       drawPoint(mx,my+1);
	   drawPoint(mx+1,my+1);
       drawPoint(mx+2,my+1);
     }
     
void drawPoint(int x,int y){
       gotoXY(x,y);
       cout << (char)223;
     }   
     
void erase(){
       if(outMap(mx,my)){
         mx = 0;
         my = 0;
       }
     }
     
void move(){
       mx ++;
     }
};

#endif // _TRUCK_H

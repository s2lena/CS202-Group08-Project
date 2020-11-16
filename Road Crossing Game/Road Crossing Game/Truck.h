#ifndef _TRUCK_H
#define _TRUCK_H_

#include "Vehicle.h"

class Truck : public Vehicle {
public:
Truck(){
       mx = 0;
       my = 0;
     }
     
Truck(int x,int y){
      mx = x;
      my = y;
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
         gotoXY(mx,my);
         cout << " ";
         mx = 1;
       }
     }
     
void move(){
       mx ++;
     }
};

#endif // _TRUCK_H

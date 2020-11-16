#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car(){
       mx = 0;
       my = 0;
     }
     
  Car(int x, int y){
    mx = x;
    my = y;
  }

void draw(){
       drawPoint(mx,my);
       drawPoint(mx,my+1);
       drawPoint(mx+1,my+1);
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

#endif // _CAR_H_

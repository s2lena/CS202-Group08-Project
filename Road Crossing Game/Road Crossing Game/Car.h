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
    erasePoint(mx,my);
    erasePoint(mx+1,my);
    erasePoint(mx,my+1);
    erasePoint(mx+1,my+1);
    erasePoint(mx+2,my+1);
    mx = 1;
    }
    erasePoint(mx,my);
    erasePoint(mx+1,my);
    erasePoint(mx,my+1);
    erasePoint(mx+1,my+1);
    erasePoint(mx+2,my+1);
     }

void erasePoint(int x, int y){
  goToXY(x,y);
  cout << " ";
}
     
void move(){
       mx ++;
     }
};

#endif // _CAR_H_

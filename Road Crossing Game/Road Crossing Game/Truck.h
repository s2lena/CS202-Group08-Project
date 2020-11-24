#ifndef _TRUCK_H
#define _TRUCK_H_

#include "Console.h"
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
  drawPoint(mx+2,my);
  drawPoint(mx,my+1);
  drawPoint(mx+1,my+1);
  drawPoint(mx+2,my+1);
  drawPoint(mx+3,my+1);
}
     
void drawPoint(int x,int y){
	GotoXY(x,y);
  cout << (char)223;
}   
     
void erase(){
  if(outMap(mx,my)){
    erasePoint(mx+1,my);
    erasePoint(mx+2,my);
    erasePoint(mx,my+1);
    erasePoint(mx+1,my+1);
    erasePoint(mx+2,my+1);
    erasePoint(mx+3,my+1);
    mx = 1;
    }
    erasePoint(mx+1,my);
    erasePoint(mx+2,my);
    erasePoint(mx,my+1);
    erasePoint(mx+1,my+1);
    erasePoint(mx+2,my+1);
    erasePoint(mx+3,my+1);
  }
    
void erasePoint(int x, int y){
	GotoXY(x,y);
  cout << " ";
}
     
void move(){
  mx ++;
}

};

#endif // _TRUCK_H

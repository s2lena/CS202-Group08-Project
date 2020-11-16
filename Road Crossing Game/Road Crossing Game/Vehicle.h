#ifndef _VEHICLE_H_
#define _VEHICLE_H_

void gotoXY(int x, int y)  {  
   COORD coord; 
   coord.X = x;  
   coord.Y = y;  
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
 }  
 
bool outMap(int x,int y){
   if(x >= 90 || y >= 20 ){
     return true;
   }
   return false;
 }

class Vehicle {
public:
	int mx;
	int my;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Erase() = 0;
 
  int Vehicle::getX(){
    return mX;
}

  int Vehicle::getY(){
    return mY;
}

  bool outMap(int x,int y){
   if(x > 90 || y > 20 ){
     return true;
   }
   return false;
 }
};

#endif // _VEHICLE_H_

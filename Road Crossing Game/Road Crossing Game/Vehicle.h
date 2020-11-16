#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle {
public:
	int mx;
	int my;
	virtual void Move() = 0;
	virtual void Draw() = 0;
	virtual void Erase() = 0;
 
  int getX(){
    return mx;
}

  int getY(){
    return my;
}

  bool outMap(int x,int y){
   if(x > 90 || y > 20 ){
     return true;
   }
   return false;
 }
};

#endif // _VEHICLE_H_

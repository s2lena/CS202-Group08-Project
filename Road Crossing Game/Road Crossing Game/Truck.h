#ifndef _TRUCK_H
#define _TRUCK_H_

#include "Console.h"
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck() {
        mx = 0;
        my = 0;
    }
    Truck(int x,int y){
        mx = x;
        my = y;
    }

    void draw(){
        drawPoint(mx, my, my);
        drawPoint(mx+1,my, my);
        drawPoint(mx,my+1, my);
        drawPoint(mx+1,my+1, my);
        drawPoint(mx+2,my+1, my);
    }
     
    void drawPoint(int x,int y, int t){
	    GotoXY(x,y);
        if (y == t)
            cout << (char)219;
        else
            cout << (char)223;
    }   
     
    void erase(){
        erasePoint(mx, my);
        erasePoint(mx+1,my);
        erasePoint(mx,my+1);
        erasePoint(mx+1,my+1);
        erasePoint(mx+2,my+1);
    }
    
    void erasePoint(int x, int y){
	    GotoXY(x,y);
        cout << " ";
    }
     
    void move(){
        mx++;
        if(outMap(mx,my)) {
            mx = 30;
            //DrawCrossWalk();
        }
    }
    bool Impact(int x, int y) {
        int check_x[5] = { this->mx, this->mx + 1, this->mx, this->mx + 1, this->mx + 2 };
        int check_y[5] = { this->my, this->my, this->my + 1, this->my + 1, this->my + 1 };
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++)
                if (x + i == check_x[j] && y == check_y[j])
                    return true;
        }
        return false;
    }
};

#endif // _TRUCK_H

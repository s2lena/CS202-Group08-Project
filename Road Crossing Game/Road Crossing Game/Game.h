#ifndef _GAME_H_
#define _GAME_H_

#include "Bird.h"
#include "Dinosaur.h"
#include "Car.h"
#include "Truck.h"
#include "People.h"
#include "Console.h"
#include <vector>

const int y_truck = 16;
const int y_car = 8;
const int y_bird = 12;
const int y_dinosaur = 4;

class Game {
protected:
	vector<Truck> truck;
	vector<Car> car;
	vector<Bird> bird;
	vector<Dinosaur> dinosaur;
	People people;
	int level;
public:
	Game();
	void DrawGame();
	~Game();
	People GetPeople();
	vector<Car> GetCar();
	vector<Truck> GetTruck();
	vector<Bird> GetBird();
	vector<Dinosaur> GetDinosaur();
	void UpdatePosPeople(char moving);
	void UpdatePosAnimal();
	void UpdatePosVehicle();

	void ResetGame(); 
	void ExitGame(HANDLE); 
	void StartGame();
	void CreateGame(int lv);
};


#endif // _GAME_H_

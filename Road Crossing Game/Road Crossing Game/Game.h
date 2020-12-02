#ifndef _GAME_H_
#define _GAME_H_

#include "Bird.h"
#include "Dinosaur.h"
#include "Car.h"
#include "Truck.h"
#include "People.h"
#include "Console.h"
#include <vector>
#include <string>
#include <fstream>

const int y_truck = 16;
const int y_car = 8;
const int y_bird = 13;
const int y_dinosaur = 5;

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
	void EraseGame();
	~Game();
	People GetPeople();
	void ChangeState();
	void UpdatePosPeople(short i);
	void UpdatePosAnimal();
	void UpdatePosVehicle();
	void PauseGame(HANDLE);
	void ResumeGame(HANDLE);
	void ResetGame(); 
	void ExitGame(HANDLE); 
	void LoadGame();
	bool SaveGame();
	void CreateGame(int lv);
	bool LevelUp();
	int LogIn();
	bool SetGame(int a);
	bool IsImpact();
};

void Subthread();

#endif // _GAME_H_

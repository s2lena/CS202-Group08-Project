#include "Game.h"

Game::Game() {
	level = 1;
};

void Game::DrawGame() {
	for (int i = 0; i < truck.size(); i++)
		truck[i].draw();
	for (int i = 0; i < car.size(); i++)
		car[i].draw();
	for (int i = 0; i < bird.size(); i++)
		bird[i].Draw(); 
	for (int i = 0; i < dinosaur.size(); i++)
		dinosaur[i].Draw();
	people.Draw();
}

Game::~Game() {
	truck.erase(truck.begin(), truck.end());
	car.erase(car.begin(), car.end());
	bird.erase(bird.begin(), bird.end());
	dinosaur.erase(dinosaur.begin(), dinosaur.end());
}

People Game::GetPeople() {
	return people;
}

vector<Car> Game::GetCar() {
	return car;
}

vector<Truck> Game::GetTruck() {
	return truck;
}

vector<Bird> Game::GetBird() {
	return bird;
}

vector<Dinosaur> Game::GetDinosaur() {
	return dinosaur;
}

void Game::CreateGame(int lv) {
	level = lv;
	for (int i = 0; i < lv; i++) {
		int x_vehicle = 3 * i + 5;
		int x_animal = WIDTH - 3 * i - 5;
		Truck t(x_vehicle, y_truck);
		Car c(x_vehicle, y_car);
		Bird b(x_animal, y_bird);
		Dinosaur d(x_animal, y_dinosaur);
		truck.push_back(t);
		car.push_back(c);
		bird.push_back(b);
		dinosaur.push_back(d);
	}
}

void Game::ResetGame() {
	level = 1;
	this->CreateGame(level);
	this->people.Reset();
}

void Game::StartGame() {

}
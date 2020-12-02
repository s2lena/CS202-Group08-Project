#include "Game.h"

Game::Game() {
	level = 1;
}

void Game::DrawGame() {
	for (int i = 0; i < truck.size(); i++)
		truck[i].draw();
	for (int i = 0; i < car.size(); i++)
		car[i].draw();
	for (int i = 0; i < bird.size(); i++)
		bird[i].Draw(); 
	for (int i = 0; i < dinosaur.size(); i++)
		dinosaur[i].Draw();
}

void Game::EraseGame() {
	for (int i = 0; i < truck.size(); i++)
		truck[i].erase();
	for (int i = 0; i < car.size(); i++)
		car[i].erase();
	for (int i = 0; i < bird.size(); i++)
		bird[i].Erase();
	for (int i = 0; i < dinosaur.size(); i++)
		dinosaur[i].Erase();
}

Game::~Game() {
	truck.erase(truck.begin(), truck.end());
	car.erase(car.begin(), car.end());
	bird.erase(bird.begin(), bird.end());
	dinosaur.erase(dinosaur.begin(), dinosaur.end());
}

bool Game::IsImpact() {
	bool check = false;
	for (int i = 0; i < this->level; i++) {
		if (this->truck[i].Impact(this->people.mx, this->people.my))
			check = true;
		else if (this->car[i].Impact(this->people.mx, this->people.my))
			check = true;
		else if (this->bird[i].Impact(this->people.mx, this->people.my))
			check =  true;
		else if (this->dinosaur[i].Impact(this->people.mx, this->people.my))
			check = true;
		if (check)
			break;
	}
	return check;
}

void Game::ChangeState() {
	people.state = false;
}

People Game::GetPeople() {
	return this->people;
}

void Game::UpdatePosPeople(short i)
{
	switch (i)
	{
	case 1:
		this->people.Up(1);
		break;
	case 2:
		this->people.Down(1);
		break;
	case 3:
		this->people.Right(1);
		break;
	case 4:
		this->people.Left(1);
		break;
	default:
		break;
	}

}

void  Game::UpdatePosAnimal()
{
	for (int i = 0; i < level; i++)
	{
		bird[i].Move();
	}
	for (int i = 0; i < level; i++)
	{
		dinosaur[i].Move();
	}
}

void Game::UpdatePosVehicle()
{
	for (int i = 0; i < level; i++)
	{
		car[i].move();
	}
	for (int i = 0; i < level; i++)
	{
		truck[i].move();

	}
}

void Game::CreateGame(int lv) {
	level = lv;
	for (int i = 0; i < lv; i++) {
		int x_vehicle = 6 * i + 30;
		int x_animal = WIDTH - 6 * i;
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
	truck.erase(truck.begin(), truck.end());
	car.erase(car.begin(), car.end());
	bird.erase(bird.begin(), bird.end());
	dinosaur.erase(dinosaur.begin(), dinosaur.end());
	this->CreateGame(level);
	this->people.Reset();
}

bool Game::LevelUp() {
	bool check = false;
	if (this->level == 10) {
		GotoXY(65, 10);
		cout << "FINISH";
		GotoXY(55, 11);
		cout << "Congratulation!!";
		check = true;
	}
	else {
		this->level++;
		truck.erase(truck.begin(), truck.end());
		car.erase(car.begin(), car.end());
		bird.erase(bird.begin(), bird.end());
		dinosaur.erase(dinosaur.begin(), dinosaur.end());
		this->people.Reset();
		this->CreateGame(level);
	}
	return check;
}

void Game::ExitGame(HANDLE t)
{
	TerminateThread(t, 0);
	system("cls");
	DrawBoard();
	int x = 54;
	GotoXY(x, 8);
	cout << "(o^-^o) WE PASS CS202 (o^-^o)" << endl;
	GotoXY(x - 3, 9);
	cout << "(o^-^o) HAVE A NICE VACATION (o^-^o)" << endl;
	GotoXY(0, 20);
	exit(0);
}
void Game::PauseGame(HANDLE t)
{
	SuspendThread(t);
}
void Game::ResumeGame(HANDLE t)
{
	ResumeThread(t);
}


void Game::LoadGame() {
	string str = LoadFile();
	int x = 0; int y = 0;
	TextColor(7);
	if (str != "Exit") {
		ifstream ifs;
		ifs.open(str);
		ifs >> this->level;
		for (int i = 0; i < this->level; i++) {
			ifs >> x >> y;
			Truck t(x, y);
			this->truck.push_back(t);
		}

		for (int i = 0; i < this->level; i++) {
			ifs >> x >> y;
			Car c(x, y);
			this->car.push_back(c);
		}

		for (int i = 0; i < this->level; i++) {
			ifs >> x >> y;
			Bird b(x, y);
			this->bird.push_back(b);
		}

		for (int i = 0; i < this->level; i++) {
			ifs >> x >> y;
			Dinosaur d(x, y);
			this->dinosaur.push_back(d);
		}

		ifs >> people.mx >> people.my >> people.state;
		ifs.close();
	}
	else
		this->CreateGame(1);
}

bool Game::SaveGame() {
	DrawFrame(false);
	ofstream ofs;
	string tmp;
	int x = 53;  int y = 9;
	GotoXY(x + 7, y);
	cout << "SAVE GAME" << endl;
	GotoXY(x, y + 1);
	cout << "Input to save game: ";
	GotoXY(x, y + 2);
	cout << "Name: ";
	getline(cin, tmp);
	tmp = tmp + ".txt";
	SaveFile(tmp);
	ofs.open(tmp);
	ofs << this->level << endl;
	for (int i = 0; i < this->truck.size(); i++)
		ofs << truck[i].mx << " " << truck[i].my << " ";
	ofs << endl;
	for (int i = 0; i < this->car.size(); i++)
		ofs << car[i].mx << " " << car[i].my << " ";
	ofs << endl;
	for (int i = 0; i < this->bird.size(); i++)
		ofs << bird[i].a.x << " " << bird[i].a.y << " ";
	ofs << endl;
	for (int i = 0; i < this->dinosaur.size(); i++)
		ofs << dinosaur[i].a.x << " " << dinosaur[i].a.y << " ";
	ofs << endl;
	ofs << this->people.mx << " " << this->people.my << " " << this->people.state << endl;
	ofs.close();
	return ChoiceFrame("Do you want to continue?");
}

int Game::LogIn() {
	DrawBoard();
	ShowCur(false);
	int t = 50;
	int z = 5;
	GotoXY(t, z);
	for (int i = 0; i <= 30; i++) cout << "*";
	for (int i = 1; i <= 4; i++) {
		GotoXY(t, z + i); cout << "*";
		GotoXY(t + 30, z + i); cout << "*";
	}
	GotoXY(t, z + 5);
	for (int i = 0; i <= 30; i++) cout << "*";

	vector<string> menu = { "New Game", "Load Game", "Setting","Exit" };
	const int y = 6;
	const int x = 62;
	int pos = 0;
	int c = 0;
	bool check = true;
	while (check)
	{
		c = 0;
		for (int i = 0; i < 4; i++)
		{
			if (i == pos)
				TextColor(227);
			else
				TextColor(7);
			GotoXY(x, y + i);
			cout << menu[i];
		}
		switch ((c = _getch())) {
		case KEY_UP:
			pos = pos - 1;
			break;
		case KEY_DOWN:
			pos = pos + 1;
			break;
		case KEY_ENTER:
			check = false;
			break;
		default:
			break;
		}
		if (pos < 0)
			pos = pos + 4;
		if (pos >= 4)
			pos = pos - 4;
	}
	TextColor(7);
	return pos;
}

bool Game::SetGame(int a) {
	bool check = false;
	clrscr();
	switch (a) {
	case 0:
		this->CreateGame(1);
		break;
	case 1:
		this->LoadGame();
		break;
	case 2:
		GotoXY(62, 7);
		cout << "Not update Settings" << endl;
		GotoXY(0, 20);
		system("PAUSE");
		GotoXY(0, 20);
		cout << "                                         " << endl;
		check = true;
		break;
	default:
		this->ChangeState();
		break;
	}
	return check;
}
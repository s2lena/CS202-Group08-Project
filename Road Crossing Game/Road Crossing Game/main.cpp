#include "Console.h"
#include "Game.h"
#include <thread>

const int WIDTH=100;
const int HEIGHT=20;
const int LEFT = 30;
Game* game;
int MOVING;

void Subthread() {
	while (1) {
		if (!game->GetPeople().isDead()) {
			if (MOVING)
				game->GetPeople().Erase();
			game->UpdatePosPeople(MOVING);
			game->GetPeople().Draw();

			MOVING = 0;
			game->EraseGame();
			game->UpdatePosVehicle();
			game->UpdatePosAnimal();
			game->DrawGame();

			if (game->IsImpact()) {
				game->ProcessDead();
			}
			if (game->GetPeople().isFinish()) {
				if (game->LevelUp()) {
					game->ProcessFinish();
				}
				else {
					clrscr();
					DrawCrossWalk();
				}
			}
		}
		Sleep(100);
	}
}

int main() {
	FixConsoleWindow();
	game = new Game;
	game->SetGame(game->LogIn());
	clrscr();
	if (game->GetPeople().state) {
		clrscr();
		int c = 0;
		MOVING = 0;
		DrawCrossWalk();
		thread t(Subthread);
		while (1) {
			c = 0;
			if (!game->GetPeople().isDead()) {
				switch ((c = _getch())) {
				case KEY_UP:
					MOVING = 1;
					break;
				case KEY_DOWN:
					MOVING = 2;
					break;
				case KEY_RIGHT:
					MOVING = 3;
					break;
				case KEY_LEFT:
					MOVING = 4;
					break;
				case KEY_L:
					game->PauseGame(t.native_handle());
					if (!game->SaveGame()) {
						clrscr();
						DrawCrossWalk();
						game->DrawGame();
						game->ResumeGame(t.native_handle());
					}
					else
						game->ChangeState();
					break;
				case KEY_T:
					game->PauseGame(t.native_handle());
					game->LoadGame();
					clrscr();
					DrawCrossWalk();
					game->DrawGame();
					game->ResumeGame(t.native_handle());
					break;
				case KEY_P:
					game->PauseGame(t.native_handle());
					break;
				case KEY_M:
					game->PauseGame(t.native_handle());
					clrscr();
					game->SetGame(game->LogIn());
					clrscr();
					DrawCrossWalk();
					game->ResumeGame(t.native_handle());
					break;
				default:
					game->ResumeGame(t.native_handle());
					break;
				}
			}
			else {
				game->PauseGame(t.native_handle());
				int pos = ChoiceFrame("Do you want to reset?");
				if (!pos) {
					clrscr();
					DrawCrossWalk();
					MOVING = 0;
					game->ResetGame();
					game->DrawGame();
					game->ResumeGame(t.native_handle());
				}
				else
					game->ExitGame(t.native_handle());

			}
		}
	}
	EndFrame();
	return 0;
}
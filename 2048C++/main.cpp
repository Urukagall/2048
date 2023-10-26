#include <iostream>
#include <vector>
#include <random>

#include <string>
#include <windows.h>
#include "Box.h"
#include "Grid.h"
#include "Test.h"
using namespace std;


void InputSize(int& size) {
	cout << "Entrez la taille du tableau ";
	cin >> size;
}



void main()
{

	int size = 0;

	//Test* gridTest = new Test();

	bool defeat = false;
	bool win = false;
	InputSize(size);

	Grid* grid = new Grid(size);

	grid->Print();



	int numberZero = 0;
	int randomNumber = 0;
	bool leftArrowKeyPressed = false;
	bool rightArrowKeyPressed = false;
	bool upArrowKeyPressed = false;
	bool downArrowKeyPressed = false;

	grid->PlaceNumber();
	grid->PlaceNumber();
	grid->Print();
	while (!defeat && !win) {
		if (GetKeyState(VK_LEFT) & 0x8000) {
			if (!leftArrowKeyPressed) {
				leftArrowKeyPressed = true;
				grid->MoveHorizontal("left");
				grid->PlaceNumber();
				grid->Print();
			}
		}
		else {
			leftArrowKeyPressed = false;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			if (!rightArrowKeyPressed) {
				rightArrowKeyPressed = true;
				grid->MoveHorizontal("right");
				grid->PlaceNumber();
				grid->Print();
			}
		}
		else {
			rightArrowKeyPressed = false;
		}
		if (GetKeyState(VK_UP) & 0x8000) {
			if (!upArrowKeyPressed) {
				upArrowKeyPressed = true;
				grid->MoveVertical("up");
				grid->PlaceNumber();
				grid->Print();
			}
		}
		else {
			upArrowKeyPressed = false;
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			if (!downArrowKeyPressed) {
				downArrowKeyPressed = true;
				grid->MoveVertical("down");
				grid->PlaceNumber();
				grid->Print();
			}
		}
		else {
			downArrowKeyPressed = false;
		}
		grid->Defeat(defeat);
		grid->Win(win);
	}

	if (defeat) {
		cout << "Vous avez perdu !!!!";
	}
	else {
		cout << "Vous avez gagne !!!!";
	}

	delete grid;
}


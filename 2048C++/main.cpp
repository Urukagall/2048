#include <iostream>
#include <vector>
#include <random>
#include <string>

#include <windows.h>
#include "Box.h"
#include "Grid.h"
#include "Test.h"
using namespace std;

//Fonction pour demander la taille du tableau
void InputSize(int& size) {
	cout << "Entrez la taille du tableau ";
	cin >> size;
}



void main()
{
	//Création des variables
	int size = 0;
	bool defeat = false;
	bool win = false;
	int numberZero = 0;
	int randomNumber = 0;
	bool leftArrowKeyPressed = false;
	bool rightArrowKeyPressed = false;
	bool upArrowKeyPressed = false;
	bool downArrowKeyPressed = false;


	//Test* gridTest = new Test();

	//Création de la grille en fonction de size
	InputSize(size);
	Grid* grid = new Grid(size);

	//Initialisation de la grille de départ
	grid->PlaceNumber();
	grid->PlaceNumber();
	grid->Print();

	//Boucle de jeu
	while (!defeat && !win) {
		//Détection de la touche pressée
		if (GetKeyState(VK_LEFT) & 0x8000) {
			if (!leftArrowKeyPressed) {
				leftArrowKeyPressed = true;
				if (grid->MoveHorizontal("left")) {
					grid->PlaceNumber();
				}
				grid->Print();
			}
		}
		else {
			leftArrowKeyPressed = false;
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			if (!rightArrowKeyPressed) {
				rightArrowKeyPressed = true;
				if (grid->MoveHorizontal("right")) {
					grid->PlaceNumber();
				}
				grid->Print();
			}
		}
		else {
			rightArrowKeyPressed = false;
		}
		if (GetKeyState(VK_UP) & 0x8000) {
			if (!upArrowKeyPressed) {
				upArrowKeyPressed = true;
				if (grid->MoveVertical("up")) {
					grid->PlaceNumber();
				}
				grid->Print();
			}
		}
		else {
			upArrowKeyPressed = false;
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			if (!downArrowKeyPressed) {
				downArrowKeyPressed = true;
				if (grid->MoveVertical("down")) {
					grid->PlaceNumber();
				}
				grid->Print();
			}
		}
		else {
			downArrowKeyPressed = false;
		}
		grid->Defeat(defeat);
		grid->Win(win);
	}
	
	//Vérification des conditions de victoire et défaite
	if (defeat) {
		cout << "Vous avez perdu !!!!";
	}
	else {
		cout << "Vous avez gagne !!!!";
	}

	delete grid;
}


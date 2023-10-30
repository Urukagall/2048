#include "Grid.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
using namespace std;

const string reset("\033[0m");
const string brightRed("\033[0;91m");
const string brightGreen("\033[0;92m");
const string brightYellow("\033[0;93m");
const string BrightBlue("\033[0;94m");
const string brightMagenta("\033[0;95m");
const string brightCyan("\033[0;96m");
const string red("\033[0;31m");
const string green("\033[0;32m");
const string yellow("\033[0;33m");
const string blue("\033[0;34m");
const string magenta("\033[0;35m");


//constructeur des test
Grid::Grid(string sStr, int size)
{
	//initialisation des variables
	this->size = size;
	grid = vector<vector<Box>>(size, vector<Box>(4));
	int number;
	string letter;

	//création de la grille
	for (size_t i = 0; i < size * size; i++)
	{
		grid[i / size][i % size] = Box();
		letter = sStr[i];
		number = stoi(letter);
		grid[i / size][i % size].value = number;
	}
}

//Constructeur
Grid::Grid(int size)
{
	//initialisation des variables
	color = { brightRed,brightGreen,brightYellow,BrightBlue,brightMagenta,brightCyan,red,green,yellow,blue,magenta };

	this->size = size;
	grid = vector<vector<Box>>(size, vector<Box>(size));

	//création de la grille
	for (size_t i = 0; i < size * size; i++)
	{
		grid[i / size][i % size] = Box();
	}
}

//destructeur
Grid::~Grid()
{

}

//Méthode pour afficher la grille
void Grid::Print() {
	system("cls");
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < color.size(); k++)
			{
				//affichage des couleur
				if (grid[i][j].value != 0 and grid[i][j].value == pow(2, k))
				{
					cout << color[k];
				}
			}
			//affichage des numéro avec des espaces différents en fonction de la taille du nombre
			if (grid[i][j].value > 1000) {
				cout << "[ " << grid[i][j].value << "]";
			}
			else if (grid[i][j].value > 100) {
				cout << "[ " << grid[i][j].value << " ]";
			}
			else if (grid[i][j].value > 10) {
				cout << "[  " << grid[i][j].value << " ]";
			}
			else if (grid[i][j].value != 0) {
				cout << "[  " << grid[i][j].value << "  ]";
			}
			else {
				cout << "[  " << grid[i][j].value << "  ]";
			}
			cout << reset;
		}
		cout << endl;
		//affichage de la ligne de séparation des cases
		for (int i = 0; i < size; i++)
		{
			cout << "_______";
		}
		cout << endl;
		cout << endl;
	}
	cout << endl;
}


//méthode de génération de nombre aléatoire
int Grid::GenerateRandomNumber(int randomNumber) {
	random_device rd;
	mt19937 generator(rd());
	//génère un nombre aléatoire entre 1 et la valeur de la variable
	uniform_int_distribution<int> distribution(1, randomNumber);

	return distribution(generator);
}

//méthode place un nombre dans la grille
void Grid::PlaceNumber() {
	vector<Box> empty;
	int numberZero = 0;
	int randomPos = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (grid[i][j].value == 0)
			{
				numberZero += 1;
				empty.push_back(grid[i][j]);
			}
		}
	}

	randomPos = GenerateRandomNumber(numberZero);

	int indexZero = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (grid[i][j].value == 0)
			{
				indexZero += 1;
				if (indexZero == randomPos)
				{
					grid[i][j].value = GenerateRandomNumber(2) * 2;
				}
			}
		}
	}


}

//méthode de déplacement horizontale
bool Grid::MoveHorizontal(string move) {

	//récupère les valuer de la grille avant le déplacement
	vector<vector<Box>> gridStart = grid;

	for (int i = 0; i < size; i++) {
		vector<int> row;

		//rajoute les valeurs non nul de la ligne dans une variable
		for (int j = 0; j < size; j++) {
			if (grid[i][j].value != 0) {
				row.push_back(grid[i][j].value);
			}
		}
		if (move == "left") {
			//rajoute des 0 a la droite de la ligne pour remplir la ligne (simule un déplacement vers la gauche)
			while (row.size() < size) {
				row.push_back(0);
			}
			//fusionne les nombre qui son côte à côte si ils ont les même valeurs, en commencant par la gauche
			for (int j = 0; j < size - 1; j++) {
				if (row[j] == row[j + 1] && row[j] != 0) {
					row[j] *= 2;
					row[j + 1] = 0;
				}
			}
		}
		else {
			//rajoute des 0 a la gauche de la ligne pour remplir la ligne (simule un déplacement vers la droite)
			while (row.size() < size) {
				row.insert(row.begin(), 0);
			}
			//fusionne les nombre qui son côte à côte si ils ont les même valeurs, en commencant par la droite
			for (int j = size - 1; j > 0; j--) {
				if (row[j] == row[j - 1] && row[j] != 0) {
					row[j] *= 2;
					row[j - 1] = 0;
				}
			}
		}



		//rajoute les valeurs non nul de la ligne dans une variable
		vector<int> newRow;
		for (int j = 0; j < size; j++) {
			if (row[j] != 0) {
				newRow.push_back(row[j]);
			}
		}

		//rajoute des 0 a la droite de la ligne pour remplir la ligne (simule un déplacement vers la gauche)
		if (move == "left") {
			while (newRow.size() < size) {
				newRow.push_back(0);
			}
		}
		//rajoute des 0 a la gauche de la ligne pour remplir la ligne (simule un déplacement vers la droite)
		else {
			while (newRow.size() < size) {
				newRow.insert(newRow.begin(), 0);
			}

		}

		//rajoute les valeurs dans la grille
		for (int j = 0; j < size; j++) {
			grid[i][j].value = newRow[j];
		}
	}

	//récupère les valuer de la grille après le déplacement
	vector<vector<Box>> gridEnd = grid;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//si la grille avant et après le déplacement est la même renvoie true pour dire qu'il ne faut pas regénérer un nombre car il n'y a eu aucun mouvement
			if (gridStart[i][j].value != gridEnd[i][j].value) {
				return true;
			}
		}
	}
	return false;
}

bool Grid::MoveVertical(string move) {

	//récupère les valuer de la grille avant le déplacement

	vector<vector<Box>> gridStart = grid;

	for (int i = 0; i < size; i++) {
		vector<int> column;

		//rajoute les valeurs non nul de la colonne dans une variable
		for (int j = 0; j < size; j++) {
			if (grid[j][i].value != 0) {
				column.push_back(grid[j][i].value);
			}
		}
		if (move == "up") {
			//rajoute des 0 en bas de la colonne pour remplir la colonne (simule un déplacement vers le haut)
			while (column.size() < size) {
				column.push_back(0);
			}
			//fusionne les nombre qui son côte à côte si ils ont les même valeurs, en commencant par le haut
			for (int j = 0; j < size - 1; j++) {
				if (column[j] == column[j + 1] && column[j] != 0) { 
					column[j] *= 2;
					column[j + 1] = 0;
				}
			}
		}
		else {
			//rajoute des 0 en haut de la colonne pour remplir la ligne (simule un déplacement vers la bas)
			while (column.size() < size) {
				column.insert(column.begin(), 0);
			}
			//fusionne les nombre qui son côte à côte si ils ont les même valeurs, en commencant par le bas
			for (int j = size - 1; j >= 1; j--) {
				if (column[j] == column[j - 1] && column[j] != 0) {
					column[j] *= 2;
					column[j - 1] = 0;
				}
			}
		}


		//rajoute les valeurs non nul de la colonne dans une variable
		vector<int> newColumn;
		for (int j = 0; j < size; j++) {
			if (column[j] != 0) {
				newColumn.push_back(column[j]);
			}
		}
		//rajoute des 0 en bas de la colonne pour remplir la colonne (simule un déplacement vers le haut)
		if (move == "up") {
			while (newColumn.size() < size) {
				newColumn.push_back(0);
			}
		}
		else {
			//rajoute des 0 en haut de la colonne pour remplir la ligne (simule un déplacement vers la bas)
			while (newColumn.size() < size) {
				newColumn.insert(newColumn.begin(), 0);
			}
		}
		//rajoute les valeurs dans la grille
		for (int j = 0; j < size; j++) {
			grid[j][i].value = newColumn[j];
		}
	}


	vector<vector<Box>> gridEnd = grid;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (gridStart[i][j].value != gridEnd[i][j].value) {
				return true;
			}
		}
	}
	return false;

}

//méthode pour savoir si on perd et renvoie vers l'écran de défaite
void Grid::Defeat(bool& ifDefeat) {
	int zero = 0;
	for (int i = 0; i < size; i++) {
		for (int y = 0; y < size; y++) {
			if (grid[i][y].value == 0) {
				zero += 1;
			}
		}
	}
	if (zero == 0) {
		ifDefeat = true;
	}
}

//méthode pour savoir si on gagne et renvoie vers l'écran de win
void Grid::Win(bool& win) {
	for (int i = 0; i < size; i++) {
		for (int y = 0; y < size; y++) {
			if (grid[i][y].value == 64) {
				win = true;
				break;
			}
		}
	}

}

//méthode pour comparer les résultat des test avec le résultat attendue
bool Grid::CompareTest(string sStr) {
	int number;
	string letter;
	for (size_t i = 0; i < size * size; i++)
	{
		letter = sStr[i];
		number = stoi(letter);
		if (grid[i / size][i % size].value != number) {
			return false;
		}
		
	}
	return true;
}
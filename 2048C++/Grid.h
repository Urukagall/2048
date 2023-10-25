#pragma once
#include <vector>
#include <string>
#include "Box.h"

using namespace std;
class Grid
{
public:

	int size;
	vector<vector<Box>> grid;

	Grid(int size);
	~Grid();
	void Print();
	int PlaceNumber();
	int GenerateRandomNumber(int randomNumber);
	void moveHorizontal(string move);
	void moveVertical(string move);
	void Defeat(bool& ifDefeat);
	void Win(bool& win);
	void SpawnNumber(int& randomNumber);

};
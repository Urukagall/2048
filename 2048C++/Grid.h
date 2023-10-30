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
	vector<string> color;
	vector<int> numberValue;

	Grid(std::string sStr, int size);
	Grid(int size);
	~Grid();
	void Print();
	void PlaceNumber();
	int GenerateRandomNumber(int randomNumber);
	bool MoveHorizontal(string move);
	bool MoveVertical(string move);
	void Defeat(bool& ifDefeat);
	void Win(bool& win);
	bool CompareTest(string sStr);


};
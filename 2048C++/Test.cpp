#include "Test.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Test::Test() 
{

	string sConfig ;
	sConfig += "0200";
	sConfig += "0000";
	sConfig += "0000";
	sConfig += "0000";
	Grid oGrid(sConfig, 4);

	string sResult;
	sResult += "2000";
	sResult += "0000";
	sResult += "0000";
	sResult += "0000";

	oGrid.MoveHorizontal("left");
	cout << oGrid.CompareTest(sResult);

}

Test::~Test() {
}
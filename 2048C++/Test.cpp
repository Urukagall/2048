#include "Test.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

Test::Test() 
{
	std::string sConfig;
	sConfig += "0000";
	sConfig += "0000";
	sConfig += "0000";
	sConfig += "0000";

	Grid oGrid(sConfig);
	//hardcode
	//"0002"

	std::string sResult;
	sConfig += "0000";
	sConfig += "0000";
	sConfig += "0000";
	sConfig += "0000";


	Grid oGirdResult(4);
	//hardcode
	//"2000"

	oGrid.MoveHorizontal("");

	//compare
	//créer méthode dans Grid qui compare sResult et oGrid
}

Test::~Test() {
}
#pragma once

#include "ZTRengine.h"
#include "thisGame.h"

using namespace std;

class newGame :
	public runable
{
public:
	newGame();
	void run(char);
	string get_name();
private:
	string name;
};
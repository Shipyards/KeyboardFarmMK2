#pragma once

#include "ZTRengine.h"
#include "runable.h"
#include "load.h"

class saveGame :
	public ZTRengine::runable
{
public:
	saveGame();
	void run(char);
	string get_name();
private:
	string name;
};




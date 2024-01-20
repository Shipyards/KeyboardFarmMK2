#pragma once

#include "ZTRengine.h"
#include "runable.h"
#include "load.h"

class loadGame :
	public ZTRengine::runable
{
public:
	loadGame();
	void run(char);
	string get_name();
private:
	string name;
};


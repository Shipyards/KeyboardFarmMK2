#pragma once

#include "ZTRengine.h"
#include "runable.h"

class manageObjects :
	public ZTRengine::runable
{
public:
	manageObjects();
	void run(char);
	string get_name();
private:
	string name;
};


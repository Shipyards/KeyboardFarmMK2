#pragma once

#include "ZTRengine.h"

class credits :
	public ZTRengine::runable
{
public:
	credits();
	void run(char);
	string get_name();
private:
	string name;
};


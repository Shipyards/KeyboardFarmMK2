#pragma once

#include <map>
#include "ZTRobject.h"
#include "saveslot.h"
#include <fstream>

using namespace std;

namespace ZTRengine
{
	class gamecore
	{
	public:
		map<string, ZTRobject*> gameobjects;
		gamecore()
		{
			this->gameobjects = map<string, ZTRobject*>();
		}
	};
}
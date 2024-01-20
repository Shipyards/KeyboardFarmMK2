#pragma once

#include <iostream>
#include "ZTRobject.h"
#include "ZTRutils.h"
#include "runable.h"
#include "gamecore.h"
#include "datapacket.h"
#include "datacore.h"
#include "proccore.h"
#include "eventcore.h"
#include "GUIDgen.h"

using namespace std;

namespace ZTRengine
{
	class ZTRcore
	{
	public:
		static ZTRutils *util;
		static gamecore *Gcore;
		static datacore *Dcore;
		static proccore *Pcore;
		static eventcore *Ecore;
	};
}
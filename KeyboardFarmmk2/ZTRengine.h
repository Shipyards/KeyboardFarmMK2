/*
   Copyright 2024 Jacob T. Ray

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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

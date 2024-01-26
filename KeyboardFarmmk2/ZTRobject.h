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
#include <map>
#include "GUIDgen.h"
#include "datapacket.h"
#include "serializeable.h"
#include "ZTRtypes.h"

using namespace std;

namespace ZTRengine
{
	class ZTRobject
	{
	public:
		virtual class DPlocal :
			public datapacket
		{
			const ZTRtypes::ZTRtype type = ZTRtypes::default_type;
		};
	public:
		string GUID;
		const ZTRtypes::ZTRtype type = ZTRtypes::default_type;
		DPlocal* datapack;
		ZTRobject();
		virtual ZTRtypes::ZTRtype get_type() = 0;
	};
}

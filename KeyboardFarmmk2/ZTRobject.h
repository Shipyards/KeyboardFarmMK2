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
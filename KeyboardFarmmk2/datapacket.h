#pragma once

#include <iostream>
#include "GUIDgen.h"
#include "serializeable.h"
#include "ZTRtypes.h"
#include <fstream>

using namespace std;

namespace ZTRengine
{
	class datapacket : //The data storage base class
		public serializeable
	{
	public:
		struct data
		{
			int a;
		};
		const ZTRtypes::ZTRtype type = ZTRtypes::default_type;
		string GUID;
		data packetdata;
		datapacket();
		~datapacket();
		virtual char* serialize();
		virtual size_t datasize();
		virtual bool deserialize(char*);
	};
}
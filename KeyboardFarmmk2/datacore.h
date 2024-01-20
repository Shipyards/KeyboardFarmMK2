#pragma once

#include "datapacket.h"

namespace ZTRengine
{
	class datacore
	{
	public:
		map<string, datapacket*> datapackets;
		datacore()
		{
			this->datapackets = map<string, datapacket*>();
		}
	};
}
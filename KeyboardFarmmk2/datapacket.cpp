#include "datapacket.h"
#include "ZTRengine.h"

using namespace std;

namespace ZTRengine
{
	datapacket::datapacket()
	{
		this->packetdata.a = 1;
		this->GUID = GUIDgen();
		ZTRcore::Dcore->datapackets[this->GUID] = this;
	}
	datapacket::~datapacket()
	{
		ZTRcore::Dcore->datapackets.erase(this->GUID);
	}
	char* datapacket::serialize()
	{
		return reinterpret_cast<char*>(&this->packetdata);
	}
	size_t datapacket::datasize()
	{
		return sizeof(data);
	}
	bool datapacket::deserialize(char* buildfrom)
	{
		this->packetdata = buildfrom;
		return true;
	}
}
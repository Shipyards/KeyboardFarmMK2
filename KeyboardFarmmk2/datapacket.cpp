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
		this->packetdata = *reinterpret_cast<data*>(&buildfrom);
		return true;
	}
	bool datapacket::deserialize(data buildfrom)
	{
		this->packetdata = buildfrom;
		return true;
	}
}

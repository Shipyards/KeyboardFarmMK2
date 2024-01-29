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

#include "ZTRengine.h"

using namespace std;
using namespace ZTRengine;

/* marshaled to the load system as: "test"*/
class gameObjectTest :
	public ZTRobject
{
public:
	class DPlocal :
		public virtual datapacket
	{
	public:
		struct data
		{
			int a = 3;
			int b = 7;
			int c = 10;
		};
		const ZTRtypes::ZTRtype type = ZTRtypes::test;
		data packetdata;
		DPlocal()
		{

		}
		char* serialize()
		{
			return (char*) &this->packetdata;
		}
		size_t sizeofdata()
		{
			return sizeof(data);
		}
		bool deserialize(char* datain)
		{
			try { this->packetdata = *reinterpret_cast<data*>(datain); }
			catch (exception e) { throw ZTRutils::ID10T_ERR(); }
		}
	};
	DPlocal *datapack;
	const ZTRtypes::ZTRtype type = ZTRtypes::test;
	gameObjectTest();
	~gameObjectTest();
	ZTRtypes::ZTRtype get_type();
	//string get_ID();
	void testfunc1();
	void testfunc2();
	void set(int Ain, int Bin, int Cin);
	void seta(int Ain);
	void setb(int Bin);
	void setc(int Cin);
};


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


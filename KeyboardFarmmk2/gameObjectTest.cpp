#include "ZTRengine.h"
#include "gameObjectTest.h"

using namespace std;
using namespace ZTRengine;

gameObjectTest::DPlocal* datapack;
gameObjectTest::gameObjectTest()
{
	this->datapack = new DPlocal();
	this->GUID = this->datapack->GUID;
	ZTRcore::Gcore->gameobjects[this->GUID] = this;
}
gameObjectTest::~gameObjectTest()
{
	ZTRcore::Gcore->gameobjects.erase(this->GUID);
}
ZTRtypes::ZTRtype gameObjectTest::get_type()
{
	return this->type;
}
void gameObjectTest::testfunc1()
{
	cout << this->datapack->packetdata.a << endl;
	cout << this->datapack->packetdata.b << endl;
	cout << this->datapack->packetdata.c << endl;
}
void gameObjectTest::testfunc2()
{
	char a1, b1, c1 = '~';
	cout << "(0-9)\na: " << flush;
	cin >> a1;
	cout << "b: " << flush;
	cin >> b1;
	cout << "c: " << flush;
	cin >> c1;
	cout << flush;
	this->datapack->packetdata.a = a1;
	this->datapack->packetdata.b = b1;
	this->datapack->packetdata.c = c1;
}
void gameObjectTest::set(int Ain, int Bin, int Cin)
{
	this->datapack->packetdata.a = Ain;
	this->datapack->packetdata.b = Bin;
	this->datapack->packetdata.c = Cin;
}
void gameObjectTest::seta(int Ain)
{
	this->datapack->packetdata.a = Ain;
}
void gameObjectTest::setb(int Bin)
{
	this->datapack->packetdata.b = Bin;
}
void gameObjectTest::setc(int Cin)
{
	this->datapack->packetdata.c = Cin;
}
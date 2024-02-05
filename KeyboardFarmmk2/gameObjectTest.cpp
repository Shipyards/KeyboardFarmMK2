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
	this->datapack->packetdata.a = ZTRutils::chartoint(a1);
	this->datapack->packetdata.b = ZTRutils::chartoint(b1);
	this->datapack->packetdata.c = ZTRutils::chartoint(c1);
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

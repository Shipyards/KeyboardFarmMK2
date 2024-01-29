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

#include "manageObjects.h"
#include "ZTRinterface.h"
#include "gameObjectTest.h"
#include "ZTRtypes.h"
#include "runable.h"

using namespace std;
using namespace ZTRengine;


// this is a temporary object

class testobjinterface :
	public runable
{
private:
	gameObjectTest* workingobj;
public:
	testobjinterface(gameObjectTest* obj)
	{
		this->workingobj = obj;
		this->name = "test object: "+this->workingobj->GUID;
	}
	void run(char runmode)
	{
		workingobj->testfunc2();
	}
	string get_name()
	{
		return this->name;
	}
	string name;
};


manageObjects::manageObjects()
{
	this->name = "Manage Objects";
}
void manageObjects::run(char runmode)
{
	vector<runable*> interfaces;
	map<string, ZTRobject*>::const_iterator i;
	cout << boolalpha << ZTRcore::Gcore->gameobjects.empty() << endl;
	if (ZTRcore::Gcore->gameobjects.empty())
	{
		cout << "No objects created" << endl;
		throw ZTRutils::ZTRcontinue();
	}
	for (i = ZTRcore::Gcore->gameobjects.cbegin(); i != ZTRcore::Gcore->gameobjects.cend(); i++)
	{
		switch (i->second->get_type())
		{
		case ZTRtypes::default_type:
			throw ZTRutils::ID10T_ERR();
			break;
		case ZTRtypes::test:
		{
			gameObjectTest* testobjptr = (gameObjectTest*)(&*i->second);
			interfaces.push_back(new testobjinterface(testobjptr));
			break;
		}
		default:
			throw ZTRutils::ID10T_ERR();
			break;
		}
	}
	ZTRinterface objmenu = ZTRinterface("Objects", interfaces);
	objmenu.run('~');
	throw ZTRutils::ZTRcontinue();
	return;
}
string manageObjects::get_name()
{
	return this->name;
}

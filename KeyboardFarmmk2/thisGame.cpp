#include "thisGame.h"
#include "ZTRinterface.h"
#include "manageObjects.h"
#include "saveGame.h"
#include <iostream>

using namespace std;
using namespace ZTRengine;

keyBoardFarm::keyBoardFarm()
{
	testObj = new gameObjectTest();
}
void keyBoardFarm::start()
{
	/*this->testObj->testfunc2();*/
	manageObjects* mObj = new manageObjects(); saveGame* sG = new saveGame();
	vector<runable*> mainmenuitems = {mObj, sG};
	ZTRinterface gamemenu = ZTRinterface("Keyboard farm", mainmenuitems);
	gamemenu.run('~');
	delete mObj, sG;
} 
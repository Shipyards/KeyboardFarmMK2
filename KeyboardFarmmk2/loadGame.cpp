#include "loadGame.h"

using namespace std;
using namespace ZTRengine;

loadGame::loadGame()
{
	this->name = "Load Game";
}
void loadGame::run(char runmode)
{
	load* loadgame = new load();
	loadgame->run('~');
	delete loadgame;
	throw ZTRutils::ZTRcontinue();
}
string loadGame::get_name()
{
	return this->name;
}
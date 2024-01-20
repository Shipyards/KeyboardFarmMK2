#include "saveGame.h"
#include "save.h"

using namespace std;
using namespace ZTRengine;

saveGame::saveGame()
{
	this->name = "Save Game";
}
void saveGame::run(char runmode)
{
	save* savegame = new save();
	savegame->run('~');
	delete savegame;
	throw ZTRutils::ZTRcontinue();
}
string saveGame::get_name()
{
	return this->name;
}
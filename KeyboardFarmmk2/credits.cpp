#include "credits.h"
#include "ZTRutils.h"

using namespace std;
using namespace ZTRengine;

credits::credits()
{
	this->name = "Credits";
}
void credits::run(char runmode)
{
	ZTRutils::clrscreen();
	ZTRutils::timeDelayPrint("Game designer: Jake Ray\nLead Developer: Jake Ray\n", 20);
	throw ZTRutils::ZTRcontinue();
}
string credits::get_name()
{
	return this->name;
}
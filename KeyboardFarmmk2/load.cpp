#include "load.h"
#include "ZTRengine.h"
#include "saveslot.h"
#include "extract_saveslots.h"
#include "ZTRinterface.h"
#include "ZTRutils.h"
#include <vector>
#include <map>

using namespace std;

namespace ZTRengine
{
	load::load()
	{
		this->name = "Load Game";
	}
	void load::run(char runmode)
	{
		map<string, saveslot*>* saveslots;
		saveslots = extract_saveslots();
		if (saveslots->empty())
		{
			cout << "No files to load from!\nHave a nice day!" << endl;
			throw ZTRutils::ZTRcontinue();
			return;
		}
		vector<runable*> saves;
		map<string, saveslot*>::const_iterator b;
		for (b = saveslots->cbegin(); b != saveslots->cend(); b++)
		{
			saveslot* x = &*b->second;
			saves.push_back(x);
		}
		ZTRinterface* savesinterface = new ZTRinterface("Load from:", saves);
		savesinterface->run('l');
		delete saveslots, saves;
	}
	string load::get_name()
	{
		return this->name;
	}
}
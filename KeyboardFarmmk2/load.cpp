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

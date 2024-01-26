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

#include "save.h"
#include "ZTRengine.h"
#include "saveslot.h"
#include "extract_saveslots.h"
#include "editsaves.h"
#include "ZTRinterface.h"
#include "ZTRutils.h"
#include <vector>
#include <map>

using namespace std;

namespace ZTRengine
{
	newsave::newsave()
	{
		this->name = "New save";
	}
	void newsave::run(char runmode)
	{
		string newname = "";
		bool running = true;
		while (running)
		{
			cout << "New Save Name: " << flush;
			cin >> newname;
			if (newname == "exit")
			{
				running = false;
				continue;
			}
			cout << "\n \nNew name: " << newname << endl << "Confirm Y/N: ";
			char YN = ' ';
			cin >> YN;
			if (YN == 'N')
			{
				continue;
			}
			running = false;
		}
		editsaves::addsave(newname);
	}
	string newsave::get_name()
	{
		return this->name;
	}
	save::save()
	{
		this->name = "Save Game";
	}
	void save::run(char runmode)
	{
		newsave* newslot = new newsave();
		vector<runable*> saves;
		saves.push_back(newslot);
		try
		{ 
			map<string, saveslot*>* saveslots;
			saveslots = extract_saveslots();
			map<string, saveslot*>::const_iterator b;
			for (b = saveslots->cbegin(); b != saveslots->cend(); b++)
			{
				saveslot* x = &*b->second;
				saves.push_back(x);
			}
			delete saveslots;
		}
		catch (nosaves e) { cout << "No files to existing files" << endl; }
		ZTRinterface* savesinterface = new ZTRinterface("Save to:", saves);
		savesinterface->run('s');
	}
	string save::get_name()
	{
		return this->name;
	}
}

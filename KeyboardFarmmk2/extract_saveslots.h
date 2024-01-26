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

#pragma once

#include "saveslot.h"
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include "ZTRFIO.h"

namespace ZTRengine
{
	class nosaves {};
	static vector<string> get_savenames() 
	{
		vector<string> savenames = vector<string>();
		ZTRFIO* file = new ZTRFIO("savenames.bin");
		if (file->is_empty())
		{
			throw nosaves();
		}
		int numofsaves = file->read<int>(ZTRFIO::standard);
		for (int iter = 0; iter < numofsaves; iter++)
		{
			savenames.push_back(file->read<string>(ZTRFIO::standard));
		}
		return savenames;
	}
	static map<string, saveslot*>* extract_saveslots()
	{
		map<string, saveslot*>* saveslots = new map<string, saveslot*>();
		vector<string> savenames;
		try
		{
			savenames = get_savenames();
		}
		catch (nosaves e) { throw nosaves(); }
		catch (exception e2) { throw ZTRutils::ID10T_ERR(); }
		vector<string>::const_iterator b;
		for (b = savenames.begin(); b != savenames.cend(); b++)
		{
			saveslots->insert({ *b, new saveslot(*b) });
			continue;
		}
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b-done-        \n";
		return saveslots;
	}
}

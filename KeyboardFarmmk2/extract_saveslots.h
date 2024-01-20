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
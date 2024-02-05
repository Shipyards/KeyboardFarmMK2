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

#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include "runable.h"
#include "extract_saveslots.h"
#include "ZTRFIO.h"
#include "editsaves.h"
#include <stdio.h>


const static std::string savenamesfilename = "savenames";

using namespace std;

namespace ZTRengine
{
	bool editsaves::addsave(string savename)
	{
		using namespace std;
		int numofitems;
		ZTRFIO* savenamesfile = new ZTRFIO(savenamesfilename);
		if (!savenamesfile->is_empty())
		{
			numofitems = savenamesfile->read<int>(ZTRFIO::standard);
		}
		else 
		{ 
			numofitems = 0;
		}
		savenamesfile->write<int>(numofitems + 1, ZTRFIO::beginpos);
		savenamesfile->write<string>(savename, ZTRFIO::endpos);
		delete savenamesfile;
		saveslot newslot(savename);
		try { newslot.runsave(); }
		catch (ZTRutils::ZTRexit e1) {};
		return true;
	}
	bool editsaves::removesave(string savename)
	{
		vector<string> currentsavenames = get_savenames();
		vector<string> notdeletenames = vector<string>();
		bool exists = false;

		vector<string>::const_iterator csnit;
		for (csnit = currentsavenames.cbegin(); csnit != currentsavenames.cend(); csnit++) //makes sure savename is in existing savenames and complies all remaining savenames
		{
			if (*csnit == savename)
			{
				exists = true;
				continue;
			}
			notdeletenames.push_back(*csnit);
		}

		if (!exists) { return false; }

		remove(savename.c_str()); // c function to delete a file

		ZTRFIO* SVNfile = new ZTRFIO(savenamesfilename);

		//re write the savenames file
		SVNfile->clear_file();
		SVNfile->write<int>(notdeletenames.size(), ZTRFIO::beginpos); // correct num of items
		vector<string>::const_iterator ndnit;
		for (ndnit = notdeletenames.cbegin(); ndnit != notdeletenames.cend(); ndnit++) // write each name not deleted
		{
			SVNfile->write<string>(*ndnit, ZTRFIO::endpos);
		}

		delete SVNfile;
	}
}

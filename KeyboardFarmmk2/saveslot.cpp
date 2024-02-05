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

#include "saveslot.h"
#include "runable.h"
#include "datapacket.h"
#include "gameObjectTest.h"
#include "newGame.h"
#include "ZTRFIO.h"

using namespace std;

namespace ZTRengine
{
	saveslot::saveslot(string filenamein)
	{
		this->filename = filenamein;
		this->filenameactual = filenamein + ".bin";
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		if (workingfile->is_empty()) { cout << "warning saveslot is file is emtpy" << endl; }
		else { this->info = workingfile->read<slotinfo>(); }
	}
	string saveslot::get_name()
	{
		return this->filename;
	}
	void saveslot::runsave()
	{
		slotinfo thisinfo;
		strncpy_s(thisinfo.datetime, ZTRutils::currentDateTime().c_str(), sizeof(thisinfo.datetime));
		cout << "datetime" << ZTRutils::currentDateTime().c_str() << endl;
		thisinfo.numberofitems = ZTRcore::Dcore->datapackets.size();

		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		string packet_type;

		cout << "saving to file: " << this->filename << endl;
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);

		map<string, datapacket*>::iterator packetit;
		for (packetit = ZTRcore::Dcore->datapackets.begin(); packetit != ZTRcore::Dcore->datapackets.end(); packetit++)
		{
			datapacket* workingpacket = packetit->second;
			cout << "saving datapacket: " << string(workingpacket->GUID) << endl;
			workingfile->write<ZTRtypes::ZTRtype>(workingpacket->type, ZTRFIO::standard);
			workingfile->write<char*>(workingpacket->serialize(), ZTRFIO::standard);
		}

		cout << "saving to file: " << this->filename << "complete\n";
		delete workingfile;
		cout << "done saving!" << endl;
	}
	streampos saveslot::loadinfo()
	{
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		this->info = workingfile->read<slotinfo>(ZTRFIO::beginpos);

		return workingfile->get_ptrpos();

		delete workingfile;
	}
	void saveslot::updateinfo()
	{
		strncpy_s(this->info.datetime, ZTRutils::currentDateTime().c_str(), sizeof(this->info.datetime));
		this->info.numberofitems = ZTRcore::Dcore->datapackets.size();
		cout << this->info.datetime << endl;
	}
	streampos saveslot::saveinfo() // saves all the slot information
	{
		this->updateinfo();
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);

		workingfile->write<slotinfo>(this->info, ZTRFIO::beginpos);

		cout << workingfile->get_ptrpos() << endl;
		return workingfile->get_ptrpos();

		delete workingfile;
	}
	void saveslot::runload()
	{
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		string packet_type;
		ZTRtypes::ZTRtype loadobjtype;
		slotinfo thisinfo;
		cout << "loading from file: " << this->filename << endl;
		this->info = workingfile->read<slotinfo>(ZTRFIO::beginpos);

		loadobjtype = workingfile->read<ZTRtypes::ZTRtype>(ZTRFIO::standard);
		switch (loadobjtype)
		{
		case ZTRtypes::test:
			cout << "loading test_object" << endl;
			{ 
				gameObjectTest::DPlocal* loadpacket = new gameObjectTest::DPlocal(); 
				loadpacket->deserialize(workingfile->read<char*>());
			}
			break;
		default:
			throw "stoopbid";
			break;
		}

		cout << "loading from file: " << this->filename << "  complete\n";
		newGame* begin = new newGame();
		delete workingfile;
		begin->run('~');
	}
	void saveslot::deletefile()
	{

	}
	void saveslot::run(char mode) // 'l' for load from this slot --- 's' for save to this slot
	{
		switch (mode)
		{
		case 'l':
			this->runload();
			break;
		case 's':
			this->runsave();
			break;
		case 'd':
			this->deletefile();
			break;
		default:
			break;
		}
	}
}

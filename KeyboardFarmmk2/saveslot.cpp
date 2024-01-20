#include "saveslot.h"
#include "runable.h"
#include "datapacket.h"
#include "gameObjectTest.h"
#include "newGame.h"
#include "ZTRFIO.h"

using namespace std;

namespace ZTRengine
{
	saveslot::saveslot()
	{

	}
	saveslot::saveslot(string filenamein)
	{
		this->filename = filenamein;
		this->filenameactual = filenamein + ".bin";
	}
	string saveslot::get_name()
	{
		return this->filename;
	}
	void saveslot::runsave()
	{
		slotinfo thisinfo;
		strncpy_s(thisinfo.datetime, ZTRutils::currentDateTime().c_str(), sizeof(thisinfo.datetime));
		thisinfo.numberofitems = ZTRcore::Dcore->datapackets.size();

		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		string packet_type;

		cout << "saving to file: " << this->filename << endl;
		workingfile->write<string>(this->filename);
		workingfile->write<slotinfo>(thisinfo);

		map<string, datapacket*>::iterator packetit;
		for (packetit = ZTRcore::Dcore->datapackets.begin(); packetit != ZTRcore::Dcore->datapackets.end(); packetit++)
		{
			datapacket* workingpacket = packetit->second;
			cout << "saving datapacket: " << string(workingpacket->GUID) << endl;
			workingfile->write<ZTRtypes::ZTRtype>(workingpacket->type);
			workingfile->write<char*>(workingpacket->serialize());
		}
		cout << "saving to file: " << this->filename << "complete\n";
		delete workingfile;
		cout << "done saving!" << endl;
		throw ZTRutils::ZTRexit();
	}
	void saveslot::runinfosave() // saves all the slot information
	{
		slotinfo thisinfo;
		strncpy_s(thisinfo.datetime, ZTRutils::currentDateTime().c_str(), sizeof(thisinfo.datetime));
		thisinfo.numberofitems = ZTRcore::Dcore->datapackets.size();
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);

		workingfile->clear_file();
		workingfile->write<string>(this->filename);
		workingfile->write<slotinfo>(thisinfo);

		delete workingfile;
	}
	void saveslot::runload()
	{
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		string packet_type;
		//test
		cout << "loading from file: " << this->filename << endl;

		workingfile->read<ZTRtypes::ZTRtype>(ZTRFIO::standard);

		cout << "loading from file: " << this->filename << "complete\n";
		newGame* begin = new newGame();
		delete workingfile;
		begin->run('~');
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
		default:
			break;
		}
	}
}
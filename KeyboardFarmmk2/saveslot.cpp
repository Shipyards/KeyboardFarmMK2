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
		workingfile->write<slotinfo>(this->info);

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
	streampos saveslot::loadinfo()
	{
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		this->info = workingfile->read<slotinfo>(ZTRFIO::standard);
	}
	void saveslot::updateinfo()
	{
		strncpy_s(this->info.datetime, ZTRutils::currentDateTime().c_str(), sizeof(this->info.datetime));
		this->info.numberofitems = ZTRcore::Dcore->datapackets.size();
	}
	streampos saveslot::saveinfo() // saves all the slot information
	{
		this->updateinfo();
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);

		workingfile->write<string>(this->filename);
		workingfile->write<slotinfo>(this->info);

		delete workingfile;
	}
	void saveslot::runload()
	{
		ZTRFIO* workingfile = new ZTRFIO(this->filenameactual);
		string packet_type;
		ZTRtypes::ZTRtype loadobjtype;
		slotinfo thisinfo;
		cout << "loading from file: " << workingfile->read<string>(ZTRFIO::standard) << endl;
		thisinfo = workingfile->read<slotinfo>(ZTRFIO::standard);

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

		cout << "loading from file: " << this->filename << "complete\n";
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
#include "ZTRinterface.h"
#include "ZTRutils.h"
#include "runable.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

namespace ZTRengine
{
	ZTRinterface::ZTRinterface(string name, vector<runable*> runables, char runmode)
	{
		this->interfaceName = name;
		this->runmode = runmode;
		for (unsigned int x = 0; x < runables.size(); x++)
		{
			this->options.push_back(runables[x]);
		}
	}
	ZTRinterface::ZTRinterface(string name, vector<runable*> runables) //options should throw 'ZTRcontinue' to loop back to the interface
	{
		this->interfaceName = name;
		this->runmode = '~';
		for (unsigned int x = 0; x < runables.size(); x++)
		{
			this->options.push_back(runables[x]);
		}
		this->options.push_back(new ZTRinterfaceexit());
	}
	void ZTRinterface::run(char runmode)
	{
		unsigned short int userselect = 10;
		string userin = "+";
		bool running = true;
		while (running)
		{
			cout << "\n| " << this->interfaceName << " |\n";
			for (unsigned int e = 0; e < this->options.size(); e++)
			{
				cout << e+1 << ". " << options[e]->get_name() << "\n";
			}
			cout << "::: " << flush;
			cin >> userin;
			userselect = ZTRutils::unsignedintfromstr(userin);
			try
			{
				if (userselect > options.size())
				{
					cout << "number out of range" << endl;
					throw ZTRutils::ZTRcontinue();
				}
				userselect--;
				options[userselect]->run(runmode);
			}
			catch (ZTRutils::ZTRexit e1)
			{
				running = false;
				break;
			}
			catch (ZTRutils::ZTRcontinue c1)
			{
				running = true;
				continue;
			}
			catch (ZTRutils::ID10T_ERR i1)
			{
				cout << "ID10T ERROR; you so stupid" << endl;
			}
			catch (...)
			{
				cout << "unable to run selection, please try again --- press enter to continue";
				cout << "::: " << flush;
				cin >> userin;
				continue;
			}
			break;
		}
	}
	ZTRinterface::~ZTRinterface()
	{
		vector<runable*>::const_iterator it;
		for (it = this->options.cbegin(); it != this->options.cend(); it++)
		{
			delete *it;
		}
	}
};
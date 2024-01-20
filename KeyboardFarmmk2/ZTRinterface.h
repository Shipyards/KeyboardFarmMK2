#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "runable.h"
#include "ZTRutils.h"

using namespace std;

namespace ZTRengine
{
	class ZTRinterfaceexit :
		public runable
	{
	public:
		ZTRinterfaceexit()
		{
			this->name = "Exit";
		}
		void run(char runmode)
		{
			throw ZTRutils::ZTRexit();
		}
		string get_name()
		{
			return this->name;
		}
		string name;
	};
	class ZTRinterface :/* works with up to 9 options for now */
		public runable
	{
	public:
		char runmode;
		ZTRinterface(string, vector<runable*>, char);
		ZTRinterface(string, vector<runable*>);
		~ZTRinterface();
		void run(char);
	private:
		string interfaceName;
		vector<runable*> options;
	};
}
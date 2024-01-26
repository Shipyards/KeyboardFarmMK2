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

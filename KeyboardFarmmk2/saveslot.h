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
#include "runable.h"

using namespace std;

namespace ZTRengine
{
	class saveslot :
		public runable
	{
	private:
		struct slotinfo 
		{
			char datetime[80];
			int numberofitems;
		};
	public:
		slotinfo info;
		string filename;
		string filenameactual;
		saveslot(string);
		string get_name();
		void updateinfo();
		streampos loadinfo();
		streampos saveinfo();
		void runsave();
		void runload();
		void deletefile();
		void run(char); // 'l' for load from this slot --- 's' for save to this slot
	};
}

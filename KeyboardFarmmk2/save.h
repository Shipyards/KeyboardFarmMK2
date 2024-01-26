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
/*
ofstream file;
file.open("testdata.bin", ios::binary);
int a = 10;
int b = 234;
char test[7] = "abcdef";
cout << "writing to file\n";
file.write(reinterpret_cast<char*>(&a), sizeof(a)); //works with struct rather than a
cout << "completed\n";
file.close();
*/
#include <fstream>
#include "ZTRengine.h"

using namespace std;
using namespace ZTRengine;

namespace ZTRengine
{
	class newsave :
		public runable
	{
	public:
		newsave();
		void run(char);
		string get_name();
	private:
		string name;
	};
	class save :
		public runable
	{
	public:
		save();
		void run(char);
		string get_name();
	private:
		string name;
	};
}

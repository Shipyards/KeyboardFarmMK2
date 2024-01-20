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
#pragma once

#include <iostream>

using namespace std;

namespace ZTRengine
{
	class runable
	{
	public:
		runable()
		{
			this->name = "runable";
		};
		virtual void run(char runmode)
		{
			return;
		}
		virtual string get_name()
		{
			return this->name;
		}
		string name;
	};
}
#pragma once

#include "runable.h"

using namespace std; 

namespace ZTRengine
{
	class load :
		public runable
	{
	public:
		load();
		void run(char);
		string get_name();
	private:
		string name;
	};
}
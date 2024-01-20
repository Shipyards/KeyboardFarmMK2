#pragma once

#include <iostream>

using namespace std;

namespace ZTRengine
{
	class editsaves
	{
	public:
		static bool addsave(string savename);
		static bool removesave(string savename);
	};
}
#pragma once

namespace ZTRengine
{
	class serializeable
	{
	public:
		virtual char* serialize() = 0;
		virtual size_t datasize() = 0;
		virtual bool deserialize(char*) = 0;
	};
}
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
#include <fstream>
#include <string>
#include "ZTRobject.h"
#include "serializeable.h"



namespace ZTRengine
{
	class ZTRFIO
	{
	private:
		fstream Fstrm;
		ios::streampos lastreadpos;
		ios::streampos lastwritepos;
		ios::streampos laststrmpos;
		void create_file()
		{
			this->Fstrm.open(this->filename, ios::out);
			this->Fstrm.close();
		}
	public:
		enum to_frommode
		{
			standard,
			endpos,
			beginpos,
			currentpos,
			lastpos
		};
		std::string filename;
		bool OK;
		ZTRFIO(std::string filename)
		{
			using namespace std;
			if (filename[filename.length() - 4] != '.')
			{
				filename += ".bin";
			}
			this->filename = filename;
			this->Fstrm = fstream(filename, ios::in | ios::out | ios::binary);
			if (this->Fstrm.fail())
			{
				this->Fstrm.close();
				this->create_file();
				this->Fstrm = fstream(filename, ios::in | ios::out | ios::binary);
			}
			this->OK = false;
			this->record_readpos();
			this->record_writepos();
		}
		~ZTRFIO() { this->Fstrm.close(); } 
		void clear_file() // * WARNING * THIS FUNCTION WILL PERMANETLY DELETE FILE CONTENTS
		{
			this->Fstrm.close();
			this->Fstrm.open(this->filename, ios::out);
			this->Fstrm.close();
			this->Fstrm.open(this->filename, ios::in | ios::out | ios::binary);
		}
		bool delete_file()
		{
			this->Fstrm.close();
			this->OK = false;
			remove(this->filename.c_str());
		}
		bool is_empty()
		{
			this->Fstrm.seekg(0, ios::end);
			bool empty = this->Fstrm.tellg() == 0;
			this->ptr_goback();
			return empty;
		}
		void ptr_tostart()
		{
			this->laststrmpos = this->Fstrm.tellg();
			this->Fstrm.seekg(0, ios::beg);
		}
		void ptr_toend()
		{
			this->laststrmpos = this->Fstrm.tellg();
			this->Fstrm.seekg(0, ios::end);
		}
		void ptr_toread()
		{
			this->laststrmpos = this->Fstrm.tellg();
			this->Fstrm.seekg(this->lastreadpos);
		}
		void record_readpos()
		{
			this->lastreadpos = this->Fstrm.tellg();
		}
		void ptr_towrite()
		{
			this->laststrmpos = this->Fstrm.tellg();
			this->Fstrm.seekg(this->lastwritepos);
		}
		void record_writepos()
		{
			this->lastwritepos = this->Fstrm.tellg();
		}
		void ptr_goback()
		{
			this->Fstrm.seekg(this->laststrmpos);
		}
		void record_lastpos()
		{
			this->laststrmpos = this->Fstrm.tellg();
		}
		streampos get_ptrpos()
		{
			return this->Fstrm.tellg();
		}
		void set_ptrpos(streampos posin)
		{
			this->Fstrm.seekg(posin);
		}
		template<class T>
		void write(T writevar) //only works with basic types
		{
			this->ptr_towrite();
			this->Fstrm.write(reinterpret_cast<char*>(&writevar), sizeof(writevar));
			this->record_writepos();
		}
		template<class T>
		void write(T writevar, to_frommode modeset) //only works with basic types
		{
			this->record_lastpos();
			switch (modeset)
			{
			case endpos:
				this->ptr_toend();
				break;
			case beginpos:
				this->ptr_tostart();
				break;
			case standard:
				this->ptr_towrite();
				break;
			case lastpos:
				this->ptr_goback();
				break;
			}
			this->Fstrm.write(reinterpret_cast<char*>(&writevar), sizeof(writevar));
			this->record_writepos();
		}
		template<> void write<std::string>(std::string writevar) //only works with basic types
		{
			this->ptr_towrite();
			size_t sizeofstring = writevar.size();
			this->Fstrm.write(reinterpret_cast<const char*>(&sizeofstring), sizeof(size_t));
			this->Fstrm.write(writevar.c_str(), sizeofstring);
			this->record_writepos();
		}
		template<> void write<std::string>(std::string writevar, to_frommode modeset) //only works with basic types
		{
			size_t sizeofstring = writevar.size();
			this->record_lastpos();
			switch (modeset)
			{
			case endpos:
				this->ptr_toend();
				break;
			case beginpos:
				this->ptr_tostart();
				break;
			case standard:
				this->ptr_towrite();
				break;
			case currentpos:
				break;
			case lastpos:
				this->ptr_goback();
				break;
			default:
				throw ZTRutils::ID10T_ERR(); // :)
			}
			this->Fstrm.seekg(0, ios::end);
			this->Fstrm.write(reinterpret_cast<const char*>(&sizeofstring), sizeof(size_t));
			this->Fstrm.write(writevar.c_str(), sizeofstring);
			this->record_writepos();
		}
		template<class T>
		T read(to_frommode modeset) //only works with basic types
		{
			switch (modeset)
			{
			case endpos:
				this->ptr_toend();
				break;
			case beginpos:
				this->ptr_tostart();
				break;
			case standard:
				this->ptr_toread();
				break;
			case currentpos:
				break;
			case lastpos:
				this->ptr_goback();
				break;
			default:
				throw ZTRutils::ID10T_ERR(); // :)
			}
			T returnvar = T();  
			this->Fstrm.read((char*)(&returnvar), sizeof(T));
			this->record_readpos();
			return returnvar;
		}
		template<class T>
		T read(to_frommode modeset, size_t readsize) //only works with basic types
		{
			switch (modeset)
			{
			case endpos:
				this->ptr_toend();
				break;
			case beginpos:
				this->ptr_tostart();
				break;
			case standard:
				this->ptr_toread();
				break;
			case currentpos:
				break;
			case lastpos:
				this->ptr_goback();
				break;
			default:
				throw ZTRutils::ID10T_ERR(); // :)
			}
			T returnvar = T();
			this->Fstrm.read((char*)(&returnvar), sizeof(T));
			this->record_readpos();
			return returnvar;
		}
		template<class T>
		T read()
		{
			this->ptr_toread();
			T returnvar = T();
			this->Fstrm.read((char*)(&returnvar), sizeof(T));
			this->record_readpos();
			return returnvar;
		}
		template<> std::string read<std::string>(to_frommode modeset)
		{
			switch (modeset)
			{
			case endpos:
				this->ptr_toend();
				break;
			case beginpos:
				this->ptr_tostart();
				break;
			case standard:
				this->ptr_toread();
				break;
			case currentpos:
				break;
			case lastpos:
				this->ptr_goback();
				break;
			default:
				throw ZTRutils::ID10T_ERR(); // :)
			}
			size_t size;
			this->Fstrm.read(reinterpret_cast<char*>(&size), sizeof(size_t));
			std::string holdstring(size,'\0');
			this->Fstrm.read(&holdstring[0], size);
			this->record_readpos();
			return holdstring;
		}
		template<> char* read<char*>(to_frommode modeset, size_t readsize)
		{
			this->ptr_toread();
			char* holder = new char;
			this->Fstrm.read(holder, sizeof(readsize));
			this->record_readpos();
			return holder;
		}
	};
}

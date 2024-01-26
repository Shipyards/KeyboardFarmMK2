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

#include <iostream>
#include "ZTRinterface.h"
#include "ZTRengine.h"
#include "newGame.h"
#include "loadGame.h"
#include "credits.h"
#include "ZTRFIO.h"
#include "editsaves.h"


using namespace ZTRengine;

gamecore* ZTRcore::Gcore = new gamecore();
ZTRutils* ZTRcore::util = new ZTRutils();
datacore* ZTRcore::Dcore = new datacore();

int main()
{
	using namespace std;
	newGame* begin = new newGame();
	loadGame* load = new loadGame();
	credits* credit = new credits();
	vector<runable*> menuitems = { begin, load, credit };
	ZTRinterface* mainInterface = new ZTRinterface("Keyboard Farm", menuitems);
	mainInterface->run('~');
	delete mainInterface;
}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
// Function to write a string to a binary file
//void writeStringToFile(const std::string& filename, const std::string& str) {
//	std::ofstream file(filename, std::ios::binary | std::ios::app);
//	if (file.is_open()) {
//		size_t strSize = str.size();
//		file.write(reinterpret_cast<const char*>(&strSize), sizeof(size_t));
//		file.write(str.c_str(), strSize);
//		file.close();
//		std::cout << "String '" << str << "' written to file successfully.\n";
//	}
//	else {
//		std::cerr << "Unable to open the file.\n";
//	}
//}
//
// Function to read strings from a binary file
//std::vector<std::string> readStringsFromFile(const std::string& filename) {
//	std::vector<std::string> result;
//
//	std::ifstream file(filename, std::ios::binary);
//	if (file.is_open()) {
//		size_t strSize;
//		while (file.read(reinterpret_cast<char*>(&strSize), sizeof(size_t))) {
//			std::string str(strSize, '\0');
//			file.read(&str[0], strSize);
//			result.push_back(str);
//		}
//
//		file.close();
//		std::cout << "Strings read from file successfully.\n";
//	}
//	else {
//		std::cerr << "Unable to open the file.\n";
//	}
//
//	return result;
//}
//
//int main() {
//	const std::string filename = "strings.dat";
//
//	 Strings to be written to the file
//	std::vector<std::string> stringsToWrite = { "Hello", "World", "C++", "Binary", "File" };
//
//	 Write each string to the file
//	for (const auto& str : stringsToWrite) {
//		writeStringToFile(filename, str);
//	}
//
//	 Read strings from the file
//	std::vector<std::string> readStrings = readStringsFromFile(filename);
//
//	 Display the read strings
//	std::cout << "Read strings:\n";
//	for (const auto& str : readStrings) {
//		std::cout << str << "\n";
//	}
//
//	return 0;
//}

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

#include "loadGame.h"

using namespace std;
using namespace ZTRengine;

loadGame::loadGame()
{
	this->name = "Load Game";
}
void loadGame::run(char runmode)
{
	load* loadgame = new load();
	loadgame->run('~');
	delete loadgame;
	throw ZTRutils::ZTRcontinue();
}
string loadGame::get_name()
{
	return this->name;
}

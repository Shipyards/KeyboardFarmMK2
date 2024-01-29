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

#include "newGame.h"
#include <iostream>

using namespace std;

newGame::newGame()
{
	this->name = "New Game";
}
void newGame::run(char runmode)
{
	char e;
	char userin;
	keyBoardFarm* thisGame = new keyBoardFarm();
	cout << "New game sucessfully created; press any key, then enter to begin\n:::" << flush;
	cin >> userin;
	cout << "Begining game\n";
	thisGame->start();
	delete thisGame;
	return;
}
string newGame::get_name()
{
	return this->name;
}

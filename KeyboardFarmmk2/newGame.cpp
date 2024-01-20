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
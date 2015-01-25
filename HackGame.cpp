// HackGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "game_core.h"

int _tmain(int argc, _TCHAR* argv[]) {
	std::cout << "Start Running..." << std::endl;
	game_core gc;
	gc.start_game();
}

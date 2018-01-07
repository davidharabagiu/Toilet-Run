//
// Main.cpp
// Main source file. Contains the entry point of the application.
// Created by David Harabagiu on 21.12.2017
//

#include "Game.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	srand(time(NULL));
	Game game("Toilet Run Dev Test");
	game.Run();
	return 0;
}

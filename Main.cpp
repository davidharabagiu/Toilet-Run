//
// Main.cpp
// Main source file. Contains the entry point of the application.
// Created by David Harabagiu on 21.12.2017
//

#include "Game.hpp"
#include <ctime>

Game game("Toilet Run Dev Test");

int main(int argc, char **argv)
{
	srand(time(NULL));
	game.Run();
	return 0;
}

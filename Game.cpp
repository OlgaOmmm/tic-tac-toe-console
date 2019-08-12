#include <iostream>
#include "Game.h"

//game cycle
Game::Game() {
	while (!endOfGame()){
		this->draw();
		std::cout << "\twaiting for player " << current_player << '\n';
		inputNumber = this->getPlayerData();
		this->setPlayerData();
		this->player_change();
	}
}

//draw game space
void Game::draw() {
	std::cout << "._______.\n";
	std::cout << "|XO-game|\n";
	std::cout << "|_" << arr[0] << "_" << arr[1] << "_" << arr[2] << "_|\n";
	std::cout << "|_" << arr[3] << "_" << arr[4] << "_" << arr[5] << "_|\n";
	std::cout << "|_" << arr[6] << "_" << arr[7] << "_" << arr[8] << "_|\n";
}

//input data processing
int Game::getPlayerData() {
	while (true) {
		int a;
		std::cout << "please, input a number from 1 to 9 to do your turn\n";
		std::cin >> a;

		if (std::cin.fail()) {
			std::cin.clear(); 
			std::cin.ignore(32767, '\n');
		}
		else {
			std::cin.ignore(32767, '\n'); 
			if ((a <= SIZE) && (a > 0)) {
				if (static_cast<int>(arr[a - 1]) == 49 + a - 1) //compare ascii
					return a;
			}
		}
	}
}

//writing to arr 'X' or 'O'
void Game::setPlayerData() {
	arr[inputNumber - 1] = player_sign;
}

//next player
void Game::player_change() {

	//change current player
	if (current_player == 1) {
		current_player = 2;
		player_sign = 'X';
	}
	else if (current_player == 2) {
		current_player = 1;
		player_sign = 'O';
	}
}

//when game over - write result (win or draw)
bool Game::endOfGame() {
	int arr_compare = 0;

	// if someone WIN
	if (((arr[0] == arr[1]) && (arr[1] == arr[2])) || ((arr[3] == arr[4]) && (arr[4] == arr[5])) || ((arr[6] == arr[7]) && (arr[7] == arr[8])) || //compare lines
		((arr[0] == arr[3]) && (arr[3] == arr[6])) || ((arr[1] == arr[4]) && (arr[4] == arr[7])) || ((arr[2] == arr[5]) && (arr[5] == arr[8])) || //compare columns
		((arr[0] == arr[4]) && (arr[4] == arr[8])) || ((arr[2] == arr[4]) && (arr[4] == arr[6]))) //compare diagonals
		{
		this->draw();
		if (current_player == 1)
			std::cout << "\tPlayer2 win!\nGAME OVER";
		else
			std::cout << "\tPlayer1 win!\nGAME OVER";
		return true;
		}

	//if player's moves are over - DRAW
	for (int i = 0; i < SIZE; ++i) {
		if ((arr[i] == 'X') || (arr[i]) == 'O')
			arr_compare++;
	}
	if (arr_compare == SIZE) {
		std::cout << "\tDraw!\nGAME OVER\n";
		return true;
	}
	else
		return false;
}

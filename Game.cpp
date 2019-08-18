#include <iostream>
#include <string>
#include "Game.h"

Game::Game() {
	currentPlayer = player1;
	playerSign = 'O'; // or 'X'
	inputNumber = ' ';
}
	
//game cycle
void Game::start() {
	while (!endOfGame()) {
		draw();
		std::cout << "\twaiting for Player" << currentPlayer << '\n';
		setPlayerData(inputNumber=getPlayerData(), playerSign);
		playerChange();
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
char Game::getPlayerData() {
	std::string playerData;
	char verifiedData;
	while (true) {
		std::cout << "please, input a number from 1 to 9 to do your turn\n";
		std::getline(std::cin, playerData);
		if (playerData.length() == 1 && playerData[0] <= '9' && playerData[0] >= '1')
			return verifiedData = playerData[0];
	}
}

//writing to arr 'X' or 'O'
void Game::setPlayerData(char& inputNumber, char& playerSign) {
	int arrIndex;
	arrIndex = (int)inputNumber - 49;
	arr[arrIndex] = playerSign;
}

//change player
void Game::playerChange() {

	//change current player
	if (currentPlayer ==player1) {
		currentPlayer = player2;
		playerSign = 'X';
	}
	else {
		currentPlayer = player1;
		playerSign = 'O';
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
		draw();
		if (currentPlayer == player1)
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

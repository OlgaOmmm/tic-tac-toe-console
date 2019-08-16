#pragma once
class Game {
public:
	Game();
	void start();
	void draw();
	int getPlayerData();
	void setPlayerData();
	void playerChange();
	bool endOfGame();
private:
	static const int SIZE = 9;
	char arr[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	enum players { player1 = 1, player2 } currentPlayer;
	char playerSign;
	char inputNumber;
};

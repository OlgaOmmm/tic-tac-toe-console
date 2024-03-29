#pragma once
class Game {
public:
	Game();
	void start();
	void draw();
	char getPlayerData();
	void setPlayerData(char inputNumber, char &playerSign);
	void playerChange();
	bool endOfGame();
private:
	static const int SIZE = 9;
	char arr[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	enum PlayerType { CROSS = 1, NAUGHT } currentPlayer;
	char playerSign;
};	

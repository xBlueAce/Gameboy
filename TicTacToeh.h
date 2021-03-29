#ifndef TicTacToe_h
#define TicTacToe_h
#include "Player.h"
#include <vector>
using namespace std;

class TicTacToe {
public:
	TicTacToe();

	void displayBoard();
	//void setPlayers();
	void playGame();
	void updateBoard(char userInput, bool playerOne);
	//void settingUpBoard();
	bool isAvailableOption(char userInput, vector<char> v);
private:
	char spot_A = 'a', spot_B = 'b', spot_C ='c',       //  a | b | c
		spot_D = 'd', spot_E = 'e', spot_F = 'f',
		spot_G = 'g', spot_H = 'h', spot_I = 'i';
	//vector<char> available{ 'a','b','c','d','e','f','g','h','i' };
	//vector<char> chosen{};
	//Player One_;
	//Player Two_;
};

#endif // !TicTacToe_h


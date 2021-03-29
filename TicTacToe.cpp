#include <iostream>
#include <vector>
#include "TicTacToeh.h"
using namespace std;

TicTacToe::TicTacToe() {
	displayBoard();
	char arr[3][3] = { {spot_A, spot_B, spot_C},{spot_D, spot_E, spot_F}, {spot_G, spot_H,spot_I} };

}

void TicTacToe::displayBoard() {
	cout << spot_A << "|" << spot_B << "|" << spot_C << endl
		<< spot_D << "|" << spot_E << "|" << spot_F << endl
		<< spot_G << "|" << spot_H << "|" << spot_I << endl;
}

void TicTacToe::playGame() {
	int counter = 0; // counting the step of the game;
	bool hasWon = false; // if someone won
	bool playerOne = true; // player one = true and player two - false;
	char userInput{};
	vector<char> chosen{};

	cout << "intializing game... *Tic tac Toe*\n";
	displayBoard();
	do {
		
		// which player is playing
		if (playerOne) {
			cout << "Player 1 ";
			playerOne = false; // goes to next character;
		}
		else {
			cout << "Player 2 ";
			playerOne = true;
		}

		// check if it is a valid input
		// make sure it hasn't been chosen
		try {
			cout << "please select spot (a-i)\n>>";
			cin >> userInput;

			// checks if user input is within range
			if (userInput < 'a' || userInput > 'i'||!isAvailableOption(userInput, chosen)) {
				
				playerOne = !playerOne; // resets
				throw userInput;
			}
		}
		catch(char userInput){
			cout << "your input is out of range, please try another one\n";
			continue;
		}
		
		
		// updateboard
		chosen.push_back(userInput); // added user option to chosen vector.
		cout << "will update board\n\n";
		updateBoard(userInput, !playerOne);
	} while (!hasWon);
}

void TicTacToe::updateBoard(char userInput, bool playerOne) {
	char insert;
	(playerOne) ? insert = 'X' : insert = 'O';
	if (userInput == 'a') {
		spot_A = insert;
	}
	else if (userInput == 'b') {
		spot_B = insert;
	}
	else if (userInput == 'c') {
		spot_C = insert;
	}
	if (userInput == 'd') {
		spot_D = insert;
	}
	else if (userInput == 'e') {
		spot_E = insert;
	}
	else if (userInput == 'f') {
		spot_F = insert;
	}
	if (userInput == 'g') {
		spot_G = insert;
	}
	else if (userInput == 'h') {
		spot_H = insert;
	}
	else if (userInput == 'i') {
		spot_I = insert;
	}
	displayBoard();
	return;
}

bool TicTacToe::isAvailableOption(char userInput, vector<char> v) {
	// if it is empty then option has been taken
	if (v.empty()) {
		return true;
	}

	//checks vector to ensure it is not taken
	for (auto x : v) {
		if (userInput == x) {
			return false;
		}
	}
	
	return true;
}
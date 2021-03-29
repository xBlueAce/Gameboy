/*
Application created by Carlos Agustin

*/

#include <iostream>
#include "Player.h"
#include "TicTacToeh.h"
#include <string>
using namespace std;


void greeting();
void testnewUser();
void mainMenuText(bool isUserLogged);
//input valid for selection
char input;

int main() {
	TicTacToe ttt;
	bool toContinue = true; // checks to continue
	bool isUserlogged = false; // check to see if user is logged in.
	char userInput;
	greeting();
	std::cin.ignore(); // Ignoring
	//testnewUser();
	do {
		mainMenuText(isUserlogged);
		cin >> userInput;
		switch (userInput) {
		case 'a': cout << "running a";
			
			ttt.playGame();
			break;

		case 'b': cout << "running b";
			break;
		
		case 'c': cout << "running c";
			break;
		default:
			cout << "default\n";
		}
	} while (toContinue && userInput != 'q');
	return 0;
}


void greeting() {
	std::cout << "Welcome to Carlos Agustin Program." << std::endl;
	std::cout << "press enter to continue..." << std::endl << ">>";
}

void mainMenuText(bool isUserLogged) {
	std::cout << "[a] Log in\n"
		<< "[b] .....\n";
	if (isUserLogged) {
		std::cout << "[b] TicTacToe\n"
			<< "[c] other games";
	}
	std::cout << "[q] to quit\n>>";

}

void testnewUser() {
	std::string name;
	std::cout << "Please Enter Player Name:";
	//std::getline(std::cin, name);
	dPlayerList dli;
	dli_display(dli);
	dli_prepend(dli, "first", 1, 12);
	std::cout << dli.size_ << " is the size!" << std::endl;
	cout << "\n\n displaying current dli\n";
	dli_display(dli);
	cout << endl;
	dli_append(dli, "second", 2, 13);
	dli_prepend(dli, "zero", 0, 11);
	dli_append(dli, "last", 3, 14);
	dli_insertAt(dli, 2, "change2", 24, 2);
	dli_insertAt(dli, 0, "new zero", 10, 1);
	dli_insertAt(dli, 20, "20 index", 222222, 15);
	cout << dli.size_ << " is the size of the list!\n";
	cout << endl;
	dli_display(dli);
	dli_delete(dli, 0);
	cout << endl << endl;
	dli_display(dli);


	cout << "\n\ndeleting the last one\n";
	cout << dli.size_ << "<- this is the size of the dli\n";
	dli_delete(dli, dli.size_ - 1);
	dli_display(dli);


	cout << "\n\n\n testing out if we worked out at any number.\n";
	dli_display(dli);
	cout << endl << endl;
	dli_delete(dli, 3);
	dli_display(dli);
	
}

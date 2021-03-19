/*
Application created by Carlos Agustin

*/

#include <iostream>
#include "Player.h"
#include <string>

void greeting();
void newUser();

//input valid for selection
char input;

int main() {
	
	greeting();
	std::cin.ignore(); // Ignoring
	newUser();
	
	return 0;
}


void greeting() {
	std::cout << "Welcome to Carlos Agustin Program." << std::endl;
	std::cout << "press enter to continue..." << std::endl << ">>";
}

void mainMenu() {
	std::cout << "[a] Tic Tac Toe\n"
		<< "[b] ....."
		<< "[q] Quit\n>>";

}

void newUser() {
	std::string name;
	std::cout << "Please Enter Player Name:";
	//std::getline(std::cin, name);
	dPlayerList dli;
	dli_prepend(dli, "first", 1, 12);
	std::cout << dli.size_ << " is the size!" << std::endl;
	dli_append(dli, "second", 2, 13);
	dli_prepend(dli, "zero", 0, 11);
	dli_append(dli, "last", 3, 14);
	dli_insertAt(dli, 2, "change2", 24, 2);
	dli_insertAt(dli, 0, "new zero", 10, 1);
	dli_insertAt(dli, 20, "20 index", 222222, 15);
	std::cout << dli.size_ << " is the size of the list!\n";
	dli_delete(dli, 0);
	dli_display(dli);
}

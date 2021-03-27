#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"

//Constructors
Player::Player() :name_("James Bond"), id_(0001), score_(0000) {}

Player::Player(std::string name) : name_(name), id_(0002), score_(0001) {}

Player::Player(std::string name, int score, int id) : name_(name), id_(id), score_(score) {}

//Accessors
std::string Player::getName() const { return name_; }
int Player::getScore() const { return score_; }
int Player::getID() const { return id_; }

// Mutators
void Player::setName(std::string name) { name_ = name; }
void Player::setID(int id) { id_ = id; }
void Player::setScore(int score) { score_ = score; }

std::ostream& operator<<(std::ostream& os, const Player& pl) {
	os << std::setprecision(2) << std::fixed;
	return os << "Player[" << std::setw(12) << pl.name_ << " ID:"
		<< pl.id_ << " Score:" << pl.score_ << "]";
}

// displays the node.
std::ostream& operator<<(std::ostream& os, const playerNode& node) {
		return os << node.prev_ << "<---" << node.pl_ << "-->" << node.next_;
	}

/*
				DOUBLE LINKEDLIST FUNCTIONS

*/

void dli_prepend(dPlayerList& dli, playerNode* node) {
	
	playerNode *p = dli.head_;	// we let create a temp node and point it to the head of dli
	node->next_ = p;			// Now that node, the next we point to p, previous will stay null
	dli.head_ = node;			// then we point the head_ to the node, to show it is the begining of the list

	// Ensuring the prev point is set properly.
	if (dli.size_ == 0) { // if list is empty
		dli.tail_ = node; // we point the tail to this node
	}
	else if (dli.size_ > 0) {
		playerNode* prevP = dli.tail_;
		while (prevP->prev_ != nullptr) {
			prevP = prevP->prev_;
		}
		prevP->prev_ = node;
	}
	++dli.size_;
}

void dli_prepend(dPlayerList& dli, const std::string& name, int id, int score) {
	dli_prepend(dli, new playerNode(Player(name, score, id)));
}

//adding node to the end
void dli_append(dPlayerList& dli, playerNode* node) {
	playerNode *p = dli.tail_;	//setting a temp node to point to the end
	node->prev_ = p;			//point node->prev to that temp node
	dli.tail_ = node;			//point tail to the node.
	
	// setting the head to the node if it is empty
	if (dli.size_ == 0) {
		dli.head_ = node;
	}
	else if(dli.size_>0){
		playerNode* index = dli.head_;
		while(index->next_!=nullptr){
			index = index->next_;
		}
		index->next_ = node; //we want he next to point to the node instead of null since we added a new vaule.
		
	}
	++dli.size_; // increasing size since we are adding to the list.
}

void dli_append(dPlayerList& dli, const std::string& name, int id, int score) {
	dli_append(dli, new playerNode(Player(name, id, score)));
}

// inserting at specfic point in the list.
// start as |0|1|2|3|4| ... |n| ...
void dli_insertAt(dPlayerList& dli, size_t index, playerNode* node) {
	if (index == 0) {
		dli_prepend(dli, node);
		return;
	}
	else if (index >= dli.size_) {
		if (index > dli.size_) {
			std::cout << "Index is out of scope. Apending to the end.";
		}
		dli_append(dli, node);
		return;
	}
	else {
		size_t currently = 0;
		playerNode* tempP = dli.head_;
		while (index != (currently++ + 1)) {
			tempP = tempP->next_;
		}
		playerNode* tempP1 = tempP->next_;
		tempP->next_ = node;
		node->next_ = tempP1;

		node->prev_ = tempP;
		tempP1->prev_ = node;
		dli.size_++;
	}
}

void dli_insertAt(dPlayerList& dli, size_t index, const std::string& name, int id, int score) {
	dli_insertAt(dli, index, new playerNode(Player(name, id, score)));
}



// dli => |0|1|.....|n-1|n|
void dli_delete(dPlayerList& dli, size_t index) {
	// if nothign on the list
	if (dli.size_ == 0) {
		std::cout << "ERROR CANNOT DELETE. ERROR CODE NO DATA TO DELETE.\n";
		return;
	}

	// if index is 0 an size is 1
	if (dli.size_ == 1 && index == 0) {
		dli.head_ = nullptr;
		dli.tail_ = nullptr;
		dli.size_ -= 1;
		return;
	}
	//  it is out of scope to delete.
	if (dli.size_ <= 0 || (index < 0 || index > dli.size_ - 1)) {
		std::cout << " OUT OF SCOPE ERROR."<<
			"index is " << index << " and size is << "<< dli.size_ << "\n";
		return;
	}

	//variables
	playerNode* pH0 = dli.head_;
	playerNode* pH1 = pH0->next_;

	playerNode* pT0 = dli.tail_;
	playerNode* pT1 = pT0->prev_;

	// if deleting the first
	if (index == 0) {
		// deletes head
		dli.head_ = pH1;
		pH0 = nullptr;
		dli.size_ -= 1;
		pH1->prev_ = nullptr; // deletes tail
		return;
	}

	//if deleting the last index;
	if (index == (dli.size_ - 1)) {
		pT0 = pT0->prev_; // sets to the node previous
		pT0->next_ = nullptr; // make it point to null
		dli.tail_ = pT0; // point tail to the last node
		return;
	}

	// delete whereever asked
	playerNode* temp = dli.head_;
	int counter = 0;
	while (counter != index) {
		temp = temp->next_;
		//std::cout << temp->pl_.getName() << "<-test->";
		counter += 1;
	}
	// pH0 is the node we want to delete;
	pT0 = temp->prev_;
	pT1 = temp->next_;

	pT0->next_ = pT1;
	pT1->prev_ = pT0;
	//delete pH0;




	
}

void dli_display(dPlayerList& dli) {
	playerNode * p = dli.head_;
	while (p != nullptr) {
		std::cout << *p << std::endl;
		p = p->next_;
	}
}
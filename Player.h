#ifndef Player_H
#define Player_H
#include <string>

//=======================================================================
//                    Player Class
//=======================================================================
class Player {
public:
	Player();
	Player(std::string name);
	Player(std::string name, int score, int id);
	
	// Accessors
	std::string getName()const;
	int getScore() const;
	int getID() const;

	//Mutators
	void setName(std::string name);
	void setID(int id);
	void setScore(int score);

	/*
	Putting player name on file.
	*/
	
	// displaying player.
	friend std::ostream& operator<<(std::ostream& os, const Player& pl);


private:
	std::string name_;
	int id_;
	int score_;
};


//=========================================================================
//             Starting of player linked list
//=========================================================================
//		Purpose is to ensure we can trace towards a list to ensure we have 
//  the right space for the amount of players.
//  
// -Carlos
//==========================================================================
struct playerNode {

	// player node of holding the data and the next part of the node.
	playerNode(const std::string& name, int score, int id,
		playerNode *prev = nullptr, playerNode* next = nullptr) :
		playerNode(Player(name, score, id), next, prev) {}

	playerNode(const Player& pl, playerNode* next = nullptr, playerNode*
		prev = nullptr) : pl_(pl), next_(next), prev_(prev) {}


	// displays the node 
	friend std::ostream& operator<<(std::ostream& os, const playerNode& node);

	// data "holder" of player
	Player pl_;

	// pointers of the node.
	struct playerNode *prev_;
	struct playerNode *next_;

}; // ending playerNode struct;

//===========================================================================
//                      Doubly link list
//===========================================================================
struct dPlayerList{
	dPlayerList() :head_(nullptr), tail_(nullptr), size_(0) {}

	playerNode* head_;
	playerNode* tail_;
	size_t size_;
};

//==========================================================================
//						Doubly-linked list Functions
//==========================================================================
void dli_prepend(dPlayerList& dli, playerNode* node);
void dli_prepend(dPlayerList& dli, const std::string& name, int id, int score);

void dli_append(dPlayerList& dli, playerNode* node);
void dli_append(dPlayerList& dli, const std::string& name, int id, int score);

//index is where the player wants to be added. |0|1|2|3|etc.|
void dli_insertAt(dPlayerList& dli, size_t index, playerNode* node);
void dli_insertAt(dPlayerList& dli, size_t index, const std::string& name, int id, int score);

void dli_delete(dPlayerList& dli, size_t index);

void dli_display(dPlayerList& dli);

#endif // ending of player header file
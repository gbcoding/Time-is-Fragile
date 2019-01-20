#pragma once
#include "Header.h"
//#include "Scientist.h"
#include "Items.h"
#include "map.h"

class Avatar
{
public:
	Avatar(status map[][30]);
	Avatar(status map[][30], string playername, string avatarname, int gamestate, int itemstate, int x, int y, int ls, int d1, int d2, int d3, int d4, int d5, int d6, int d7);
	~Avatar() {};
	// Function to format avatar dialogue	
	void avatarDialogue(const char * p); 

	//Basic commandline menu functions
	string commandLine(status map[][30]);

	void listCommands();

	void printJournal();

	void examineRoom(status map[][30]);
	
	
	// Avatar Movement functions
	void moveAvatarNorth(status map[][30], int steps);
	void moveAvatarSouth(status map[][30], int steps);
	void moveAvatarEast(status map[][30], int steps);
	void moveAvatarWest(status map[][30], int steps);

	int nearScientist(status map[][30]);
	
	// Various Gamestate Accessors

	string getPName(); //returns Player name
	string getAvatarName();

	//Coordinate getters
	status getAvatarPosition(status map[][30]);
	int getX() { return x; } 
	int getY() { return y; }
		
	int getGameState();
	int getRoom(status map[][30]);
	int getItemState();

	int getLS_dialogue_state() { return ls_dialogue_state; }
	int getS1_dialogue_state() { return s1_dialogue_state; }
	int getS2_dialogue_state() { return s2_dialogue_state; }
	int getS3_dialogue_state() { return s3_dialogue_state; }
	int getS4_dialogue_state() { return s4_dialogue_state; }
	int getS5_dialogue_state() { return s5_dialogue_state; }
	int getS6_dialogue_state() { return s6_dialogue_state; }
	int getS7_dialogue_state() { return s7_dialogue_state; }
	

	// Mutators that collect information from passed object.
	
	void setCoords(int new_x, int new_y);

	void setGameState(int new_gamestate);
	void pickUpItem(int how_many);
	void setItemState(int new_state);

	void setLS_dialogue_state(int new_state);
	void setS1_dialogue_state(int new_state);
	void setS2_dialogue_state(int new_state);
	void setS3_dialogue_state(int new_state);
	void setS4_dialogue_state(int new_state);
	void setS5_dialogue_state(int new_state);
	void setS6_dialogue_state(int new_state);
	void setS7_dialogue_state(int new_state);
	

private:
	//string current_action;
	string player_name;
	string avatar_name;
	
	int x; //current column position (0-29)
	int y; //current row position; (0-19)

	//variables for storing various states of the game
	int current_room;
	int game_state;
	int item_state = 0;

	int ls_dialogue_state = 1;
	int s1_dialogue_state = 1;
	int s2_dialogue_state = 1;
	int s3_dialogue_state = 1;
	int s4_dialogue_state = 1;
	int s5_dialogue_state = 1;
	int s6_dialogue_state = 1;
	int s7_dialogue_state = 1;
};
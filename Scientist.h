#pragma once
#include "Header.h"
#include "Avatar.h"
#include "map.h"
class Scientist
{
	public:
		Scientist(){}; 
		Scientist(string init_name, int init_x, int init_y, status map[][30]);
		void setCoords(int new_x, int new_y);

		//accessors
		int getGameState();
		string getName();
		int getLS_DialogueState();
		int getS1_DialogueState();
		int getS2_DialogueState();
		int getS3_DialogueState();
		int getS4_DialogueState();
		int getS5_DialogueState();
		int getS6_DialogueState();
		int getS7_DialogueState();
		int getX();
		int getY();
		bool isAdjacent(status map[][30]);
		void setToExamined() { isExamined = true; }

		//mutators

		void setGameState(int update_game_state);

		//dialogue interaction functions for talking to scientists
		void scientist1Dialogue(Avatar* the_player);
		void scientist2Dialogue(Avatar* the_player);
		void scientist3Dialogue(Avatar* the_player);
		void scientist4Dialogue(Avatar* the_player);
		void scientist5Dialogue(Avatar* the_player);
		void scientist6Dialogue(Avatar* the_player);
		void scientist7Dialogue(Avatar* the_player);

	protected:	
		int x, y;
		int game_state;
		string name;
		bool isExamined = false;
		//initates dialogue states to 1 at the beginning of the game.
		static int ls_dialogue_state;
		static int s1_dialogue_state;
		static int s2_dialogue_state;
		static int s3_dialogue_state;
		static int s4_dialogue_state;
		static int s5_dialogue_state;
		static int s6_dialogue_state;
		static int s7_dialogue_state;
	
	// TODO Dialogue
	// TODO Possibly a function to give player an item
	// TODO As dialogue is run, update in player's journal


};

class Lead_Scientist: public Scientist
{
	public:
		Lead_Scientist() {};
		Lead_Scientist(string init_name, int init_x, int init_y, status map[][30]);
		void leadScientistDialogue(Avatar* the_player);	
};
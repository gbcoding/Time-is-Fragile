//This file will write all info needed to save the game to saveFile.txt

#include "saveFile.h"
#include "Avatar.h"

void saveGame(Avatar* the_player)
{
	char savefile;
	cout << "Which save file do you wish to save your game to?\n\n";

	cout << "1) Save File 1\n";
	cout << "2) Save File 2\n";
	cout << "3) Save File 3\n";

	cin >> savefile;
	if (savefile == '1')
	{
		ofstream gameFile;
		gameFile.open("saveFile.txt");		

		gameFile << the_player->getPName() << " " << the_player->getAvatarName() << " " << the_player->getGameState() << " " << the_player->getItemState() << " " << the_player->getX() << " " << the_player->getY() << " " << the_player->getLS_dialogue_state() << " " << the_player->getLS_dialogue_state() << " " << the_player->getS1_dialogue_state() << " " << the_player->getS2_dialogue_state() << " " << the_player->getS3_dialogue_state() << " " << the_player->getS4_dialogue_state() << " " << the_player->getS5_dialogue_state() << " " <<
			the_player->getS6_dialogue_state() << " " << the_player->getS7_dialogue_state() << endl;

		gameFile.close();
	}
	else if (savefile == '2')
	{
		ofstream gameFile;
		gameFile.open("saveFile2.txt");

		gameFile << the_player->getPName() << " " << the_player->getAvatarName() << " " << the_player->getGameState() << " " << the_player->getItemState() << " " << the_player->getX() << " " << the_player->getY() << " " << the_player->getLS_dialogue_state() << " " <<	the_player->getLS_dialogue_state() << " " << the_player->getS1_dialogue_state() << " " << the_player->getS2_dialogue_state() << " " << the_player->getS3_dialogue_state() << " " << the_player->getS4_dialogue_state() << " " << the_player->getS5_dialogue_state() << " " <<
			the_player->getS6_dialogue_state() << " " << the_player->getS7_dialogue_state() << endl;

		gameFile.close();
	}
	else if (savefile == '3')
	{
		ofstream gameFile;
		gameFile.open("saveFile3.txt");
		
		gameFile << the_player->getPName() << " " << the_player->getAvatarName() << " " << the_player->getGameState() << " " << the_player->getItemState() << " " << the_player->getX() << " " << the_player->getY() << " " << the_player->getLS_dialogue_state() << " " <<	the_player->getLS_dialogue_state() << " " << the_player->getS1_dialogue_state() << " " << the_player->getS2_dialogue_state() << " " << the_player->getS3_dialogue_state() << " " << the_player->getS4_dialogue_state() << " " << the_player->getS5_dialogue_state() << " " <<
			the_player->getS6_dialogue_state() << " " << the_player->getS7_dialogue_state() << endl;

		gameFile.close();
	}
	else
	{
		cout << "Invalid Input\n\n";
	}

	cout << "Game saved" << endl;
}

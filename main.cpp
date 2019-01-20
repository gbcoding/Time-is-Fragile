/*---------------------------------------------------------------------|
| Name: Time is fragile Laboratory(Level Zero) main.cpp file.          |
|                                                                      |
| Main function: This file carries out story and objective progression |
| Makes use of Avatar object, Scientist objects, and item objects as   |
| well as functions from func.cpp and map.cpp.                         |
|----------------------------------------------------------------------|*/


#include "Header.h"
#include "Avatar.h"
#include "Scientist.h"
#include "func.h"
#include "map.h"
#include "Items.h"
#include "saveFile.h"

char confirmation;
status map[20][30];

int main()
{
	

	char main_select, save_menu;
	bool menu_flag = true;
	Avatar *Player = NULL;
	InitMap(map);

	//variables responsible for loading of save files
	string arg1, arg2, arg3; //variables for displaying save file
	do
	{
	cout << "===========================================================================================\n"
	     << "##########   ##########   ###          ###   ###########                                   \n"
	     << "    ##           ##       ## ##      ## ##   ## 			                                \n"
	     << "    ##           ##       ##  ##    ##  ##   ##                                            \n"
	     << "    ##           ##       ##   ##  ##   ##   ######  	                                    \n"
	     << "    ##           ##       ##    ####    ##   ##                                            \n"
	     << "    ##           ##       ##     ##     ##   ##                                            \n"
	     << "    ##       ##########   ##     ##     ##   ###########                                   \n"
	     << "          ----------------------------                                                     \n"
	     << "             ##########       ###	       						                            \n"
	     << "                 ##        ###  ### 							                            \n"
	     << "                 ##       ##                                                               \n"  
	     << "                 ##         ###                                                            \n"
	     << "                 ##            ###                                                         \n"
	     << "                 ##               ##                                                       \n"
	     << "                 ##        ###  ###                                                        \n"
	     << "             ##########      ###                                                           \n"
	     << "          ----------------------------                                                     \n"
	     << "##########   ########         ##           ####      ##########   ##           ##########  \n"
	     << "##           ##     ##      ##  ##       ##    ##        ##       ##           ##          \n"
	     << "##           ##    ##      ##    ##     ##      ##       ##       ##           ##          \n"
	     << "######       #######      ##########   ##                ##       ##           ######      \n" 
	     << "##           ##    ##     ##      ##   ##    #####       ##       ##           ##          \n"
	     << "##           ##     ##    ##      ##    ###     ##       ##       ##           ##    	    \n"
	     << "##           ##      ##   ##      ##      #####  #   ##########   ##########   ##########  \n"
	     << "========================================================================================== \n";
	cout << endl
	    << "___                    __    __   ___   ___    __  ___  ___    ___   ___   _  _  _    _         __                         \n" // Prints By Garrett Brumley & Jacob Montes
		<< "|__|  |___|     ====  | __  |__|  |__|  |__|  |__   |    |     |__|  |__|  |  |  |\\  /|  |     |__   |___|   ====               \n"
		<< "|__|    |             |__|  |  |  |  \\  |  \\  |__   |    |     |__|  |  \\  |__|  | \\/ |  |___  |__     |                    \n"

		<< "                _   __   ___   __   ___    _    _   __         ___   __   __         \n"
		<< "        ====    |  |__|  |    |  |  |__|   |\\  /|  |  |  |\\  |  |   |__  |__  ====    \n"
		<< "             |__|  |  |  |__  |__|  |__|   | \\/ |  |__|  |  \\|  |   |__   __|            \n\n\n";
	
		cout << "1) New Game \n"
		     << "2) Continue \n"
		     << "3) Quit Game \n";
	
		cout << "Select an Option (Enter the number): ";
		cin >> main_select;
		cin.ignore(); //clean input stream
					  					  
		//check to see if there is a save file 
		// If there is not, display only new game and quit game as options.
		// If there is, a save file in the whatever directory detected, load it and give option to continue game.

		if(main_select == '1') //start new game
		{
			menu_flag = false;
		}
		else if(main_select == '2')
		{			
			bool local_flag = true;

			//Save file initialization variables
			string p_name_init1, a_name_init1, p_name_init2, a_name_init2, p_name_init3, a_name_init3;
			int gamestate_init1, itemstate_init1, x_init1, y_init1, ls_init1, d1_init1, d2_init1, d3_init1, d4_init1, d5_init1, d6_init1, d7_init1;
			int gamestate_init2, itemstate_init2, x_init2, y_init2, ls_init2, d1_init2, d2_init2, d3_init2, d4_init2, d5_init2, d6_init2, d7_init2;
			int gamestate_init3, itemstate_init3, x_init3, y_init3, ls_init3, d1_init3, d2_init3, d3_init3, d4_init3, d5_init3, d6_init3, d7_init3;

			while (local_flag == true)				
			{
				system("CLS");
				cout << "===============================================\n";
				cout << "              \"S A V E   F I L E S\"         \n\n";

				//Displays Save Files

				char c; //manipulation character

				ifstream gameFile("saveFile.txt"); //open file to gameFile input stream
				if (gameFile.is_open()) //if file can be opened
				{
					c = gameFile.peek(); //check to see if there's anything in the file
					if (c == EOF) //if empty, do not display.
					{
						
					}
					else //if not empty
					{
						gameFile >> p_name_init1 >> a_name_init1 >> gamestate_init1 >> itemstate_init1 >> x_init1 >> y_init1 >> ls_init1 >> d1_init1 >> d2_init1 >> d3_init1 >> d4_init1 >> d5_init1 >> d6_init1 >> d7_init1; //read in initialization variables
													
						cout << "1) Player name: " << p_name_init1 << "  Avatar name: " << a_name_init1 << "  Gamestate: " << gamestate_init1 << endl; // reads and displays savefile	
						gameFile.clear();
						gameFile.seekg(0, ios::beg);
						
					}
				}
				else //if file can not be opened
				{
					cout << "Error, could not load saveFile.txt.\n";
				}

				ifstream gameFile2("saveFile2.txt"); //open file to gameFile input stream
				if (gameFile2.is_open()) //if file can be opened
				{
					c = gameFile2.peek(); //check to see if there's anything in the file
					if (c == EOF)//if empty, do not display.
					{

					}
					else
					{
						gameFile2 >> p_name_init2 >> a_name_init2 >> gamestate_init2 >> itemstate_init2 >> x_init2 >> y_init2 >> ls_init2 >> d1_init2 >> d2_init2 >> d3_init2 >> d4_init2 >> d5_init2 >> d6_init2 >> d7_init2; //read in initialization variables 						
						cout << "2) Player name: " << p_name_init2 << "  Avatar name: " << a_name_init2 << "  Gamestate: " << gamestate_init2 << endl; // reads and displays savefile	
						gameFile2.clear();
						gameFile2.seekg(0, ios::beg);
					}
				}
				else //if file can not be opened
				{
					cout << "Error, could not load saveFile2.txt.\n";
				}

				ifstream gameFile3("saveFile3.txt"); //open file to gameFile input stream
				if (gameFile3.is_open()) //if file can be opened
				{
					c = gameFile3.peek();//check to see if there's anything in the file
					if (c == EOF) //if empty, do not display.
					{

					}
					else
					{
						gameFile3 >> p_name_init3 >> a_name_init3 >> gamestate_init3 >> itemstate_init3 >> x_init3 >> y_init3 >> ls_init3 >> d1_init3 >> d2_init3 >> d3_init3 >> d4_init3 >> d5_init3 >> d6_init3 >> d7_init3; //read in initialization variables					
						cout << "3) Player name: " << p_name_init3 << "  Avatar name: " << a_name_init3 << "  Gamestate: " << gamestate_init3 << endl; // reads and displays savefile	
						gameFile3.clear();
						gameFile3.seekg(0, ios::beg);
					}
				}
				else //if file can not be opened
				{
					cout << "Error, could not load saveFile3.txt.\n";
				}

				cout << "Type 'B' to go back\n";
				cout << "Select Save File to load:";
				cin >> save_menu;
				cin.ignore();//clean input stream

				if (save_menu == '1') //if player selects 1
				{
					c = gameFile.peek(); //check to see if there's anything in the file
					if (c != EOF)//check to see if it was properly loaded
					{
						Player = new Avatar(map, p_name_init1, a_name_init1, gamestate_init1, itemstate_init1, x_init1, y_init1, ls_init1, d1_init1, d2_init1, d3_init1, d4_init1, d5_init1, d6_init1, d7_init1);
						gameFile.close();
						gameFile2.close();
						gameFile3.close();

						local_flag = false; //end the loop
						menu_flag = false;
						cout << "=============================================\n\n";
					}
					else
					{
						cout << "Invalid Save File Detected\n\n";
						cin.ignore();
					}
				}
				else if (save_menu == '2') //same as 1, but for file 2
				{
					c = gameFile2.peek(); //check to see if there's anything in the file
					if (c != EOF)//check to see if it was properly loaded
					{
						Player = new Avatar(map, p_name_init2, a_name_init2, gamestate_init2, itemstate_init2, x_init2, y_init2, ls_init2, d1_init2, d2_init2, d3_init2, d4_init2, d5_init2, d6_init2, d7_init2);

						gameFile.close();
						gameFile2.close();
						gameFile3.close();

						local_flag = false;
						menu_flag = false;

						cout << "=============================================\n\n";
					}
					else
					{
						cout << "Invalid Save File Detected\n\n";
						cin.ignore();
					}
				}
				else if(save_menu == '3') //same as 1 and 2, but for file 3
				{
					c = gameFile3.peek(); //check to see if there's anything in the file
					if (c != EOF)//check to see if it was properly loaded
					{
						Player = new Avatar(map, p_name_init3, a_name_init3, gamestate_init3, itemstate_init3, x_init3, y_init3, ls_init3, d1_init3, d2_init3, d3_init3, d4_init3, d5_init3, d6_init3, d7_init3);

						gameFile.close();
						gameFile2.close();
						gameFile3.close();

						local_flag = false;
						menu_flag = false;

						cout << "=============================================\n\n";
					}
					else
					{
						cout << "Invalid Save File Detected\n\n";
						cin.ignore();
					}
				}
				else if (save_menu == 'b' || save_menu == 'B')
				{
					system("CLS");
					local_flag = false;
				}
				else
				{
					cout << "Invalid Save File Selected" << endl;
					cin.ignore();
				}
			}

			//Drop character back into the game level. 
		}
		else if(main_select == '3')
		{
			cout << "Exiting game.\n";
			return 0;
		}
		else
		{
			cout << "Invalid input.\n";
		}
	} while (menu_flag == true);

	if (main_select == '1')
	{

		//begin intro music here

		system("CLS");

		simTypeFast("=  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =\n\n\n");

		cout << "########     ########        ####      ##            ####          ####      ##       ##   ##########  \n"
			 << "##     ##    ##     ##     ##    ##    ##          ##    ##      ##    ##    ##       ##   ##          \n"
			 << "##    ##     ##    ##     ##      ##   ##         ##      ##    ##      ##   ##       ##   ##          \n"
			 << "######       #######      ##      ##   ##         ##      ##   ##            ##       ##   ######      \n"
			 << "##           ##    ##     ##      ##   ##         ##      ##   ##    #####   ##       ##   ##          \n"
			 << "##           ##     ##     ##    ##    ##          ##    ##     ###     ##    ##     ##    ##    	     \n"
			 << "##           ##      ##      ####      #########     ####         #####  #     #######     ##########  \n\n\n";
			 
		
		simTypeSlow(">> Beginning startup...\n\n");		
			
		simTypeFast("The year is 2095. Following the great Technological Boom in the 2070's, scientists \n\n"
			"have developed technologies thought impossible only 100 years prior. However, the \n\n"
			"rest of society is a dark and gloomy place. Distrust continued to escalate following \n\n"
			"a continuing cycle of endless lies from politicians and the media, increasing tensions in an\n\n"
			"increasingly divided America. Upheaval was soon to follow. Fall of 2043 saw violent protests,\n\n"
			"break out across the nation. Governmental response was brutal. Martial law was quickly declared\n\n"  
			"to secure the country until the crisis could be contained.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore(); //Dramatic pause

		simTypeFast("However, attempts to neutralize antigovernment forces were met with far heavier resistance \n\n"
			"than expected. Furious and distrustful citizens responded with force. Full might was\n\n"
			"brought down on those attempting to rebel, quelling the uprising but forcing Americans to\n\n"
			"live under oppressive authoritarian rule while the Federal Government attempted to regain control of the\n\n"
			"situation. Small, hidden forces of freedom fighters continued to carry out secret attacks aimed\n\n"
			"toward weakening the grip of \"The Feds\" and restoring democracy to the country once again.\n\n\n"
			"On December 31st, 2069, mysterious packages arrived at 100 different government buildings in America's largest\n\n"
			"cities, going unnoticed during the New Year's celebrations. \n\n\n"
			"At Midnight, at the turn of the decade, the packages went off.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore();// same

		simTypeFast("They were not bombs; far worse. Each package contained an extremely high energy EMP device,\n\n"
			"positioned at strategic geographic locations to trigger a massive EMP event and temporarily halt all \n\n"
			"government operations. This was designed to completely incapacitate government capabilities by taking\n\n"
			"out all US Electricity for a short amount of time to allow targeted assaults of key points. \n\n\n"
			"Fate changed that day when 8 hours into the operation, 8:00 am EST, a massive geomagnetic event occurred.\n\n\n"
			"A coronal mass ejection erupted from the Sun and scored a direct hit to earth, which collided\n\n"
			"with the man made EMP field, destroying electrical equipment and technology around the globe.\n\n"
			"With the earth in total blackout and without computers to support the infrastructures humans\n\n"
			"relied on, the world began to fall into chaos.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore();

		simTypeFast("The sheer force of the combined EMP event caused electrical fires globally. Forms of automated\n\n"
			"transportation were rendered all but useless. Food could not be produced or kept fresh\n\n"
			"and millions died to starvation. Workers were simply unable to coordinate or travel in a modern fashion\n\n"
			"and the modern world was without technology for nearly two years. With the complete collapse\n\n"
			"of society, new governments arose. The New American Government was founded in 2072, when\n\n"
			"a group of programmers, engineers, and other scientists gathered in an attempt to return\n\n"
			"the world to a technologically modern status once again.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore();

		simTypeFast("Many places were rendered uninhabitable due to contamination and waste\n\n"
			"released as a result of the failure of various hazard containment systems around the globe.\n\n"
			"Much of the significantly dwindled population is living in poor health and hunger. Despite\n\n"
			"this, technological advancement continues to progress at an extraordinarily fast rate.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore();

		simTypeFast("A small research arm of the New American Government has recently completed an ongoing\n\n"
			"project on a Time Travel device. The device itself is unstable, only allowing for a few short\n\n"
			"moments of cross-time travel. For this reason, any and all personnel using the device must \n\n"
			"form a mental interface link with an avatar. This will keep the agent safe in his own time\n\n"  
			"should the mission go awry. The avatar itself is capable of high quality self-decomposition\n\n" 
			"to eliminate the possibility of disturbing the timeline further.\n\n>>Press Enter to Continue\n\n\n");

		
		cin.ignore();

		simTypeFast("The mental interface link is very simple due to both time and technology restraints,\n\n"
			"meaning that the operator must utilize a command line interface to direct the avatar, a\n\n"
			"highly advanced semi-AI unit with superhuman functions, including strength and\n\n"
			"precision, as well as being highly sensory, capable of detecting all 5 human senses.\n\n"
			"The AI installed in the avatar is able to carry out most functions autonomously, but\n\n"
			"must follow all commands from the operator...\n\n\n"); //In this way, the avatar is capable handling itself for indefinite periods of time maintaining its current state while waiting for a command 

		simTypeFast("=  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =  =\n\n\n");

		cin.ignore();
		 
		//End intro music here.
	}
	system("CLS");
	int gamestate = 1;
	
	if (main_select == '1')
	{
		Player = new Avatar(map); // Player object is the object that will represent the user
	}
	
// Planned inventory stuff
//	const int max_items = 10;
//	string inventory[max_items];
//	int num_items = 0;
	
	Lead_Scientist LS("Henry Weiss", 17, 17, map); // Initialize Lead_Scientist object
	Scientist S1("Marcus Grey", 6, 9, map); //Initialize other scientists
	Scientist S2("Charles Bennigan", 3, 17, map);
	Scientist S3("Algernop Kaiser", 13, 9, map);
	Scientist S4("Rachel Klein", 17, 9, map);
	Scientist S5("Bernard Sanders", 22, 15, map);
	Scientist S6("Ezekiel Morris", 24, 13, map);
	Scientist S7("Jeremy Bantz", 23, 5, map);

	system("CLS");
	simTypeFast("E n t e r i n g  t h e . . . . \n\n");
	simTypeSuperFast("|\\           __   __   __   __    __  _____  __    __             /|\n");
	simTypeSuperFast("| \\/\\  |    |__| |__| |  | |__|  |__|   |   |  |  |__|  |___|  \\/\\ |\n");
	simTypeSuperFast("|/     |___ |  | |__| |__| |  \\  |  |   |   |__|  |  \\    |       \\|\n");
	simTypeSuperFast( "+------------------------------------------------------------------+\n");

	for (int i = 0; i < 20; i++)
	{
		printMapRow(i); // print grid row and left vertical column of board

						// now print board values for each row as characters
		for (int j = 0; j < 30; j++)
		{
			cout << static_cast<char>(map[i][j]) << " ";
		}

		cout << "|" << endl;    // print right vertical column of board
	}

	simTypeSuperFast("+------------------------------------------------------------------+\n"); 
	simTypeSuperFast("|______   |  __________|     |____    __|       __|    __|    __   |\n"); 
	simTypeSuperFast("|      |__|_____   |______        |__|  |    __|  |   |______|_____|\n"); 
	simTypeSuperFast("| __         |  |___|   |___| |_____     ___|      ______      | |_ |\n"); 
	simTypeSuperFast("|   |________|    __|      |__|    |____|   |___| |  |   |_____|   ||\n\n"); 
	simTypeSuperFast("A - Avatar Position                                  N      \n");
	simTypeSuperFast("# - Scientist Position                              /|\\    \n");
	simTypeSuperFast("! - Lead Scientist Position                      W---|---E  \n");
	simTypeSuperFast("% - Object Location                                 \\|/    \n");
	simTypeSuperFast("                                                     S      \n");
	
	cout << endl << endl;
	//=======
	//First objective code block
	//=======

	if (Player->getGameState() == 1)
	{
		
		simTypeFast("==New Objective: Talk to the lead scientist==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<";
		cin.ignore();
		bool local_flag = true;
		while (local_flag == true)
		{
			string action;
			
			action = Player->commandLine(map); //Call member function to take in player command


			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
					case 1:
						S1.scientist1Dialogue(Player);						
						break;
					case 2:
						S2.scientist2Dialogue(Player);
						break;
					case 3:
						S3.scientist3Dialogue(Player);
						break;
					case 4:
						S4.scientist4Dialogue(Player);
						break;
					case 5:
						S5.scientist5Dialogue(Player);
						break;
					case 6:
						S6.scientist6Dialogue(Player);
						break;
					case 7:
						S7.scientist7Dialogue(Player);
						break;
					case 9:
						if (action == "talk to lead scientist")
						{
							LS.leadScientistDialogue(Player);
							local_flag = false; //once objective has been completed, break loop
							Player->setGameState(2); //set new gamestate
						}
						else
						{
							Player->avatarDialogue("There are no scientists aroud me...\n\n");
						}						
						break;
					default:
						Player->avatarDialogue("There are no scientists aroud me...\n");
						break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
			if (local_flag == true)
			{
				cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
				cin.ignore();
			}
		}
		
	}

	//=======
	//Second objective code block
	//=======
	if (Player->getGameState() == 2)
	{		
		simTypeFast("==New Objective: Talk to scientists around the lab to see if they need help==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<";
		cin.ignore();
		bool local_flag = true;
		
		while (local_flag == true)
		{
			string action;
			
			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
					case 1:
						S1.scientist1Dialogue(Player);						
						local_flag = false; //objective is completed, move to next objective
						Player->setGameState(3);//Set new gamestate
						break;
					case 2:
						S2.scientist2Dialogue(Player);
						break;
					case 3:
						S3.scientist3Dialogue(Player);
						break;
					case 4:
						S4.scientist4Dialogue(Player);
						break;
					case 5:
						S5.scientist5Dialogue(Player);
						break;
					case 6:
						S6.scientist6Dialogue(Player);
						break;
					case 7:
						S7.scientist7Dialogue(Player);
						break;
					case 9:
						if (action == "talk to lead scientist")
						{
							LS.leadScientistDialogue(Player);
						}
						else
						{
							Player->avatarDialogue("There are no scientists aroud me...\n\n");
						}
						break;
					default:
						if (action == "talk to lead scientist")
						{
							Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
						}
						else
						{
							Player->avatarDialogue("There are no scientists aroud me...\n\n");
						}
						break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}
					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
			if (local_flag == true)
			{
				cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
				cin.ignore();
			}
		}
	}

	//=======
	//Third objective code block
	//=======
	if (Player->getGameState() == 3)
	{	
		simTypeFast("==New Objective: Find the Mass Spectrometer==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<";
		cin.ignore();
		bool local_flag = true;
		bool on_map = false;
		Item *Mass_Spectrometer = NULL; //declare pointer to item object

		while (local_flag == true)
		{
			string action;
			
			action = Player->commandLine(map);

			if ((action == "examine room") && (Player->getRoom(map) == 1) && Player->getItemState() == 0)
			{
				simTypeFast("Something has appeared on the map!\n\n");
				Mass_Spectrometer = new Item("Mass Spectrometer", 1, 5, 1, map); // Initialize new item  when player examines generator room. (Name: Mass Spectrometer, x: 1, y: 5, amount: 1, map array)
				on_map = true;
			}
			else if (action == "examine item")
			{
				if(on_map == true)
				{ 
					if (Mass_Spectrometer->isAdjacent(map) == true)
					{
						Player->avatarDialogue("There are many stacks of paper piled high on this desk. I need to be careful\n\n");
						simTypeFast("not to disturb anything while I search... It looks precarious.\n\nGive me one moment\n\n");
						cin.ignore();
						itemInteract(Mass_Spectrometer, Player); //pick up item
						if (Player->getItemState() != 0) //if player has picked up the item  //add to inventory
						{
							delete Mass_Spectrometer; //Deletes object from map after player picks it up
							on_map = false;
							map[5][1] = OPEN;
						}
					}
					else 
					{
						Player->avatarDialogue("There are no items near me...\n\n");
					}
				}
				else
				{
					Player->avatarDialogue("There are no items near me...\n\n");
				}
			}
			else if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					if (S1.getS1_DialogueState() == 3) //Aka, if item task was completed
					{
						Player->setGameState(4); //sets new gamestate
						local_flag = false; //objective is completed, move to next objective
					}
					break;
				case 2:
					S2.scientist2Dialogue(Player);
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
			cout << ">> Continue <<"; //displays continue command prompt
			cin.ignore();
		}
	}

	//=======
	//Fourth objective code block
	//=======
	if (Player->getGameState() == 4)
	{
		simTypeFast("==New Objective: Talk to other scientists around the lab==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<"; //displays continue command prompt
		cin.ignore();
		bool local_flag = true;

		while (local_flag == true)
		{
			string action;
			
			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					break;
				case 2:
					S2.scientist2Dialogue(Player); //Next in story, retrieve book for Scientist 2 from scientist 7. 
					Player->setGameState(5);
					local_flag = false;
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
	
			if (local_flag == true)
			{
				cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
				cin.ignore();
			}
		}
	}

	//=======
	//Fifth objective code block
	//=======

	if (Player->getGameState() == 5)
	{
		simTypeFast("==New Objective: Obtain the research book for Dr. Bennigan==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<"; //displays continue command prompt
		cin.ignore();
		bool local_flag = true;
		

		while (local_flag == true)
		{
			string action;

			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					break;
				case 2:
					S2.scientist2Dialogue(Player); //Next in story, retrieve book for Scientist 2 from scientist 7. 
					if (S2.getS2_DialogueState() == 3)
					{
						Player->setGameState(6);
						local_flag = false; //move to next game state
					}
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
			if (local_flag == true)
			{
				cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
				cin.ignore();
			}
		}
	}

	//=======
	//Sixth objective code block
	//=======
	if (Player->getGameState() == 6)
	{
		Player->avatarDialogue(" Alright, we've helped out two scientists so far. I suggest that we return to the lead scientist and check in on their progress\n\n");
		simTypeFast("==New Objective: Return to Lead Scientist==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<"; //displays continue command prompt
		cin.ignore();
		bool local_flag = true;

		while (local_flag == true)
		{
			string action;

			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					break;
				case 2:
					S2.scientist2Dialogue(Player); //Next in story, retrieve book for Scientist 2 from scientist 7. 
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
						local_flag = false; //once objective has been completed, break loop
						Player->setGameState(7); //set new gamestate
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
		}
		if (local_flag == true)
		{
			cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
			cin.ignore();
		}
	}

	//=======
	//Seventh objective code block
	//=======
	if (Player->getGameState() == 7)
	{
		simTypeFast("==New Objective: Obtain Power Core from Nuclear Storage Room==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<"; //displays continue command prompt
		Item *Nuclear_core = NULL; //declare pointer to item object
		Nuclear_core = new Item("Nuclear Core", 29, 11, 1, map); //place the nuclear core on the map
		bool on_map = true; 
		cin.ignore();
		bool local_flag = true;

		while (local_flag == true)
		{
			string action;

			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					break;
				case 2:
					S2.scientist2Dialogue(Player); //Next in story, retrieve book for Scientist 2 from scientist 7. 
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
						local_flag = false; //once objective has been completed, break loop
						Player->setGameState(8); //set new gamestate
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				if (on_map == true)
				{
					if (Nuclear_core->isAdjacent(map) == true)
					{
						Player->avatarDialogue("A glowing metal ball sits alone in a glass case. On the front side of the case, a tag reads\n\n");
						simTypeFast("\"DO NOT REMOVE WITHOUT EXPRESS PERMISSION FROM LEAD SCIENTIST.\"\n\n");
						cin.ignore();
						itemInteract(Nuclear_core, Player); //pick up item
						if (Player->getItemState() != 0) //if player has picked up the item  //add to inventory
						{
							delete Nuclear_core; //Deletes object from map after player picks it up
							map[11][29] = OPEN;
							on_map = false;
						}
					}
					else
					{
						Player->avatarDialogue("There are no items near me...\n\n");
					}
				}
				else
				{
					Player->avatarDialogue("There are no items near me...\n\n");
				}


			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
			if (local_flag == true)
			{
				cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
				cin.ignore();
			}
		}
	}

	//=======
	//Eighth and final objective code block
	//=======

	if (Player->getGameState() == 8)
	{
		simTypeFast("==New Objective: Deliver the Nuclear Core to Dr. Klein==\n\n");
		simTypeFast("Your Journal has been updated...\n\n");
		cout << ">> Continue <<"; //displays continue command prompt
		cin.ignore();
		bool local_flag = true;

		while (local_flag == true)
		{
			string action;

			action = Player->commandLine(map);

			if (action == "talk to scientist" || action == "talk to lead scientist")
			{
				switch (nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map))
				{
				case 1:
					S1.scientist1Dialogue(Player);
					break;
				case 2:
					S2.scientist2Dialogue(Player); //Next in story, retrieve book for Scientist 2 from scientist 7. 
					break;
				case 3:
					S3.scientist3Dialogue(Player);
					break;
				case 4:
					S4.scientist4Dialogue(Player);
					if (S4.getS4_DialogueState() == 4)
					{
						cout << ">> Continue <<" << endl;
						cin.ignore();
						Player->setGameState(9); //Go to end of level script.
					}
					break;
				case 5:
					S5.scientist5Dialogue(Player);
					break;
				case 6:
					S6.scientist6Dialogue(Player);
					break;
				case 7:
					S7.scientist7Dialogue(Player);
					break;
				case 9:
					if (action == "talk to lead scientist")
					{
						LS.leadScientistDialogue(Player);
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				default:
					if (action == "talk to lead scientist")
					{
						Player->avatarDialogue("I'm not near the lead scientist, "); cout << Player->getPName() << endl;
					}
					else
					{
						Player->avatarDialogue("There are no scientists aroud me...\n\n");
					}
					break;
				}
				syncGameStates(&S1, Player); //Which scientist object doesn't matter, all dialogue states are static.
			}
			else if (action == "examine scientist")
			{
				//detect for nearby scientists, store value and call examine scientist function to display detailed descriptions of the scientists.
				int nearby_scientist;
				nearby_scientist = nearPlayer(Player, LS, S1, S2, S3, S4, S5, S6, S7, map);
				if (nearby_scientist > 0)
				{
					switch (nearby_scientist)
					{
					case 1:
						S1.setToExamined();
						break;
					case 2:
						S2.setToExamined();
						break;
					case 3:
						S3.setToExamined();
						break;
					case 4:
						S4.setToExamined();
						break;
					case 5:
						S5.setToExamined();
						break;
					case 6:
						S6.setToExamined();
						break;
					case 7:
						S7.setToExamined();
						break;
					case 9:
						LS.setToExamined();
						break;
					}

					examineScientist(nearby_scientist);
				}
				else
				{
					Player->avatarDialogue("There are no scientists aroud me...\n");
				}
			}
			else if (action == "examine item")
			{
				Player->avatarDialogue("There are no items near me...\n\n");
			}
			else if (action == "save game")
			{
				saveGame(Player);
			}
			else if (action == "quit game")
			{
				delete Player;
				exit(0);
			}
			else
			{
				Player->avatarDialogue("I didn't understand that...\n\n");
				cout << ">>"; simTypeFast("Type help for list of commands\n\n");
			}
		}
		if (local_flag == true)
		{
			cout << ">> Continue <<"; //displays continue command prompt if not continuing to next objective
			cin.ignore();
		}
	}


	if (Player->getGameState() == 9)
	{
		simTypeFast("===================================================================================================================\n\n");
		//End of level scripting goes here
		simTypeFast("As you prepare to step into the device, all of the scientist in the lab gather in the main room to witness history.\n\n");
		simTypeFast("+All Scientists+ \"Good luck!\"\n\n"); 
		cin.ignore();
		Player->avatarDialogue("Well, here goes nothing. Get ready, "); cout << Player->getPName(); simTypeFast("!\n\n\n\n");

		simTypeFast("You jump into the Time Device....\n\n\n");


		simTypeSuperFast("===========================================================================================\n"
						 "##########   ##########   ###          ###   ###########                                   \n"
						 "    ##           ##       ## ##      ## ##   ## 			                                \n"
						 "    ##           ##       ##  ##    ##  ##   ##                                            \n"
						 "    ##           ##       ##   ##  ##   ##   ######  	                                    \n"
						 "    ##           ##       ##    ####    ##   ##                                            \n"
						 "    ##           ##       ##     ##     ##   ##                                            \n"
						 "    ##       ##########   ##     ##     ##   ###########                                   \n"
						 "          ----------------------------                                                     \n"
						 "             ##########       ###	       						                            \n"
						 "                 ##        ###  ### 							                            \n"
						 "                 ##       ##                                                               \n"
						 "                 ##         ###                                                            \n"
						 "                 ##            ###                                                         \n"
						 "                 ##               ##                                                       \n"
						 "                 ##        ###  ###                                                        \n"
						 "             ##########      ###                                                           \n"
						 "          ----------------------------                                                     \n"
						 "##########   ########         ##           ####      ##########   ##           ##########  \n"
						 "##           ##     ##      ##  ##       ##    ##        ##       ##           ##          \n"
						 "##           ##    ##      ##    ##     ##      ##       ##       ##           ##          \n"
						 "######       #######      ##########   ##                ##       ##           ######      \n"
						 "##           ##    ##     ##      ##   ##    #####       ##       ##           ##          \n"
						 "##           ##     ##    ##      ##    ###     ##       ##       ##           ##    	    \n"
						 "##           ##      ##   ##      ##      #####  #   ##########   ##########   ##########  \n"
						 "========================================================================================== \n");

		system("PAUSE");
		system("CLS");

		cout << endl << endl; Player->avatarDialogue("Thanks for playing!\n\n");

		cin.ignore();
		saveGame(Player);
		exit(1);

	}
}
#include "Avatar.h"
#include "Scientist.h"
#include "Items.h"
#include "func.h"
#include "map.h"

// Git repository test

Avatar::Avatar(status map[][30])
{
	setCoords(15, 18);
//	y = 18; 
//	x = 15; 
	map[y][x] = P_LOCATION; //Initialize player position at coords 17, 18
	setGameState(1); //Sets gamestate to 1
	bool local_flag = true;
	simTypeSlow("Preparing to initialize Avatar.AI_...\n\n");

	
	
	cout << "(AI:)"; 
	simTypeFast("You... ARE the agent assigned to this mission, remember? I hope so. The mind link can\n\n"
		 "be difficult to get used to at first, but you should retain most of your memories. If not, you\n\n"
		 "should have them returned to you when the link is terminated.\n\n\n");

	std::cin.ignore();

	cout << "(AI:)"; simTypeFast("But before we proceed, I'm going to need a name!\n\n");
	simTypeFast("Enter name for your Avatar AI: ");
	do
	{
		cin >> avatar_name;
	
		cout << "\n(AI:)"; simTypeFast("You want to name me "); cout << avatar_name; simTypeFast("? \n\n");

		if (isYes() == true)
		{
			cout << endl; avatarDialogue("Alright!\n\n");
			local_flag = false;
		}
		else
		{
			cout << ">> Enter name for your Avatar AI: ";
		}
	} while (local_flag == true);

	avatarDialogue("What is your name?\n\n");
	simTypeFast("Enter your name: ");
	local_flag = true; //reset flag for new menu
	do
	{
		cin >> player_name;
		cout << endl; avatarDialogue("Your name is "); cout << player_name << "?" << endl;

		if (isYes())
		{
			cout << endl; avatarDialogue("Alright!\n\n");
			local_flag = false;
		}
		else
		{
			simTypeFast("Enter your name: ");
		}

	} while (local_flag == true);

	simTypeSlow("Initializing Avatar.AI_");
	simTypeSlow("Introduction_sequence_ completed...");
	std::cin.ignore();
}

Avatar::Avatar(status map[][30], string playername, string avatarname, int gamestate, int itemstate, int init_x, int init_y, int ls, int d1, int d2, int d3, int d4, int d5, int d6, int d7) //When initializing avatar from a savefile
{
	player_name = playername; // initializes player name from save file
	avatar_name = avatarname; //initializes avatar name from save file
	game_state = gamestate; //initializes gamestate from save file
	item_state = itemstate; // initializes item state from savefile
	setCoords(init_x, init_y); // initializes coordinates from save file
	ls_dialogue_state = ls; //initiailzes dialogue states for scientists
	s1_dialogue_state = d1;
	s2_dialogue_state = d2;
	s3_dialogue_state = d2;
	s4_dialogue_state = d4;
	s5_dialogue_state = d5;
	s6_dialogue_state = d6;
	s7_dialogue_state = d7;
	map[init_y][init_x] = P_LOCATION;
}


string Avatar::commandLine(status map[][30])
{
	int i = 0, num_of_moves = 0;
	string current_action, arg_1, arg_2, arg_3;
	bool local_flag = true, is_map = false;
	char c;

	do
	{	
		if (is_map == false) //do not clear sceen if displaying map
		{
			system("CLS");
		}
		else
		{
			is_map = false;
		}
		cout <<"==============================================================\n\n";
		cout << player_name << ":~$ ";	
		
		//Convert string to all lower case to avoid input checkin
		getline(std::cin, current_action);

		cout << endl;//Formatting
		processLine(current_action, arg_1, arg_2, arg_3, 'L'); //processes input into variables, use key letter L to convert to lowercase

		if (arg_1 == "help")
		{
			listCommands();
			cout << ">> Exit Help<<";
			cin.ignore();
		}
		else if (arg_1 == "map")
		{
			system("CLS");
			printMap(map); //prints map, showing current position relative to the world	
			is_map = true; //do not clear map on next iteration of loop
		}
		else if (arg_1 == "move")
		{
			//check to see if arg_3 is digits first
			
			num_of_moves = argToInt(arg_3);

			if (arg_2 == "north")
			{
				moveAvatarNorth(map, num_of_moves);
				system("CLS");
				printMap(map);
			}
			else if (arg_2 == "south")
			{
				moveAvatarSouth(map, num_of_moves);
				system("CLS");
				printMap(map);
			}
			else if (arg_2 == "east")
			{
				moveAvatarEast(map, num_of_moves);
				system("CLS");
				printMap(map);
			}
			else if (arg_2 == "west")
			{
				moveAvatarWest(map, num_of_moves);
				system("CLS");
				printMap(map);
			}
			else
			{
				cout << "(" << avatar_name << ":)" << arg_2; simTypeFast(" is not a recognized argument. Try north, south, east, or west\n"); cout << flush;
				
			}
			is_map = true; //Keeps map on screen, while player moves
			
		}
		else if (arg_1 == "journal")
		{
			printJournal();
			cout << ">> Exit Journal<< ";
			cin.ignore();
		}
		else if (arg_1 == "examine")
		{
			if (arg_2 == "room")
			{
				examineRoom(map);
				cout << ">> Continue <<";
				cin.ignore();
				if (game_state == 3 && (getRoom(map) == 1))
				{
					return current_action; //return string to initialize object
				}
			}
			else if (arg_2 == "scientist")
			{
				return (arg_1 + " " + arg_2);

			}
			else if (arg_2 == "item")
			{
				return (arg_1 + " " + arg_2); //if player wants to examine item, return and carry out code in main
			}
			else
			{
				avatarDialogue("There's lots of things in this lab, "); cout << player_name; simTypeFast(", can you specify a bit?\n");
				simTypeFast("Try examine room, examine scientist, or examine item\n\n"); 
				cout << ">> Continue <<";
				cin.ignore();
			}
		}
		else
		{			
			return current_action;
			local_flag = false;
		}
		
	}while(local_flag == true);
}

void Avatar::listCommands()
{
	cout << "=============================================================\n";
	cout << "List of Commands: \n\n";
	cout << "help - You're here!" << endl;
	cout << "map - Print map of area" << endl;
	cout << "move <direction> <# of steps> - Enter number of spaces and cardinal direction to direct your Avatar to move" << endl;
	cout << "talk to <NPC name> - Enter a conversation with a nearby NPC " << endl;
	cout << "journal - View current objectives" << endl;
	cout << "examine <room/scientist/item> - Displays a summary of target as observed by your Avatar" << endl;
	cout << "quit game - Quits the game" << endl;

	// TODO Inventory
}

void Avatar::moveAvatarNorth(status map[][30], int steps)
{
	string direction = "north";
	map[y][x] = OPEN; //clear current map space

	if (isWall(map, direction, steps, x, y)) //if there is a wall in the way
	{		
		for (int n = 1; n <= steps; n++) //increment through steps to find where the wall is
		{
			if (map[y - n][x] != OPEN) //if location is not open
			{
				map[y - (n - 1)][x] = P_LOCATION; //set new player location to the first not open location + 1
				
				steps = n; //store new steps value for correct outputting
				

				if (map[y - n][x] == SCIENTIST || map[y - n][x] == LEAD_SCIENTIST)
				{
					simTypeSlow("You hit a scientist");
				}
				else
				{
					simTypeSlow("You hit the wall");
				}	
				
				avatarDialogue("Ow!\n\n");
				y = y - (n - 1); //store new y value
				break; //end the for loop, it's no longer needed
			}
		}
	}
	else //if there's no wall in the way, store as usual.
	{
		map[y - steps][x] = P_LOCATION;
		y = y - steps; //(store new y value)
		
	}
}

void Avatar::moveAvatarSouth(status map[][30], int steps)
{
	string direction = "south";
	map[y][x] = OPEN; //clear current map space
	if (isWall(map, direction, steps, x, y)) //if there is a wall in the way
	{		
		for (int n = 1; n <= steps; n++) //increment through steps to find where the wall is
		{
			if (map[y + n][x] != OPEN) //if location is not open
			{
				map[y + (n - 1)][x] = P_LOCATION; //set new player location to the first not open location + 1
				
				steps = n; //store new steps value for correct outputting
				

				if (map[y + n][x] == SCIENTIST || map[y + n][x] == LEAD_SCIENTIST)
				{
					simTypeSlow("You hit a scientist");
				}
				else
				{
					simTypeSlow("You hit the wall");
				}

				avatarDialogue("Ow!\n\n");
				y = y + (n - 1); //store new y value
				break; //end the for loop, it's no longer needed
			}
		}
	}
	else //if there's no wall in the way, store as usual.
	{
		map[y + steps][x] = P_LOCATION;
		y = y + steps; //(store new y value)
		
	}
	
}

void Avatar::moveAvatarEast(status map[][30], int steps)
{
	string direction = "east";
	map[y][x] = OPEN; //clear current map space

	if (isWall(map, direction, steps, x, y)) //if there is a wall in the way
	{		
		for (int n = 1; n <= steps; n++) //increment through steps to find where the wall is
		{
			if (map[y][x + n] != OPEN) //if location is not open
			{
				map[y][x + (n - 1)] = P_LOCATION; //set new player location to the first not open location + 1				

				steps = n; //store new steps value for correct outputting
				

				if (map[y][x + n] == SCIENTIST || map[y][x + n] == LEAD_SCIENTIST)
				{
					simTypeSlow("You hit a scientist");
				}
				else
				{
					simTypeSlow("You hit the wall");
				}

				avatarDialogue("Ow!\n\n");
				x = x + (n - 1); //store new x value
				break; //end the for loop, it's no longer needed
			}
		}
	}
	else //if there's no wall in the way, store as usual.
	{
		map[y][x + steps] = P_LOCATION; //move to new map space (right)
		x = x + steps; //(store new x value)
		
	}	
}

void Avatar::moveAvatarWest(status map[][30], int steps)
{
	string direction = "west";
	map[y][x] = OPEN; //clear current map space

	if (isWall(map, direction, steps, x, y)) //if there is a wall in the way
	{		
		for (int n = 1; n <= steps; n++) //increment through steps to find where the wall is
		{
			if (map[y][x - n] != OPEN) //if location is not open
			{
				map[y][x - (n - 1)] = P_LOCATION; //set new player location to the first not open location - 1
				
				steps = n; //store new steps value for correct outputting
				
				
				if (map[y][x - n] == SCIENTIST || map[y][x - n] == LEAD_SCIENTIST)
				{
					simTypeSlow("You hit a scientist");
				}
				else
				{
					simTypeSlow("You hit the wall");
				}
				
				avatarDialogue("Ow!\n\n");
				
				x = x - (n - 1); //store new y value
				break; //end the for loop, it's no longer needed
			}
		}
	}
	else //if there's no wall in the way, store as usual.
	{
		map[y][x - steps] = P_LOCATION;
		x = x - steps; //(store new x value)
		
	}
	
}


void Avatar::printJournal()
{
	cout << "==============================================================\n\n";
	cout << "                        JOURNAL                               \n\n";
	simTypeFast("Avatar: "); cout << avatar_name; 
	cout << "                ";
	simTypeFast("Player: "); cout << player_name << endl << endl;
	if (game_state == 1)
	{
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist.\n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 2)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help\n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 3)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer\n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 4)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer --COMPLETE--\n\n";
		cout << "4) Talk to other scientists around the lab\n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 5)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer --COMPLETE--\n\n";
		cout << "4) Talk to other scientists around the lab --COMPLETE--\n\n";
		cout << "5) Obtain the research book for Dr. Bennigan\n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 6)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer --COMPLETE--\n\n";
		cout << "4) Talk to other scientists around the lab --COMPLETE--\n\n";
		cout << "5) Obtain the research book for Dr. Bennigan --COMPLETE--\n\n";
		cout << "6) Check in with the Lead Scientist \n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 7)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer --COMPLETE--\n\n";
		cout << "4) Talk to other scientists around the lab --COMPLETE--\n\n";
		cout << "5) Obtain the research book for Dr. Bennigan --COMPLETE--\n\n";
		cout << "6) Check in with the Lead Scientist --COMPLETE--\n\n";
		cout << "7) Acquire the Nuclear Power Core \n\n";
		simTypeFast(".    .    .\n\n");
	}
	else if (game_state == 8)
	{
		cout << endl;
		cout << "                  ==Current Objective==\n\n";
		cout << "1) Talk to Lead Scientist. --COMPLETE--\n\n";
		cout << "2) Find a scientist in need of help --COMPLETE--\n\n";
		cout << "3) Find the Mass Spectrometer --COMPLETE--\n\n";
		cout << "4) Talk to other scientists around the lab --COMPLETE--\n\n";
		cout << "5) Obtain the research book for Dr. Bennigan --COMPLETE--\n\n";
		cout << "6) Check in with the Lead Scientist --COMPLETE--\n\n";
		cout << "7) Acquire the Nuclear Power Core --COMPLETE--\n\n";
		cout << "8) Deliver the power core box to Dr. Klein\n\n";
		simTypeFast(".    .    .\n\n");
	}

	else
	{
		cout << "I have no idea how I got to this point then....\n";
	}
}

/*void Avatar::showInventory()
{
	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i];
	}
}
*/
int Avatar::getRoom(status map[][30])
{
	if ((x > 0 && x < 8) && (y > 4 && y < 11)) // If player's coordinates are within these bounds
	{
		current_room = 1; // Generator Room
		return 1;
	}

	if (((x > 1 && x < 8) && (y > 10 && y < 19)) || ((x > 7 && x < 11) && ( y > 13 && y < 18))) // If player's coordinates are within these bounds
	{
		current_room = 2; // Eco Lab
		return 2;
	}
	
	if ((x > 11  && x < 19) && (y > 5 && y < 20)) // If player's coordinates are within these bounds
	{
		current_room = 3; // Main Room
		return 3;
	}

	if ((x > 19 && x < 24) && (y > 0 && y < 9)) // If player's coordinates are within these bounds
	{
		current_room = 4; // Library
		return 4;
	}

	if ((x > 19 && x < 23) && (y > 9 && y < 15)) // If player's coordinates are within these bounds
	{
		current_room = 5; // Research offices
		return 5;
	}

	if ((x > 23 && x < 26) && (y > 8 && y < 15)) // If player's coordinates are within these bounds
	{
		current_room = 6; // Server Room
		return 6;
	}

	if ((x > 26 && x < 30) && (y > 8 && y < 15)) // If player's coordinates are within these bounds
	{
		current_room = 7; // Nuclear storage room
		return 7;
	}

	if ((x > 18 && x < 30) && (y > 14 && y < 17)) // If player's coordinates are within these bounds
	{
		current_room = 8; //Hallway
		return 8;
	}

	if ((x > 23 && x < 26) && (y > 16 && y < 26)) // If player's coordinates are within these bounds
	{
		current_room = 9; // Office 1
		return 9;
	}

	if ((x > 26 && x < 30) && (y > 17 && y < 20) || (x > 28 && x < 30) && (y > 18 && y < 20)) // If player's coordinates are within these bounds
	{
		current_room = 10; //Lead scientist's office
		return 10;
	}

	return 11;
}

void Avatar::examineRoom(status map[][30])
{
	int lab_room;
	lab_room = getRoom(map);

	if (lab_room == 1)
	{		
		static bool firstexamine = true;

		if(firstexamine == true)
		{
			cout << " "; avatarDialogue(" This seems to be the generator room for the lab. There's a lot of noise coming from the various\n\n");
			simTypeFast("    machines that line the room. The room is well lit with a shiny marble floor, marred with the occasional\n\n");
			simTypeFast("    rubber smudge from the carts and weight bearing machines that the scientists use to move much of the heavy\n\n");
			simTypeFast("    equipment across the room. Several different types of electrical cords and cables are attached to each generator,\n\n");
			simTypeFast("    uniformly tethered to the wall adjacent to it. The cables then travel up the wall, across the ceiling and into a \n\n");
			simTypeFast("    central port, suppling power to the rest of the facility. There is a scientist in the South-East corner of the room looking \n\n");
			simTypeFast("    over something on a clipboard. He looks worried.\n\n");
			firstexamine = false; //set first examine to false so to not force user to wait for long dramatic typing
		}
		else
		{
			cout << " (" << avatar_name << ":) This seems to be the generator room for the lab. There's a lot of noise coming from the various\n\n"
				<< "    machines that line the room. The room is well lit with a shiny marble floor, marred with the occasional\n\n"
				<< "    rubber smudge from the carts and weight bearing machines that the scientists use to move much of the heavy\n\n"
				<< "    equipment across the room.Several different types of electrical cords and cables are attached to each generator,\n\n"
				<< "    uniformly tethered to the wall adjacent to it.The cables then travel up thewall, across the ceiling and into a \n\n"
				<< "    central port, supplying power to the rest of the facility. There is a scientist in the South-East corner of the room looking \n\n"
				<< "    over something on a clipboard. He looks worried.\n\n";
		}

		if (game_state == 3) //if in gamestate three, will display this text while current objective is to search for mass spectrometer
		{
			cout << endl << " "; avatarDialogue(" After re-examining the room based on new search parameters, I now believe it is relevant to report that there is a desk in\n\n");
			simTypeFast("    the North West corner of the room cluttered with three monitors and an assortment of random objects. However, a scan of the area\n\n");
			simTypeFast("    indicates a high occurrence of objects with physical attributes similar to the Mass Spectrometer we're looking for.\n\n\n");
		}
	}
	else if (lab_room == 2)
	{
		static bool firstexamine = true;

		if (firstexamine == true)
		{
			cout << " "; avatarDialogue(" My sensors are indicating increased humidity levels, as well as a highly earthy smell. This is the laboratory's Eco Lab.\n\n");
			simTypeFast("    Standard laboratory tables are arranged in rows across the room, close enough to one another to allow one or two people to move\n\n");
			simTypeFast("    between them at a time. Plant samples sit illuminated inside glass specimen cases which simulate the perfect climate for\n\n");
			simTypeFast("    each respective species. On the west side of the room, there is a scientist taking samples from one of the specimen cases along the wall.\n\n\n");
			firstexamine = false;
		}
		else
		{
			cout << " (" << avatar_name << ":) My sensors are indicating increased humidity levels, as well as a highly earthy smell. This is the laboratory's Eco Lab.\n\n"
				<< "    Standard laboratory tables are arranged in rows across the room, close enough to one another to allow one or two people to move\n\n"
				<< "    between them at a time. Plant samples sit illuminated inside glass specimen cases which simulate the perfect climate for\n\n"
				<< "    each respective species. On the west side of the room, there is a scientist taking samples from one of the specimen cases along the wall.\n\n\n";
		}
	}
	else if (lab_room == 3)
	{
		static bool firstexamine = true;

		if (firstexamine == true)
		{
			cout << " "; avatarDialogue(" I'm standing in the main room of the Top Secret \"Chrono Research\" Sector of the Lynard B. Weiss NAG(New American Government) Research Facility.\n\n\n");
			simTypeFast("    On the north end of the room, two scientists stand on both sides of a large metal device, adjusting measurements on their tablets as they\n\n");
			simTypeFast("    obtain readings from it. It's the time machine! So we're going in that thing, huh? Well I am, anyway... The center of the time machine contains\n\n");
			simTypeFast("    a large bowl shaped divot about 1.5 meters in diameter and about two feet deep. Desks line both the East and West walls of the room, each with\n\n");
			simTypeFast("    a collection of monitors flashing lines of code across their screens. The lead scientist is standing near the southeast corner of the room,\n\n");
			simTypeFast("    leaning over a table displaying what I infer to be the blueprints to the time device. A hallway leads out of the west side of the room towards\n\n");
			simTypeFast("    some of the smaller research rooms of this sector.\n\n\n");
			firstexamine = false;
		}
		else
		{
			cout << " (" << avatar_name << ":) I'm standing in the main room of the Top Secret \"Chrono Research\" Sector of the Lynard B. Weiss NAG(New American Government) Research Facility.\n\n\n"
				<< "    On the north end of the room, two scientists stand on both sides of a large metal device, adjusting measurements on their tablets as they\n\n"
				<< "    obtain readings from it. Its the time machine! So were going in that thing, huh? Well I am, anyway... The center of the time machine contains\n\n"
				<< "    a large bowl shaped divot about 1.5 meters in diameter and about two feet deep. Desks line both the East and West walls of the room, each with\n\n"
				<< "    a collection of monitors flashing lines of code across their screens. The lead scientist is standing near the southeast corner of the room,\n\n"
				<< "    leaning over a table displaying what I infer to be the blueprints to the time device. A hallway leads out of the west side of the room towards\n\n"
				<< "    some of the smaller research rooms of this sector.\n\n\n";
		}
	}
	else if (lab_room == 4)
	{
		//examine info for room 4 goes here
		cout << " "; avatarDialogue(" A musty smell hangs in the air, the source of which appears to be a great collection of books, stacked on wooden shelves that adorn the walls of the room.\n\n");
		simTypeFast("    In the center of the room, another large collection of bookshelves stand, their great stature imposing upon the comfortable looking tables around the room, places where\n\n");
		simTypeFast("    scientists in the sector study. Heavy glass doors containing a variety of senors guard the entrance to the lab, denying entry to those unauthorized to access it. A\n\n");
		simTypeFast("    scientist sits behind a desk on the east side of the room, nearly hidden from view by three large monitors that display various technical readouts. The scientist is\n\n");
		simTypeFast("    reading a book.\n\n\n");
		
	}
	else if (lab_room == 5)
	{
		cout << " "; avatarDialogue(" A security clearance room containing several scientific research workspaces, along with those of several assistants to Dr. Bentz. They're not here right now, though.\n\n");
		simTypeFast("    I wonder where they could be.\n\n    The room also contains an array of automatic security systems to prevent unauthorized access to the library, where the collection of all research on\n\n");
		simTypeFast("    the top secret Time Device Project is stored. There doesn't seem to be anything else of particular interest in here.\n\n\n");
		
		//examine info for room 5 goes here
	}
	else if (lab_room == 6)
	{
		cout << " "; avatarDialogue(" This is the server room for the lab. Contains the workspaces of Dr. Bantz and Dr. Morris.\n\n");
		simTypeFast("    On the north end of the room are two pods laying vertically, side by side wih one another. One pod contains\n\n"); 
		simTypeFast("    a motionless human. It's you! The other pod door stands open. A scientist sits behind his desk, monitoring an assortment\n\n");
		simTypeFast("    of brain waves and life sign readouts. The dull hum of servers persists in the background. \n\n");
		//examine info for room 6 goes here
	}
	else if (lab_room == 7)
	{

		cout << " "; avatarDialogue(" My geiger counter is off the charts! This is the atomic storage room. Most of the more complex energy sources\n\n");
		simTypeFast("    are obtained from this room by scientists in full hazmat protection gear. Fortunately as an Avatar, this hazard does not affect me.\n\n");
		simTypeFast("    The walls are solid concrete, and a set of stairs descends to an underground room where a majority of the radioactive materials are stored.\n\n");
		simTypeFast("    Downstairs, many metals and substances are stored and organized by isotope, each with their own unique containment procedures and \n\n");
		simTypeFast("    warning labels. It's eerily quiet down here. Material classifications and handling procedures are labled on nearly every available wall space.\n\n\n");
		//examine info for room 7 goes here
	}
	else if (lab_room == 8)//examine info for room 8 goes here
	{
		cout << " "; avatarDialogue(" I'm in the hallway that connects the smaller lab rooms together. A scientist is leaning against the wall holding a cup of coffee \n\n"); 
		simTypeFast("    and reading his tablet.\n\n\n");
		
	}
	else if (lab_room == 9)//examine info for room 9 goes here
	{
		cout << " "; avatarDialogue(" This is a basic office space. There is a nameplate on the desk that reads \" Rachel Klein, Ph.D\". The office is neatly organized.\n\n");
		simTypeFast("    I probably shouldn't be messing with anything in here.\n\n\n");
		
	}
	else if (lab_room == 10)//examine info for room 10 goes here
	{
		cout << " "; avatarDialogue(" This seems to be the office of the Lead Scientist. One of the larger offices in the sector. The walls are addorned with awards and certifications. A set of blueprints sits on the lone desk\n\n");
		simTypeFast("    on the south side of the room. Also on the desk are several photographs. One in particular appears to be a photo of the Weiss family, taken many years ago.\n\n\n");
		simTypeFast("    A portrait of Lynard B. Weiss hangs on the wall behind the desk, casting a knowing gaze across the office.\n\n\n");
		
	}
	else 
	{
		avatarDialogue("I'm currently between two rooms... try moving a bit farther into one of the rooms so I can get a better look at it.\n\n");
	}


}



//Avatar Dialogue function. Formats avatar text
void Avatar::avatarDialogue(const char * p)
{
	if (NULL == p)
	{
		return;
	}
	cout << "(" << avatar_name << ":)";
	while (*p)
	{

		printf("%c\xDB", *p++);
		::Sleep(15);
		printf("\b \b");
		::Sleep(15);
	}

}


//Accessor functions
status Avatar::getAvatarPosition(status map[][30])
{
	return map[x][y];
}

string Avatar::getPName()
{
	return player_name;
}
string Avatar::getAvatarName()
{
	return avatar_name;
}

int Avatar::getGameState()
{
	return game_state;
}

int Avatar::getItemState()
{
	return item_state;
}



//Mutators for Avatar Class

void Avatar::setCoords(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}

void Avatar::setGameState(int new_gamestate)
{
	game_state = new_gamestate;
}

void Avatar::pickUpItem(int how_many)
{
	item_state = item_state + how_many;
}

void Avatar::setItemState(int new_state)
{
	item_state = new_state;

}
void Avatar::setLS_dialogue_state(int new_state)
{
	ls_dialogue_state = new_state;
}
	
void Avatar::setS1_dialogue_state(int new_state)
{ 
	s1_dialogue_state = new_state; 
}
void Avatar::setS2_dialogue_state(int new_state)
{ 
	s2_dialogue_state = new_state;
}
void Avatar::setS3_dialogue_state(int new_state)
{ 
	s3_dialogue_state = new_state; 
}
void Avatar::setS4_dialogue_state(int new_state)
{ 
	s4_dialogue_state = new_state; 
}
void Avatar::setS5_dialogue_state(int new_state)
{ 
	s5_dialogue_state = new_state; 
}
void Avatar::setS6_dialogue_state(int new_state)
{ 
	s6_dialogue_state = new_state; 
}
void Avatar::setS7_dialogue_state(int new_state)
{ 
	s7_dialogue_state = new_state; 
}
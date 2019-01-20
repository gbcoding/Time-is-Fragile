#include "func.h"
#include "map.h"

bool isYes()
{
	char y_n;
	bool local_flag = true;
	do
	{
		cout << "[Y/N]: ";	
		cin >> y_n;
		if (y_n == 'Y' || y_n == 'y')
		{
			cin.ignore();
			return true;
		}
		else if (y_n == 'N' || y_n == 'n')
		{
			cin.ignore();
			return false;
		}
		else
		{
			cout << "This is a yes or no question... Y or N. Case doesn't even matter!\n";
		}
	} while (local_flag == true);

}
//Function that checks player's location with locations of other map objects and returns their value. Returns 9 for lead scientist and 10 for an item

int nearPlayer(Avatar* Player, Lead_Scientist LS, Scientist S1, Scientist S2, Scientist S3, Scientist S4, Scientist S5, Scientist S6, Scientist S7, status map[][30])
{
	int x = Player->getX();
	int y = Player->getY();

	if (map[y + 1][x] == SCIENTIST || map[y - 1][x] == SCIENTIST || map[y][x - 1] == SCIENTIST || map[y][x + 1] == SCIENTIST)
	{
		if ((y + 1 == S1.getY() && x == S1.getX()) || (y - 1 == S1.getY() && x == S1.getX()) || (x - 1 == S1.getX() && y == S1.getY()) || (x + 1 == S1.getX() && y == S1.getY()))
		{
			return 1;
		}
		else if ((y + 1 == S2.getY() && x == S2.getX()) || (y - 1 == S2.getY() && x == S2.getX()) || (x - 1 == S2.getX() && y == S2.getY()) || (x + 1 == S2.getX() && y == S2.getY()))
		{
			return 2;
		}
		else if ((y + 1 == S3.getY() && x == S3.getX()) || (y - 1 == S3.getY() && x == S3.getX()) || (x - 1 == S3.getX() && y == S3.getY()) || (x + 1 == S3.getX() && y == S3.getY()))
		{
			return 3;
		}
		else if ((y + 1 == S4.getY() && x == S4.getX()) || (y - 1 == S4.getY() && x == S4.getX()) || (x - 1 == S4.getX() && y == S4.getY()) || (x + 1 == S4.getX() && y == S4.getY()))
		{
			return 4;
		}
		else if ((y + 1 == S5.getY() && x == S5.getX()) || (y - 1 == S5.getY() && x == S5.getX()) || (x - 1 == S5.getX() && y == S5.getY()) || (x + 1 == S5.getX() && y == S5.getY()))
		{
			return 5;
		}
		else if ((y + 1 == S6.getY() && x == S6.getX()) || (y - 1 == S6.getY() && x == S6.getX()) || (x - 1 == S6.getX() && y == S6.getY()) || (x + 1 == S6.getX() && y == S6.getY()))
		{
			return 6;
		}
		else if ((y + 1 == S7.getY() && x == S7.getX()) || (y - 1 == S7.getY() && x == S7.getX()) || (x - 1 == S7.getX() && y == S7.getY()) || (x + 1 == S7.getX() && y == S7.getY()))
		{
			return 7;
		}
		else
		{
			//this shouldn't be used, will rewrite later.
		}
		
	}
	else if (map[y + 1][x] == LEAD_SCIENTIST || map[y - 1][x] == LEAD_SCIENTIST || map[y][x - 1] == LEAD_SCIENTIST || map[y][x + 1] == LEAD_SCIENTIST)
	{
		return 9;
	}
	else if (map[y + 1][x] == ITEM || map[y - 1][x] == ITEM || map[y][x - 1] == ITEM || map[y][x + 1] == ITEM)
	{
		return 10;
	}
	else
	{
		return 0;
	}
}



/* =============================================================================================================
Note about syncGameStates function:

Scientists will keep track of their own dialogue states. It is important to pull any dialogue changes from
a scientist at the end of interaction so to be able to update the journal and examine functions as player
progresses through the game. Scientists will change dialogue states of other scientists during conversation
as new information is revealed to the player.
================================================================================================================*/
void syncGameStates(Scientist* scientist_object, Avatar* Avatar_object)
{
	scientist_object->setGameState(Avatar_object->getGameState());

	Avatar_object->setLS_dialogue_state(scientist_object->getLS_DialogueState());
	Avatar_object->setS1_dialogue_state(scientist_object->getS1_DialogueState());
	Avatar_object->setS2_dialogue_state(scientist_object->getS2_DialogueState());
	Avatar_object->setS3_dialogue_state(scientist_object->getS3_DialogueState());
	Avatar_object->setS4_dialogue_state(scientist_object->getS4_DialogueState());
	Avatar_object->setS5_dialogue_state(scientist_object->getS5_DialogueState());
	Avatar_object->setS6_dialogue_state(scientist_object->getS6_DialogueState());
	Avatar_object->setS7_dialogue_state(scientist_object->getS7_DialogueState());

}

/* =============================================================================================================
Note about itemInteract function:

Displays message upon successfully finding item

Asks player what they want to do with it:

-pick up
 - if amount > 1, how many?

================================================================================================================*/

void itemInteract(Item* item_object, Avatar* Avatar_object)
{			
		Avatar_object->avatarDialogue("I found a "); cout << item_object->getName() << "!\n\n";

		simTypeFast("Shall I pick it up? ");

		if (isYes() && item_object->getAmount() == 1) //for one off items
		{
			Avatar_object->pickUpItem(1); //Also sets item state to 1
			cout << endl; Avatar_object->avatarDialogue("I've picked up the "); cout << item_object->getName(); cout << endl << endl;
		}
		else if(isYes()) //for items with varied amounts
		{
			int num_items;
			Avatar_object->avatarDialogue("How many would you like to pick up? ");
			cin >> num_items; cout << endl;
			Avatar_object->pickUpItem(num_items);
			item_object->setAmount(item_object->getAmount() - num_items); //subtracts amount of items taken from item object on map
		}
		else
		{
			Avatar_object->avatarDialogue("Okay, I'll leave it there for now.\n\n");
		}

}



void simTypeSuperFast(const char * p) //simulates superfasttyping when outputting text
{
	if (NULL == p)
	{
		return;
	}
	while (*p)
	{

		printf("%c\xDB", *p++);
		::Sleep(4);
		printf("\b \b");
		::Sleep(4);
	}
}
void simTypeFast(const char * p) //simulates Fast typing when outputting text
{
	if (NULL == p)
	{
		return;
	}
	while (*p)
	{

		printf("%c\xDB", *p++);
		::Sleep(15);
		printf("\b \b");
		::Sleep(15);
	}
}
void simTypeSlow(const char * p) //simulates slowtyping when outputting text
{
	if (NULL == p)
	{
		return;
	}
	printf(">>");
	while (*p)
	{
		
		printf("%c\xDB", *p++);
		::Sleep(40);
		printf("\b \b");
		::Sleep(40);
	}
	printf("\n\n");
}

bool isWall(status map[][30], string direction, int steps, int x, int y)
{
	if (direction == "north") //for north (subtracting from row index)
	{
		for (int n = 1; n <= steps; n++) //increment through steps to check for not open spaces, if one is found, end function
		{
			if (map[y - n][x] != OPEN) //If one of the positions is not open, return that there is a wall (isWall = true)
			{	
				return true;
			}
		}
		//if all positions are open, return that there is no wall (isWall = false)
		return false;
	}
	else if (direction == "south") //for south (adding to row index)
	{
		for (int n = 1; n <= steps; n++)//same as above but for south
		{
			if (map[y + n][x] != OPEN) //If one of the positions is not open, return that there is a wall (isWall = true)
			{
				return true;
			}
		}
		//if all positions are open, return that there is no wall (isWall = false)
		return false;
	}
	else if (direction == "east") //for east (adding to column index)
	{
		for (int n = 1; n <= steps; n++) //same as above but for east
		{
			if (map[y][x + n] != OPEN) //If one of the positions is not open, return that there is a wall (isWall = true)
			{
				return true;
			}
		}
		//if all positions are open, return that there is no wall (isWall = false)
		return false;

	}
	else //if(direction == "west") for west(subtracting from column index
	{
		for (int n = 1; n <= steps; n++) //same as above but for west
		{
			if (map[y][x - n] != OPEN) //If one of the positions is not open, return that there is a wall (isWall = true)
			{
				return true;
			}
		}
		//if all positions are open, return that there is no wall (isWall = false)
		return false;
	}
	

}

void processLine(string current_action, string& str_1, string& str_2, string& str_3, char tolowercase)
{
	char c;
	int temp_int;
	int command_length;
	int i = 0;//initialize counter to 0
	int z = 0; //starting point for .substr
	int m = 1; //controls number of arguments taken

	if (tolowercase == 'L')
	{
		while (current_action[i]) //convert all commandline arguments to lowercase
		{
			c = current_action[i];
			if (isupper(c))
			{
				c = tolower(c);
				current_action[i] = c;
			}
			i++;
		}
	}

	command_length = current_action.length();
	i = 0; //reset counter to 0;
	
	//step through array, storing characters into str_1 until a ' ' or newline char is found
	while (current_action[i] && i < command_length)
	{

		//skip any leading whitespace or whitespace leading up to a word
		while (current_action[i] && isspace(static_cast<unsigned char>(current_action[i])) && i < command_length)//while the current value of current_action IS a space and exists
		{
			i++;
		}
		//begin storing actual letters
		if (current_action[i] && i < command_length)
		{
			if (m == 1) //upon first run, store in str_1
			{
				int n = 0;
				z = i;
				while (current_action[i] && !isspace(static_cast<unsigned char>(current_action[i])) && i < command_length) //while the current value of current_action IS NOT a space and exists
				{
					i++;
					n++;
				}
				str_1 = current_action.substr(z, n);
				
				m++;
			}
			else if (m == 2)//upon second run, store in str_2
			{
				int n = 0;
				z = i; //starting spot for next substr
				while (current_action[i] && !isspace(static_cast<unsigned char>(current_action[i])) && i < command_length) //while the current value of current_action IS NOT a space and exists
				{
					i++;
					n++;
				}
				str_2 = current_action.substr(z, n);
				m++;
			}
			else //upon third run, store in int_1;
			{
				int n = 0;
				z = i; //starting spot for next substr
				while (current_action[i] && !isspace(static_cast<unsigned char>(current_action[i])) && i < command_length) //while the current value of current_action IS NOT a space and exists
				{
					i++;
					n++;
				}
				str_3 = current_action.substr(z, n);	
			}
		}
	}
}

int argToInt(string argument)
{
	char temp[3];
	strcpy(temp, argument.c_str());
	return atoi(temp);
}

void examineScientist(int scientist_num)
{
	if (scientist_num == 1)
	{
		simTypeFast(" Marcus Grey - Scientist in charge of power and energy management for the sector. Somewhat scatterbrained\n\n");
		simTypeFast("   but an otherwise hard worker and a great friend. Dr. Grey also does research on multiple types of\n\n");
		simTypeFast("   new energies and inorganic substances.\n\n\n");
	}
	else if (scientist_num == 2)
	{
		simTypeFast(" Charles Bennigan - Charles acquired his dual research degrees in both micro and macrobiology from the NA\n\n");
		simTypeFast(" academy of Life Sciences. Both of his parents perished in the period after the Great Storm. Although Charles\n\n");
		simTypeFast(" was just a small child when it happened, the experience has motivated him. He is resolute in his desire to\n\n");
		simTypeFast(" fix this broken world for the sake of those who also lost everything. An ambitious man, Charles has a vested\n\n");
		simTypeFast(" interest in the Time Device project, seeing it as a way to reunite with both his parents and the many friends\n\n");
		simTypeFast(" he lost during the storm.\n\n\n");
	}
	else if (scientist_num == 3)
	{
		simTypeFast(" Algernop Kaiser - Hailing from the former state of Germany, Dr. Kaiser works as the laboratory's Earth Sciences director.\n\n");
		simTypeFast(" At 2:00 PM on January First, 2070, the Storm hit Germany, the most technologically advanced country in the world.\n\n");
		simTypeFast(" Kaiser barely escaped with his life when, during his afternoon commute to work, the motor of his vehicle was\n\n");
		simTypeFast(" hit by the first and most powerful wave of the Storm, setting it ablaze and sending the vehicle careening\n\n");
		simTypeFast(" off of the mountain road that it was so precariously navigating. Perhaps it was extraordinary luck, or perhaps\n\n"); 
		simTypeFast(" it was destined for Kaiser to escape with his life that day. Upon regaining consciousness, both stranded with\n\n"); 
		simTypeFast(" minor injuries and without electrical devices to call for help or navigate home, Kaiser called upon his survivalist\n\n"); 
		simTypeFast(" instincts and knowledge of earth science to survive in the Schwarzwald for the next 6 months.\n\n\n");
	}
	else if (scientist_num == 4)
	{
		simTypeFast(" Rachel Klein - Assistant Lead of the Time Device Project. Rachel is a brilliant physicist, and her intense\n\n");
		simTypeFast(" personality serves to compliment her intelligence. Although some of the others may not want to admit it, she\n\n");
		simTypeFast(" is the glue that keeps this project together. Being one of the older members of the project, Rachel has witnessed\n\n");
		simTypeFast(" horrfying things in her lifetime, being one of the few surviving members of the Storm Recovery Project. While\n\n");
		simTypeFast(" while working on the recovery project, she met and eventually formed a close friendship with Lynard B. Weiss,\n\n");
		simTypeFast(" which lasted until his death nearly five years ago.\n\n\n");
	}
	else if(scientist_num == 5)
	{
		simTypeFast(" Bernard Sanders - Has fought very hard for his right to break, as well as those for the entire working sector.\n\n\n");
	}
	else if (scientist_num == 6)
	{
		simTypeFast(" Ezekiel Morris - AI developer and representitve from the Avatar Project, Ezekiel is the sector's Robotics expert.\n\n");
		simTypeFast(" He helped develop me and prepare you for the mission, so you -should- know him, but for the sake of brevity, I'll\n\n ");
		simTypeFast(" go over it again so you're not asking questions later. Ezekiel is of a kinder diposition than most other scientists\n\n");
		simTypeFast(" here. Perhaps because of his extensive background in coding, Ezekiel is a highly logical man and his\n\n");
		simTypeFast(" ability to directly forsee the consequences of events around him has saved him in many tough situations\n\n\n");
	}
	else if (scientist_num == 7)
	{
		simTypeFast(" Jeremy Bantz - Jeremy is the systems network engineer for the sector, and has claimed the nickname \"The Mastermind\" from\n\n");
		simTypeFast(" his peers. In charge of security for the top Secret sector as well as the keeping of records, information, and library keeping.\n\n");
		simTypeFast(" Jeremy is one of the last remaining true \"bookworms\", possessing a vast collection of personal paper novels, as well as\n\n");
		simTypeFast(" physical copies of manuals for various subjects. As the archivist for the Time Project, Jeremy is rightfully concerned about \n\n");
		simTypeFast(" the security of all information stored in this lab.\n\n\n");
	}
	else //Lead scientist
	{
		simTypeFast(" Henry Weiss - Lead Scientist of the Time Device Project and son of laboratory founder Lynard B. Weiss. Lynard was the founding Secretary of General Science\n\n");
		simTypeFast(" for the New American Government. The Time Device Project could be considered his brainchild. One of the brightest\n\n");
		simTypeFast(" of his time, Lynard's personal research into quantum physics laid the foundations for what would become humanity's\n\n");
		simTypeFast(" best chance at recovery. His son, Henry intends to complete his father's work after the tragic accident that robbed\n\n");
		simTypeFast(" the world of its greatest Scientist.\n\n\n");
	}

//	cout << ">> Continue <<";
//	cin.ignore();

}
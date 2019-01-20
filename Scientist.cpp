#include "Scientist.h"
#include "func.h"
//Every time a scientist object is initialized, it gives it a different predetermined map position
Scientist::Scientist(string init_name, int init_x, int init_y, status map[][30])
{
	setCoords(init_x, init_y);
	map[init_y][init_x] = SCIENTIST; //Initializes a Scientist object at location (x, y)
	name = init_name;
}

void Scientist::setCoords(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}


bool Scientist::isAdjacent(status map[][30])
{
	if (map[y + 1][x] == P_LOCATION || map[y - 1][x] == P_LOCATION || map[y][x - 1] == P_LOCATION || map[y][x + 1] == P_LOCATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Lead_Scientist::Lead_Scientist(string init_name, int init_x, int init_y, status map[][30])
{
	x = init_x;
	y = init_y;
 	map[y][x] = LEAD_SCIENTIST; // Initializes a Lead Scientist object at location (x, y)
	name = init_name;
}

//======
//LEAD SCIENTIST DIALOGUE BLOCK
//======
void Lead_Scientist::leadScientistDialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	if (game_state == 1)
	{
		cout << "++Lead Scientist++ "; simTypeFast("Good to see you, "); cout << the_player->getPName(); simTypeFast(". I'm sorry that it was on such late notice, but we just solved it!\n\n");

		simTypeFast("Or at least we think we did. Anyway, if our calculations are correct, we just need a few items to complete the test.\n\n");

		simTypeFast("Go talk to the other scientists to see what they need so we can get this thing up and running.\n\n\n");
	}
	else if (game_state == 2)
	{
		if (ls_dialogue_state == 1)
		{
			cout << "++Lead Scientist++ "; simTypeFast("How are those tasks coming? We're on a bit of a schedule here, if you haven't noticed.\n\n");
			ls_dialogue_state++;
		}
		else if (ls_dialogue_state == 2)
		{
			cout << "++Lead Scientist++ "; simTypeFast("Do you need something? Go talk to some of the other scientists and help them with their work.\n\n");
			ls_dialogue_state--;
		}
	}
	else if (game_state > 2 && game_state < 6)
	{
		the_player->avatarDialogue(" The Lead Scientist is studying intently on the blueprints. I think we probably have other things we should be doing right now too.\n\n");
	}
	else if (game_state == 6)
	{
		cout << "++Lead Scientist++ "; simTypeFast("Thank you for helping out around the lab. Dr. Klein has just informed me that she has recieved the results of the final tests\n\n");
		simTypeFast("and we will be clear to begin the mission shortly. However, I do have one more favor to ask of you. Would you please go into the Nuclear\n\n");
		simTypeFast("storage facility and retrieve the Nuclear Core? One of the conveniences of having an Avatar on hand is that I don't have to\n\n");
		simTypeFast("expose any of my scientists to harmful radiation. However, it's perfectly safe for you, "); cout << the_player->getAvatarName() << ".\n\n";
		the_player->avatarDialogue("Understood.\n\n");
		cout << "++Lead Scientist++ "; simTypeFast("Please bring the power core to me, then we will begin.\n\n");
	}
	else if (game_state == 7)
	{
		if (the_player->getItemState() == 0)
		{

			cout << "++Lead Scientist++ "; simTypeFast("While you're out collecting the core, please talk to Dr. Klein for your mission briefing. \n\n");

		}
		else
		{
			cout << "++Lead Scientist++ "; simTypeFast("Ah, there it is. What a beauty of atomic engineering. \n\n");
			simTypeFast("*The Lead Scientist produces a small metal box, about 30 centimeters long and 30 centimeters wide and motions us place the core into it*\n\n");
			the_player->avatarDialogue("I've placed the Nuclear Core into the core container.\n\n");
			cout << "++Lead Scientist++ "; simTypeFast("Please take this to Dr. Klein. She'll insert it into the device.\n\n");
			the_player->setItemState(0);
			ls_dialogue_state = 3;
		}
	}
	else if (game_state == 9)
	{
		cout << "++Lead Scientist++ "; simTypeFast("I have no further tasks for you. Please take the power core to Dr. Klein. \n\n");
	}
}



//======
//SCIENTIST 1 DIALOGUE BLOCK
//======
void Scientist::scientist1Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	string scientist_name = "Scientist 1";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}


	if (game_state == 1)
	{
		the_player->avatarDialogue(" The scientist seems a bit busy right now. You know what they say, never interrupt someone with a clipboard.\n\n");
	}
	else if (game_state == 2)//If first time talking to scientist, greeting dialogue
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Oh god... where is it...\n\n Oh. I'm sorry, I didn't see you there.\n\n\n");
		cout << "+" << scientist_name << "+ "; simTypeFast("I'm currently behind schedule and... well, this is embarrassing to admit,\n\n");
		simTypeFast(" but it seems I've misplaced an item invaluable to the startup of the time device. Would you mind\n\n");
		simTypeFast(" looking around for it? The item is a Mass Spectrometer. It'll be about a foot in length and width.\n\n\n");
		simTypeFast("Please bring it back to me here when you find it. Now if you'll excuse me, I need to finish preparing these samples.\n\n");
		 // move to next dialogue choice to progress objective	
	}
	else if(game_state == 3)
	{
		if (the_player->getItemState() == 0) //If player does not have item
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Have you found that mass spectrometer yet?\n\n");
		}
		else if (the_player->getItemState() == 1) //If player does have item
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Terriffic! Thank you so much for your help. I'm sure there are other scientists that\n\n");
			simTypeFast("may require your help as well.\n\n");
			the_player->setItemState(0); //Removes item from player. This code will be replaced once inventory is written.

			s1_dialogue_state = 3;//progress objective
		}		
	}
	else
	{

			cout << "+" << scientist_name << "+ "; simTypeFast("Thank you again for you help finding my tools... A bit embarassing.\n\n>>The scientist laughs\n\n");
			cout << "+" << scientist_name << "+ "; simTypeFast("Well, I need to take readings on some mass bearing energy samples we've acquired during testing.\n\n");
			simTypeFast(" It's a quirky thing, that Device. \n\n Ah.\n\n That's probably not what you wanted to hear right now, is it? The thing is,\n\n");
			simTypeFast(" we've only been able to sustain it for a few seconds. You'll need to get in and out quick. We're calculating to the exact\n\n");
			simTypeFast(" millisecond, and we don't know how long we can hold the time rift open for sure. That's the biggest reason why we need\n\n");
			simTypeFast(" help from the avatar program for this mission. At least you will safe while your avatar goes through the rift. They're expendible.  \n\n");

			the_player->avatarDialogue("Hey! I'm right here you know >.>\n\n");
	}
}

//======
//SCIENTIST 2 DIALOGUE BLOCK
//======
void Scientist::scientist2Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	string scientist_name = "Scientist 2";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}

	if (game_state == 1)
	{
		//If talking to scientist before first objective is completed
		the_player->avatarDialogue(" He's preoccupied with his plants... Maybe we'd best come back later. \n\n");
	}
	else if (game_state == 2)
	{
		//If first time talking to scientist, greeting dialogue
		cout << "+" << scientist_name << "+ "; simTypeFast("Hmmm... Traichondrias, Festius Roots, and... this algae. Gotta be honest with you, not sure where they\n\n ");
		simTypeFast(" got this stuff. It has some very interesting properties though. I'd like to analyze it further. Have you\n\n");
		simTypeFast(" talked to the scientist in the generator room? I heard he was looking for some analysis tools. I may need to ask your help with some\n\n");
		simTypeFast(" work after that.\n\n");
		s2_dialogue_state = 2; //If player talks to scientist 2 during gamestate 2, they will not recieve this intro in gamestate 3
		
	}
	else if (game_state == 3)
	{
		if (s2_dialogue_state == 1) //If player did not talk to  scientist 2 during gamestate 2, run greeting dialogue
		{		
			cout << "+" << scientist_name << "+ "; simTypeFast("Hmmm... Traichondrias, Festius Roots, and... this algae. Gotta be honest with you, not sure where they\n\n ");
			simTypeFast(" got this stuff. It has some very interesting properties though. I'd like to analyze it further. Have you\n\n");
			simTypeFast(" talked Marcus in the generator room? I heard he was looking for some analysis tools. I may need to ask your help with some\n\n");
			simTypeFast(" work after that.\n\n");
			s2_dialogue_state = 2;//then increase dialogue state to 2 to progress story
		}
		else
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("What? He lost the mass spectrometer? Ugh. This is why nothing ever gets done. \n\n ");
			cin.ignore();
			the_player->avatarDialogue("Do you have any ideas about where we could find it?\n\n");
			cin.ignore();
			cout << "+" << scientist_name << "+ "; simTypeFast(" That fool couldn't find his pen if it was in his shirt pocket. My guess would be it's\n\n");
			simTypeFast("not far away.\n\n");
		}
	}
	else if (game_state == 4)
	{
		the_player->avatarDialogue("*The scientist appears to be fighting a rather vicious plant sample*\n\n");
		cout << "+" << scientist_name << "+ "; simTypeFast("\"It bit me! What the hell??\" \n\n\n ");
		simTypeFast("\"I don't get paid enough for this... Er, glad you're back, "); cout << the_player->getPName(); simTypeFast(". Mind helping\n\n");
		simTypeFast(" me out with some research? As you can see, I've got my hands full here. Turns out this strain of Traichondia does NOT like being poked with pointy objects.\n\n");
		simTypeFast(" I've been talking to Jeremy, the lab librarian about some reference books I need for my research. If you could travel to the lab library and and retrieve\"\n\n");
		simTypeFast(" my reference books, I would be incredibly grateful.\"\n\n");
	}
	else if (game_state == 5)
	{
		if (the_player->getItemState() == 0) //If player does not have item
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Still waiting on that book. You need to go to the library to retrieve it.\n\nIt's the northmost room in the sector.\n\n");			
		}
	
		if (the_player->getItemState() == 1) //If player does have item
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Ah there it is. Now I can get on with my research. Thanks! \n\n");
			simTypeFast("*He swiftly opens the book and picks up his tools to begin engaging with the plant sample once more*\n\n");
			s2_dialogue_state = 3; //set dialogue state to 3 to move on to next objective
			the_player->setItemState(0); //Removes item from player. This code will be replaced once inventory is written.
			
		}
	}
	else
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("I wonder if we'll be aware of the timeline change, given that we know that it's changing.\n\n");
		simTypeFast("Research has shown there's a sort of link between the mental and the temporal. I don't know much about it, though. That's just what I've heard.\n\n");
	}
}

//======
//SCIENTIST 3 DIALOGUE BLOCK
//======
void Scientist::scientist3Dialogue(Avatar* the_player)
{
	string scientist_name = "Scientist 3";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}

	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	if (game_state == 1)
	{
		the_player->avatarDialogue(" The scientist is absorbed in his work on The Device and just waves me away when I try to talk to him. \n\n");
	}
	else
	{
		if (s3_dialogue_state == 1)
		{
			//If first time talking to scientist, greeting dialogue
			cout << "+" << scientist_name << "+ "; simTypeFast("Ah, "); cout << the_player->getPName(); simTypeFast(", welcome to the Chrono Research Sector.\n\n");
			simTypeFast("I'm Dr. Algernop Kaiser, director of natural and earth sciences for the project. If you wish to know more about the project, let me know.\n\n");
			isExamined = true; //Introduces himself by name, so show name while talking to him.
			s3_dialogue_state++; //advances to dialogue state 2
		}
		else if (s3_dialogue_state == 2)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("If you wish to know more about mission specifics, please talk to Dr. Klein to the east. She's the\n\n"
				"assistant lead to the project and will take care of your briefing. However, I can tell you more about the forces we're working with on the project.\n\n"
				"Would you like to hear more?\n\n");
			if (isYes())
			{
				s3_dialogue_state++; // advances to dialogue state 3
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("I see. I understand that you may be busy right now, but just let me know if you want to learn more about\n\n"
					"time travel.\n\n");
			}
		}

		if (s3_dialogue_state == 3)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("I'm glad to hear you're interested. There are a vast number of complexities, as you can imagine.\n\n"
				"When understanding the concept of alternate timelines, one has to understand just how many variables are at work here.\n\n"
				"Consider this: I will use the term \"moment\" to refer to a \"point\" in time. On a graph, that would mean that the unit of time used to measure it\n\n"
				"is so small that it's basically zero. A nearly infinite number of \"moments\" could fit into any measure of time. This is a common concept in Calculus,\n\n"
				"and is referred to as taking the \"limit of time\", as size of your unit of measurement (milliseconds, seconds, hours, ect) approaches zero.\n\n"
				"Are you following me so far, "); cout << the_player->getPName() << "?\n\n";

			if (isYes())
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("That's good. You can talk to me again later and we can continue our lesson.\n\n");
				s3_dialogue_state++;//set scientist dialogue state to 4
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("Eh, I don't really know what I expected. You're no scientist... But come back later and we can try again.\n\n");
			}
		}
		else if (s3_dialogue_state == 4)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Now that you understand the concept of a \"point\" in time, consider this:\n\n"
				"that for every one of those essentially infinite points in time, there are an ENORMOUS number of changes that could possibly occur.\n\n"
				"To understand one's effect on a timeline, they would have to calculate every single possible change that could occur as a result of an action.\n\n"
				"For example, let's say a man is running late for work. He is about to walk out the door and realizes he doesn’t have his keys.\n\n"
				"At this moment in time, a split occurs. In one timeline (or branch), the man is able to recall exactly where he last left his keys.\n\n"
				"In the other timeline, he is not.\n\nSo person A from that timeline branch gets his keys and leaves for work. Meanwhile, person B\n\n"
				"stays home and has to look for his keys. We now have two timelines as a result of the two possible outcomes that could occur at that\n\n"
				"very moment.\n\nStill following me?\n\n");

			if (isYes())
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("Think about that for a bit, then come back to me later for more information.\n\n");
				s3_dialogue_state++; //set scientist dialogue state to 5
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("That's too bad. It's only going to get more complex from here. Talk to me again in a bit and I'll go over it again.\n\n");
			}
		}
		else if (s3_dialogue_state == 5)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("In our given example, we currently have two time branches originating from one moment. \n\n"
				"In one timeline (or branch), the man is able to recall exactly where he last left his keys, and in the other he is not.\n\n"
				"Understand now, that because there are now two timelines that have arisen from that moment, now each will have its own unique branching timeline possibilities.\n\n"
				"Let us now say, that in the timeline where the man forgets his keys, he decides to look for them in the most likely place he can think of – next to his bed...\n\n"
				"Or does he think to look in the other most likely place – his living room? Or any of the other nearly infinite places that he could look in the house,\n\n "
				"each having its own consequence of on a timeline.\n\nFor the sake of simplicity, let us assume that for the vast majority of the timeline branches for person B, he does not make it to work on time because he was searching for his keys.\n\n"
				"Now, when person B finally arrives at work, in one timeline branch, the man is fired from his job for being late, and in the other, he is let off with a warning and keeps his job.\n\n"
				"If the man loses his job, this will impact the rest of his life, as well as the others around him, leading to more deviations from the original timeline (Person A), \n\n"
				"resulting an incomprehensible number of unforseen changes and consequences. At this point, you may be wondering what happened to Person A\n\n"
				"Well, they never made it to work. They were killed in a car accident with a drunk driver on the way there. Person B lived because he lost his car keys.\n\n\n");

			simTypeFast("Think about that for a bit, then come back to me later for more information.\n\n");
			s3_dialogue_state++; //set scientist dialogue state to 6		
		}
		else if (s3_dialogue_state == 6)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("As established, Person A was killed on the way to work by a drunk driver. This is unfortunate, but sometimes life occurs this way.\n\n"
				"However, there is also a version of person A in a separate timeline that lived and made it to work on time because the drunk driver was not there at that particular moment.\n\n"
				"Perhaps he was on a different road, perhaps he was not drunk, perhaps he had not even been born in that particular time branch due. These circumstances are completely out of\n\n"
				"the control of our Subject. In the same way, many of these cirumstances are completely out of our hands as well.\n\nUntil now, that is.\n\n"
				"We now have the technology and power to go back and redirect those timelines to produce more favorable outcomes. The tricky part is predicting how this will influcnce unforseen events.\n\n");

			simTypeFast("Think about that for a bit, then come back to me later for more information.\n\n");
			s3_dialogue_state++; //set scientist dialogue state to 6		
		}
		else if (s3_dialogue_state == 7)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("We just explored a handful of possible timeline branches that could have occurred at that moment in time for that one situation.\n\n"
				"Apply this to a larger scale. Now include the possibility that the man’s wife may have seen his keys, picked them up, and moved them to a new spot that she thought more convenient to him.\n\n"
				"Now she has altered time in a way that affects her husband by moving the keys from the place that he remembered them being to a new location. In that way, his wife unknowingly saved his life.\n\n\n"
				"This is a very simple example. Dealing with time can get incomprehensibly complex. This is something you must keep in mind during your mission. Avatars were built to include a self-decomposition\n\n"
				"feature to eliminate any possibilities of disturbing the timeline should they be stranded in a different time.\n\n");
			s3_dialogue_state++;
		}
		else if(s3_dialogue_state == 8)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Tag, "); cout << the_player->getPName(); simTypeFast(". Do you wish to hear my explanation on time branches again?\n\n");

			if (isYes())
			{
				s3_dialogue_state = 3; //set dialogue state to me
				cout << "+" << scientist_name << "+ "; simTypeFast("Alright. It is a bit to digest, so when you're ready, speak to me again and I'll go over the concepts with you again.\n\n");
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("Glad you got it the first time.\n\n");
			}
		}
	}
}

//======
//SCIENTIST 4 DIALOGUE BLOCK
//======
void Scientist::scientist4Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	string scientist_name = "Scientist 4";
	
	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}

	if (game_state == 1)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Interesting readings I'm getting. Eh, not that you'd know what they mean, anyway. Why don't\n\n");
		simTypeFast("you go talk to the Lead Scientist. He probably has something more useful for you to do than your standing around.\n\n");
	}
	else if (game_state < 8 && game_state > 1)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Please, I have far too much to do right now.\n\n");
		the_player->avatarDialogue("Apologies for bothering you.\n\n");		
	}
	if (game_state == 8)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Aha. Finally. Thank you again for your help in the laboratory. I can just insert this and\n\n");
		simTypeFast("we can begin...\n\nHere goes nothing.");
		simTypeFast("*Dr. Klein slides the core container into the side of the device. A deep roar echoes off the walls of the main room of the lab\n\n");
		simTypeFast("as the device springs to life. The bowl shaped divot in the device is suddenly filled with an eerie, glowing plasma-like substance.*");

		if (s4_dialogue_state == 2)
		{
			cout << "+" << scientist_name << "+ " << the_player->getPName(); simTypeFast(", there are some things that you need to be aware of before you go in there.\n\n");
			simTypeFast("Consider this your briefing.\n\n\n");//add briefing information.
			simTypeFast("As established, you and your Avatar will be traveling to November 22, 1963. Your target time is 12:30 CST.\n\n");
			simTypeFast("We have determined, through heavy deliberation, that you will be tasked with stopping the Asassination of 35th US President, John F. Kennedy.\n\n");
			simTypeFast("After the Asassination, President Lyndon B. Johnson took the oath of office and was sworn in as the 36th president of the United States. Under his\n\n");
			simTypeFast("leadership, America continued to deepen its involvement with Vietnam, resulting in a disasterous policy of unchecked foreign interventionism.\n\n");
			simTypeFast("America continued to grow more aggressive with its global policing, destabilizng countries, entire regions, and creating even more problems.\n\n");
			simTypeFast("Although it is impossible to truly understand the ramifications of saving President Kennedy's life, it's the best shot we have.\n\n");
			simTypeFast("Anything is better than this. There are no longer enough humans alive to revive our species. Technological progress is beginning to slow here,\n\n");
			simTypeFast("and the storm's effects on global health were catastrophic. Radiation, mutation and the continued destruction of natural life and habitats is all\n\n");
			simTypeFast("that we have left in this timeline. This planet doesn't have much time left. We're running on limited resources. We won't be able to acquire anything\n\n");
			simTypeFast("from this planet soon. It's simply too dangerous. We do have the Avatars, but they're quite few in number and cannot singlehandedly take on the burden\n\n");
			simTypeFast("of sustaining life for millions of people. If only we still had the option of extraterrestrial colonization, but our dream of exploring the stars vanished\n\n");
			simTypeFast("when the Storm hit. \n\n");

			simTypeFast("... ehm, anyway, You will only have a few seconds in the time rift before it spits you back out again. In all hope, we'll be waiting for you on the other side.\n\n\n");
			simTypeFast("Are you ready to go?\n\n");
			if (isYes())
			{
				s4_dialogue_state = 4; //go to next gamestate, end of level
			}
			else
			{
				cout << "+" << scientist_name << "+ ";  simTypeFast("Well hurry up then with whatever you need to do.\n\n");
				s4_dialogue_state = 3; 
			}
		}
		else
		{
			simTypeFast("Are you ready to go?\n\n");
			if (isYes())
			{
				s4_dialogue_state = 4;
			}
			else
			{
				cout << "+" << scientist_name << "+ ";  simTypeFast("Well hurry up then with whatever you need to do.\n\n");
			}
		}
	}	
}

//======
//SCIENTIST 5 DIALOGUE BLOCK
//======
void Scientist::scientist5Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.

	string scientist_name = "Scientist 5";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}
	
	cout << "+" << scientist_name << "+ "; simTypeFast("Can we talk later? I'm on break.\n\n");
	
	
}

//======
//SCIENTIST 6 DIALOGUE BLOCK
//======
void Scientist::scientist6Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.
	
	string scientist_name = "Scientist 6";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}

	// Begin with this regardless of gamestate

	if (s6_dialogue_state == 1)
	{
		//If first time talking to scientist, greeting dialogue
		cout << "+" << scientist_name << "+ "; simTypeFast("Ahoy, "); cout << the_player->getPName(); simTypeFast("! How are you feeling in there? You had a pretty seamless mind-link, so I wouldn't be worried\n\n");
		simTypeFast("about any adverse side effects. Mind link technology has been around since before The Great Storm. It's almost archaic!\n\n");
		simTypeFast("This time stuff though... I don't know. It'll work. It does work. But recently during my work, I've been starting to wonder\n\n");
		simTypeFast("if we should really go messing with it. Just because we've figured out how to do something doesn't mean that we should. History\n\n");
		simTypeFast("will reveals that many times over.\n\nBut at the same time, we could save humanity of this terrible future if we succeed.\n\n\n");
		simTypeFast("God knows what will happen should we fail.\n\n");
		s6_dialogue_state++;
	}
	else if (s6_dialogue_state > 1 && the_player->getGameState() == 1)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("You should probably go talk to the Lead Scientist.\n\n");
	}
	else if (s6_dialogue_state == 2)
	{		
		cout << "+" << scientist_name << "+ "; simTypeFast("Hello again. I agree that the command interface takes a little getting used to, but you seem to be doing fine.\n\n");
		simTypeFast("Other than that, it's a fine piece of technology. I'm very proud of the program, myself. The Avatars were created, truth be told\n\n");
		simTypeFast("as tools to use against the rebels during the Second Civil War. Things got... complicated.\n\n\n");
		simTypeFast("Fortunately, the early Avatar designers were resolute to invoke Asimov's laws of robotics, making them rather unfit to fight in a war and");
		simTypeFast("saving us from the risk of an Avatar uprising as well.\n\n\n");
		s6_dialogue_state++;	
	}
	else if (s6_dialogue_state == 3)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Just a bit if info about Avatars... They are suited to blend into any environment required.\n\n");
		simTypeFast("They are amazing at stealth, being able to change their appearance and speaking algorithms based on what they observe around them.\n\n");
		simTypeFast("In essence though, Avatars are composed of synthetic flesh skin, a robotic core, and a small processor. Truly a marvel of technology if I do say so myself.\n\n\n");
	}
}

//======
//SCIENTIST 7 DIALOGUE BLOCK
//======
void Scientist::scientist7Dialogue(Avatar* the_player)
{
	setGameState(the_player->getGameState()); //sets gamestate of scientist so the be able to pick dialogue options.
	
	string scientist_name = "Scientist 7";

	if (isExamined == true) //If the scientist has had the examine command run on them, display their real name instead of their scientist number.
	{
		scientist_name = name;
	}

	if (game_state == 1)
	{
		the_player->avatarDialogue(" The scientist is too lost in his book to acknowledge me.\n\n");
	}
	
	if (game_state > 1 && game_state < 5)
	{
		cout << "+" << scientist_name << "+ "; simTypeFast("Ah, I know what you're thinking. We have such plentiful access to massive databases and convenient interfaces, why use\n\n");
		simTypeFast("those archaic relics? Well you see, this project is currently the highest security priority in the NA Government.\n\n");
		simTypeFast("All research and records related to this project are not to be entered into an electronic database at this point in time.\n\n");
		simTypeFast("Although we retrieved most of the source information from a varied collection of data libraries\n\n");
		simTypeFast("from across the globe, the compilation and results of research must be kept off the web lest it travel into the wrong hands.\n\n");
		simTypeFast("As we speak, my systems are fending off millions of hacking attacks from the EX an hour, but we're holding strong.\n\n\n");
	}

	if (game_state == 5)
	{
		string input, answer1, answer2, answer3;
		if (s7_dialogue_state == 1)
		{

			cout << "+" << scientist_name << "+ "; simTypeFast("Hmm, it seems you come to me with a purpose.\n\n");
			the_player->avatarDialogue("Yes, we were asked to pick up a book for the scientist in the Eco Lab.\n\n");
			cout << "+" << scientist_name << "+ "; simTypeFast("Oh, Charles wants his reference book on Complex Systems Biology, eh? Couldn't be bothered to come here himself? \n\n");
			the_player->avatarDialogue("Well, he was busy...\n\n");
			simTypeFast("*the scientist sighs*\n\n");
			cout << "+" << scientist_name << "+ "; simTypeFast("The rules are that individuals may only check out books in person for security reasons. We appear to be at an impasse. \n\n");
			the_player->avatarDialogue("Then you may want to inform him of that rule. We're just trying to get the Device up and running as quickly as possible.\n\nOrders form the lead scientist.\n\n");
			cout << "+" << scientist_name << "+ "; simTypeFast("Hmm. How about this. As information director of the Chrono Research sector, it's my duty to ensure that the agent of this \n\n");
			simTypeFast("mission is mentally fit for the task. I know sometimes the Avatar integration can be a bit disorienting at times. I just need to check your memory retention \n\n");
			simTypeFast("with a simple question about your knowledge of your surroundings. If you can answer correctly, you may take the book.\n\n");
			the_player->avatarDialogue("Fair enough. I hope you've been paying attention, "); cout << the_player->getPName() << ".\n\n";
			cout << "+" << scientist_name << "+ "; simTypeFast("Who was the founder of the Time Device Project?\n\n");
			simTypeFast(">> Who founded the Time Device Project? (Case and punctuation matters):");

			getline(cin, input);
			processLine(input, answer1, answer2, answer3, 'U');
			if (answer1 == "Lynard" && answer2 == "B." && answer3 == "Weiss")
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("Very good. I will make this one exception because I am aware of who you are and what your role is in this project. Here's the book.\n\n");
				the_player->setItemState(1);
				the_player->avatarDialogue("I've picked up the Complex Systems Biology Book!\n\n");
				s7_dialogue_state = 3; //if player passes, set to dialog state 3
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("No, that's incorrect. Perhaps you should take a bit more time to get used to examining your surroundings.\n\nCome back when you wish to try again.\n\n");
				s7_dialogue_state = 2; //if player fails, set to retry statement.
			}
		}
		else if (s7_dialogue_state == 2)
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("Ready to try again?\n\n");
			simTypeFast(">> Who founded the Time Device Project? (Case and punctuation matters):");

			getline(cin, input);
			processLine(input, answer1, answer2, answer3, 'U');
			if (answer1 == "Lynard" && answer2 == "B." && answer3 == "Weiss")
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("Very good. I will make this one exception because I am aware of who you are and what your role is in this project. Here's the book.\n\n");
				the_player->setItemState(1);
				s7_dialogue_state = 3;
				the_player->avatarDialogue("I've picked up the Complex Systems Biology Book!\n\n");
			}
			else
			{
				cout << "+" << scientist_name << "+ "; simTypeFast("No, that's still incorrect. Perhaps you should take a bit more time to get used to examining your surroundings.\n\nCome back when you wish to try again.\n\n");
			}
		}
		else 
		{
			cout << "+" << scientist_name << "+ "; simTypeFast("You need to take that book to Dr. Bennigan immediately, and don't even think about setting it down somewhere.\n\n");
		}
	}
}

//mutators near end of file, low maintenence functions

void Scientist::setGameState(int new_game_state)
{
	game_state = new_game_state;
}


//accessors at end of file, lowest maintenence functions

int Scientist::getX()
{
	return x;
}
int Scientist::getY()
{
	return y;
}

int Scientist::getGameState()
{
	return game_state;
}
int Scientist::getLS_DialogueState()
{
	return ls_dialogue_state;
}
int Scientist::getS1_DialogueState()
{
	return s1_dialogue_state;
}
int Scientist::getS2_DialogueState()
{
	return s2_dialogue_state;
}
int Scientist::getS3_DialogueState()
{
	return s3_dialogue_state;
}
int Scientist::getS4_DialogueState()
{
	return s4_dialogue_state;
}
int Scientist::getS5_DialogueState()
{
	return s5_dialogue_state;
}
int Scientist::getS6_DialogueState()
{
	return s6_dialogue_state;
}
int Scientist::getS7_DialogueState() 
{
	return s7_dialogue_state;
}

int Scientist::ls_dialogue_state = 1; //declare values of static member variables
int Scientist::s1_dialogue_state = 1;
int Scientist::s2_dialogue_state = 1;
int Scientist::s3_dialogue_state = 1;
int Scientist::s4_dialogue_state = 1;
int Scientist::s5_dialogue_state = 1;
int Scientist::s6_dialogue_state = 1;
int Scientist::s7_dialogue_state = 1;
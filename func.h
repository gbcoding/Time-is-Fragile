#pragma once
#include "Header.h"
#include "Scientist.h"
#include "Avatar.h"
#include "map.h"

bool isYes();

void syncGameStates(Scientist* scientist_object, Avatar* Avatar_object);

void syncGameStates(Item* item_object, Avatar* Avatar_object);

void itemInteract(Item* item_object, Avatar* Avatar_object);

void simTypeSlow(const char * p); //simulates slow typing when outputting text
void simTypeFast(const char * p); //simulates fast typing when outputting text
void simTypeSuperFast(const char * p); //simulates superfast typing when outputting text
bool isWall(status map[][30], string direction, int steps, int x, int y); //Checks to see if there is a wall in the way of character path
void processLine(string current_action, string& str_1, string& str_2, string& str_3, char tolowercase);
int argToInt(string argument);


int nearPlayer(Avatar* Player, Lead_Scientist LS, Scientist S1, Scientist s2, Scientist S3, Scientist S4, Scientist S5, Scientist S6, Scientist S7, status map[][30]);

void examineScientist(int scientist_num);
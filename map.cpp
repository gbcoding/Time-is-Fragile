#include "map.h"

//Builds map
void InitMap(status map[][30])
{
	int size = 20;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			map[row][col] = CLOSED;
		}
	}

	for (int row = 5; row <= 10; row++)
	{
		for (int col = 1; col <= 7; col++)
		{
			map[row][col] = OPEN;
		}
	}
	for (int row = 10; row <11; row++)
	{
		for (int col = 1; col<5; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 10; row <11; row++)
	{
		for (int col = 6; col<8; col++)
		{
			map[row][col] = WALL;
		}
	}

	for (int row = 11; row <= 18; row++)
	{
		for (int col = 2; col <= 7; col++)
		{
			map[row][col] = OPEN;
		}
	}

	for (int row = 14; row <= 17; row++)
	{
		for (int col = 5; col <= 11; col++)
		{
			map[row][col] = OPEN;
		}
	}

	for (int row = 14; row <15; row++)
	{
		for (int col = 11; col<12; col++)
		{
			map[row][col] = VWALL;
		}
	}
	for (int row = 17; row <18; row++)
	{
		for (int col = 11; col<12; col++)
		{
			map[row][col] = VWALL;
		}
	}
	for (int row = 6; row <= 20; row++)
	{
		for (int col = 12; col <= 19; col++)
		{
			map[row][col] = OPEN;
		}
	}
	for (int row = 6; row <15; row++)
	{
		for (int col = 19; col<20; col++)
		{
			map[row][col] = VWALL;
		}
	}
	for (int row = 17; row <21; row++)
	{
		for (int col = 19; col<20; col++)
		{
			map[row][col] = VWALL;
		}
	}

	for (int row = 1; row <= 16; row++)
	{
		for (int col = 20; col <= 23; col++)
		{
			map[row][col] = OPEN;
		}
	}
	for (int row = 9; row <15; row++)
	{
		for (int col = 23; col<24; col++)
		{
			map[row][col] = VWALL;
		}
	}

	for (int row = 14; row <15; row++)
	{
		for (int col = 20; col<21; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 14; row <15; row++)
	{
		for (int col = 22; col<23; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 14; row <15; row++)
	{
		for (int col = 24; col<25; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 8; row <9; row++)
	{
		for (int col = 20; col< 22; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 8; row <9; row++)
	{
		for (int col = 23; col<24; col++)
		{
			map[row][col] = WALL;
		}
	}

	for (int row = 9; row <= 20; row++)
	{
		for (int col = 24; col <= 29; col++)
		{
			map[row][col] = OPEN;
		}
	}
	for (int row = 14; row <15; row++)
	{
		for (int col = 24; col<25; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 9; row <15; row++)
	{
		for (int col = 26; col<27; col++)
		{
			map[row][col] = VWALL;
		}
	}
	for (int row = 17; row <19; row++)
	{
		for (int col = 26; col<27; col++)
		{
			map[row][col] = VWALL;
		}
	}
	for (int row = 14; row <15; row++)
	{
		for (int col = 27; col<28; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 14; row <15; row++)
	{
		for (int col = 29; col<30; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 16; row <17; row++)
	{
		for (int col = 24; col<25; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 16; row <17; row++)
	{
		for (int col = 26; col<27; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 16; row <17; row++)
	{
		for (int col = 26; col<28; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 16; row <17; row++)
	{
		for (int col = 29; col<30; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 18; row <19; row++)
	{
		for (int col = 27; col<28; col++)
		{
			map[row][col] = WALL;
		}
	}
	for (int row = 19; row <20; row++)
	{
		for (int col = 27; col<28; col++)
		{
			map[row][col] = VWALL;
		}
	}

	map[9][14] = TIME_DEVICE_SIDE;
	map[9][15] = TIME_DEVICE_CENTER;
	map[9][16] = TIME_DEVICE_SIDE;
}

void printMapRow(int i)
{
	// based on row integer passed, print out corresponding row letter of board 
	switch (i)
	{
	case 0: cout << " | ";
		break;
	case 1: cout << " | ";
		break;
	case 2: cout << " | ";
		break;
	case 3: cout << " | ";
		break;
	case 4: cout << " | ";
		break;
	case 5: cout << " | ";
		break;
	case 6: cout << " | ";
		break;
	case 7: cout << " | ";
		break;
	case 8: cout << " | ";
		break;
	case 9: cout << " | ";
		break;
	case 10: cout << " | ";
		break;
	case 11: cout << " | ";
		break;
	case 12: cout << " | ";
		break;
	case 13: cout << " | ";
		break;
	case 14: cout << " | ";
		break;
	case 15: cout << " | ";
		break;
	case 16: cout << " | ";
		break;
	case 17: cout << " | ";
		break;
	case 18: cout << " | ";
		break;
	case 19: cout << " | ";
		break;
	case 20: cout << " | ";
		break;
	default:cout << "Unknown grid row value: " << i << ". Program terminating..." << endl;
		exit(EXIT_FAILURE);
	}

	return;
}

void printMap(status map[][30])
{
	int col_size = 20;
	int row_size = 30;
	// print column and board headers(Formatting is correct below, extra \'s necessary

	cout << "|\\           __   __   __   __    __  _____  __    __             /|" << endl;
	cout << "| \\/\\  |    |__| |__| |  | |__|  |__|   |   |  |  |__|  |___|  \\/\\ |" << endl;
	cout << "|/     |___ |  | |__| |__| |  \\  |  |   |   |__|  |  \\    |       \\|" << endl;
	cout << "+------------------------------------------------------------------+" << endl;
	// loop through two-dimensional array to print out corresponding items
	for (int i = 0; i < col_size; i++)
	{
		printMapRow(i); // print grid row and left vertical column of board

						// now print board values for each row as characters
		for (int j = 0; j < row_size; j++)
		{
			cout << static_cast<char>(map[i][j]) << " ";
		}

		cout << "|" << endl;    // print right vertical column of board
	}
	cout << "+------------------------------------------------------------------+" << endl;
	cout << "| _____   |   ________ __|   |____    _  __      __|   __|    __   |" << endl;
	cout << "|      |__|_____   |______        |__|  |     __|  |  |______|_____|" << endl;
	cout << "| __         |  |___|   |___| |_____     |___|    ________    | |_ |" << endl;
	cout << "|   |________|    __|      |__|    |____|   |___|    |   |___ |   ||" << endl;
	cout << endl;//formatting
	cout << "A - Avatar Position                                  N     \n";
	cout << "# - Scientist Position                              /|\\    \n";
	cout << "! - Lead Scientist Position                      W---|---E \n";
	cout << "% - Object Location                                 \\|/    \n";
	cout << "                                                     S     \n";
	cout << endl;
	return;
}

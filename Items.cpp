#include "Items.h"
// for implementation of the Items in the gameworld
Item::Item(string init_name, int init_x, int init_y, int init_amount, status map[][30])
{
	x = init_x;
	y = init_y;
	item_name = init_name;
	amount = init_amount;
	map[y][x] = ITEM;

}
void Item::setCoords(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}

void Item::setAmount(int new_amount)
{
	amount = new_amount;
}
int Item::getX()
{
	return x;
}
int Item::getY()
{
	return y;
}
bool Item::isAdjacent(status map[][30])
{
	if(map[y + 1][x] == P_LOCATION || map[y - 1][x] == P_LOCATION || map[y][x - 1] == P_LOCATION || map[y][x + 1] == P_LOCATION)
	{
		return true;
	}
	else
	{
		return false;
	}
}

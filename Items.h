#pragma once
#include "Header.h"
#include "map.h"
class Item
{
	public:
		Item() {};
		Item(string init_name, int init_x, int init_y, int init_amount, status map[][30]);
		void setCoords(int new_x, int new_y);
		void setAmount(int new_amount);
		string getName() { return item_name; }
		int getAmount() { return amount; }
		int getX();
		int getY();
		bool isAdjacent(status map[][30]);

	protected:
		int x, y;
		string item_name;
		double value;
		int amount; //number of this item the object contains

};
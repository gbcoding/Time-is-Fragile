#pragma once
#include "Header.h"

enum status { OPEN = ' ', CLOSED = 'x', WALL = '_', VWALL = '|', P_LOCATION = 'A', SCIENTIST = '#', LEAD_SCIENTIST = '!', ITEM = '%', TIME_DEVICE_SIDE = 'Z', TIME_DEVICE_CENTER = '0'};

void InitMap(status map[][30]);
void printMapRow(int i);
void printMap(status map[][30]);

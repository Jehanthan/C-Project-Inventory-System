/*
Author:		Jehanthan Naraentheraraja
Student ID: 105-825-186
Class:		PRG 255 - NDDL
Date:		07/08/2023
Program:	Final Lab Project
*/

#include "inventory.h"



int main(void)
{
	inventory itemInfo[MAX] = { 0 };

	readFile(itemInfo);

	menuChoice(itemInfo);

	writeFile(itemInfo);

	return 0;
}





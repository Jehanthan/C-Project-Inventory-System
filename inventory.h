#pragma once
#ifndef INVENTORY_H_
#define INVENTORY_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 12

typedef struct
{
	char itemName[10];
	char itemNum[10];
	float cost;
	int stock;
	float itemProfit;
	float totalProfit;
} inventory;


void readFile(inventory items[]);
void menuChoice(inventory items[]);
void ShowAllInfo(inventory items[]);
void sellItem(inventory items[]);
void ShowProductInfo(inventory items[]);
void addExistItem(inventory items[]);
void addNewItem(inventory items[]);
void writeFile(inventory items[]);

#endif
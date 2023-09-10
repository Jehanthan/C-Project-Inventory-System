
#include "inventory.h"


void readFile(inventory items[])
{
	FILE* fp;
	fp = fopen("inventory.txt", "rb+");

	if (!fp)
	{
		printf("Unable to open inventory.txt.\n");
		exit(1);
	}
	while (!feof(fp))
	{

		fread(&items, sizeof(inventory), MAX, fp);

	}
	fclose(fp);
}


void menuChoice(inventory items[])
{
	char menuChoice;
	int index, counter = 0;

	do {
		printf("\t\t\tInventory Control System\n\n\n");
		printf("\t\tTo choose a function, enter its letter label:\n\n");
		printf("a) Show the name, identication number and number of each item in stock,\n"
			"   including the cost of each item and total value of each item in stock.\n");
		printf("b) Allow the owner to enter the sale of an item\n");
		printf("c) Show the number of units sold, the profit for each item and the total store\n   profit\n");
		printf("d) Allow the owner to order more of an existing item\n");
		printf("e) Allow the owner to order new items\n");
		printf("f) Quit\n\n");
		printf("Menu Choice -> ");
		scanf(" %c", &menuChoice);

		menuChoice = tolower(menuChoice);

		system("cls");

		switch (menuChoice)
		{
		case 'a':
			ShowAllInfo(items);
			system("pause");
			system("cls");
			break;
		case'b':
			sellItem(items);
			system("pause");
			system("cls");
			break;
		case 'c':
			ShowProductInfo(items);
			system("pause");
			system("cls");
			break;
		case 'd':
			addExistItem(items);
			system("pause");
			system("cls");
			break;
		case 'e':
			addNewItem(items);
			system("pause");
			system("cls");
			break;
		case 'f':
			printf("\n\nThank you for using the Inventory Control System!\n\n");
			break;
		default:
			printf("\nInvalid Selection, Please Try Again!\n\n\n\n");
			break;
		}
	} while (menuChoice != 'f');

	system("pause");
	system("cls");
}

void ShowAllInfo(inventory items[])
{
	int index, counter = 0;

	for (index = 0; index < MAX; index++)
	{
		if (strlen(items[index].itemName) != 0)
		{
			counter = 1;
		}
	}

	if (counter)
	{

		printf("\n\n\t\t\t\t\t\t\tInventory Info\n\n\n");
		printf("\tInventory Slot\t\tItem Name\t\tItem Number\t\tCost of Item\t\tStock\t\tValue of Item\n\n");

		for (index = 0; index < MAX; index++)
		{
			if (strlen(items[index].itemName) != 0)
			{
				printf("\t%-2d\t%24s\t%14s\t\t\t$%.2f\t%18d\t\t$%-13.2f\n\n\n", index + 1, items[index].itemName, items[index].itemNum, items[index].cost, items[index].stock, items[index].cost * items[index].stock);
			}

		}
	}

	else
	{
		printf("\n\nPlease add Inventory first!\n\n");
	}


}

void sellItem(inventory items[])
{
	int loop = 0, sellAmount, userChoice, counter = 0;
	float profit;

	for (loop = 0; loop < MAX; loop++)
	{
		if (strlen(items[loop].itemName) != 0)
		{
			counter = 1;
		}
	}

	if (counter)
	{
		do {
			ShowAllInfo(items);
			printf("Please choose which inventory item to sell: ");
			scanf(" %d", &userChoice);
			userChoice--;
			if (userChoice < MAX)
			{
				printf("\nHow much of %s is to be sold? ", items[userChoice].itemName);
				scanf("%d", &sellAmount);
				if (sellAmount < items[userChoice].stock)
				{
					profit = items[userChoice].cost * sellAmount;
					printf("\n\nTotal Owing = $%.2f\n\n", profit * 1.5);
					profit = (float)(profit * 1.5) - profit;
					items[userChoice].itemProfit += profit;
					for (loop = 0; loop < MAX; loop++)
					{
						items[loop].totalProfit += profit;
					}
					items[userChoice].stock -= sellAmount;
					loop = 1;
				}
				else
				{
					printf("\tERROR: That much stock is not available\n\n");
				}
			}
			else
			{
				printf("That is not a valid option! Please try again!\n\n");

				system("cls");
			}
		} while (!loop);
	}

	else
	{
		printf("\n\nPlease add Inventory first!\n\n");
	}


}


void ShowProductInfo(inventory items[])
{
	int index, counter = 0;

	for (index = 0; index < MAX; index++)
	{
		if (strlen(items[index].itemName) != 0)
		{
			counter = 1;
		}
	}

	if (counter)
	{
		printf("\n\t\t\t\t\t\tInventory Info\n\n\n");
		printf("\tItem Name\t\tItem Number\t\tStock\t\tValue of Item\n\n");

		for (index = 0; index < MAX; index++)
		{
			if (strlen(items[index].itemName) != 0)
			{

				printf("%16s\t%14s\t%18d\t\t$%-13.2f\n\n", items[index].itemName, items[index].itemNum, items[index].stock, items[index].cost * items[index].stock);
			}
		}
		printf("\n\n\tTotal Profit -> $%.2f\n\n", items[0].totalProfit);
	}

	else
	{
		printf("\n\nPlease add Inventory first!\n\n");
	}



}

void addExistItem(inventory items[])
{
	int indexChoice, counter = 0, index, newStock;

	for (index = 0; index < MAX; index++)
	{
		if (strlen(items[index].itemName) != 0)
		{
			counter = 1;
		}
	}

	if (counter)
	{
		if (strlen(items[index].itemName) != 0)
		{
			ShowAllInfo(items);
			printf("\n\nTo Add More Stock Please Select the Appropriate Inventory Slot# -> ");
			scanf("%d", &indexChoice);
			indexChoice--;

			if (indexChoice >= 0 && indexChoice < MAX)
			{
				printf("\n\nYou have chosen to update %s\n\n", &items[indexChoice].itemName);
				printf("Please Enter The Quantity You want to Add -> ");
				scanf("%d", &newStock);
				printf("\n");
				printf("Inventory Updated!\n\n");
				items[indexChoice].stock += newStock;
				counter = 0;
			}
		}

	}

	else
	{
		printf("\n\nPlease add Inventory first!\n\n");
	}




}

void addNewItem(inventory items[])
{
	int loop = 0, freeIndex;
	char editChoice;

	for (loop = 0; loop < MAX; loop++)
	{
		if (strlen(items[loop].itemName) == 0)
		{
			printf("\n\n");
			freeIndex = loop;
			loop = MAX;
		}
	}

	printf("Please Enter Name of Part: ");
	scanf(" ");
	gets(items[freeIndex].itemName);
	printf("\nPlease Enter Number of Part: ");
	scanf(" ");
	gets(items[freeIndex].itemNum);
	printf("\nPlease Enter Quantity of Part: ");
	scanf("%d", &items[freeIndex].stock);
	printf("\nPlease Enter Price of Part: ");
	scanf("%f", &items[freeIndex].cost);
	printf("\n\n");
	printf("Inventory Updated!\n\n");
}


void writeFile(inventory items[])
{
	FILE* fp;
	fp = fopen("inventory.txt", "wb+");

	if (!fp)
	{
		printf("Unable to open inventory.txt.\n");
		exit(1);
	}
	while (!feof(fp))
	{

		fwrite(&items, sizeof(inventory), MAX, fp);

	}
	fclose(fp);
}
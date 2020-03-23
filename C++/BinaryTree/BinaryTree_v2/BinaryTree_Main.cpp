
#include "stdafx.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>


int main()
{
	// for restarting program. appointing ESC as exit button to press
	int exit = 0;
	while (exit != 27)
	{
		//Generating random unique values to add to our tree
		//-------------------------------------------------
		//random func enable
		srand(time(0));
		//variables
		const int tmpSize = 6;
		int mas[tmpSize];
		//loop for rand unique values generation
		for (int i = 0; i < tmpSize; i++)
		{
			//seting limit to 0..9
			mas[i] = rand() % 10;
			//flag for unique values check
			bool reroll = false;
			//using do while loop. repeat loop condition if reroll occured to check new value
			do
			{
				//loop exit conditon
				reroll = false;
				//running through the loop
				for (int j = 0; j < i; j++)
				{
					//checking for conjuctions
					if (mas[i] == mas[j])
					{
						//reroling
						mas[i] = rand() % 10;
						//seting flag
						reroll = true;
						//no point to continue this loop further
						break;
					}
				}
			} while (reroll);
		}
		//printing our values on the screen
		for (int i = 0; i < tmpSize; i++)
			std::cout << mas[i] << " ";
		std::cout << std::endl;
		//-------------------------------
		//Generating random unique values finished
		

		//Creating our Tree:
		BinaryTree bt;

		std::cout << "Tree is making.." << std::endl;
		//filling our tree with values we have made previously
		for (int i = 0; i < tmpSize; i++)
		{
			//our method returns error code. if there was an error - printing msg and breaking loop
			if (bt.AddNode(mas[i]) == ERROR)
			{
				std::cout << "AddNode() Error!" << std::endl;
				break;
			}
		}
		std::cout << "Done! " << std::endl;

		//additional self-explanatory test cases

		std::cout << "Tree Size is: " << bt.GetSize() << std::endl;

		std::cout << "Printing as tree.. " << std::endl;

		bt.PrintTree(true);

		std::cout << "Done! " << std::endl;

		std::cout << "Printing as string.. " << std::endl;

		bt.PrintTree(false);

		std::cout << "Done! " << std::endl;

		std::cout << "Trying to remove Node '7'... " << std::endl;

		bt.RemoveNode(7);

		std::cout << "Done! " << std::endl;
		
		std::cout << "Tree Size is: " << bt.GetSize() << std::endl;

		std::cout << "Printing as string.. " << std::endl;

		bt.PrintTree(false);

		std::cout << "Done! " << std::endl;

		std::cout << "Printing as tree.. " << std::endl;

		bt.PrintTree(true);

		std::cout << "Done! " << std::endl;
		
		std::cout << "Clearing our tree.." << std::endl;

		bt.Clear();

		std::cout << "Tree Size is: " << bt.GetSize() << std::endl;

		std::cout << "Done! " << std::endl;

		//asking user wether he wants to restar or exit the program
		std::cout << "Press any key to restart or ESC for exit:" << std::endl;
		exit = _getch();
		if (exit != 27)
			system("CLS");
	}
    return 0;
}


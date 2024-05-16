#ifndef RETURNITEM_H
#define RETURNITEM_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
#include "Keyboard.h"
using namespace std;

class ReturnItem : public TradeItems
{
	public:
		ReturnItem(int cardNumber, int itemID) : TradeItems(cardNumber, itemID, "") {}

		void execute() override
		{
			string borrowedItems = LibraryDatabase::getBorrowedItemsFormatted(LibraryCardNumber);
			if(borrowedItems.empty())
			{
				Screen::displayMessage("You have no items to return.");
				return;
			}

			Screen::displayMessage("Which item do you wish to return:\n" + borrowedItems);
			int itemIndex = Keyboard::getInput();

			string itemToReturn = LibraryDatabase::getBorrowedItemNameByIndex(LibraryCardNumber, itemIndex);
			if(itemToReturn.empty())
			{
				Screen::displayMessage("Invalid item selection.");
				return;
			}

			Screen::displayMessage("Please scan the item (Enter any number to continue)...");
			Keyboard::getInput();
			LibraryDatabase::removeItem(LibraryCardNumber, itemToReturn);
			Screen::displayMessage("Item returned!");
		}
};

#endif

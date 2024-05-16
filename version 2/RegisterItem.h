#ifndef REGISTERITEM_H
#define REGISTERITEM_H
#include "TradeItems.h"
#include "Screen.h"
#include "Keyboard.h"
#include "LibraryDatabase.h"
using namespace std;

class RegisterItem : public TradeItems
{
	public:
		RegisterItem(int cardNumber, int itemID, const string& memberType) : TradeItems(cardNumber, itemID, memberType) {}

		void execute() override
		{
			if(MemberType == "Faculty")
			{
				Screen::displayMessage("Enter item type (1 for book, 2 for magazine, 3 for DVD):");
				int itemType = Keyboard::getInput();

				Screen::displayMessage("Enter item ID (5 digits):");
				int itemID = Keyboard::getInput();

				Screen::displayMessage("Enter item name:");
				string itemName;
				cin.ignore();
				getline(cin, itemName);

				Screen::displayMessage("Please scan the item (Enter any number to continue)...");
				Keyboard::getInput();

				LibraryDatabase::addItemToDatabase(itemType, itemID, itemName);
				Screen::displayMessage("Item registered successfully!");
			}	else{
					Screen::displayMessage("You are not authorized to register new items.");
				}
		}
};

#endif

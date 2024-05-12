#ifndef RETURNITEM_H
#define RETURNITEM_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
using namespace std;

class ReturnItem : public TradeItems
{
	public:
		ReturnItem(int cardNumber, int itemID) : TradeItems(cardNumber, itemID, "") {}
	
		void execute() override
		{
			Screen::displayMessage("Scan the barcode of the item you wish to return... (Press 1 to scan a book, 2 to scan a magazine, 3 to scan a DVD)");
			int itemType = Keyboard::getInput();
			LibraryDatabase::removeItem(LibraryCardNumber, itemType);
			string itemTypeDesc = (itemType == 1) ? "book" : (itemType == 2) ? "magazine" : "DVD";
			Screen::displayMessage("Return process initiated for " + itemTypeDesc + ".");
		}
};

#endif

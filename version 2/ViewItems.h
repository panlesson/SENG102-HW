#ifndef VIEWITEMS_H
#define VIEWITEMS_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
using namespace std;

class ViewItems : public TradeItems
{
	public:
		ViewItems(int cardNumber) : TradeItems(cardNumber, 0, "") {}
			
		void execute() override
		{
			string items = LibraryDatabase::getBorrowedItems(LibraryCardNumber);
			Screen::displayMessage("Items currently borrowed: " + items);
		}
};

#endif

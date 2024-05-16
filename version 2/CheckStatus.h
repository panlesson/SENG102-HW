#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
using namespace std;

class CheckStatus : public TradeItems
{
	public:
		CheckStatus(int cardNumber) : TradeItems(cardNumber, 0, "") {}
	
		void execute() override
		{
			Screen::displayMessage("Checking for overdue items...");
			bool hasOverdueItems = LibraryDatabase::getOverdueStatus(LibraryCardNumber);
			if (hasOverdueItems)
			{
				Screen::displayMessage("You have overdue items! Please return them as soon as possible.");
			} 	else{
					Screen::displayMessage("You have no overdue items. Thank you for your consideration!");
				}
		}
};

#endif

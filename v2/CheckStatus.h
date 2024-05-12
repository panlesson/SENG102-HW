#ifndef CHECKSTATUS_H
#define CHECKSTATUS_H
#include "TradeItems.h"
#include "LibraryDatabase.h"
#include "Screen.h"
using namespace std;

class CheckStatus : public TradeItems
{
	public:
		// Constructor to initialize the LibraryCardNumber inherited from TradeItems
		CheckStatus(int cardNumber) : TradeItems(cardNumber, 0, "") {}
	
		// Override the execute function to check overdue status
		void execute() override
		{
			// Displaying checking status process message
			Screen::displayMessage("Checking for overdue items...");
	
			// Retrieve overdue status from the LibraryDatabase
			bool hasOverdueItems = LibraryDatabase::getOverdueStatus(LibraryCardNumber);
	
			// Based on the status, display the appropriate message
			if(hasOverdueItems)
			{
				Screen::displayMessage("You have overdue items! Please return them as soon as possible.");
			} 	else{
					Screen::displayMessage("You have no overdue items. Thank you for your consideration!");
				}
		}
};

#endif

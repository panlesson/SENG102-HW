#ifndef REGISTERITEM_H
#define REGISTERITEM_H
#include "TradeItems.h"
#include "Screen.h"
using namespace std;

class RegisterItem : public TradeItems
{
	public:
		RegisterItem(int cardNumber, int itemID, string memberType) : TradeItems(cardNumber, itemID, memberType) {}
	
		void execute() override
		{
			if (MemberType == "Faculty")
			{
				Screen::displayMessage("Registering new item: " + to_string(ItemID));
			}	else {
					Screen::displayMessage("You are not authorized to register new items.");
				}
		}
};

#endif

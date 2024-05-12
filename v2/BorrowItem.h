#ifndef BORROWITEM_H
#define BORROWITEM_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
using namespace std;

class BorrowItem : public TradeItems
{
	public:
		BorrowItem(int cardNumber, int itemID, string memberType) : TradeItems(cardNumber, itemID, memberType) {}
	
		void execute() override
		{
			if (canBorrowItemType())
			{
				string itemDescription = getItemDescription() + " - Duration left: " + to_string(getDuration()) + " days";
				LibraryDatabase::addItem(LibraryCardNumber, itemDescription);
				Screen::displayMessage("Borrowing item: " + itemDescription);
			}	else {
					Screen::displayMessage("Your user credentials do not permit borrowing this type of item.");
				}
		}
	
	private:
		bool canBorrowItemType()
		{
			if(MemberType == "Public" && ItemID == 3)	// Assuming DVD is type 3
			{  
				return false;
			}
			return true;
		}
	
		string getItemDescription()
		{
			int typeCount = LibraryDatabase::getTypeCount(LibraryCardNumber, ItemID);
			string itemType = (ItemID == 1) ? "Book" : (ItemID == 2) ? "Magazine" : "DVD";
			return itemType + " " + to_string(typeCount + 1);  // Increment to show new item count
		}
	
		int getDuration()
		{
			switch(ItemID)
			{
				case 1:
					return 14;  // 14 days for books
				case 2:
					return 7;   // 7 days for magazines
				case 3:
					return 3;   // 3 days for DVDs
				default:
					return 0;
			}
		}
};

#endif

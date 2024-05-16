#ifndef BORROWITEM_H
#define BORROWITEM_H
#include "TradeItems.h"
#include "Screen.h"
#include "LibraryDatabase.h"
#include "Keyboard.h"
using namespace std;

class BorrowItem : public TradeItems
{
	public:
		BorrowItem(int cardNumber, int itemID, const string& memberType) : TradeItems(cardNumber, itemID, memberType) {}

		void execute() override {
			if (LibraryDatabase::getBorrowedItemsCount(LibraryCardNumber) >= 5) {
				Screen::displayMessage("You cannot borrow more than 5 items at a time.");
				return;
			}

			Screen::displayMessage("Which item type do you wish to borrow (Enter 1 for books, 2 for magazines, 3 for DVDs):");
			int itemType = Keyboard::getInput();

			if (itemType == 3 && MemberType == "Public") {
				Screen::displayMessage("Public members may not borrow DVDs.");
				return;
			}

			vector<LibraryDatabase::Item> items = LibraryDatabase::getItemsByType(itemType);

			if (items.empty()) {
				Screen::displayMessage("No items available for the selected type.");
				return;
			}

			Screen::displayMessage("Here is the list of items in the library's inventory:");
			for (int i = 0; i < items.size(); ++i) {
				Screen::displayMessage(to_string(i + 1) + "- " + items[i].itemName);
			}

			Screen::displayMessage("Enter the number of the item you wish to borrow:");
			int itemIndex = Keyboard::getInput();
			LibraryDatabase::Item selectedItem = LibraryDatabase::getItemByIndex(itemType, itemIndex);

			if (selectedItem.itemID == 0) {
				Screen::displayMessage("Invalid item selection.");
				return;
			}

			string itemDescription = selectedItem.itemName + " - Duration left: " + to_string(getDuration(itemType)) + " days";
			LibraryDatabase::addItem(LibraryCardNumber, itemDescription);
			Screen::displayMessage("Borrowing item: " + itemDescription);
			Screen::displayMessage("Please scan the item (Enter any number to continue)...");
			Keyboard::getInput(); // Simulate scanning
			LibraryDatabase::removeLibraryItem(selectedItem); // Remove the item from the library's inventory
			Screen::displayMessage("Item borrowed!");
		}

	private:
		int getDuration(int itemType)
		{
			switch(itemType)
			{
				case 1: return 14;
				case 2: return 7;
				case 3: return 3;
				default: return 0;
			}
		}
};

#endif

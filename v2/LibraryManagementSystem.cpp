#include <iostream>
#include <string>
#include "LibraryKiosk.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Scanner.h"
#include "Account.h"
#include "LibraryDatabase.h"
#include "ViewItems.h"
#include "CheckStatus.h"
#include "BorrowItem.h"
#include "ReturnItem.h"
#include "RegisterItem.h"
#include "TradeItems.h"
using namespace std;

int main()
{
	LibraryKiosk kiosk;
	bool systemRunning = true;

	while(systemRunning)
	{
		kiosk.displayMessage("Welcome to the Library Management System!");
		kiosk.displayMessage("Please enter your 8-digit Library Card Number:");

		string cardInput;
		int cardNumber;
		string memberType;
		while(true)
		{
			cardInput = to_string(kiosk.getInput());
			if(cardInput.length() == 8)
			{
				cardNumber = stoi(cardInput);
				if(cardInput[0] == '1')
				{
					memberType = "Faculty";
				}	else if(cardInput[0] == '2')
					{
						memberType = "Student";
					}	else{
							memberType = "Public";
						}
				break;
			}
			kiosk.displayMessage("Invalid library card number. Please enter an 8-digit number:");
		}

		kiosk.displayMessage("Please enter your PIN:");
		string pinInput;
		int pin;
		while(true)
		{
			pinInput = to_string(kiosk.getInput());
			if(pinInput.length() == 6)
			{
				pin = stoi(pinInput);
				break;
			}
			kiosk.displayMessage("Invalid PIN. Please enter a 6-digit number:");
		}

		Account userAccount(cardNumber, pin, memberType);
		if(kiosk.userLogin(cardNumber, pin))
		{
			kiosk.displayMessage("Login successful!");

			bool exitRequested = false;
			while(!exitRequested)
			{
				kiosk.displayMessage("\nPlease select an option:\n1 - View Items\n2 - Check Status\n3 - Borrow Item\n4 - Return Item\n5 - Register Item\n6 - Exit");
				int choice = kiosk.getInput();

				switch (choice)
				{
					case 1:
					{
						ViewItems viewItems(cardNumber);
						kiosk.executeAction(viewItems);
						break;
					}
					case 2:
					{
						CheckStatus checkStatus(cardNumber);
						kiosk.executeAction(checkStatus);
						break;
					}
					case 3:
					{
						kiosk.displayMessage("Scan the barcode of the item to continue...\n(Enter 1 to scan a book, Enter 2 to scan a magazine, Enter 3 to scan a DVD)");
						int itemChoice = kiosk.getInput();
						if(memberType == "Public" && itemChoice == 3)
						{
							kiosk.displayMessage("Your user credentials do not permit borrowing DVDs.");
						} 	else{
							string itemType = (itemChoice == 1) ? "book" : (itemChoice == 2) ? "magazine" : "DVD";
							kiosk.displayMessage("Item type " + itemType + " selected. Borrowing process initiated.");
							BorrowItem borrowItem(cardNumber, itemChoice, memberType);
							kiosk.executeAction(borrowItem);
							}
						break;
					}
					case 4:
					{
						ReturnItem returnItem(cardNumber, 0);  // 'itemID' is not used in the updated design
						kiosk.executeAction(returnItem);
						break;
					}
					case 5:
					{
						if(memberType == "Faculty")
						{
							kiosk.displayMessage("Scan the barcode of the item you wish to register... (Enter any key to continue)");
							kiosk.getInput();
							kiosk.displayMessage("Register process initiated.");
						} 	else{
							kiosk.displayMessage("You are not authorized to register new items.");
							}
						break;
					}
					case 6: 
					{
						kiosk.displayMessage("Thank you for using the Library Management System.\nLogging out...");
						exitRequested = true;
						systemRunning = false;
						break;
					}
					default:
						kiosk.displayMessage("Invalid option. Please try again.");
						break;
				}
			}
		}	else{
				kiosk.displayMessage("Invalid card number or PIN. Please try again.");
			}
	}
	
	return 0;
}

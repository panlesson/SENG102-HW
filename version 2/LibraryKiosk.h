#ifndef LIBRARYKIOSK_H
#define LIBRARYKIOSK_H
#include "Screen.h"
#include "Keyboard.h"
#include "LibraryDatabase.h"
#include "TradeItems.h"
#include "ViewItems.h"
#include "CheckStatus.h"
#include "BorrowItem.h"
#include "ReturnItem.h"
#include "RegisterItem.h"
#include "Account.h"
using namespace std;

class LibraryKiosk
{
	private:
		bool userLoggedIn;
		int cardNumber;
		string memberType;

	public:
		LibraryKiosk() : userLoggedIn(false)
		{
			LibraryDatabase::initializeUsers();
			LibraryDatabase::initializeItems();
		}

		void displayMessage(const string& message)
		{
			Screen::displayMessage(message);
		}

		int getInput()
		{
			return Keyboard::getInput();
		}

		bool userLogin(int userNumber, int userPin)
		{
			displayMessage("Attempting login with card number: " + to_string(userNumber) + " and PIN: " + to_string(userPin));
			bool loginResult = LibraryDatabase::userLogin(userNumber, userPin);
			displayMessage(loginResult ? "Login successful!" : "Login failed.");
			return loginResult;
		}

		void executeAction(TradeItems& action)
		{
			action.execute();
		}

		void run()
		{
			bool systemRunning = true;

			while(systemRunning)
			{
				displayMessage("Welcome to the Library Management System!");
				bool loginSuccessful = false;

				while(!loginSuccessful)
				{
					displayMessage("Please enter your 8-digit Library Card Number:");

					while(true)
					{
						cardNumber = getInput();
						string cardInput = to_string(cardNumber);
						if(cardInput.length() == 8)
						{
							if(cardInput[0] == '1'){
								memberType = "Faculty";
							}	else if(cardInput[0] == '2'){
									memberType = "Student";
								}	else{
										memberType = "Public";
									}
							break;
						}
						displayMessage("Invalid library card number. Please enter an 8-digit number:");
					}

					displayMessage("Please enter your PIN:");
					int pin;
					while(true)
					{
						pin = getInput();
						string pinInput = to_string(pin);
						if (pinInput.length() == 6)
						{
							break;
						}
						displayMessage("Invalid PIN. Please enter a 6-digit number:");
					}

					if (userLogin(cardNumber, pin))
					{
						loginSuccessful = true;
						displayMessage("Member type: " + memberType);

						bool exitRequested = false;
						while(!exitRequested)
						{
							displayMessage("\nPlease select an option:\n1 - View Items\n2 - Check Status\n3 - Borrow Item\n4 - Return Item\n5 - Register Item\n6 - Exit");
							int choice = getInput();

							switch(choice)
							{
								case 1:
								{
									ViewItems viewItems(cardNumber);
									executeAction(viewItems);
									break;
								}
								case 2:
								{
									CheckStatus checkStatus(cardNumber);
									executeAction(checkStatus);
									break;
								}
								case 3:
								{
									BorrowItem borrowItem(cardNumber, 0, memberType);
									executeAction(borrowItem);
									break;
								}
								case 4:
								{
									ReturnItem returnItem(cardNumber, 0);
									executeAction(returnItem);
									break;
								}
								case 5:
								{
									RegisterItem registerItem(cardNumber, 0, memberType);
									executeAction(registerItem);
									break;
								}
								case 6:
								{
									displayMessage("Thank you for using the Library Management System.\nLogging out...");
									exitRequested = true;
									systemRunning = false;
									break;
								}
								default:
								{
									displayMessage("Invalid option. Please try again.");
									break;
								}
							}
						}
					}
					else
					{
						displayMessage("Invalid card number or PIN. Please try again.");
					}
				}
			}
		}
};

#endif

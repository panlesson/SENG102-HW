#ifndef LIBRARYKIOSK_H
#define LIBRARYKIOSK_H
#include "Screen.h"
#include "Keyboard.h"
#include "LibraryDatabase.h"
#include "TradeItems.h"  // Includes all trade item classes
using namespace std;

class LibraryKiosk {
	private:
		bool userLoggedIn;
	public:
		LibraryKiosk() : userLoggedIn(false) {}
	
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
			return LibraryDatabase::userLogin(userNumber, userPin);
		}
	
		void executeAction(TradeItems& action)
		{
			action.execute();
		}
};

#endif

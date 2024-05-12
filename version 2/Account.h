#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
	private:
		int LibraryCardNumber;
		int Pin;
		string MemberType;
	public:
		Account(int cardNumber, int pin, const string& type) : LibraryCardNumber(cardNumber), Pin(pin), MemberType(type) {}
	
		bool validatePIN(int userPin)
		{
			return Pin == userPin;
		}
	
		string getMemberType() const
		{
			return MemberType;
		}
	
		string getBorrowedItems();
		bool getOverdueStatus();
};

#endif

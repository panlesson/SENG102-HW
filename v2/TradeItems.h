#ifndef TRADEITEMS_H
#define TRADEITEMS_H
using namespace std;

class TradeItems
{
	protected:
		int LibraryCardNumber;
		int ItemID;
		string MemberType;
	public:
		TradeItems(int cardNumber, int itemID, string memberType) : LibraryCardNumber(cardNumber), ItemID(itemID), MemberType(memberType) {}
	
		virtual ~TradeItems() = default;
	
		int getLibraryCardNumber() const { return LibraryCardNumber; }
		int getItemID() const { return ItemID; }
		string getMemberType() const { return MemberType; }
	
		virtual void execute() = 0;  // Pure virtual function makes this an abstract class
};

#endif

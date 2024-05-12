#ifndef LIBRARYDATABASE_H
#define LIBRARYDATABASE_H
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class LibraryDatabase
{
	private:
		static map<int, vector<string>> borrowedItems;  // Maps user to list of items
	public:
		static bool userLogin(int userNumber, int userPin)
		{
			return true;
		}
	
		static string getBorrowedItems(int userNumber)
		{
			string result = "Items borrowed by user\n";
			if (borrowedItems.find(userNumber) != borrowedItems.end()) {
				for (const auto& item : borrowedItems[userNumber]) {
					result += item + "\n";
				}
			}
			return result;
		}
	
		static void addItem(int userNumber, const string& item)
		{
			borrowedItems[userNumber].push_back(item);
		}
	
		static int getTypeCount(int userNumber, int itemType)
		{
			return count_if(borrowedItems[userNumber].begin(), borrowedItems[userNumber].end(), 
								 [itemType](const string& desc) { return desc.find(itemType == 1 ? "Book" : itemType == 2 ? "Magazine" : "DVD") != string::npos; });
		}
	
		static bool getOverdueStatus(int userNumber)
		{
			return false;  // Placeholder for simplification
		}
		
		static void removeItem(int userNumber, int itemType)
		{
			if (!borrowedItems[userNumber].empty())
			{
				auto& items = borrowedItems[userNumber];
				auto it = find_if(items.rbegin(), items.rend(), [itemType](const string& desc){
					return desc.find(itemType == 1 ? "Book" : itemType == 2 ? "Magazine" : "DVD") != string::npos;
				});
				if (it != items.rend()) {
					items.erase((it + 1).base());
				}
			}
		}
};

map<int, vector<string>> LibraryDatabase::borrowedItems = {};

#endif

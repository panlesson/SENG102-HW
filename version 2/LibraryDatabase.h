#ifndef LIBRARYDATABASE_H
#define LIBRARYDATABASE_H
#include <string>
#include <vector>
using namespace std;

class LibraryDatabase
{
	public:
		struct Item
		{
			int itemType;
			int itemID;
			string itemName;
		};

	private:
		static const int MAX_ITEMS = 10;

		struct User
		{
			int cardNumber;
			int pin;
			string memberType;
			string borrowedItems[MAX_ITEMS];
			int itemCount;
			bool hasOverdue;
		};

		static vector<User> users;
		static vector<Item> items;

	public:
		static void initializeUsers()
		{
			users =
			{
				{11111111, 111111, "Faculty", {}, 0, false},
				{13582713, 647711, "Faculty", {}, 0, false},
				{15857585, 411871, "Faculty", {}, 0, false},
				{22222222, 222222, "Student", {}, 0, false},
				{28874049, 183121, "Student", {}, 0, false},
				{22977978, 474728, "Student", {}, 0, false},
				{20849848, 885006, "Student", {}, 0, false},
				{25254279, 382309, "Student", {}, 0, false},
				{23549160, 758568, "Student", {}, 0, false},
				{33333333, 333333, "Public", {}, 0, false},
				{75342860, 415998, "Public", {}, 0, false},
				{83759768, 420476, "Public", {}, 0, false},
				{79456279, 714394, "Public", {}, 0, false},
				{67865210, 969520, "Public", {}, 0, false},
				{45342115, 203926, "Public", {}, 0, false},
				{33213338, 473405, "Public", {}, 0, false},
				{74431645, 661049, "Public", {}, 0, false},
				{89317441, 444053, "Public", {}, 0, false}
			};
		}

		static void initializeItems()
		{
			items = {
				{1, 15372, "The Lord of the Rings, JRR Tolkien"},
				{1, 10814, "Pride and Prejudice, Jane Austen"},
				{1, 12496, "His Dark Materials, Philip Pullman"},
				{1, 15172, "The Hitchhiker's Guide to the Galaxy, Douglas Adams"},
				{1, 11396, "Harry Potter and the Goblet of Fire, JK Rowling"},
				{1, 15337, "To Kill a Mockingbird, Harper Lee"},
				{1, 11811, "Winnie the Pooh, AA Milne"},
				{1, 13632, "Nineteen Eighty-Four, George Orwell"},
				{1, 11339, "Jane Eyre, Charlotte Bronte"},
				{1, 14180, "Catch-22, Joseph Heller"},
				{2, 27005, "National Geographic"},
				{2, 25215, "Cosmopolitan"},
				{2, 23367, "New York Times"},
				{2, 25460, "Game Informer"},
				{2, 29850, "Sports Illustrated"},
				{3, 30054, "The Incredibles"},
				{3, 32290, "Shrek 2"},
				{3, 36561, "Avatar"},
				{3, 38375, "Spider-Man"},
				{3, 39467, "Finding Nemo"}
			};
		}

		static bool userLogin(int userNumber, int userPin)
		{
			for (const auto& user : users)
			{
				if (user.cardNumber == userNumber && user.pin == userPin)
				{
					return true;
				}
			}
			return false;
		}

		static string getBorrowedItems(int userNumber)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber)
				{
					string result = "Items borrowed by user:\n";
					for(int j = 0; j < user.itemCount; ++j)
					{
						result += user.borrowedItems[j] + "\n";
					}
					return result;
				}
			}
			return "";
		}

		static string getBorrowedItemsFormatted(int userNumber)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber)
				{
					string result;
					for(int j = 0; j < user.itemCount; ++j)
					{
						result += to_string(j + 1) + "-" + user.borrowedItems[j] + "\n";
					}
					return result;
				}
			}
			return "";
		}

		static int getBorrowedItemsCount(int userNumber)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber)
				{
					return user.itemCount;
				}
			}
			return 0;
		}

		static string getBorrowedItemNameByIndex(int userNumber, int index)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber && index > 0 && index <= user.itemCount)
				{
					return user.borrowedItems[index - 1];
				}
			}
			return "";
		}

		static void addItem(int userNumber, const string& item)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber && user.itemCount < MAX_ITEMS)
				{
					user.borrowedItems[user.itemCount++] = item;
					return;
				}
			}
			User newUser = {userNumber, 0, "", {}, 0, false};
			newUser.borrowedItems[newUser.itemCount++] = item;
			users.push_back(newUser);
		}

		static bool getOverdueStatus(int userNumber)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber)
				{
					return user.hasOverdue;
				}
			}
			return false;
		}

		static void removeItem(int userNumber, const string& item)
		{
			for(auto& user : users)
			{
				if(user.cardNumber == userNumber)
				{
					for(int j = 0; j < user.itemCount; ++j)
					{
						if(user.borrowedItems[j] == item)
						{
							for(int k = j; k < user.itemCount - 1; ++k)
							{
								user.borrowedItems[k] = user.borrowedItems[k + 1];
							}
							user.itemCount--;
							return;
						}
					}
				}
			}
		}

		static void removeLibraryItem(const Item& itemToRemove)
		{
			for(auto it = items.begin(); it != items.end(); ++it)
			{
				if(it->itemID == itemToRemove.itemID)
				{
					items.erase(it);
					return;
				}
			}
		}

		static void addItemToDatabase(int itemType, int itemID, const string& itemName)
		{
			items.push_back({itemType, itemID, itemName});
		}

		static void addUser(int cardNumber, int pin, const string& memberType)
		{
			User newUser = {cardNumber, pin, memberType, {}, 0, false};
			users.push_back(newUser);
		}

		static vector<Item> getItemsByType(int itemType)
		{
			vector<Item> result;
			for (const auto& item : items)
			{
				if (item.itemType == itemType)
				{
					result.push_back(item);
				}
			}
			return result;
		}

		static Item getItemByIndex(int itemType, int index)
		{
			vector<Item> itemsByType = getItemsByType(itemType);
			if (index > 0 && index <= itemsByType.size())
			{
				return itemsByType[index - 1];
			}
			return {0, 0, ""};
		}
};

vector<LibraryDatabase::User> LibraryDatabase::users;
vector<LibraryDatabase::Item> LibraryDatabase::items;

#endif

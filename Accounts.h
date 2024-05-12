#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    struct User {
        string libraryCardNumber;
        string pin;
        string role; 
    };

    vector<User> users;
    const string adminLibraryCardNumber = "admin";
    const string adminPin = "admin";

    bool isAdminLoggedIn; 

    bool loadUsersFromFile();
    void saveUsersToFile();

public:
    Account();
    bool verifyLogin();
    void addUser();
    void listUsers();
    void updateUser();
    void deleteUser();

    bool isAdmin() const { return isAdminLoggedIn; } 
};

Account::Account() {
    isAdminLoggedIn = false;
    loadUsersFromFile();
}

bool Account::loadUsersFromFile() {
    ifstream inputFile("Account.txt");
    if (!inputFile) {
        cerr << "Error opening Account file.\n";
        return false;
    }

    users.clear();
    User newUser;
    while (inputFile >> newUser.libraryCardNumber >> newUser.pin >> newUser.role) {
        users.push_back(newUser);
    }

    inputFile.close();
    return true;
}

void Account::saveUsersToFile() {
    ofstream outputFile("Account.txt");
    if (!outputFile) {
        cerr << "Error opening Account file for writing.\n";
        return;
    }

    for (const auto& user : users) {
        outputFile << setw(20) << left << user.libraryCardNumber
                   << setw(20) << left << user.pin
                   << setw(20) << left << user.role << endl;
    }

    outputFile.close();
}

bool Account::verifyLogin() {
    string inputLibraryCardNumber;
    string inputPin;

    do {
        cout << "Enter your Library Card Number: ";
        cin >> inputLibraryCardNumber;
        if (inputLibraryCardNumber == adminLibraryCardNumber) {
            cout << "Enter your admin PIN: ";
            cin >> inputPin;
            if (inputPin == adminPin) {
                cout << "Admin login successful!\n";
                isAdminLoggedIn = true;
                return true;
            } else {
                cout << "Invalid admin PIN. Please try again.\n";
            }
        } else {
            bool userFound = false;
            for (const auto& user : users) {
                if (user.libraryCardNumber == inputLibraryCardNumber) {
                    userFound = true;
                    cout << "Enter your PIN: ";
                    cin >> inputPin;
                    if (inputPin == user.pin) {
                        if (user.role == "admin") {
                            cout << "Admin login successful!\n";
                            isAdminLoggedIn = true;
                        } else {
                            cout << "User login successful!\n";
                        }
                        return true;
                    } else {
                        cout << "Invalid PIN. Please try again.\n";
                        break;
                    }
                }
            }
            if (!userFound) {
                cout << "User not found. Please try again.\n";
            }
        }
    } while (true);

    return false;
}

void Account::addUser() {
    if (!isAdminLoggedIn) {
        cout << "Admin login required to add user.\n";
        return;
    }

    User newUser;
    cout << "Enter new user's Library Card Number: ";
    cin >> newUser.libraryCardNumber;
    cout << "Enter new user's PIN: ";
    cin >> newUser.pin;
    newUser.role = "user"; 
    users.push_back(newUser);
    saveUsersToFile();
    cout << "User added successfully!\n";
}

void Account::listUsers() {
    if (!isAdminLoggedIn) {
        cout << "Admin login required to list users.\n";
        return;
    }

    if (users.empty()) {
        cout << "No users to list.\n";
        return;
    }

    cout << "List of users:\n";
    cout << setw(20) << left << "Library Card Number"
              << setw(20) << left << "PIN"
              << setw(20) << left << "Role" << endl;
    for (const auto& user : users) {
        cout << setw(20) << left << user.libraryCardNumber
                  << setw(20) << left << user.pin
                  << setw(20) << left << user.role << endl;
    }
}

void Account::updateUser() {
    if (!isAdminLoggedIn) {
        cout << "Admin login required to update user.\n";
        return;
    }

    string searchLibraryCardNumber;
    cout << "Enter the Library Card Number of the user to update: ";
    cin >> searchLibraryCardNumber;

    bool userFound = false;
    for (auto& user : users) {
        if (user.libraryCardNumber == searchLibraryCardNumber) {
            cout << "Enter new PIN for user " << user.libraryCardNumber << ": ";
            cin >> user.pin;
            userFound = true;
            saveUsersToFile();
            cout << "User updated successfully!\n";
            break;
        }
    }

    if (!userFound) {
        cout << "User not found.\n";
    }
}

void Account::deleteUser() {
    if (!isAdminLoggedIn) {
        cout << "Admin login required to delete user.\n";
        return;
    }

    string searchLibraryCardNumber;
    cout << "Enter the Library Card Number of the user to delete: ";
    cin >> searchLibraryCardNumber;

    bool userFound = false;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->libraryCardNumber == searchLibraryCardNumber) {
            users.erase(it);
            userFound = true;
            saveUsersToFile();
            cout << "User deleted successfully!\n";
            break;
        }
    }

    if (!userFound) {
        cout << "User not found.\n";
    }
}

#endif


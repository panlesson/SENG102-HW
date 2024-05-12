#include <iostream>
#include <iomanip>
#include "Accounts.h"
#include "Wiew.h"
#include "Borrow.h"
#include "Return.h"
#include "Register.h"
#include "Status.h"
#include "Delete.h"
using namespace std;

int main() {
    Account account;

    cout << "Welcome to the Library Management System\n";

    if (!account.verifyLogin()) {
        cout << "Invalid login. Exiting...\n";
        return 1;
    }

    int choice;
    do {
        cout << "\nMain Menu:\n"
             << "0- Exit\n"
             << "1- View Items\n"
             << "2- Borrow Item\n"
             << "3- Return Item\n"
             << "4- Register Item\n"
             << "5- Check Status\n"
             << "6- Manage Users[AdminOnly]\n"
             << "7- Delete Item\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(choice) {
            case 1:
                Wiew::displayItems();
                break;
            case 2:
                int borrowChoice;
                cout << "Borrow Menu:\n"
                     << "1- Borrow by Book Name\n"
                     << "2- Borrow by QR Code\n";
                cout << "Enter your choice: ";
                cin >> borrowChoice;
                if (cin.fail()) {
                    cout << "Invalid input.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                switch(borrowChoice) {
                    case 1:
                        Borrow::borrowItemByName();
                        break;
                    case 2:
                        Borrow::borrowItemByQrCode();
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                }
                break;
            case 3:
                int returnChoice;
                cout << "Return Menu:\n"
                     << "1- Return by Book Name\n"
                     << "2- Return by Barcode\n";
                cout << "Enter your choice: ";
                cin >> returnChoice;
                if (cin.fail()) {
                    cout << "Invalid input.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                switch(returnChoice) {
                    case 1:
                        Return::returnItemByName();
                        break;
                    case 2:
                        Return::returnItemByBarcode();
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                        break;
                }
                break;
            case 4:
                Register::registerItem();
                break;
            case 5:
                Status::checkStatus();
                break;
            case 6:
                if (account.isAdmin()) {
                    int manageChoice;
                    cout << "\nManage Users Menu:\n"
                         << "1- Add User\n"
                         << "2- Delete User\n"
                         << "3- View User\n"
                         << "4- Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> manageChoice;
                    if (cin.fail()) {
                        cout << "Invalid input.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    switch (manageChoice) {
                        case 1:
                            account.addUser();
                            break;
                        case 2:
                            account.deleteUser();
                            break;
                        case 3:
                            account.listUsers();
                            break;
                        case 4:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } else {
                    cout << "Access Denied. Only admin can access this menu.\n";
                }
                break;
            case 7:
                Delete::deleteItem(); 
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}




#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Status {
public:
    static void checkStatus() {
        while (true) {
            ifstream dataFile("DATA.txt");
            if (!dataFile) {
                cerr << "Error opening DATA file.\n";
                return;
            }

            int choice;
            cout << "Select an option:\n";
            cout << "1. Borrowed Items\n";
            cout << "2. Stored Items\n";
            cout << "3. Exit\n:";
            cin >> choice;

            string title, author, publicationDate, barcode, status;
            bool found = false;
            while (dataFile >> title >> author >> publicationDate >> barcode >> status) {
                if ((choice == 1 && status == "Borrowed") || (choice == 2 && status == "Stored")) {
                    cout << title << " - " << author << " - " << publicationDate << " - " << status << "\n";
                    found = true;
                }
            }
            dataFile.close();

            if (!found) {
                cout << "No items found.\n";
            }

            if (choice == 3) {
                break; 
            }
        }
    }
};

#endif


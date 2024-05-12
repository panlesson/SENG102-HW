#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

class Borrow {
public:
    static void borrowItemByQrCode() {
        string qrCode;
        cout << "Enter the QR code of the book you want to borrow: ";
        cin >> qrCode;
        removeSpaces(qrCode);
        borrowItem(qrCode);
    }

    static void borrowItemByName() {
        string name;
        cout << "Enter the name of the book you want to borrow: ";
        cin >> name;
        removeSpaces(name); 
        borrowItem(name);
    }

private:
    static void removeSpaces(string& str) {
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    }

    static void borrowItem(const string& key) {
        ifstream dataFile("DATA.txt");
        if (!dataFile) {
            cerr << "Error opening DATA file.\n";
            return;
        }

        string title, author, publicationDate, barcode, status;
        vector<string> newData;
        bool found = false;
        while (dataFile >> title >> author >> publicationDate >> barcode >> status) {
            if ((barcode == key || title == key) && status == "Stored") {
                found = true;
                status = "Borrowed";
            }
            newData.push_back(title + " " + author + " " + publicationDate + " " + barcode + " " + status);
        }
        dataFile.close();

        if (found) {
            ofstream dataFileOut("DATA.txt");
            if (!dataFileOut) {
                cerr << "Error opening DATA file for writing.\n";
                return;
            }

            for (const auto& line : newData) {
                dataFileOut << line << endl;
            }
            dataFileOut.close();

            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book not found or not available for borrowing.\n";
        }
    }
};

#endif


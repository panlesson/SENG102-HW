#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
class Return {
public:
    static void returnItemByName() {
        string bookName;
        cout << "Enter the name of the book you want to return: ";
        cin >> bookName;
        removeSpaces(bookName);
        returnItem(bookName);
    }

    static void returnItemByBarcode() {
        string barcode;
        cout << "Enter the QR Code of the book you want to return: ";
        cin >> barcode;
        removeSpaces(barcode);
        returnItem(barcode);
    }

private:
    static void removeSpaces(string& str) {
        str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    }

    static void returnItem(const string& key) {
       
        ifstream dataFile("DATA.txt");
        if (!dataFile) {
            cerr << "Error opening DATA file.\n";
            return;
        }

       
        string title, author, publicationDate, barcode, status;
        vector<string> newData;
        bool found = false;
        while (dataFile >> title >> author >> publicationDate >> barcode >> status) {
            if (title == key || barcode == key) {
                found = true;
                if (status == "Borrowed") {
                    status = "Stored";
                    cout << "Book returned successfully.\n";
                } else if (status == "Stored") {
                    cout << "Book is already in inventory.\n";
                }
            }
            newData.push_back(title + " " + author + " " + publicationDate + " " + barcode + " " + status);
        }
        dataFile.close();

        
        ofstream dataFileOut("DATA.txt");
        if (!dataFileOut) {
            cerr << "Error opening DATA file for writing.\n";
            return;
        }

        for (const auto& line : newData) {
            dataFileOut << line << endl;
        }
        dataFileOut.close();

        if (!found) {
            cout << "Book not found.\n";
        }
    }
};

#endif 


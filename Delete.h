#ifndef DELETE_H
#define DELETE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Delete {
public:
    static void deleteItem() {
        cout << "Choose the deletion criteria:\n"
                  << "1- Delete by Book Name\n"
                  << "2- Delete by QR Code\n";
        int criteria;
        cout << "Enter your choice: ";
        cin >> criteria;

        if (criteria == 1) {
            deleteItemByBookName();
        } else if (criteria == 2) {
            string barcode;
            cout << "Enter the QR Code of the book to delete: ";
            cin >> barcode;
            if (!deleteByBarcode(barcode)) {
                cout << "Book not found.\n";
            }
        } else {
            cout << "\nInvalid choice.\n";
        }
    }

private:
    static bool deleteByBookName(const string& bookName) {
        ifstream inputFile("DATA.txt");
        if (!inputFile) {
            cerr << "Error opening DATA file.\n";
            return false;
        }

        ofstream outputFile("temp.txt");
        if (!outputFile) {
            cerr << "Error creating temporary file.\n";
            inputFile.close();
            return false;
        }

        string title, author, publicationDate, barcode, status;
        bool bookFound = false;
        while (inputFile >> title >> author >> publicationDate >> barcode >> status) {
            if (title != bookName) {
                outputFile << title << " " << author << " " << publicationDate << " " << barcode << " " << status << "\n";
            } else {
                bookFound = true;
            }
        }

        inputFile.close();
        outputFile.close();

        remove("DATA.txt");
        rename("temp.txt", "DATA.txt");

        return bookFound;
    }

    static bool deleteByBarcode(const string& barcode) {
        ifstream inputFile("DATA.txt");
        if (!inputFile) {
            cerr << "Error opening DATA file.\n";
            return false;
        }

        ofstream outputFile("temp.txt");
        if (!outputFile) {
            cerr << "Error creating temporary file.\n";
            inputFile.close();
            return false;
        }

        string title, author, publicationDate, tempBarcode, status;
        bool bookFound = false;
        while (inputFile >> title >> author >> publicationDate >> tempBarcode >> status) {
            if (tempBarcode != barcode) {
                outputFile << title << " " << author << " " << publicationDate << " " << tempBarcode << " " << status << "\n";
            } else {
                bookFound = true;
            }
        }

        inputFile.close();
        outputFile.close();

        remove("DATA.txt");
        rename("temp.txt", "DATA.txt");

        return bookFound;
    }

    static void deleteItemByBookName() {
        string bookName;
        cout << "Enter the name of the book to delete: ";
        cin.ignore(); 
        getline(cin, bookName);
        if (!deleteByBookName(bookName)) {
            cout << "Book not found.\n";
        }
    }
};

#endif 


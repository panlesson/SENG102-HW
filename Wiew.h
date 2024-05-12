#ifndef WIEW_H
#define WIEW_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
using namespace std;
class Wiew {
public:
    static void displayItems();
};

void Wiew::displayItems() {
    ifstream dataFile("DATA.txt");
    if (!dataFile) {
        cerr << "Error opening DATA file.\n";
        return;
    }

    cout << "Displaying items...\n";
    cout << setw(20) << "Title" << " - "
              << setw(20) << "Author" << " - "
              << setw(20) << "Publication Date" << " - "
              << setw(20) << "QR code" << " - "
              << setw(20) << "Status" << endl;

    string title, author, publicationDate, barcode, status;
    while (dataFile >> title >> author >> publicationDate >> barcode >> status) {
        cout << setw(20) << title << " - "
                  << setw(20) << author << " - "
                  << setw(20) << publicationDate << " - "
                  << setw(20) << barcode << " - "
                  << setw(20) << status << endl;
    }

    dataFile.close();
}

#endif 


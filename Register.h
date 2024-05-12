#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class Register {
public:
   static void registerItem() {
    ofstream dataFile("DATA.txt", ios::app);
    if (!dataFile) {
        cerr << "Error opening DATA file for writing.\n";
        return;
    }

    cout << "Warning!!! Don't Enter more than 20 Characters.\n" << endl;

    string title, author, publicationDate, barcode;

    cout << "Enter book title (max 20 characters): ";
    getline(cin >> ws, title); 
    if (title.length() > 20) {
        cout << "Title exceeds 20 characters. Please enter a shorter title.\n";
        return;
    }
    title.erase(remove_if(title.begin(), title.end(), ::isspace), title.end()); 

    cout << "Enter author name (max 20 characters): ";
    getline(cin >> ws, author); 
    if (author.length() > 20) {
        cout << "Author name exceeds 20 characters. Please enter a shorter name.\n";
        return;
    }
    author.erase(remove_if(author.begin(), author.end(), ::isspace), author.end());

    cout << "Enter publication date (max 20 characters): ";
    getline(cin >> ws, publicationDate); 
    if (publicationDate.length() > 20) {
        cout << "Publication date exceeds 20 characters. Please enter a shorter date.\n";
        return;
    }
    publicationDate.erase(remove_if(publicationDate.begin(), publicationDate.end(), ::isspace), publicationDate.end());

    cout << "Enter QR Code (max 20 characters): ";
    getline(cin >> ws, barcode); 
    if (barcode.length() > 20) {
        cout << "QR Code exceeds 20 characters. Please enter a shorter code.\n";
        return;
    }
    barcode.erase(remove_if(barcode.begin(), barcode.end(), ::isspace), barcode.end());

    dataFile << title << " " << author << " " << publicationDate << " " << barcode << " Stored\n";
    cout << "Book registered successfully.\n";
    dataFile.close();
}
};

#endif 


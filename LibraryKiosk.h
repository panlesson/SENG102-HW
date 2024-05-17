#ifndef LIBRARYKIOSK_H
#define LIBRARYKIOSK_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class LibraryKiosk {
public:
    void searchItem(const string& item);
    void receiveKeyboardInput(const string& input);
    void scanBarcode(const string& barcode);
    void displayMessage(const string& message);
};

#endif


#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
using namespace std;

class Screen
{
	public:
		static void displayMessage(const string& message)
		{
			cout << message << endl;
		}
};

#endif

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
using namespace std;

class Keyboard
{
	public:
		static int getInput()
		{
			int input;
			cin >> input;
			return input;
		}
};

#endif

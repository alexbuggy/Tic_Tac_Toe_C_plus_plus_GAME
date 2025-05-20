#pragma once
#include <iostream>
#include <string>
using namespace std;
class PLAYER {
public:
	PLAYER(int pozplayer ):pozplayer(pozplayer) {
	}
	void setsymbol() {
		cout << endl;
		cout << "CHOOSE YOUR SYMBOL:";
		cin >> simbol;
		if (simbol == "x" || simbol == "o")
		{
			cout << endl;
		}
		else
		{
			do {
				cout << endl;
				cout << "CHOOSE A CHARACTER BETWEEN x AND o:";
				cin >> simbol;
			} while (simbol != "x" && simbol != "o");
		}
	}
	void setpoz() {

		cin >> pozplayer;
	}
	int getpoz() {
		return pozplayer;
	}
	string getsymbol() {
		return simbol;
	}
private:
	int pozplayer;
	string simbol;
};
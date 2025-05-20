#pragma once
#include <iostream>
using namespace std;
class PlayerO {
public:
	PlayerO(int pozo) :pozo(pozo) {
	}
	void setpoz() {
		
		cin >> pozo;
	}
	int getpoz() {
		return pozo;
	}
	string getsymbol() {
		return "o";
	}
private:
	int pozo;
public:

	PlayerO() = default;
};
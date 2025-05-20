#pragma once
#include <iostream>
using namespace std;
class PlayerX {
public:
	PlayerX(int pozx) :pozx(pozx) {
	}
	void setpoz() {
		
		cin >> pozx;
	}
	int getpoz() {
		return pozx;
	}
	string getsymbol() {
		return "x";
	}
private:
	int pozx;
};
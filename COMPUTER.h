#pragma once
#include <iostream>
#include <string>
using namespace std;
class COMPUTER {
public:
	COMPUTER(int computerPosition) :computerPosition(computerPosition) {
	}
	void SetSymbol(string symbolnew) {
		symbol = symbolnew;
	}
	string GetSymbol(){
	return symbol;
	}
	int GetPoz() {
		return computerPosition;
	}
private:
	int computerPosition;
	string symbol;
};
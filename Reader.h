#pragma once
#include <iostream>
#include "Date.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include "LendCard.h"

using namespace std;

struct Reader {
	string code;
	string name;
	string ID;
	int gender;
	// 1: male, 2: female, 3: other, 0: undefined
	string email;
	string address;
	Date startDay;
	Date endDay;
	vector<LendCard> lendCards;
	Reader();
	~Reader();
};

void ThongTinDocGia(Reader reader);
int HashReaderCode(const string &s);
string EncodeReaderCode(Reader reader);
string HashSixDigitCodeR(int num);
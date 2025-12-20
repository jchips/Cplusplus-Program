#ifndef STOREMENU_H
#define STOREMENU_H
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class StoreMenu {
public:
	int readStoreItems();
	void writeStoreItems() const;
	void menuOptionOne() const;
	void menuOptionTwo() const;
	void menuOptionThree() const;

private:
	const int BORDER_WIDTH = 25;
	map<string, int> storeItems;
	string nCharString(size_t t_num, char t_char) const;
};
#endif

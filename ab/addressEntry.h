#pragma once
#include <string>
using namespace std;

class addressEntry
{
private:
	 string name;
	 string number;
	 string address;
public:
	addressEntry();
	addressEntry(string nm,string nb,string ad);
	~addressEntry();
	string getName();
	string getNumber();
	string getAddress();
	
};

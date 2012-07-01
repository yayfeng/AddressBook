#include "StdAfx.h"
#include "addressEntry.h"

addressEntry::addressEntry():name(""),number(""),address(""){}
addressEntry::addressEntry(string nm,string nb,string ad)
{
	name=nm;
	number=nb;
	address=ad;
}

addressEntry::~addressEntry(void)
{
}

string addressEntry::getName()
{
	return name;
}
string addressEntry::getNumber()
{
	return number;
}
string addressEntry::getAddress()
{
	return address;
}

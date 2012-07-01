#pragma once
#include "addressEntry.h"
#include "AddressList.h"
#include<sstream>


class CmdHandle
{
private:
	 AddressList *addresslist;
	

public:
	CmdHandle(void);
	~CmdHandle(void);
	 void AddHandle();
	 void SearchHandle();
	void DeleteHandle();
	  void HelpHandle();
	void QuitHandle();
};

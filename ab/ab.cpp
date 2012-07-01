// ab.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "addressEntry.h"
#include "AddressList.h"
#include "CmdHandle.h"
#include <iostream>
using namespace std;

int main()
{
	string cmd;
	CmdHandle *cmdhandle=new CmdHandle();
	while(getline(cin,cmd))
	{
		if(cmd=="add")
		{
			cmdhandle->AddHandle();
		}
		else if(cmd=="search")
		{
			cmdhandle->SearchHandle();
		}
		else if(cmd=="delete")
		{
			cmdhandle->DeleteHandle();
		}
		else if(cmd=="!help")
		{
			cmdhandle->HelpHandle();
		}
		else if(cmd=="!quit")
		{
			break;
		}
		else
		{
			cout<<"error command"<<endl;
			cmdhandle->HelpHandle();
		}
	}
	delete cmdhandle;
	return 0;
}


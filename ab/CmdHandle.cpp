#include "StdAfx.h"
#include "CmdHandle.h"
#include <iostream>


CmdHandle::CmdHandle(void)
{
	addresslist=new AddressList();

}

CmdHandle::~CmdHandle(void)
{
		addresslist->StoreData();
	delete addresslist;
}
void CmdHandle::AddHandle()
{
	string name,number,address;
	addressEntry *entry;
	cout<<"name:";		
	if(getline(cin,name))
	{
		cout<<"number:";
		if(getline(cin,number))
		{
			cout<<"address:";
			if(getline(cin,address))
			{
				entry=new addressEntry(name,number,address);
				addresslist->AddEntry(entry);
				cout<<"address entry added"<<endl;
		//		cout<<entry->getName()<<" "<<entry->getNumber()<<" "<<entry->getAddress();
			}
		}
	}
}
void CmdHandle::SearchHandle()
{
	string searchField,input;
	vector<addressEntry> result;
	int i=0;
	cout<<"by (name|number|address):";
	while(true)
	{	
	getline(cin,searchField);
	if(searchField=="name"||searchField=="number"||searchField=="address")
	{
		break;
	}
	else
	{
		cout<<"error input"<<endl;
		cout<<"by (name|number|address):";
	}
	}
		if(searchField=="name")
		{
			cout<<"name:";
			if(getline(cin,input))
			{
				addresslist->SearchEntryName(input,result,input.find(".*"));
			}
				
		}
		else if(searchField=="number")
		{
			cout<<"number:";
			if(getline(cin,input))
			{
				addresslist->SearchEntryNumber(input,result,input.find(".*"));
			}
		}
		else if(searchField=="address")
		{
			cout<<"address:";
			if(getline(cin,input))
			{
				addresslist->SearchEntryAddress(input,result,input.find(".*"));
			}
		}
		if(result.empty())
		{
			cout<<"none has been found"<<endl;
		}
		else
		{
			 ostringstream ss;
			ss<<result.size();
			cout<<ss.str()<<" results have been found"<<endl;
			for(int j=0;j<result.size();j++)
			{
				cout<<"name:"<<result[j].getName()<<endl;
				cout<<"number:"<<result[j].getNumber()<<endl;
				cout<<"address:"<<result[j].getAddress()<<endl;
				cout<<endl;
			}
		}


}
void CmdHandle::DeleteHandle()
{
	string deleteField,input;
	int i=0,num=0;
    cout<<"by (name|number|address):";
    while(true)
	{	
	getline(cin,deleteField);
	if(deleteField=="name"||deleteField=="number"||deleteField=="address")
	{
		break;
	}
	else
	{
		cout<<"error input"<<endl;
		cout<<"by (name|number|address):";
	}
	}
			
		if(deleteField=="name")
		{
			cout<<"name:";
			if(getline(cin,input))
			{
				num=addresslist->DeleEntryName(input,input.find(".*"));
			}
				
		}
		else if(deleteField=="number")
		{
			cout<<"number:";
		    if(getline(cin,input))
			{
				num=addresslist->DeleEntryNumber(input,input.find(".*"));
			}
				
		}
		else if(deleteField=="address")
		{
			cout<<"address:";
			if(getline(cin,input))
			{
				num=addresslist->DeleEntryAddress(input,input.find(".*"));
			}
				
		}
		 ostringstream ss;
		ss<<num;
		cout<<ss.str()<<" entry have been deleted"<<endl;
		
}
void CmdHandle::HelpHandle()
{
	cout<<"You can input these command below:"<<endl;
	cout<<"add         to add entry in addressbook"<<endl;
	cout<<"search      to search entry in addressbook by field (name|number|address)"<<endl;
	cout<<"delete      to delete entry in addressbook by field (name|number|address)"<<endl;
	cout<<"!help       print this help message"<<endl;
	cout<<"!quit       quit the program"<<endl;
	
}

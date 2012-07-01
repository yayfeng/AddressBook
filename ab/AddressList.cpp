#include "StdAfx.h"
#include "AddressList.h"

AddressList::AddressList(void)
{
	
	pHead=new node();
	pHead->pNext=NULL;
	pHead->entry=new addressEntry();
	len=0;
	
}

AddressList::~AddressList(void)
{

	node *p=pHead;
	node *q=p;
	while(p)
	{
		p=p->pNext;
//		delete q->entry;
		delete q;
		q=p;
	}

}

bool AddressList::AddEntry(addressEntry *entry)                    
{
	try{
	node *p=pHead;
    while(p->pNext!=NULL)
	{
		p=p->pNext;
	}
	node *item=new node();
	item->entry=entry;
	p->pNext=item;
	item->pNext=NULL;
	len++;
	}catch(exception e)
	{
		cout<<e.what();
	}
	return true;
}
vector<addressEntry> AddressList::SearchEntryName(string nm, vector<addressEntry> &searchResult,int flag)
{
	node *p=pHead;
	while(p->pNext!=NULL)
	{
		p=p->pNext;
	if(p->entry!=NULL)
	{
		if(flag==-1)
		{
		
				if(p->entry->getName()==nm)
				{
					searchResult.push_back(*(p->entry));
				}
				}
				else
				{
					string temp=nm.substr(0,flag);
					if(p->entry->getName().find(temp)!=-1)
					{
						searchResult.push_back(*(p->entry));

					}
				}

	}
	else
	{
		cout<<"error";
	}
	
	}
    return searchResult;
}
vector<addressEntry> AddressList::SearchEntryNumber(string nb, vector<addressEntry> &searchResult,int flag)
{
	node *p=pHead;
	while(p->pNext!=NULL)
	{		
	    p=p->pNext;
		if(flag==-1)
		{
		if(p->entry->getNumber()==nb)
		{
			searchResult.push_back(*(p->entry));
		}
		}
		else
		{
			string temp=nb.substr(0,flag);
			if(p->entry->getNumber().find(temp)!=-1)
			{
				searchResult.push_back(*(p->entry));

			}
		}

	}
	  return searchResult;
}
vector<addressEntry> AddressList::SearchEntryAddress(string ad, vector<addressEntry> &searchResult,int flag)
{
	node *p=pHead;
	while(p->pNext!=NULL)
	{
		 p=p->pNext;
		if(flag==-1)
		{
		if(p->entry->getAddress()==ad)
		{
			searchResult.push_back(*(p->entry));
		}
		}
		else
		{
			string temp=ad.substr(0,flag);
			if(p->entry->getAddress().find(temp)!=-1)
			{
				searchResult.push_back(*(p->entry));

			}
		}

	}
	  return searchResult;
}
int AddressList::DeleEntryName(string nm,int flag)
{
	int num=0;
	node *p=pHead;
	node *q=p;
	if(p->pNext!=NULL)
	{
		p=p->pNext;
		while(p)
		{
			if(flag==-1)
			{
				if(p->entry->getName()==nm)
				{
					    node *temp=p;
						q->pNext=p->pNext;
						p=p->pNext;
						delete temp;
						num++; 
						len--;
				}
			}
			else
			{
				string temp=nm.substr(0,flag);
				if(p->entry->getName().find(temp)!=-1)
				{
					 node *temp=p;
				q->pNext=p->pNext;
				p=p->pNext;
				delete temp;
				num++; 
				len--;
				}
			}
		}
	}

	return num;
}
int AddressList::DeleEntryNumber(string nb,int flag)
{
	int num=0;
	node *p=pHead;
	node *q=p;
	if(p->pNext!=NULL)
	{
		p=p->pNext;
		while(p)
		{
			if(flag==-1)
			{
				if(p->entry->getNumber()==nb)
				{
					    node *temp=p;
						q->pNext=p->pNext;
						p=p->pNext;
						delete temp;
						num++; 
						len--;
				}
			}
			else
			{
				string temp=nb.substr(0,flag);
				if(p->entry->getNumber().find(temp)!=-1)
				{
					 node *temp=p;
					q->pNext=p->pNext;
					p=p->pNext;
					delete temp;
					num++; 
					len--;
				}
			}
		}
	}

	return num;
}
int AddressList::DeleEntryAddress(string ad,int flag)
{
	int num=0;
	node *p=pHead;
	node *q=p;
	if(p->pNext!=NULL)
	{
		p=p->pNext;
		while(p)
		{
			if(flag==-1)
			{
				if(p->entry->getAddress()==ad)
				{
					    node *temp=p;
						q->pNext=p->pNext;
						p=p->pNext;
						delete temp;
						num++; 
						len--;
				}
			}
			else
			{
				string temp=ad.substr(0,flag);
				if(p->entry->getAddress().find(temp)!=-1)
				{
					 node *temp=p;
				q->pNext=p->pNext;
				p=p->pNext;
				delete temp;
				num++; 
				len--;
				}
			}
		}
	}
	return num;
}
bool AddressList::IsEmpty()
{
	if(len==0)
		return true;
	else
		return false;
}
void AddressList::StoreData()
{
	if(!this->IsEmpty())
	{
		ofile.open("D:/addressbook.txt",ofstream::out|ofstream::app);
	if(ofile)
	{
		if(pHead->pNext!=NULL)
		{
			node *p=pHead->pNext;
			while(p)
			{
				ofile.write((char*)(p->entry),sizeof(AddressList));
				p=p->pNext;
			}
		}
		
	}
    ofile.clear();
	ofile.close();
	}
}
//void AddressList::ImportData()
//{
//	try{
//	ifile.open("D:/addressbook.txt",ofstream::in);
//	
//	if(ifile)
//	{
//		while(ifile.peek()!=EOF)
//		{
//			
//			ifile.read((char*)temp,sizeof(AddressList));
//			this->AddEntry(temp);
//		}
//	}
//	}catch(exception e)
//	{
//		cout<<e.what();
//	}
//	ifile.clear();
//	ifile.close();
//
//}
		
	



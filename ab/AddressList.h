#pragma once
#include <vector>
#include "addressEntry.h"
#include<fstream>
#include<iostream>

 struct node{
	addressEntry *entry;
	node *pNext;
	
};
class AddressList
{
	ifstream ifile;
	ofstream ofile;
    //addressEntry *temp;
public:
	node *pHead;
	int len;
	AddressList(void);
	~AddressList(void);
	bool AddEntry(addressEntry *entry);                                               //在链表的末尾插入元素                                        
    vector<addressEntry> SearchEntryName(string nm,vector<addressEntry> &searchResult,int flag);                         //搜索名字
	vector<addressEntry> SearchEntryNumber(string nb,vector<addressEntry> &searchResult,int flag);                      //搜索号码
    vector<addressEntry> SearchEntryAddress(string ad,vector<addressEntry> &searchResult,int flag);                     //搜索地址
    int DeleEntryName(string nm,int flag);                                            //删除链表中的与输入姓名相同的节点
	int DeleEntryNumber(string nb,int flag);                                            //删除链表中的与输入号码相同的节点
	int DeleEntryAddress(string ad,int flag);                                            //删除链表中的与输入地址相同的节点
    bool IsEmpty();                                                             //判断是否为空链表
	void StoreData();
	void ImportData();
};

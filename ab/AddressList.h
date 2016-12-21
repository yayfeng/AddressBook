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
	bool AddEntry(addressEntry *entry);                                               //�������ĩβ����Ԫ��                                        
    vector<addressEntry> SearchEntryName(string nm,vector<addressEntry> &searchResult,int flag);                         //��������
	vector<addressEntry> SearchEntryNumber(string nb,vector<addressEntry> &searchResult,int flag);                      //��������
    vector<addressEntry> SearchEntryAddress(string ad,vector<addressEntry> &searchResult,int flag);                     //������ַ
    int DeleEntryName(string nm,int flag);                                            //ɾ�������е�������������ͬ�Ľڵ�
	int DeleEntryNumber(string nb,int flag);                                            //ɾ�������е������������ͬ�Ľڵ�
	int DeleEntryAddress(string ad,int flag);                                            //ɾ�������е��������ַ��ͬ�Ľڵ�
    bool IsEmpty();                                                             //�ж��Ƿ�Ϊ������
	void StoreData();
	void ImportData();
};

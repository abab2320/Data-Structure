#pragma once
#include <iostream>
#include "Item.h"
using namespace std;
class Picture:public Item
{
protected:

public:
	string nation;
	string length;
	string wide;

	Picture();
	Picture(int ID, string title, string author, int rate, string nation, string length, string wide);
	void add(int id);
	void showInfo();

	//�޸�
	void modify();
	//����
	void save();

	//�ж��Ƿ�Ϊ������
	bool isName(string a);
	
};


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

	//修改
	void modify();
	//保存
	void save();

	//判断是否为正整数
	bool isName(string a);
	
};


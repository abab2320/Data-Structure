#pragma once
#include "Item.h"
class Book :public Item
{
protected:
	
public:
	string ISBN;
	int page;
	string press;

	//构造函数
	Book(int ID, string title, string author, int rate, string press, string ISBN, int page);
	Book();
	//添加函数，引导使用者填写信息

	void save();
	void add(int id);
	void showInfo();
	void modify();
	//void test01();
};




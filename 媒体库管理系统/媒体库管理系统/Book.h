#pragma once
#include "Item.h"
class Book :public Item
{
protected:
	
public:
	string ISBN;
	int page;
	string press;

	//���캯��
	Book(int ID, string title, string author, int rate, string press, string ISBN, int page);
	Book();
	//��Ӻ���������ʹ������д��Ϣ

	void save();
	void add(int id);
	void showInfo();
	void modify();
	//void test01();
};




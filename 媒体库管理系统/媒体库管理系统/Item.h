#pragma once
#include <iostream>
#include <fstream>
#define filename "save file.txt"
using namespace std;
class Item
{
protected:
	//�������������࣬���㴴����ͬ����
	int kind;
	int ID;
	string author;
	//�����ִ����������Ӱ�ȫ
	int rate;
	string title;
public:
	virtual void showInfo() = 0;
	virtual void add(int id) = 0;
	//�޸�
	virtual void modify() = 0;
	//����
	virtual void save() = 0;
	//virtual Item* read() = 0;

	int Rate();
	//��ʾ�ּ�
	string showRate(int rate);

	//��ȡtitle
	string showTitle();

	//��ȡ����
	int showKind();

	//��ȡ���
	int showID();

	//��ȡ���
	string showKindName(int kind); 
	string showAuthor();

	//virtual void test01();
};


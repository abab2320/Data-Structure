#pragma once
#include <iostream>
#include <fstream>
#define filename "save file.txt"
using namespace std;
class Item
{
protected:
	//用数字区分种类，方便创建不同的类
	int kind;
	int ID;
	string author;
	//用数字代表评级更加安全
	int rate;
	string title;
public:
	virtual void showInfo() = 0;
	virtual void add(int id) = 0;
	//修改
	virtual void modify() = 0;
	//保存
	virtual void save() = 0;
	//virtual Item* read() = 0;

	int Rate();
	//显示分级
	string showRate(int rate);

	//获取title
	string showTitle();

	//获取种类
	int showKind();

	//获取编号
	int showID();

	//获取类别
	string showKindName(int kind); 
	string showAuthor();

	//virtual void test01();
};


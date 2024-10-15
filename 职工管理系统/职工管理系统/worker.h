#pragma once
#include <iostream>
#include <string>
using namespace std;
class worker
{
public:
	string name;
	int ID;
	int depID;

	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDepartment() = 0;
};


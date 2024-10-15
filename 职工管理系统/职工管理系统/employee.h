#pragma once
#include <iostream>
#include "worker.h"
class employee:public worker
{
public:
	employee(int ID, string name, int depID);
	//显示个人信息
	void showInfo();

	//获取岗位名称
	string getDepartment();
};


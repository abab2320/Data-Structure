#pragma once
#include <iostream>
#include "worker.h"
class boss:public worker
{
public:
	boss(int ID, string name, int depID);
	//显示个人信息
	void showInfo();

	//获取岗位名称
	string getDepartment();
};


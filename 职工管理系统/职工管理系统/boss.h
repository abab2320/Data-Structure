#pragma once
#include <iostream>
#include "worker.h"
class boss:public worker
{
public:
	boss(int ID, string name, int depID);
	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDepartment();
};


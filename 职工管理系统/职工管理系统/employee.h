#pragma once
#include <iostream>
#include "worker.h"
class employee:public worker
{
public:
	employee(int ID, string name, int depID);
	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDepartment();
};


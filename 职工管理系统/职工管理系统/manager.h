#pragma once
#include <iostream>
#include"worker.h"
class manager :public worker
{
public:
	manager(int ID, string name, int depID);
	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDepartment();
};


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

	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDepartment() = 0;
};


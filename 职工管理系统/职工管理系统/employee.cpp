#include "employee.h"

employee::employee(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}

//��ʾ������Ϣ
void employee::showInfo()
{
	cout << "ְ����ţ�" << ID << "\tְ��������" << name
		<< "\t��λ��" << getDepartment() 
		<<"\t��λְ����ɾ�����������"<<endl;
}

//��ȡ��λ����
string employee::getDepartment()
{
	return string("Ա��");
}

#include "boss.h"

boss::boss(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}

//��ʾ������Ϣ
void boss::showInfo()
{
	cout << "ְ����ţ�" << ID << "\tְ��������" << name
		<< "\t��λ��" << getDepartment()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

//��ȡ��λ����
string boss::getDepartment()
{
	return string("�ϰ�");
}

#include "manager.h"

manager::manager(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}
//��ʾ������Ϣ
void manager:: showInfo()
{
	cout << "ְ����ţ�" << ID << "\tְ��������" << name
		<< "\t��λ��" << getDepartment()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;

}

//��ȡ��λ����
string manager:: getDepartment()
{
	return string("����");
}

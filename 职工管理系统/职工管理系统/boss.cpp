#include "boss.h"

boss::boss(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}

//显示个人信息
void boss::showInfo()
{
	cout << "职工编号：" << ID << "\t职工姓名：" << name
		<< "\t岗位：" << getDepartment()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

//获取岗位名称
string boss::getDepartment()
{
	return string("老板");
}

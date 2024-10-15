#include "manager.h"

manager::manager(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}
//显示个人信息
void manager:: showInfo()
{
	cout << "职工编号：" << ID << "\t职工姓名：" << name
		<< "\t岗位：" << getDepartment()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;

}

//获取岗位名称
string manager:: getDepartment()
{
	return string("经理");
}

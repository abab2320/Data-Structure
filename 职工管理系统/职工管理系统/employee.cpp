#include "employee.h"

employee::employee(int id, string name, int did)
{
	this->name = name;
	this->ID = id;
	this->depID = did;
}

//显示个人信息
void employee::showInfo()
{
	cout << "职工编号：" << ID << "\t职工姓名：" << name
		<< "\t岗位：" << getDepartment() 
		<<"\t岗位职责：完成经理交给的任务"<<endl;
}

//获取岗位名称
string employee::getDepartment()
{
	return string("员工");
}

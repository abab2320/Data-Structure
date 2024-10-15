#include "workerManager.h"
#include <iostream>
#include <string>
using namespace std;



workerManager::workerManager()
{
	//文件不存在，第一次使用
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化指针
		this->EmpArry = NULL;
		//初始化人数
		this->Empnum = 0;
		//初始化文件是否为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化指针
		this->EmpArry = NULL;
		//初始化人数
		this->Empnum = 0;
		//初始化文件是否为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	else//文件存在且不为空
	{
		int num = this->get_Empnum();
		//cout << "职工人数为" << num << endl;
		this->Empnum = num;
		//开辟空间
		this->EmpArry = new worker* [this->Empnum];
		//将文件中的数据存到数组中
		this->init_Emp();
	}
}
int workerManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	
	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数变量
		num++;
	}
	return num;
}

//将文档中的信息录入程序
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int did;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* wo = NULL;

		if (did == 1)//普通职工
		{
			wo = new employee(id, name, 1);
		}
		else if (did == 2)//经理
		{
			wo = new manager(id, name, 2);
		}
		else if (did == 3)//员工
		{
			wo = new boss(id, name, 3);
		}
		this->EmpArry[i] = wo;
		i++;
	}
	ifs.close();
}

int workerManager::IsExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->Empnum; i++)
	{
		if (id == this->EmpArry[i]->ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::Show_Menu()
{
	cout << "欢迎使用职工管理系统" << endl;
	cout << "*****0.退出管理系统" << endl;
	cout << "*****1.增加职工信息" << endl;
	cout << "*****2.显示职工信息" << endl;
	cout << "*****3.删除离职职工" << endl;
	cout << "*****4.修改职工信息" << endl;
	cout << "*****5.查找职工信息" << endl;
	cout << "*****6.按照编号排序" << endl;
	cout << "*****7.清理所有文档" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void workerManager::Add_Emp()
{
	cout << "请输入添加的职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)//添加
	{
		//计算添加的新的空间大小
		int newSize = this->Empnum + addNum;

		//开辟新空间
		worker** newSpace = new worker * [newSize];

		//将原来空间的数据加入新空间中
		if (this->EmpArry != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				newSpace[i] = this->EmpArry[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << "个新职工的编号：" << endl;
			while (true)
			{
				cin >> id;
				if (this->IsExit(id) == -1)
				{
					break;
				}
				else
				{
					cout << "职工编号重复，请重新输入:" << endl;
				}
				
			}
			cout << "请输入第 " << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			while (true)
			{
				cout << "请选择该职工的岗位" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) break;
				else cout << "输入错误，请重新输入" << endl;
			}
			worker* wo = NULL;
			switch (dSelect)
			{
			case 1:
				wo = new employee(id, name, 1);
				break;
			case 2:
				wo = new manager(id, name, 2);
				break;
			case 3:
				wo = new boss(id, name, 3);
				break;
			}
			//将创建的职工指针保持到数组中
			newSpace[this->Empnum + i] = wo;
		}
		
		//释放原有的空间
		delete[]this->EmpArry;

		//更改新空间的指向
		this->EmpArry = newSpace;
		//更新职工人数
		this->Empnum = newSize;

		//更新职工不为空的情况
		this->FileIsEmpty = false;
		//提示
		cout << "成功添加" << addNum << "名新员工" << endl;
	}
	else {
		cout << "输入错误" << endl;
		return;
	}

	//将数据保存在文件中
	this->save();
}


void workerManager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//以输出的方式打开文件，写文件

	//将每个人的信息写入文件中
	for (int i = 0; i < this->Empnum; i++)
	{
		ofs << this->EmpArry[i]->ID << " " << this->EmpArry[i]->name << " " << this->EmpArry[i]->depID << endl;
	}
	ofs.close();
}

void workerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->Empnum; i++)
		{
			this->EmpArry[i]->showInfo();
		}
	}
	//按任意键后清屏
	
	
}

//删除职工  数组中的数据删除，本质上就是数据前移
void workerManager::del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照员工编号删除员工
		cout << "请输入想要删除的员工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);

		if (index != -1)//说明职工是否存在，并且删除该员工
		{
			for (int i = index; i < this->Empnum; i++)
			{
				this->EmpArry[i] = this->EmpArry[i++];
			}
			this->Empnum--;//更新数组中记录的人员
			//更新到文件中
			this->save();

			cout << "删除成功" << endl;

		}
		else
		{
			cout << "删除失败，未找到该员工" << endl;
		}
	}
	
}

void workerManager::mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			delete this->EmpArry[index];
			int newID;
			string newName;
			int newdid;

			cout << "查到" << id << "号员工，请输入新工号：" << endl;
			cin >> newID;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新职务：" << endl;
			cout << "1、普通职工" << endl << "2、经理" << endl << "3、老板" << endl;
			cin >> newdid;

			worker* wo = NULL;
			if (newdid == 1)
			{
				wo = new employee(newID, newName, 1);
			}
			else if (newdid == 2)
			{
				wo = new manager(newID, newName, 2);
			}
			else if (newdid == 3)
			{
				wo = new boss(newID, newName, 3);
			}
			this->EmpArry[index] = wo;
			cout << "修改成功" << this->EmpArry[index]->depID << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
}
void workerManager::find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要的查找方式" << endl;
		cout << "1、按编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select;
		while (true)
		{	
			cin >> select;
			if (select == 1 || select == 2) break;
			else cout << "输入错误，请重新输入" << endl;
		}
		if (select == 1)
		{
			cout << "请输入想要查找的编号" << endl;
			int id;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret == -1)
			{
				cout << "查无此人" << endl;
			}
			else 
			{
				this->EmpArry[ret]->showInfo();
				return;
			}
		}
		else if (select == 2)
		{
			cout << "请输入想要查找的名字：" << endl;
			string name;
			cin >> name;
			
			int flag = 0;
			for (int i = 0; i < this->Empnum; i++)
			{
				if (this->EmpArry[i]->name == name)
				{
					this->EmpArry[i]->showInfo();
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "查无此人" << endl;
			}
		}
	}
}

void workerManager::sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择你想要的排序方式" << endl;
		cout << "1、从大到小" << endl;
		cout << "2、从小到大" << endl;
		int select;
		while (true)
		{
			cin >> select;
			if (select == 1 || select == 2) break;
			else cout << "输入错误，请重新输入" << endl;
		}
		this->bubble();
		if (select == 1)
		{
			for (int i = this->Empnum - 1; i >= 0; i--)
			{
				this->EmpArry[i]->showInfo();
			}		
		}
		else
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				this->EmpArry[i]->showInfo();
			}
		}
	}
}

void workerManager::bubble()
{
	for (int i = 0; i < this->Empnum; i++)
	{
		int flag = 0;
		for (int j = 0; j < this->Empnum -i-1; j++)
		{
			if (this->EmpArry[j]->ID > this->EmpArry[j + 1]->ID)
			{
				worker* temp = this->EmpArry[j];
				this->EmpArry[j] = this->EmpArry[j + 1];
				this->EmpArry[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void workerManager::clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(filename, ios::trunc);
		ofs.close();

		if (this->EmpArry != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				if (this->EmpArry[i] != NULL)
				{
					delete this->EmpArry[i];
				}
			}
			this->Empnum = 0;
			delete[]this->EmpArry;
			this->EmpArry = NULL;
			this->FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
}

workerManager::~workerManager()
{
	if (this->EmpArry != NULL)
	{
		for (int i = 0; i < this->Empnum; i++)
		{
			if (this->EmpArry[i] != NULL)
			{
				delete this->EmpArry[i];
			}
		}
		this->Empnum = 0;
		delete[]this->EmpArry;
		this->EmpArry = NULL;
		this->FileIsEmpty = true;
	}
}
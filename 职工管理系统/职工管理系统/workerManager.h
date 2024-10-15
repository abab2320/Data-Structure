#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define filename "empFile.txt"
using namespace std;

class workerManager
{
public:
	//标志文件是否为空
	bool FileIsEmpty;
	//统计人数
	int get_Empnum();
	//初始化员工数组
	void init_Emp();
	//记录职工人数
	int Empnum;
	//职工数组指针
	worker** EmpArry;

	workerManager();
	//判断职工是否存在
	int IsExit(int id);
	
	//显示菜单
	void Show_Menu();
	//添加员工
	void Add_Emp();
	//保存文件
	void save();
	//显示员工、
	void show_Emp();
	//删除职工
	void del_Emp();
	//修改员工
	void mod_Emp();
	//查找员工
	void find_Emp();
	//排序职工
	void sort_Emp();
	//清空文件
	void clean_File();
	void exitSystem();

	//冒泡排序
	void bubble();
	~workerManager();
};


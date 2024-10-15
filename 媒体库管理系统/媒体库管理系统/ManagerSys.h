#pragma once
#include "Item.h"
#include <iostream>
//显示媒体库中管理的物品种类，方便后期修改
#define kinds 3 
using namespace std;

class ManagerSys
{
public:
	//记录每种分别的数量
	int num[kinds] = {0};
	int All = 0;
	//用父类指针的数组指向每一个对象
	Item** itemArry;
	//确认文件存在且记录不为空
	bool FileisExit;

	//构造函数
	ManagerSys();
	
	void show_menu();
	void Exist();


	//添加物品
	void Add_item();
	//显示物品
	void Show_item();
	//查询物品
	void Find_item();
	void Find_title();
	
	//排序显示
	void Sort_item();
	//按编号排序
	void bubble();
	//按作者显示
	void Sort_author();
	//按评级显示
	void Sort_rate();

	//按照编号删除物品
	void Del_item();

	//显示物品的信息
	void Sta_item();
	//统计各类评级的作品数量
	void Sta_rate();
	//修改物品的信息
	void Mod_item();
	//保存信息
	void Save_item();
	//清空系统
	void Clean_item();


	int get_num();
	int Find_ID(int id);



	~ManagerSys();
};


#include <iostream>
#include "ManagerSys.h"
using namespace std;

//执行程序的主函数
int main()
{
	ManagerSys ms;
	while (true)
	{
		ms.show_menu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//添加物品
			ms.Add_item();
			break;
		case 2:
			//查询物品
			ms.Find_item();
			break;
		case 3:
			//显示所有物品
			ms.Show_item();
			break;
		case 4:
			//按一定条件显示物品
			ms.Sort_item();
			break;
		case 5:
			//删除物品
			ms.Del_item();
			break;
		case 6:
			//显示当前库存的基本信息
			ms.Sta_item();
			break;
		case 7:
			//修改信息
			ms.Mod_item();
			break;
		case 8:
			//清空数据
			ms.Clean_item();
			break;
		case 0:
			//退出程序
			ms.Exist();
			break;
		}

		system("pause");
		system("cls");
	}
	return 0;
}
#include <iostream>
#include "ManagerSys.h"
using namespace std;

//ִ�г����������
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
			//�����Ʒ
			ms.Add_item();
			break;
		case 2:
			//��ѯ��Ʒ
			ms.Find_item();
			break;
		case 3:
			//��ʾ������Ʒ
			ms.Show_item();
			break;
		case 4:
			//��һ��������ʾ��Ʒ
			ms.Sort_item();
			break;
		case 5:
			//ɾ����Ʒ
			ms.Del_item();
			break;
		case 6:
			//��ʾ��ǰ���Ļ�����Ϣ
			ms.Sta_item();
			break;
		case 7:
			//�޸���Ϣ
			ms.Mod_item();
			break;
		case 8:
			//�������
			ms.Clean_item();
			break;
		case 0:
			//�˳�����
			ms.Exist();
			break;
		}

		system("pause");
		system("cls");
	}
	return 0;
}
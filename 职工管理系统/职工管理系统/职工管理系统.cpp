#include <iostream>
#include "workerManager.h"
using namespace std;

int main()
{
	workerManager wm;
	while (true)
	{
		wm.Show_Menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.del_Emp();
			break;
		case 4:
			wm.mod_Emp();
			break;
		case 5:
			wm.find_Emp();
			break;
		case 6:
			wm.sort_Emp();
			break;
		case 7:
			wm.clean_File();
			break;
		}

		system("pause");
		system("cls");
	}
	return 0;
}
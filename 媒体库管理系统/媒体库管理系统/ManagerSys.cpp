#include "ManagerSys.h"
#include "Book.h"
#include"Picture.h"
#include "Video.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define INVENTORY 100 //库存为100，方便后期修改
#define filename "save file.txt"

ManagerSys::ManagerSys()
{
	//对数组进行初始化
	//判断是否有
	fstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		this->FileisExit = false;
	}
	else
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			this->FileisExit = false;
		}
		else
		{
			this->FileisExit = true;
		}
		ifs.close();
	}

	if (!this->FileisExit)
	{	//初始化个数
		All = 0;
		//初始化数组
		this->itemArry = NULL;
	}
	else
	{
		All = get_num();
		//cout << "All = " << All;
		this->itemArry = new Item * [All];
		ifstream ifs;
		ifs.open(filename, ios::in);
		int kind; int ID; string title; string author; int rate;
		for (int i = 0; i < All; i++)
		{
			Item* item = NULL;
			if (ifs >> kind && ifs >> ID && ifs >> title && ifs >> author && ifs >> rate)
			{
				/*cout << "kind = " << kind;
				cout << "rate = " << rate;*/
			
				if (kind == 1)
				{
					string press; string ISBN; int page;
					ifs >> press;
					ifs >> ISBN;
					ifs >> page;
					num[0]++;
					//cout << "press = " << press;
					item = new Book(ID, title, author, rate, press, ISBN, page);
				}
				else if (kind == 2)
				{
					string producer; string year; string time;
					ifs >> producer;
					ifs >> year;
					ifs >> time;
					num[1]++;
					item = new Video(ID, title, author, rate, producer,year,time);

				}
				else if (kind == 3)
				{
					string nation; string length, wide;
					ifs >> nation;
					ifs >> length;
					ifs >> wide;
					num[2]++;
					item = new Picture(ID, title, author, rate, nation, length, wide);
				}
				this->itemArry[i] = item;
			}
		
		}
	}
}

//获得文件中物品的数量
int ManagerSys::get_num()
{
	int num = 0;
	ifstream ifs;
	ifs.open(filename, ios::in);
	string line;
	while (getline(ifs, line))
	{
		num++;
	}

	return num-1;
}

//显示系统功能
void ManagerSys::show_menu() 
{
	cout << "欢迎使用媒体库管理系统" << endl;	
	cout << "1、添加物品" << endl;
	cout << "2、查询物品" << endl;
	cout << "3、显示物品" << endl;
	cout << "4、排序显示" << endl;
	cout << "5、删除物品" << endl;
	cout << "6、统计信息" << endl;
	cout << "7、修改物品" << endl;
	cout << "8、清空系统" << endl;
	cout << "0、退出系统" << endl;
	cout << "请选择您要使用的功能：" << endl;
}


//退出程序
void ManagerSys::Exist()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加物品
void ManagerSys::Add_item()
{
	if (All >= INVENTORY)
	{
		cout << "库存已满，无法添加" << endl;
	}
	else
	{
		cout << "请输入想要添加的物品数量" << endl;
		cout << "0——返回" << endl;
		int newNum;
		while (true)
		{
			cin >> newNum;
			if (newNum == 0) return;
			else if (newNum < 0) cout << "输入错误，请重新输入" << endl;
			else if (newNum > 0) break;
		}
		/*cout << "here" << endl;
		cout << "newNum=" << newNum;*/

		Item** newSpace = new Item * [newNum + All];

		if (this->itemArry != NULL)
		{
			for (int i = 0; i < All; i++)
			{
				newSpace[i] = this->itemArry[i];
			}
		}

		for (int i = 0; i < newNum; i++)
		{
			cout << "请选择第" << i + 1 << "个物品的信息" << endl;
			cout << "类别：" << endl;
			cout << "1——图书" << "\t2——视频光盘" << "\t3——图画" << endl;
			int select;
			cin >> select;
			
			
			int id;
			cout << "编号：" << endl;
			while (true)
			{
				cin >> id;
				if (this->Find_ID(id) == -1) break;
				else cout << "编号已存在，请重新输入" << endl;
			}
			/*cout << "id =" << id;*/

			Item* item = NULL;
			switch (select)
			{
			case 1:
				item = new Book;
				item->add(id);
				num[0]++;
				break;
			case 2:
				item = new Video;
				item->add(id);
				num[1]++;
				break;
			case 3:
				item = new Picture;
				item->add(id);
				num[2]++;
				break;
			}
			newSpace[All + i] = item;
		}

		delete[]this->itemArry;
		this->itemArry = newSpace;

		All = All + newNum;
		cout << "添加完成" << endl;

		this->FileisExit = true;
		//cout << "All = " << All;
	}

}


//显示物品
void ManagerSys::Show_item()
{
	if (!FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	
	for (int i = 0; i < All; i++)
	{
		this->itemArry[i]->showInfo();
	}
}


void ManagerSys::Find_item()
{
	if (!this->FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}

	cout << "请选择查询方式" << endl;
	cout << "1——按标题查询" << endl;
	cout << "2——按编号查询" << endl;
	cout << "3——按类别查询" << endl;
	cout << "0——返回" << endl;
	int select;
	cin >> select;

	switch (select)
	{
	case 0:
		return;
	case 1:
		this->Find_title();
		break;
	case 2:
	{
		cout << "请输入想要查询的编号" << endl;
		int id;
		cin >> id;
		int i = Find_ID(id);
		if (i == -1)
		{
			cout << "编号不存在" << endl;
		}
		else
		{
			this->itemArry[i]->showInfo();
		}
	}
		break;
	case 3:
		cout << "请输入想查询的类别" << endl;
		cout << "1——图书" << endl << "2——视频光盘" << endl << "3——图画" << endl;
		int select;
		cin >> select;
		int flag = 0;

		//cout << "select = " << select<<endl;
		for (int i = 0; i < All; i++)
		{
			//cout << this->itemArry[i]->showKind()<<endl;
			if (select == this->itemArry[i]->showKind())
			{
				this->itemArry[i]->showInfo();
				flag = 1;
			}
		}

		if (flag == 0)
		{
			cout << "类别不存在" << endl;
		}
		break;
	}
}

void ManagerSys::Save_item()
{
	for (int i = 0; i < All; i++)
	{
		this->itemArry[i]->save();
	}
}

void ManagerSys::Find_title()
{
	cout << "请输入想要查询的标题" << endl;
	string temp;
	cin >> temp;

	//标记是否找到
	int flag = 0;
	for (int i = 0; i < All; i++)
	{
		if (temp == this->itemArry[i]->showTitle())
		{
			this->itemArry[i]->showInfo();
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "该标题不存在！" << endl;
	}
}

int ManagerSys::Find_ID(int id)
{
	if (!FileisExit)
	{
		return -1;
	}
	int ret = -1;
	for (int i = 0; i < All; i++)
	{
		if (this->itemArry[i]->showID() == id)
		{
			ret = i;
		}
	}

	return ret;
}

void ManagerSys::Sort_item()
{
	if (!this->FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
	}

	cout << "请选择排序方式" << endl;
	cout << "1——按编号排序" << endl;
	cout << "2——按作者排序" << endl;
	cout << "3——按评级排序" << endl;
	cout << "0——返回" << endl;

	int select;
	cin >> select;
	int choice;
	switch (select)
	{
	case 1:
		cout << "请选择具体的排序方式" << endl;
		cout << "1——从大到小" << endl;
		cout << "2——从小到大" << endl;
		cin >> choice;
		bubble();
		if (choice == 1)
		{
			for (int i = All - 1; i >= 0; i--)
			{
				this->itemArry[i]->showInfo();
			}
		}
		else if(choice == 2)
		{
			for (int i = 0; i < All; i++)
			{
				this->itemArry[i]->showInfo();
			}
		}
		break;

	case 2:
		this->Sort_author();
		break;
	case 3:
		this->Sort_rate();
		break;
	}
}


void ManagerSys::Del_item()
{
	if (!this->FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	else
	{
		cout << "请输入想要删除的物品的编号" << endl;
		cout << "0——返回" << endl;

		int id;
		cin >> id;
		
		if (id == 0)return;

		int ret = this->Find_ID(id);

		if (ret == -1)
		{
			cout << "编号不存在" << endl;
		}
		else
		{
			//用后面的将前面的覆盖
			for (int i = ret; i < All-1; i++)
			{
				this->itemArry[i] = this->itemArry[i + 1];
			}

			cout << "删除成功" << endl;
		}
	}
}

void ManagerSys::bubble()
{
	for (int i = 0; i < All; i++)
	{
		int flag = 0;
		for(int j = 0;j<All-i-1;j++)
		{
			if (this->itemArry[j] > this->itemArry[j + 1])
			{
				Item* temp = this->itemArry[j];
				this->itemArry[j] = this->itemArry[j + 1];
				this->itemArry[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
		
	}
}

void ManagerSys::Sort_rate()
{
	cout << "请输入想要显示的评级" << endl;
	cout << "1——未评级" << endl;
	cout << "2——一般" << endl;
	cout << "3——成人" << endl;
	cout << "4——儿童" << endl;
	int a;
	cin >> a;
	for (int i = 0; i < All; i++)
	{
		if (this->itemArry[i]->Rate() == a)
		{
			this->itemArry[i]->showInfo();
			//this->itemArry[i]->test01();
		}
	}
}

void ManagerSys::Sort_author()
{
	cout << "请输入想显示的作者" << endl;
	string a;
	cin >> a;
	for (int i = 0; i < All; i++)
	{
		if (this->itemArry[i]->showAuthor() == a)
		{
			this->itemArry[i]->showInfo();
		}
	}
}

void ManagerSys::Sta_item()
{
	cout << "物品库中的物品数量" << endl;
	cout << "总数量：" << All << endl;
	cout << "图书的数量：" << this->num[0] << endl;
	cout << "视频光盘的数量：" << this->num[1] << endl;
	cout << "图画的数量：" << this->num[2] << endl;

	cout << "请选择是否查看更多统计信息" << endl;
	cout << "1——返回" << endl;
	cout << "2——查看更多" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2) break;
		else cout << "输入错误，请重新输入" << endl;
	}
	if (select == 1)
	{
		return;
	}
	else
	{
		this->Sta_rate();
	}
}

void ManagerSys::Sta_rate()
{
	int a, b, c, d;
	a = b = c = d = 0;
	for (int i = 0; i < All; i++)
	{
		switch (this->itemArry[i]->Rate())
		{
		case 1:
			a++;
			break;
		case 2:
			b++;
			break;
		case 3:
			c++;
			break;
		case 4:
			d++;
			break;
		}
	}
	cout << "未评级作品数：" << a << endl;
	cout << "一般评级作品数：" << b << endl;
	cout << "成人评级作品数：" << c << endl;
	cout << "儿童评级作品数：" << d << endl;

}

void ManagerSys::Mod_item()
{
	if (!this->FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int flag = 1;
		while (flag == 1)
		{
			cout << "请输入想要修改的物品的编号" << endl;
			cout << "0——返回" << endl;
			int id;
			cin >> id;
			if (id == 0) return;
			else
			{
				int ret = this->Find_ID(id);
				if (ret == -1)
				{
					cout << "物品编号不存在" << endl;
				}
				else
				{
					this->itemArry[ret]->modify();
					cout << "修改成功" << endl;

					cout << "是否继续修改" << endl;
					cout << "1——是" << endl;
					cout << "0——否" << endl;
					cin >> flag;
				}
			}
		}


		//更新文件
		ofstream ofs;
		ofs.open(filename, ios::trunc);
		ofs.close();

		this->Save_item();
	
	}
}

void ManagerSys::Clean_item()
{
	if (!FileisExit)
	{
		cout << "文件不存在或记录为空" << endl;
		return;
	}
	else
	{
		cout << "是否要清空所有数据" << endl;
		cout << "1——是" << endl;
		cout << "2——否" << endl;
		int choice;
		cin >> choice;

		if (choice == 0) return;
		else if (choice == 1)
		{
			ofstream ofs;
			ofs.open(filename, ios::trunc);
			ofs.close();

			if (this->itemArry != NULL)
			{
				for (int i = 0; i < All; i++)
				{
					delete this->itemArry[i];
				}

				All = 0;
				delete[]this->itemArry;
				this->itemArry = NULL;
				this->FileisExit = false;
			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
}

ManagerSys::~ManagerSys()
{
	if (this->itemArry != NULL)
	{
		for (int i = 0; i < All; i++)
		{
			delete this->itemArry[i];
		}

		All = 0;
		delete[]this->itemArry;
		this->itemArry = NULL;
		this->FileisExit = false;
	}
}
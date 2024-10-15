#include "ManagerSys.h"
#include "Book.h"
#include"Picture.h"
#include "Video.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define INVENTORY 100 //���Ϊ100����������޸�
#define filename "save file.txt"

ManagerSys::ManagerSys()
{
	//��������г�ʼ��
	//�ж��Ƿ���
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
	{	//��ʼ������
		All = 0;
		//��ʼ������
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

//����ļ�����Ʒ������
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

//��ʾϵͳ����
void ManagerSys::show_menu() 
{
	cout << "��ӭʹ��ý������ϵͳ" << endl;	
	cout << "1�������Ʒ" << endl;
	cout << "2����ѯ��Ʒ" << endl;
	cout << "3����ʾ��Ʒ" << endl;
	cout << "4��������ʾ" << endl;
	cout << "5��ɾ����Ʒ" << endl;
	cout << "6��ͳ����Ϣ" << endl;
	cout << "7���޸���Ʒ" << endl;
	cout << "8�����ϵͳ" << endl;
	cout << "0���˳�ϵͳ" << endl;
	cout << "��ѡ����Ҫʹ�õĹ��ܣ�" << endl;
}


//�˳�����
void ManagerSys::Exist()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//�����Ʒ
void ManagerSys::Add_item()
{
	if (All >= INVENTORY)
	{
		cout << "����������޷����" << endl;
	}
	else
	{
		cout << "��������Ҫ��ӵ���Ʒ����" << endl;
		cout << "0��������" << endl;
		int newNum;
		while (true)
		{
			cin >> newNum;
			if (newNum == 0) return;
			else if (newNum < 0) cout << "�����������������" << endl;
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
			cout << "��ѡ���" << i + 1 << "����Ʒ����Ϣ" << endl;
			cout << "���" << endl;
			cout << "1����ͼ��" << "\t2������Ƶ����" << "\t3����ͼ��" << endl;
			int select;
			cin >> select;
			
			
			int id;
			cout << "��ţ�" << endl;
			while (true)
			{
				cin >> id;
				if (this->Find_ID(id) == -1) break;
				else cout << "����Ѵ��ڣ�����������" << endl;
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
		cout << "������" << endl;

		this->FileisExit = true;
		//cout << "All = " << All;
	}

}


//��ʾ��Ʒ
void ManagerSys::Show_item()
{
	if (!FileisExit)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}

	cout << "��ѡ���ѯ��ʽ" << endl;
	cout << "1�����������ѯ" << endl;
	cout << "2��������Ų�ѯ" << endl;
	cout << "3����������ѯ" << endl;
	cout << "0��������" << endl;
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
		cout << "��������Ҫ��ѯ�ı��" << endl;
		int id;
		cin >> id;
		int i = Find_ID(id);
		if (i == -1)
		{
			cout << "��Ų�����" << endl;
		}
		else
		{
			this->itemArry[i]->showInfo();
		}
	}
		break;
	case 3:
		cout << "���������ѯ�����" << endl;
		cout << "1����ͼ��" << endl << "2������Ƶ����" << endl << "3����ͼ��" << endl;
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
			cout << "��𲻴���" << endl;
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
	cout << "��������Ҫ��ѯ�ı���" << endl;
	string temp;
	cin >> temp;

	//����Ƿ��ҵ�
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
		cout << "�ñ��ⲻ���ڣ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}

	cout << "��ѡ������ʽ" << endl;
	cout << "1�������������" << endl;
	cout << "2��������������" << endl;
	cout << "3��������������" << endl;
	cout << "0��������" << endl;

	int select;
	cin >> select;
	int choice;
	switch (select)
	{
	case 1:
		cout << "��ѡ����������ʽ" << endl;
		cout << "1�����Ӵ�С" << endl;
		cout << "2������С����" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "��������Ҫɾ������Ʒ�ı��" << endl;
		cout << "0��������" << endl;

		int id;
		cin >> id;
		
		if (id == 0)return;

		int ret = this->Find_ID(id);

		if (ret == -1)
		{
			cout << "��Ų�����" << endl;
		}
		else
		{
			//�ú���Ľ�ǰ��ĸ���
			for (int i = ret; i < All-1; i++)
			{
				this->itemArry[i] = this->itemArry[i + 1];
			}

			cout << "ɾ���ɹ�" << endl;
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
	cout << "��������Ҫ��ʾ������" << endl;
	cout << "1����δ����" << endl;
	cout << "2����һ��" << endl;
	cout << "3��������" << endl;
	cout << "4������ͯ" << endl;
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
	cout << "����������ʾ������" << endl;
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
	cout << "��Ʒ���е���Ʒ����" << endl;
	cout << "��������" << All << endl;
	cout << "ͼ���������" << this->num[0] << endl;
	cout << "��Ƶ���̵�������" << this->num[1] << endl;
	cout << "ͼ����������" << this->num[2] << endl;

	cout << "��ѡ���Ƿ�鿴����ͳ����Ϣ" << endl;
	cout << "1��������" << endl;
	cout << "2�����鿴����" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2) break;
		else cout << "�����������������" << endl;
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
	cout << "δ������Ʒ����" << a << endl;
	cout << "һ��������Ʒ����" << b << endl;
	cout << "����������Ʒ����" << c << endl;
	cout << "��ͯ������Ʒ����" << d << endl;

}

void ManagerSys::Mod_item()
{
	if (!this->FileisExit)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int flag = 1;
		while (flag == 1)
		{
			cout << "��������Ҫ�޸ĵ���Ʒ�ı��" << endl;
			cout << "0��������" << endl;
			int id;
			cin >> id;
			if (id == 0) return;
			else
			{
				int ret = this->Find_ID(id);
				if (ret == -1)
				{
					cout << "��Ʒ��Ų�����" << endl;
				}
				else
				{
					this->itemArry[ret]->modify();
					cout << "�޸ĳɹ�" << endl;

					cout << "�Ƿ�����޸�" << endl;
					cout << "1������" << endl;
					cout << "0������" << endl;
					cin >> flag;
				}
			}
		}


		//�����ļ�
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "�Ƿ�Ҫ�����������" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
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
			cout << "�������" << endl;
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
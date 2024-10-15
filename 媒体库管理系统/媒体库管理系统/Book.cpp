#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;

void Book::showInfo()
{
	cout<<"���ͼ��"<< "\t��ţ�" << this->ID << "\t���⣺" << this->title << "\t���ߣ�" << this->author
		<< "\t�����磺" << this->press << "\tISBN���룺" << this->ISBN << "\tҳ  ����" << this->page
		<< "\t������" << showRate(rate) << endl;

}

void Book::modify()
{
	this->showInfo();
	cout << "�������޸ĺ������" << endl;
	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "�����磺" << endl;
	cin >> this->press;

	cout << "ISBN��" << endl;
	cin >> this->ISBN;

	cout << "ҳ����" << endl;
	while (true)
	{
		cin >> this->page;
		if (page <= 0)
		{
			cout << "�����������������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������" << endl;
	cout << "1����δ����" << endl;
	cout << "2����һ��" << endl;
	cout << "3��������" << endl;
	cout << "4������ͯ" << endl;
	
	while (true)
	{
		cin >> this->rate;
		if (rate == 1 || rate == 2 || rate == 3 || rate == 4) break;
		else cout << "�����������������" << endl;
	}
}

Book::Book()
{
	//kind = 1;
}
Book::Book(int ID, string title, string author, int rate, string press, string ISBN, int page)
{
	this->kind = 1;
	this->ID = ID;
	this->title = title;
	this->author = author;
	this->press = press;
	this->ISBN = ISBN;
	this->page = page;
	this->rate = rate;
}

//�ȴ����ն����ٳ�ʼ��
void Book::add(int ID)
{
	kind = 1;
	this->ID = ID;
	
	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "�����磺" << endl;
	cin >> this->press;

	cout << "ISBN��" << endl;
	cin >> this->ISBN;

	cout << "ҳ����" << endl;
	while (true)
	{
		cin >> this->page;
		if (page <= 0)
		{
			cout << "�����������������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������" << endl;
	cout << "1����δ����" << endl;
	cout << "2����һ��" << endl;
	cout << "3��������" << endl;
	cout << "4������ͯ" << endl;
	while (true)
	{
		cin >> this->rate;
		if (rate == 1 || rate == 2 || rate == 3 || rate == 4) break;
		else cout << "�����������������" << endl;
	}

	//������ͬʱ����
	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << this->press << " " << this->ISBN << " " << this->page << endl;

	ofs.close();
}

void Book::save()
{
	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << this->press << " " << this->ISBN << " " << this->page << endl;

	ofs.close();
}
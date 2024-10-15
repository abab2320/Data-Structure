#include "Picture.h"
#include <iostream>
using namespace std;

void Picture::showInfo()
{
	cout<<"���ͼ��" << "\t��ţ�" << this->ID << "\t���⣺" << this->title << "\t���ߣ�" << this->author
		<< "\t��Ʒ������" << this->nation << "\t��Ʒ���ȣ�" << this->length << "\t��Ʒ��ȣ�" << this->wide
		<< "\t������" << showRate(rate) << endl;
}


void Picture::modify()
{
	this->showInfo();
	cout << "�������޸ĺ������" << endl;
	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "��Ʒ������" << endl;
	cin >> this->nation;

	cout << "��Ʒ���ȣ�������,��λ���ף���" << endl;
	string a;
	cin >> a;
	while (true)
	{
		bool soga = this->isName(a);
		if (soga) break;
		else cout << "����Ĳ���������������������" << endl;
	}
	this->length = a;

	cout << "��Ʒ��ȣ�����������λ���ף���" << endl;
	string b;
	cin >> b;
	while (true)
	{
		bool soga = this->isName(b);
		if (soga) break;
		else cout << "����Ĳ���������������������" << endl;
	}
	this->wide = b;

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

Picture::Picture(int ID, string title, string author, int rate, string nation, string length,string wide)
{
	this->kind = 3;
	this->ID = ID;
	this->title = title;
	this->author = author;
	this->rate = rate;
	this->nation = nation;
	this->length = length;
	this->wide = wide;
}


Picture::Picture()
{
	//kind = 3;
}

void Picture::add(int ID)
{
	kind = 3;
	this->ID = ID;

	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "��Ʒ������" << endl;
	cin >> this->nation;

	cout << "��Ʒ���ȣ�������,��λ���ף���" << endl;
	string a;
	cin >> a;
	while(true)
	{
		bool soga = this->isName(a);
		if (soga) break;
		else cout << "����Ĳ���������������������" << endl;
	}
	this->length = a;

	cout << "��Ʒ��ȣ�����������λ���ף���" << endl;
	string b;
	cin >> b;
	while (true)
	{
		bool soga = this->isName(b);
		if (soga) break;
		else cout << "����Ĳ���������������������" << endl;
	}
	this->wide = b;

	cout << "������" << endl;
	cout << "1����δ����" << endl;
	cout << "2����һ��" << endl;
	cout << "3��������" << endl;
	cout << "4������ͯ" << endl;
	cin >> this->rate;

	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << nation << " " << length << " " << wide << endl;
	ofs.close();
}

void Picture::save()
{
	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << nation << " " << length << " " << wide << endl;
	ofs.close();

}


bool Picture::isName(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) > '9' || a.at(i) < '0')
		{
			return false;
		}
	}
	return true;
}
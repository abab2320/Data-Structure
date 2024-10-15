#include "Picture.h"
#include <iostream>
using namespace std;

void Picture::showInfo()
{
	cout<<"类别：图画" << "\t编号：" << this->ID << "\t标题：" << this->title << "\t作者：" << this->author
		<< "\t出品国籍：" << this->nation << "\t作品长度：" << this->length << "\t作品宽度：" << this->wide
		<< "\t评级：" << showRate(rate) << endl;
}


void Picture::modify()
{
	this->showInfo();
	cout << "请输入修改后的数据" << endl;
	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出品国籍：" << endl;
	cin >> this->nation;

	cout << "作品长度（正整数,单位厘米）：" << endl;
	string a;
	cin >> a;
	while (true)
	{
		bool soga = this->isName(a);
		if (soga) break;
		else cout << "输入的不是正整数，请重新输入" << endl;
	}
	this->length = a;

	cout << "作品宽度（正整数，单位厘米）：" << endl;
	string b;
	cin >> b;
	while (true)
	{
		bool soga = this->isName(b);
		if (soga) break;
		else cout << "输入的不是正整数，请重新输入" << endl;
	}
	this->wide = b;

	cout << "评级：" << endl;
	cout << "1——未评级" << endl;
	cout << "2——一般" << endl;
	cout << "3——成人" << endl;
	cout << "4——儿童" << endl;
	
	while (true)
	{
		cin >> this->rate;
		if (rate == 1 || rate == 2 || rate == 3 || rate == 4) break;
		else cout << "输入错误，请重新输入" << endl;
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

	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出品国籍：" << endl;
	cin >> this->nation;

	cout << "作品长度（正整数,单位厘米）：" << endl;
	string a;
	cin >> a;
	while(true)
	{
		bool soga = this->isName(a);
		if (soga) break;
		else cout << "输入的不是正整数，请重新输入" << endl;
	}
	this->length = a;

	cout << "作品宽度（正整数，单位厘米）：" << endl;
	string b;
	cin >> b;
	while (true)
	{
		bool soga = this->isName(b);
		if (soga) break;
		else cout << "输入的不是正整数，请重新输入" << endl;
	}
	this->wide = b;

	cout << "评级：" << endl;
	cout << "1——未评级" << endl;
	cout << "2——一般" << endl;
	cout << "3——成人" << endl;
	cout << "4——儿童" << endl;
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
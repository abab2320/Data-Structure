#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;

void Book::showInfo()
{
	cout<<"类别：图书"<< "\t编号：" << this->ID << "\t标题：" << this->title << "\t作者：" << this->author
		<< "\t出版社：" << this->press << "\tISBN号码：" << this->ISBN << "\t页  数：" << this->page
		<< "\t评级：" << showRate(rate) << endl;

}

void Book::modify()
{
	this->showInfo();
	cout << "请输入修改后的数据" << endl;
	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出版社：" << endl;
	cin >> this->press;

	cout << "ISBN：" << endl;
	cin >> this->ISBN;

	cout << "页数：" << endl;
	while (true)
	{
		cin >> this->page;
		if (page <= 0)
		{
			cout << "输入错误，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
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

//先创建空对象，再初始化
void Book::add(int ID)
{
	kind = 1;
	this->ID = ID;
	
	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出版社：" << endl;
	cin >> this->press;

	cout << "ISBN：" << endl;
	cin >> this->ISBN;

	cout << "页数：" << endl;
	while (true)
	{
		cin >> this->page;
		if (page <= 0)
		{
			cout << "输入错误，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
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

	//创建的同时保存
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
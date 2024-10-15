#include "Video.h"


//构造函数
Video::Video(int ID,string title,string author,int rate,string producer,string year,string time)
{
	this->kind = 2;
	this->ID = ID;
	this->title = title;
	this->author = author;
	this->rate = rate;
	this->producer = producer;
	this->year = year;
	this->time = time;
}

Video::Video()
{
	//kind = 2;
}

void Video::showInfo()
{
	cout<<"类别：视频光盘" << "\t编号：" << this->ID << "\t标题：" << this->title << "\t作者：" << this->author
		<< "\t出品者：" << this->producer << "\t出品年份：" << this->year << "\t视频时长：" << this->time
		<< "\t评级：" << showRate(rate) << endl;
}

void Video::modify()
{
	this->showInfo();
	cout << "请输入修改后的信息" << endl;

	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出品者：" << endl;
	cin >> this->producer;

	cout << "出品年份：" << endl;
	cin >> this->year;

	cout << "视频时长：" << endl;
	cin >> this->time;

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


void Video::add(int ID)
{
	kind = 2;
	this->ID = ID;

	cout << "标题：" << endl;
	cin >> this->title;

	cout << "作者：" << endl;
	cin >> this->author;

	cout << "出品者：" << endl;
	cin >> this->producer;

	cout << "出品年份：" << endl;
	cin >> this->year;

	cout << "视频时长：" << endl;
	cin >> this->time;

	cout << "评级：" << endl;
	cout << "1——未评级" << endl;
	cout << "2——一般" << endl;
	cout << "3——成人" << endl;
	cout << "4——儿童" << endl;
	cin >> this->rate;

	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << producer << " " << year << " " << time << endl;
	ofs.close();
}

void Video::save()
{
	ofstream ofs;
	ofs.open(filename, ios::app);
	ofs << this->kind << "\t" << this->ID << "\t" << this->title << "\t" << this->author << "\t"
		<< this->rate << " " << producer << " " << year << " " << time << endl;
	ofs.close();
}
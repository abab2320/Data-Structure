#include "Video.h"


//���캯��
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
	cout<<"�����Ƶ����" << "\t��ţ�" << this->ID << "\t���⣺" << this->title << "\t���ߣ�" << this->author
		<< "\t��Ʒ�ߣ�" << this->producer << "\t��Ʒ��ݣ�" << this->year << "\t��Ƶʱ����" << this->time
		<< "\t������" << showRate(rate) << endl;
}

void Video::modify()
{
	this->showInfo();
	cout << "�������޸ĺ����Ϣ" << endl;

	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "��Ʒ�ߣ�" << endl;
	cin >> this->producer;

	cout << "��Ʒ��ݣ�" << endl;
	cin >> this->year;

	cout << "��Ƶʱ����" << endl;
	cin >> this->time;

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


void Video::add(int ID)
{
	kind = 2;
	this->ID = ID;

	cout << "���⣺" << endl;
	cin >> this->title;

	cout << "���ߣ�" << endl;
	cin >> this->author;

	cout << "��Ʒ�ߣ�" << endl;
	cin >> this->producer;

	cout << "��Ʒ��ݣ�" << endl;
	cin >> this->year;

	cout << "��Ƶʱ����" << endl;
	cin >> this->time;

	cout << "������" << endl;
	cout << "1����δ����" << endl;
	cout << "2����һ��" << endl;
	cout << "3��������" << endl;
	cout << "4������ͯ" << endl;
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
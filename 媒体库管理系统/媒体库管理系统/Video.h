#pragma once
#include "Item.h"
#include <iostream>
using namespace std;
class Video:public Item
{
protected:
	
public:
	string producer;
	string year;
	string time;

	Video();
	Video(int ID, string title, string author, int rate, string producer, string year, string time);
	void add(int id);
	void showInfo();

	//ÐÞ¸Ä
	void modify();
	//±£´æ
	void save();
};


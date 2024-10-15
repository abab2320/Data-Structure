#include "Item.h"

string Item::showRate(int rate)
{
	switch (rate)
	{
	case 1:
		return "未评级";
	case 2:
		return "一般";
	case 3:
		return "成人";
	case 4:
		return "儿童";
	default:
		break;
	}
}

int Item::Rate()
{
	return rate;
}

string Item::showTitle()
{
	return title;
}

int Item::showKind()
{
	return kind;
}

int Item::showID()
{
	return ID;
}

string Item::showAuthor()
{
	return author;
}

string Item::showKindName(int kind)
{
	string a;
	switch (kind)
	{
	case 1:
		a = "图书";
		break;
	case 2:
		a = "视频光盘";
		break;
	case 3:
		a = "图画";
		break;
	}

	return a;
}
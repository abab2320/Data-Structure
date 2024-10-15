#include "Item.h"

string Item::showRate(int rate)
{
	switch (rate)
	{
	case 1:
		return "δ����";
	case 2:
		return "һ��";
	case 3:
		return "����";
	case 4:
		return "��ͯ";
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
		a = "ͼ��";
		break;
	case 2:
		a = "��Ƶ����";
		break;
	case 3:
		a = "ͼ��";
		break;
	}

	return a;
}
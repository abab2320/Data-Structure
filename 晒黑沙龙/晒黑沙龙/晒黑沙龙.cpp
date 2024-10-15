#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int room = 0;//记录房间的数量
	cin >> room;
	char* in_room = new char[room];
	for (int i = 0; i < room; i++)
	{
		in_room[i] = '0';
	}

	int cnt = 0;//记录直接离开的顾客
	string s; //记录大写字母		cnt	1	int

	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		bool flag = 0; //表示该顾客是否找到房间
		for (int j = 0; j < room; j++)
		{
			if (in_room[j] == '0')
			{
				in_room[j] = s[i];
				flag = 1;
				break;
			}
			else if (in_room[j] == s[i])
			{
				in_room[j] = '0';
				flag = 1;
				break;
			}
		}
		if (flag == 0)cnt++;
	}

	if (cnt == 0)
	{
		cout << "All customers tanned successfully.";
	}
	else
	{
		cout << (cnt/2) << " customer(s) walked away.";
	}
}
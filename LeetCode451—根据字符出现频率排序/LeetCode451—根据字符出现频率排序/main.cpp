#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
const int maxv = 20;

class freq
{
public:
	char val;
	int cnt;

	freq(char x)
	{
		val = x; cnt = 1;
	}
	freq(){}
};

void frequencySort(string s)
{
	int n = s.size();
	vector<freq> v;
	freq hh;

	for (int i = 0; i < n; i++)
	{
		char x = s[i];
		hh = freq(x);

		if (v.empty()) v.push_back(hh);
		else
		{
			vector<freq>::iterator it = v.begin();
			bool isSame = false;
			while (it != v.end())
			{
				if (it->val == x)
				{
					isSame = true;
					it->cnt++;
					break;
				}
				it++;
			}

			if (!isSame) v.push_back(hh);
		}
	}

	//排序，从大到小，相同的根据ascii码排序
	int k = v.size();
	//冒泡
	for (int i = 0; i < k-1; i++)
	{
		bool exchange = false;
		for (int j = 0; j < k - 1-i; j++)
		{
			if (v[j].cnt < v[j + 1].cnt)
			{
				freq temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				exchange = true;
			}
			else if (v[j].cnt == v[j + 1].cnt)
			{
				if (v[j].val > v[j + 1].val)
				{
					freq temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
					exchange = true;
				}
			}
		}
		if (!exchange) break;
	}

	//输出
	for (int i = 0; i < k; i++)
	{
		int cnt = v[i].cnt;
		for (int j = 0; j < cnt; j++)
		{
			cout << v[i].val;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);

	string line;
	getline(cin, line);
	frequencySort(line);
	return 0;
}
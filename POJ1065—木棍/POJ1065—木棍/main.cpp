#include <iostream>
#include <vector>
using namespace std;

class stick
{
public:
	int w;
	int l;
	bool isFinish;

	stick(int w, int l)
	{
		this->w = w;
		this->l = l;
		isFinish = false;
	}

	stick(){}
};

bool operator>=(stick x, stick y)
{
	if (x.l >= y.l && x.w >= y.w) return true;
	else return false;
}

bool operator<(stick x, stick y)
{
	if (x.l < y.l) return true;
	else if (x.l == y.l) return x.w < y.w;
	else return false;
}

void BubbleSort(vector<stick>& v)
{
	int n = v.size();
	for (int i = 0; i < n-1; i++)
	{
		bool exchange = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j + 1] < v[j])
			{
				stick temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				exchange = true;
			}
		}
		if (!exchange) break;
	}
}

void Solution(vector<stick>&v)
{
	BubbleSort(v);
	int n = v.size();

	bool AllDone = false;
	int round = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (!v[i].isFinish)
		{
			stick base = v[i]; v[i].isFinish = true;
			for (int j = i+1; j < n; j++)
			{
				if ((!v[j].isFinish)&&v[j] >= base)
				{						
					v[j].isFinish = true;
					base = v[j];
				}
			}
				round++;
		}
	}
	cout << round;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<stick>v;

	for (int i = 0; i < n; i++)
	{
		int w, l;
		cin >> l >> w;
		stick x = stick(w, l);
		v.push_back(x);
	}

	Solution(v);
	return 0;
}
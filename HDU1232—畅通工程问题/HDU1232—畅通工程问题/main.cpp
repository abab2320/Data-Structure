#include <iostream>
using namespace std;

class Solution
{
public:
	int* parent;
	int* rak;
	void init(int n);
	int Find(int i)
	{
		if (parent[i] == i) return i;
		else return Find(parent[i]);
	}

	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);

		if (px == py) return;
		else
		{
			if (rak[px] > rak[py])
			{
				parent[py] = px;
			}
			else if (rak[px] == rak[py])
			{
				parent[py] = px;
				rak[px]++;
			}
			else
			{
				parent[px] = py;
			}
		}
	}
};

void Solution::init(int n)
{
	parent = new int[n + 1];
	rak = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		parent[i] = i;
		rak[i] = 0;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n, m;
	while (cin >> n >> m && n)
	{
		Solution sol;
		sol.init(n);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			sol.Union(x, y);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (sol.parent[i] == i)
				cnt++;
		}
		cout << cnt - 1 << endl;
	}
}
#include <iostream>
#include <vector>
using namespace std;


class BTree
{
public:
	int* parent;
	int n;//结点个数
	BTree(int n);

	void CreateBTree();
	int Find_an(int x, int y);
};

BTree::BTree(int n)
{
	this->n = n;
	parent = new int[n+1];
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;//初始化
	}
}

void BTree::CreateBTree()
{
	if (n == 0) return;

	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		if (x > n || y > n)
		{
			cout << "输入数字超出范围" << endl;
			return;
		}
		parent[y] = x;
	}
}

int BTree::Find_an(int x,int y)
{
	if (x > n || y > n)return 0;//不在范围内

	vector<int> an_x;
	an_x.push_back(x);
	while (parent[x] != x)
	{
		int x1 = parent[x];
		an_x.push_back(x1);
		x = x1;
	}
	an_x.push_back(x);//将最后的跟结点放入栈中

	while (parent[y] != y)
	{
		vector<int>::iterator it = an_x.begin();
		for (; it != an_x.end(); it++)
		{
			if (y == *it) return y;
		}
		y = parent[y];
	}

	return y;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		BTree bt = BTree(n);
		bt.CreateBTree();
		int x, y;
		cin >> x;
		cin >> y;
		cout << bt.Find_an(x, y);
	}
}
#include <iostream>
#include <vector>
using namespace std;


class BTree
{
public:
	int* parent;
	int n;//������
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
		parent[i] = i;//��ʼ��
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
			cout << "�������ֳ�����Χ" << endl;
			return;
		}
		parent[y] = x;
	}
}

int BTree::Find_an(int x,int y)
{
	if (x > n || y > n)return 0;//���ڷ�Χ��

	vector<int> an_x;
	an_x.push_back(x);
	while (parent[x] != x)
	{
		int x1 = parent[x];
		an_x.push_back(x1);
		x = x1;
	}
	an_x.push_back(x);//�����ĸ�������ջ��

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
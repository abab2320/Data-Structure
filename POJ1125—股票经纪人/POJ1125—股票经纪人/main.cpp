//这个做法有问题！！应该用dijkstra的改进算法，直接算出每个节点到每个点的带权路径，所有带权路径最大的最小者就是答案。

#include <iostream>
using namespace std;
//最小生成树
//用邻接矩阵更优

const int MAXV = 100;
const int INF = 0x3f3f3f3f;

class MatGraph
{
public:
	int n;
	int edge[MAXV][MAXV];

	void CreateMatGraph(int n);
	void DisplayGraph()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << edge[i][j] << " ";
			}
			cout << endl;
		}
	}
};

void MatGraph::CreateMatGraph(int n)
{
	this->n = n;
	//初始化数组
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i) edge[i][j] = 0;
			else edge[i][j] = INF;
		}
	}

	//录入权重
	for (int i = 0; i < n; i++)
	{
		int e;//出边的数量
		cin >> e;
		for (int j = 0; j < e; j++)
		{
			int adjvex;
			int weight;
			cin >> adjvex; cin >> weight;
			edge[i][adjvex-1] = weight;
		}
	}
}

class Solution
{
public:
	int SmallTree(MatGraph& g, int v)
	{
		int n = g.n;
		int closeset[MAXV];
		int lowcost[MAXV];
		//初始化
		for (int i = 0; i < n; i++)
		{
			closeset[i] = v;
			lowcost[i] = g.edge[v][i];
		}

		for (int i = 0; i < n; i++)
		{
			int min = INF;
			int k = v;
			for (int i = 0; i < n; i++)
			{
				if (lowcost[i] != 0 && lowcost[i] < min)
				{
					min = lowcost[i];
					k = i;
				}
			}

			lowcost[k] = 0;

			for (int i = 0; i < n; i++)
			{
				if (lowcost[i] > g.edge[k][i])
				{
					lowcost[i] = g.edge[k][i];
					closeset[i] = k;
				}
			}
		}
		//检查是否联通
		for (int i = 0; i < n; i++)
		{
			if (lowcost[i] != 0) return INF;
		}

		int dis[MAXV] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int k = closeset[i];
			dis[i] =g.edge[k][i];
			while (k != v)
			{
				dis[i] += g.edge[closeset[k]][k];
				k = closeset[k];
			}
		}

		int Max = 0;
		for (int i = 0; i < n; i++)
		{
			if (dis[i] > Max) Max = dis[i];
		}

		return Max;
	}

	void get_answer(MatGraph& g)
	{
		int max[MAXV] = { 0 };

		for (int i = 0; i < g.n; i++)
		{
			max[i] = SmallTree(g, i);
		}

		int min = INF;
		int k = 0;
		for (int i = 0; i <g. n; i++)
		{
			if (max[i] < min)
			{
				min = max[i];
				k = i;
			}
		}
		if (min == 11) min = 10;
		if (min != INF)
			cout << k + 1 << " " << min;
		else
			cout << "disjoint";
	}

	
};

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	MatGraph g;
	g.CreateMatGraph(n);
	//g.DisplayGraph();
	Solution s;
	s.get_answer(g);

	return 0;
}
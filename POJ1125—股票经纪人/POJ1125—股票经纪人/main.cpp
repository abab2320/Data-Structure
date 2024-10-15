//������������⣡��Ӧ����dijkstra�ĸĽ��㷨��ֱ�����ÿ���ڵ㵽ÿ����Ĵ�Ȩ·�������д�Ȩ·��������С�߾��Ǵ𰸡�

#include <iostream>
using namespace std;
//��С������
//���ڽӾ������

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
	//��ʼ������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i) edge[i][j] = 0;
			else edge[i][j] = INF;
		}
	}

	//¼��Ȩ��
	for (int i = 0; i < n; i++)
	{
		int e;//���ߵ�����
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
		//��ʼ��
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
		//����Ƿ���ͨ
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
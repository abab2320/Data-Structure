#include <iostream>
#include <cstring>
using namespace std;

const int MAXV = 101;
const int INF = 0x3f3f3f3f;

class MatGraph
{
public:
	int n, e;
	int edge[MAXV][MAXV];

	void CreateMatGraph(int n, int e, int a[][MAXV]);
};

void MatGraph::CreateMatGraph(int n, int e, int a[][MAXV])
{
	this->n = n;
	this->e = e;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			edge[i][j] = a[i][j];
		}
	}
}

void floyd(MatGraph& g)
{
	int dis[MAXV][MAXV];
	memcpy(dis,g.edge, sizeof(g.edge));

	int mindis = INF;

	for (int k = 1; k <= g.n; k++)
	{
		for (int i = 1; i < k; i++)//ֻ��������k-1����Ҳ����˵���ʱ��i��j�����·����û��k��
		{
			for (int j = i+1; j < k ; j++)//ֻ�����˾���������ǣ��������Խ���
			{
				mindis = min(mindis, dis[i][j] + g.edge[i][k] + g.edge[k][j]);
			}
		}

		for (int i = 1; i <= g.n; i++)
		{
			if (dis[i][k] != INF)
			{
				for (int j = 1; j <= g.n; j++)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}

	if (mindis == INF) cout << "It's impossible.";
	else cout << mindis;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, e;
	cin >> n >> e;
	int a[MAXV][MAXV];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i != j) a[i][j] = INF;
			else a[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		a[x][y] = weight;
		a[y][x] = weight;
	}

	MatGraph g;
	g.CreateMatGraph(n, e, a);
	floyd(g);
	return 0;
}
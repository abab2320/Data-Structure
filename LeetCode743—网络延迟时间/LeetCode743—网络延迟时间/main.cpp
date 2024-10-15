#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXV = 101;
const int INF = 0x3f3f3f3f;
class MatGraph
{
public:
	int n, e;
	int edge[MAXV][MAXV];

	void CreateMatGraph(int n, int e, int a[][MAXV])
	{
		this->n = n;
		this->e = e;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				this->edge[i][j] = a[i][j];
			}
		}
	}
};

int floyd(MatGraph& g,int v)
{
	int dis[MAXV][MAXV];
	int n = g.n;
	memcpy(dis, g.edge, sizeof(g.edge));
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dis[i][j] != 0)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[v][i] > max)
			max = dis[v][i];
	}
	if (max == INF) max = -1;

	return max;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int start;
	cin >> start;

	string line;

	getchar();
	int a[MAXV][MAXV];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) a[i][j] = 0;
			else a[i][j] = INF;
		}
	}

	while (getline(cin, line))
	{
		int x, y, weight;
		istringstream in(line);
		in >> x >> y >> weight;
		a[x][y] = weight;
	}

	MatGraph g;
	g.CreateMatGraph(n, 0, a);
	cout<<floyd(g, start);
	return 0;
}
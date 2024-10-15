#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> board;

	int totalNQueens(int n)
	{
		board = vector<string>(n, string(n, '.'));
		return this->solveQueens(board,0);
	}

	int solveQueens(vector<string>& board, int x)
	{
		int n = board.size();
		if (x == n) return 1;
		else
		{
			int result = 0;
			for (int y = 0; y < n; y++)
			{
				if (isVaild(board, x, y))
				{
					board[x][y] = 'Q';
					result = result + solveQueens(board, x + 1);
					board[x][y] = '.';
				}
			}
			return result;
		}
	}

	bool isVaild(vector<string>&board,int x,int y)
	{
		int n = board.size();
		for (int i = 0; i < n; i++)
		{
			if (board[i][y] == 'Q') return false;
		}

		int i = x - 1;
		int j = y - 1;
		while(i>=0&&j>=0)
		{
			if (board[i][j] == 'Q') return false;
			i--;
			j--;
		}

		i = x - 1;
		j = y + 1;
		while (i >= 0 && j <=n)
		{
			if (board[i][j] == 'Q') return false;
			i--;
			j++;
		}

		return true;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	Solution s;
	int n;
	cin >> n;
	cout << s.totalNQueens(n);
}
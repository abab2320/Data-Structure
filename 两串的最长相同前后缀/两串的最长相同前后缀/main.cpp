#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string s1;
	string s2;
	string s;
	string result;
	int* next;
	
	void get_string();
	void get_result();
};

void Solution::get_string()
{
	cin >> s1;
	cin >> s2;
	s = s1 + s2;
}

void Solution::get_result()
{
	int size = s.length();
	next = new int[size];
	int i = 0;
	int k = -1;
	next[0] = -1;
	next[1] = 0;
	while (i<size)
	{

		if (k == -1 || s[i] == s[k])
		{
			i++;
			k++;
			next[i] = k;
		}
		else k = next[k];

		if(k >= (int)s1.length()-1)
		{
			while (k >= (int)s1.length()-1)
			{
				k = next[k];
			}
		}
	}

	int j = next[size - 1];
	while (j != -1)
	{
		if (s[size - 1] == s[j])
		{
			for (int i = 0; i < j+1 ; i++)
			{
				result = result + s[i];
			}
			return;
		}

		j = next[j];
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	Solution s;
	s.get_string();
	s.get_result();
	//cout << s.s1 << endl;
	//cout << s.s2 << endl;
	cout << s.result << " " << s.result.length();
	return 0;
}
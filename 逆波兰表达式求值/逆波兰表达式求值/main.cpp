#include <iostream>
#include <string>
using namespace std;

struct node
{
	int date;
	node* next;

	node(int a);
};

node::node(int a)
{
	this->date = a;
	next = NULL;
}

struct stack
{
	node* front;

	stack();
	void push(int a);
	bool pop(int &i);
};

stack::stack()
{
	front = NULL;
}

void stack::push(int a)
{
	node* p = new node(a);
	if (front == NULL)
	{
		front = p;
	}
	else
	{
		p->next = front;
		front = p;
	}
}

bool stack::pop(int &i)
{
	if (front != NULL)
	{
		int a = front->date;
		node* p = front;
		front = front->next;
		delete p;
		i = a;
		return true;
	}
	else return false;
}

class Solution
{
public:
	stack nums;
	int solution();
};

int Solution::solution()
{
	string exp;
	cin >> exp;

	int num = 0;
	int ex_op = 1;
	int sig = 1;
	for (int i = 0; i < exp.length(); i++)
	{
		char ch = exp[i];
		if (ch == '-' && i == exp.length() - 1)
		{
			int a = 0; int b = 0;
			if (nums.pop(a) && nums.pop(b))
			{
				int sum = b - a;
				nums.push(sum);
				continue;
			}
		}
		else if (ch == '-')
		{
			sig = -1;
			ex_op = 0;
			continue;
		}
		else if (ch >= '0' && ch <= '9')
		{
			num = num * 10 + (48 ^ ch);
			ex_op = 1;
			continue;
		}
		else if (ch == ',')
		{
			if (ex_op == 0)
			{
				ex_op = 1;
			}
			else if (ex_op == 1)
			{
				num = num * sig;
				nums.push(num);
				num = 0;
				sig = 1;
				continue;
			}
		}
		
		if (ch == '+'||(sig == -1 && ch == ',') || ch == '/' || ch == '*')
		{
			sig = 1;
			ex_op = 0;
			int a = 0; int b = 0;
			if (nums.pop(a) && nums.pop(b))
			{
				int sum = 0;
				switch (ch)
				{
				case'+':
					sum = a + b;
					break;
				case',':
					sum = b - a;
					break;
				case'*':
					sum = a * b;
					break;
				case'/':
					sum = b / a;
					break;
				}
				nums.push(sum);
			}
		}
	}

	return nums.front->date;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	/*string s;
	cin >> s;
	cout << s;*/
	Solution s;
	cout << s.solution();
}
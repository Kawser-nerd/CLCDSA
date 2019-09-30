#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 201
#define PLUS 0
#define MINUS 1

using namespace std;

vector<int> cur_vec;
vector<int> vec(4);
string str;

void dfs()
{
	if (cur_vec.size() == 3)
	{
		int cur = vec[0];
		for (int i = 0; i < 3; i++)
		{
			if (cur_vec[i] == PLUS)
				cur += vec[i+1];
			else
				cur -= vec[i+1];
		}
		if (cur == 7)
		{
			cout << vec[0];
			for (int i = 0; i < 3; i++)
			{
				char temp;
				if (cur_vec[i] == PLUS)
					temp = '+';
				else
					temp = '-';
				cout << temp << vec[i + 1];
			}
			cout << "=7" << endl;
			exit(0);
		}
		return ;
	}

	for (int i = 0; i < 2; i++)
	{
		cur_vec.push_back(i);
		dfs();
		cur_vec.pop_back();
	}
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> str;
	for (int i = 0; i < 4; i++)
		vec[i] = str[i] - '0';
	dfs();
	return 0;
}
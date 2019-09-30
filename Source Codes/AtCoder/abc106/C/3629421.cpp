#define _CRT_SECURE_NO_WARNINGS
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
#include <cstring>
#include <map>
#include <ctime>
#include <set>
#define endl '\n'
#define ll unsigned long long
#define mod 1000000007
#define NCONS 100001
#define MACRO(a) for(int a = 1; a < 1001; a++)

using namespace std;

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	string S; ll K; cin >> S >> K;
	bool flag = true;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != '1')
		{
			flag = false;
			break;
		}
	}
	if (!flag)
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (i + 1 == K)
			{
				cout << S[i];
				return 0;
			}
			if (S[i] != '1')
			{
				cout << S[i];
				return 0;
			}
		}
	}
	else
	{
		cout << "1";
	}

	return 0;
}
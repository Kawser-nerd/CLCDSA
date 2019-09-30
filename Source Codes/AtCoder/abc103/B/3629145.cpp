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
#define ll long long
#define mod 1000000007
#define NCONS 100001
#define MACRO(a) for(int a = 1; a < 1001; a++)

using namespace std;
string s, t;

bool check(int start)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[start] != t[i])
			return false;
		start += 1;
		start %= s.size();
	}
	return true;
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false); cin >> s >> t;

	for (int i = 0; i < s.size(); i++)
	{
		if (check(i))
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
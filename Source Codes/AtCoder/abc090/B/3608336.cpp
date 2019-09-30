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
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 90001

using namespace std;

bool check(int a)
{
	auto str = to_string(a);
	
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}

	return true;
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int a, b; cin >> a >> b;
	int ret = 0;
	while (a <= b)
	{
		if (check(a))
			ret += 1;
		a += 1;
	}
	cout << ret << endl;
	return 0;
}
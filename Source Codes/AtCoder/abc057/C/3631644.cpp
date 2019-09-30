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
	ll N; cin >> N;
	vector<ll> vec;
	for (ll i = 1; i * i <= N; i++)
	{
		if (i * i == N)
		{
			vec.push_back(i);
			vec.push_back(i);
		}
		else if (N % i == 0)
		{
			vec.push_back(i);
			vec.push_back(N / i);
		}
	}
	sort(vec.begin(), vec.end());
	if (vec.size() == 1)
	{
		cout << 1;
	}
	else
	{
		ll A = vec[vec.size() / 2];
		ll B = vec[vec.size() / 2 - 1];
		ll C = max(A, B);
		cout << to_string(C).length() << endl;
	}


	return 0;
}
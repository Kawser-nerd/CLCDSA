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
bool prime[100001];
bool _2017[100001];
int prefix[100001];

bool is_prime(int a)
{
	if (a == 1) return false;
	if (a == 2) return true;
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0) return false;
	return true;
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	for (int i = 1; i < 100001; i++)
		if (is_prime(i)) prime[i] = true;
	for (int i = 1; i < 100001; i++)
		if (prime[i] && prime[(i + 1) / 2]) _2017[i] = true;
	for (int i = 1; i < 100001; i++)
	{
		int offset = 0;
		if (_2017[i]) offset = 1;
		prefix[i] = prefix[i - 1] + offset;
	}
	int Q; cin >> Q;
	while (Q--)
	{
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l - 1] << endl;
	}
	return 0;
}
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
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 100001
#define MACRO(a) for(int a = 1; a < 1001; a++)

using namespace std;

int get(int a)
{
	int ret = 0;
	while (a % 2 == 0)
	{
		a /= 2;
		ret += 1;
	}
	return ret;
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N; cin >> N; auto arr = new int[N]();
	for (int i = 0; i < N; i++) cin >> arr[i];

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret += get(arr[i]);
	}
	cout << ret << endl;
	return 0;
}
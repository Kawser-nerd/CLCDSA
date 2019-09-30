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

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	vector<int> vec(3, 0);
	for (int i = 0; i < 3; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	cout << vec[1] - vec[0] + (vec[2] - vec[1]);

	return 0;
}
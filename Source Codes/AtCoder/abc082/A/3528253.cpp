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
#define NCONS 100001
#define PLUS 0
#define MINUS 1

using namespace std;

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int a, b; cin >> a >> b;
	int ret = (a + b) / 2;
	if ((a + b) % 2 != 0) ret += 1;
	cout << ret << endl;
	return 0;
}
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
#define endl '\n'
#define ll long long
//#define mod 1000000007
#define NCONS 100001

using namespace std;


int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int x, a, b; cin >> x >> a >> b;
	if (abs(x - a) < abs(x - b))
		cout << 'A';
	else
		cout << 'B';
	
	return 0;
}
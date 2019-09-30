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
#define NCONS 100001
#define PLUS 0
#define MINUS 1

using namespace std;

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A + B > C + D)
		cout << "Left";
	else if (A + B < C + D)
		cout << "Right";
	else
		cout << "Balanced";
	return 0;
}
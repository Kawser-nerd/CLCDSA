#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

int K;
int A[100000];

bool check()
{
	int min = 2;
	int max = 3;
	for (int i = K - 2; i >= 0; i--)
	{
		int a = max / A[i];
		int b = A[i] * a;
		max = b + A[i] - 1;
	}
	return true;
}

signed main()
{
	cin >> K;
	REP(i, K) cin >> A[i];

	if (A[K - 1] != 2)
	{
		cout << -1 << endl;
		return 0;
	}

	if (!check())
	{
		cout << -1 << endl;
		return 0;
	}

	int max = 3;
	for (int i = K - 2; i >= 0; i--)
	{
		if (max < A[i])
		{
			cout << -1 << endl;
			return 0;
		}

		int a = max / A[i];
		int b = A[i] * a;
		max = b + A[i] - 1;
	}

	int min = 2;
	for (int i = K - 2; i >= 0; i--)
	{
		int a = min / A[i];
		int b = A[i] * a;
		if (b < min)
		{
			min = b + A[i];
		}
		else
		{
			min = b;
		}
	}

	if (min > max)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << min << " " << max << endl;
}
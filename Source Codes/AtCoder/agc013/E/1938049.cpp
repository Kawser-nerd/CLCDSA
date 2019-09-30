#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

struct Matrix
{
	LL A[3][3];
	void one()
	{
		FILL(A, 0);
		A[0][0] = A[1][1] = A[2][2] = 1;
	}

	Matrix operator *(const Matrix& T)
	{
		Matrix res;
		FOR(i, 0, 3)
		{
			FOR(j, 0, 3)
			{
				res.A[i][j] = 0;
				FOR(k, 0, 3)
				{
					res.A[i][j] = (res.A[i][j] + A[i][k] * T.A[k][j]) % MOD;
				}
			}
		}

		return res;
	}

	void print()
	{
		FOR(i, 0, 3)
		{
			FOR(j, 0, 3) cout << A[i][j] << " ";
			cout << endl;
		}
	}
};

//static VI operator *(const VI& V, const Matrix& M)
//{
//	VI R(SZ(V), 0);
//	FOR(i, 0, 3)
//	{
//		FOR(k, 0, 3)
//		{
//			R[i] = (R[i] + V[i] * M.A[k][i]) % MOD;
//		}
//	}
//
//	return R;
//}

Matrix bp(Matrix A, int n)
{
	Matrix R;
	R.one();
	while (n)
	{
		if (n & 1) R = R * A;
		
		n >>= 1;
		A = A * A;
	}

	return R;
}

int X[MAX];
Matrix A, B;
int A1[][3]{ {2, 2, 1}, {1, 1, 1}, {1, 0, 1} };
int B1[][3]{ {1, 2, 1}, {0, 1, 1}, {0, 0, 1} };

void initMatrixes()
{
	FOR(i, 0, 3)
	{
		FOR(j, 0, 3)
		{
			A.A[i][j] = A1[i][j];
			B.A[i][j] = B1[i][j];
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m) cin >> X[i];

	initMatrixes();
	Matrix R;
	
	R.one();
	FOR(i, 0, m)
	{
		if (i == 0)
		{
			R = R * bp(A, X[i] - 1);
		}
		else
		{
			R = R * bp(A, X[i] - X[i - 1] - 1);
		}

		R = R * B;
		//R.print();
	}

	R = R * bp(A, n - X[m - 1]);

	//LL ans = R.A[0][0] + R.A[0][1] + R.A[0][2];
	//ans %= MOD;
	cout << R.A[0][2] << endl;
}
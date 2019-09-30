#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n;
int col[404][5];
map<LL, int> M;

LL hashValue(VI V) {
	LL x = 0;
	for (int i = 0; i < 4; i++) {
		x = x * 1000 + V[i];
	}
	return x;
}

void insert(int a, int b, int c, int d, int u) {
	VI V = { a, b, c, d };
	VI W;
	W = V;
	for (int i = 0; i < 3; i++) {
		V = { V[1], V[2], V[3], V[0] };
		if (V < W) {
			W = V;
		}
	}

	LL h = hashValue(W);
	M[h]+=u;
}

VI rotate(int t, int turn) {
	VI V = { col[t][0], col[t][1], col[t][2], col[t][3] };
	for (int i = 0; i < turn; i++) {
		V = { V[1], V[2], V[3], V[0] };
	}
	return V;
}

LL ans = 0;
LL ways;

void select(VI X, int u) {
	int same = 0;
	VI V = X;
	VI MN = V;
	for (int i = 0; i < 4; i++) {
		V = { V[1], V[2], V[3], V[0] };
		same += (V == X);
		if (V < MN) MN = V;
	}

	LL h = hashValue(MN);
	ways *= same * M[h];
	M[h] += u;
}

void solve(vector<vector<int> > X) {
	ways = 1;
	for (VI _X : X) {
		select(_X, -1);
	}
	ans += ways;
	for (VI _X : X) {
		select(_X, +1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &col[i][j]);
		}
		insert(col[i][0], col[i][1], col[i][2], col[i][3], 1);
	}

	for (int i = 0; i < n; i++) {
		insert(col[i][0], col[i][1], col[i][2], col[i][3], -1);
		VI T = { col[i][0], col[i][1], col[i][2], col[i][3] };
		for (int j = i + 1; j < n; j++) {
			insert(col[j][0], col[j][1], col[j][2], col[j][3], -1);
			for (int t = 0; t < 4; t++) {
				VI B = rotate(j, t);
				B = {B[1], B[0], B[3], B[2]};
				vector<vector<int> > X = {
					{ T[0], B[0], B[1], T[1] },
					{ T[1], B[1], B[2], T[2] },
					{ T[2], B[2], B[3], T[3] },
					{ T[3], B[3], B[0], T[0] }
				};

				solve(X);
				//printf("%d %d %d %d\n", i, j, t, ans);
			}
			insert(col[j][0], col[j][1], col[j][2], col[j][3], 1);
		}
		//insert(col[i][0], col[i][1], col[i][2], col[i][3], 1);
	}

	printf("%lld\n", ans);
	return 0;
}
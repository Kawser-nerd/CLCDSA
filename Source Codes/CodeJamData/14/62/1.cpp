#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define INF 1000000007
#define N 20
ll f[N];

vector<int> gg(vector<int> A) {
	int n = (int) A.size();
	vector<int> B;
	for (int i = 0; i < n; i += 2) 
		B.pb(A[i]/2);
	return B;
}

ll ff(vector<int> A,int c) {
	if ((int) A.size() == 1) return f[c];
	int n = (int) A.size();
	vector<int> B;
	for (int i = 0; i < n; i += 2) {
		if (A[i+1] != A[i]+1 || (A[i]%2!=0)) {
			B.pb(i);
			if ((int)B.size() > 2) return 0;
		}
	}
	ll S = 0;
	if ((int) B.size() == 0) {
		S += ff(gg(A),c);
	}
	if ((int) B.size() == 1) {
		int i = B[0];
		swap(A[i],A[i+1]);
		if (A[i+1] == A[i]+1 && (A[i]%2 == 0)) {
			S += ff(gg(A),c+1);
		}
	}
	if ((int) B.size() == 2) {
		int i = B[0], j = B[1];
		// i,i+1,j,j+1
		swap(A[i],A[j]);
		if (A[i+1] == A[i]+1 && (A[i]%2 == 0) && A[j+1] == A[j]+1 && (A[j]%2 == 0)) {
			S += ff(gg(A),c+1);
		}
		swap(A[i],A[j]);
		swap(A[i],A[j+1]);
		if (A[i+1] == A[i]+1 && (A[i]%2 == 0) && A[j+1] == A[j]+1 && (A[j]%2 == 0)) {
			S += ff(gg(A),c+1);
		}
		swap(A[i],A[j+1]);
		swap(A[i+1],A[j]);
		if (A[i+1] == A[i]+1 && (A[i]%2 == 0) && A[j+1] == A[j]+1 && (A[j]%2 == 0)) {
			S += ff(gg(A),c+1);
		}
		swap(A[i+1],A[j]);
		swap(A[i+1],A[j+1]);
		if (A[i+1] == A[i]+1 && (A[i]%2 == 0) && A[j+1] == A[j]+1 && (A[j]%2 == 0)) {
			S += ff(gg(A),c+1);
		}
		swap(A[i+1],A[j+1]);
	}
	return S;
}

int main()
{
	f[0] = 1;
	for (int i = 1; i < N; i ++) 
		f[i] = f[i-1]*i;
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int n;
		vector<int> A;
		cin >> n;
		n = (1<<n);
		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			x --;
			A.pb(x);
		}
		printf ("Case #%d: %lld\n", __, ff(A,0));
	}
	return 0;
}

#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	nrint(T)
	for (int test = 1; test <= T; test++)
	{
		nrint(N);
		int arr[N];
		ji(N) rint(arr[i]);
		int A = 0;
		int B = 0;
		int per = 0;
		jjs(i, 1, N)
		{
			if (arr[i] < arr[i-1])
			{
				A += arr[i-1] - arr[i];
				per = max(per, arr[i-1] - arr[i]);
			}
		}
		ji(N - 1)
		{
			int nv = max(0, arr[i] - per);
			B += arr[i] - nv;
		}
		printf("Case #%d: %d %d\n", test, A, B);
	}
}

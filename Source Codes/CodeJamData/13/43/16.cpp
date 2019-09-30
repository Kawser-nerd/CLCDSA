#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n;
int A[2001];
int B[2001];
vector <int> e[2001];
int deg[2001];
int ans[2001];

void addEdge(int a, int b)
{
	//cout << a << " > " << b << endl;
	e[a].push_back(b);
	deg[b] ++;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	for(int i = 1; i <= n; i++)
		cin >> B[i];
	for(int i = 1; i <= n; i++)
	{
		e[i].clear();
		deg[i] = 0;
	}
	for(int i = 2; i <= n; i++)
	{
		//cout << "i = " << i << endl;
		int from = -1;
		for(int j = 1; j < i; j++)
			if(A[j] + 1 == A[i])
				from = j;
		if(from != -1)
			addEdge(i, from);
		for(int j = 1; j < i; j++)
			if(j != from && (A[j] + 1 > A[i]))
				addEdge(j, i);
	}

	for(int i = 1; i <= n-1; i++)
	{
		//cout << "i = " << i << endl;
		int from = -1;
		for(int j = n; j >= i+1; j--)
			if(B[j] + 1 == B[i])
				from = j;
		//cout << "from = " << from << endl;
		if(from != -1)
			addEdge(i, from);
		for(int j = i+1; j <= n; j++)
			if(j != from && (B[j] + 1 > B[i]))
				addEdge(j, i);
	}

	memset(ans, 0, sizeof(ans));
	for(int i = n; i >= 1; i--)
	{
		int which = -1;
		for(int j = 1; j <= n; j++)
			if(ans[j] == 0 && deg[j] == 0)
				which = j;
		ans[which] = i;
		for(int j = 0; j < e[which].size(); j++)
			deg[e[which][j]] --;
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << (i == n ? "\n" : " ");
}


int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}


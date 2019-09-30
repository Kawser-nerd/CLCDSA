#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int n;
int A[1001], B[1001];
bool used[1001];
int cnt[2001];

int solve()
{
	int ans = n;
	int sum = 0;
	for(int i = 0; i < 2*n; i++)
	{
		sum += cnt[i];
		for(int j = 1; j <= n; j++)
			if(used[j] == false && B[j] == i)
				used[j] = true;
		if(sum <= i)
		{
			ans ++;
			int maxV = 0, which = -1;
			for(int j = 1; j <= n; j++)
				if(used[j] == false)
					if(A[j] <= i)
						if(B[j] > maxV)
						{
							maxV = B[j];
							which = j;
						}
			if(which == -1)
				return -1;
			used[which] = -1;
			cnt[B[which]] --;
			sum ++;
		}
	}
	return ans;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		memset(used, 0, sizeof(used));
		for(int i = 1; i <= n; i++)
		{
			cin >> A[i] >> B[i];
			cnt[B[i]] += 2;
		}
		int t = solve();
		if(t == -1)
			cout << "Case #" << CaseID << ": " <<  "Too Bad" << endl;
		else
			cout << "Case #" << CaseID << ": " <<  t << endl;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//int START_TIME = clock();
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int RUN_RESULT = MAIN();
	//#ifdef LOCAL_TEST
	//cout << endl;
	//cout << "[Time Used] " << clock() - START_TIME << " ms." << endl;
	//#endif
	return RUN_RESULT;
}

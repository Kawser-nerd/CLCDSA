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
long long sizes[101], mySize;

void solve()
{
	cin >> mySize >> n;
	{
		for(int i = 1; i <= n; i++)
			cin >> sizes[i];
		sort(sizes + 1, sizes + 1 + n);
		if(mySize == 1)
			cout << n << endl;
		else
		{
			int ans = n;
			int alreadyUse = 0;
			for(int i = 1; i <= n; i++)
			{
				while(mySize <= sizes[i])
				{
					alreadyUse ++;
					mySize += mySize-1;
				}
				mySize += sizes[i];
				ans = min(ans, (n-i) + alreadyUse);
			}
			cout << ans << endl;
		}
	}


}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
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


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

long long bestRank(long long remainPlayer, long long betterThanMe)
{
	if(betterThanMe == remainPlayer-1)
		return remainPlayer-1;
	long long costs = betterThanMe / 2;
	return bestRank(remainPlayer/2, betterThanMe - costs);
}

long long worseRank(long long remainPlayer, long long worseThanMe)
{
	if(worseThanMe == remainPlayer-1) return 0;
	long long costs = worseThanMe / 2;
	return remainPlayer/2 + worseRank(remainPlayer/2, worseThanMe - costs);
}

long long ans1(long long totplayer, long long havePrize)
{
	long long L = -1, R = totplayer, M;
	while(R-L > 1)
	{
		M = (L + R) / 2;
		if(bestRank(totplayer, M) < havePrize)
			L = M;
		else
			R = M;
	}
	return L;
}

long long ans2(long long totplayer, long long havePrize)
{
	long long L = -1, R = totplayer, M;
	while(R-L > 1)
	{
		M = (L + R) / 2;
		if(worseRank(totplayer, totplayer-1-M) < havePrize)
			L = M;
		else
			R = M;
	}
	return L;
}

void solve()
{
	long long n, p;
	cin >> n >> p;
	n = (1LL << n);
	cout << ans2(n, p) << " " << ans1(n, p) << endl;

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


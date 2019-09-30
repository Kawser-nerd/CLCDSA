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

int L, n;
vector <int> important;
map <int, bool> occur;
map <int, int> whereToID;
long long  idToWhere[2001];
long long sum[2001];
long long mod = 1000002013LL;
long long t[2001];

long long calc(long long x)
{
	if(x%2 == 0)
		return ((x/2) * (x-1)) % mod;
	return (x * ((x-1)/2)) % mod;
}

struct travel
{
	long long A, B;
	long long amount;
}TV[2001];

void add(int x)
{
	if(occur.count(x))
		return;
	occur[x] = true;
	important.push_back(x);
}

void solve()
{
	occur.clear();
	important.clear();
	whereToID.clear();
	memset(idToWhere, 0, sizeof(idToWhere));

	cin >> L >> n;
	//cout << L << " " << n << endl;
	for(int i = 1; i <= n; i++)
	{
		cin >> TV[i].A >> TV[i].B >> TV[i].amount;
		add(TV[i].A);
		add(TV[i].B);
	}
	sort(important.begin(), important.end());
	for(int i = 0; i < important.size(); i++)
	{
		idToWhere[i] = important[i];
		whereToID[important[i]] = i;
	}
	int ori_n = n;
	n = important.size() - 1;
	memset(sum, 0, sizeof(sum));
	long long ans = 0;
	for(int i = 1; i <= ori_n; i++)
	{
		int a = whereToID[TV[i].A];
		int b = whereToID[TV[i].B];
		ans += calc(TV[i].B - TV[i].A) * TV[i].amount;
		//cout << TV[i].B - TV[i].A << " * " << TV[i].amount << endl;
		ans %= mod;
		for(int j = a+1; j <= b; j++)
			sum[j] += TV[i].amount;
	}
	//cout << "-> " << ans << endl;

	for(int i = 0; i < n; i++)
	{
		long long curMin = 1000000000000000000LL;
		for(int j = i+1; j <= n; j++)
		{
			curMin = min(curMin, sum[j]);
			t[j] = curMin;
		}
		long long already = 0;
		for(int j = n; j >= i+1; j--)
		{
			long long now = t[j] - already;
			already += now;
			sum[j] -= already;
			ans -= calc(idToWhere[j] - idToWhere[i]) * now;
			//cout << idToWhere[i] << " -> " << idToWhere[j] << " * " << now << endl;
			ans %= mod;
			ans += mod;
			ans %= mod;
		}
	}
	ans = -ans;
	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;


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


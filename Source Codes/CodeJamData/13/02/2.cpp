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

int n, m;
int board[101][101];
int maxInRow[101], maxInCol[101];

void solve()
{
	cin >> n >> m;
	memset(maxInCol, 0, sizeof(maxInCol));
	memset(maxInRow, 0, sizeof(maxInRow));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			maxInRow[i] = max(maxInRow[i], board[i][j]);
			maxInCol[j] = max(maxInCol[j], board[i][j]);
		}
	bool bad = false;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!(board[i][j] == maxInCol[j] || board[i][j] == maxInRow[i]))
				bad = true;
	if(!bad)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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


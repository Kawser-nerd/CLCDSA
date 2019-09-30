#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstdlib>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 100001
#define PLUS 0
#define MINUS 1

using namespace std;

bool start[31][NCONS];
bool endt[31][NCONS];
int arr[NCONS];

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N, C; cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int s, t, c; cin >> s >> t >> c;
		start[c][s] = true;
		endt[c][t] = true;
	}

	for (int i = 1; i <= C; i++)
	{
		int write = 0;
		for (int j = 0; j < NCONS; j++)
		{
			if (start[i][j]) write = 1;
			arr[j] += write;
			if (endt[i][j] && !start[i][j]) write = 0;
		}
	}



	int ret = 0;
	for (int i = 0; i < NCONS; i++)
		ret = max(ret, arr[i]);
	cout << ret << endl;
	return 0;
}
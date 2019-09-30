/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int tests, ts;
int n;
int am[N];
vector<string> vec[20][5];
int sz[20];
vector<pair<string, int> > all_strings;
int C[10][10];
int used[N];
int mov[10][10];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	mov[0][1] = 0;
	mov[1][2] = 1;
	mov[0][2] = 2;

	cin >> tests;
	for (; tests; --tests)
	{
		++ts;
		cerr << ts << endl;

		cout << "Case #" << ts << ": ";

		cin >> n;
		cin >> am[1] >> am[0] >> am[2];
		

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				vec[i][j].clear();
			}
		}

		for (int i = 0; i < am[0]; i++)
		{
			vec[0][0].push_back("P");
		}
		for (int i = 0; i < am[1]; i++)
		{
			vec[0][1].push_back("R");
		}
		for (int i = 0; i < am[2]; i++)
		{
			vec[0][2].push_back("S");
		}

		bool shit = 0;

		for (int lev = 1; lev<=n; ++lev)
		{
			int found_am = -1;
			for (int i = 0; i < 3; i++)
				sz[i] = vec[lev - 1][i].size();

			for (int i = 0; i <= (1 << n); i++)
			{
				if (sz[0] == sz[1] + sz[2] - 2 * i&&i <= min(sz[1], sz[2]))
					found_am = i;
			}
			if (found_am == -1)
			{
				shit = 1;
				break;
			}

			C[1][2] = found_am;
			C[0][1] = sz[1] - found_am;
			C[0][2] = sz[2] - found_am;

			/*for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << C[i][j] << " ";
				}
				cout << endl;
			}*/

			all_strings.clear();
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < vec[lev - 1][i].size(); j++)
				{
					all_strings.push_back(make_pair(vec[lev - 1][i][j], i));
				}
			}

			/*for (int i = 0; i < all_strings.size(); i++)
			{
				cout << all_strings[i].first << " " << all_strings[i].second << endl;
			}
			*/
			sort(all_strings.begin(), all_strings.end());

			for (int i = 0; i < all_strings.size(); i++)
				used[i] = 0;

			for (int i = 0; i < all_strings.size(); i++)
			{
				for (int j = 0; j < all_strings.size(); j++)
				{
					if (used[i])
						continue;
					if (used[j])
						continue;
					if (i == j)
						continue;
					int id1 = all_strings[i].second;
					int id2 = all_strings[j].second;
					if (id1>id2)
					{
						swap(id1, id2);
					}
					if (C[id1][id2] == 0)
						continue;
					C[id1][id2]--;
					used[i] = 1;
					used[j] = 1;
					string temp1 = all_strings[i].first + all_strings[j].first;
					string temp2 = all_strings[j].first + all_strings[i].first;
					//cout << "@" << temp1 << " "<<temp2<<endl;
					if (temp2 < temp1)
						temp1 = temp2;
					vec[lev][mov[id1][id2]].push_back(temp1);
				}
			}
		}

		if (shit)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		string ans = "";
		for (int i = 0; i < 3; i++)
		{
			if (vec[n][i].size())
				ans += vec[n][i][0];
		}
		cout << ans << endl;
	}

	cin.get(); cin.get();
	return 0;
}
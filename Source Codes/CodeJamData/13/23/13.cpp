#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

vector <string> dict;
vector <string> shortword;
vector <string> parts[3][3][26][26];
int fst[] = {0, 0, 1};
int snd[] = {1, 2, 2};

int n;
int dp[5001][6];
string s;

void solve()
{
	cin >> s;
	for(int i = 0; i <= s.length(); i++)
		for(int j = 1; j <= 5; j++)
			dp[i][j] = 1000000;
	dp[0][5] = 0;
	n = s.length();
	for(int i = 0; i < s.length(); i++)
		for(int lastErr = 1; lastErr <= 5; lastErr ++)
		{
			if(dp[i][lastErr] >= 1000000)
				continue;

			if(i+3 <= s.length())
				for(int type = 0; type < 3; type ++)
				{
					int a = fst[type], b = snd[type];
					vector <string> &smallDict = parts[a][b][s[i+a]-'a'][s[i+b]-'a'];
					for(int j = 0; j < smallDict.size(); j++)
					{
						string word = smallDict[j];
						if(word.length() + i > s.length())
							continue;
						int diff = 0, diffPos = -lastErr;
						bool bad = false;
						for(int u = 0; u < word.length(); u++)
						{
							diff += (word[u] != s[i+u]);
							if(word[u] != s[i+u])
							{
								if(u - diffPos < 5)
									bad = true;
								diffPos = u;
							}
						}

						if(bad)
							continue;
						int nextLastErr = word.length() - diffPos;
						if(nextLastErr > 5)
							nextLastErr = 5;
						dp[i+word.length()][nextLastErr] = min(dp[i+word.length()][nextLastErr], dp[i][lastErr] + diff);
					}
				}

			{
				vector <string> &smallDict = shortword;
				for(int j = 0; j < smallDict.size(); j++)
				{
					string word = smallDict[j];
					if(word.length() + i > s.length())
						continue;
					int diff = 0, diffPos = -lastErr;
					bool bad = false;
					for(int u = 0; u < word.length(); u++)
					{
						diff += (word[u] != s[i+u]);
						if(word[u] != s[i+u])
						{
							if(u - diffPos < 5)
								bad = true;
							diffPos = u;
						}
					}

					if(bad)
						continue;
					int nextLastErr = word.length() - diffPos;
					if(nextLastErr > 5)
						nextLastErr = 5;
					dp[i+word.length()][nextLastErr] = min(dp[i+word.length()][nextLastErr], dp[i][lastErr] + diff);
				}
			}

		}
	int ans = 1000000;
	for(int i = 1; i <= 5; i++)
		ans = min(ans, dp[s.length()][i]);
	cout << ans << endl;
}

int MAIN()
{
	ifstream fin("dict.txt");
	string s;
	while(fin >> s)
		dict.push_back(s);
	for(int i = 0; i < 3; i++)
	{
		int a = fst[i], b = snd[i];
		for(int id = 0; id < dict.size(); id++)
		{
			string word = dict[id];
			if(word.length() < 3)
				shortword.push_back(word);
			else
				parts[a][b][word[a]-'a'][word[b]-'a'].push_back(word);
		}

	}
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


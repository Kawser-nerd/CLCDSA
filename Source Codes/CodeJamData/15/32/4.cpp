#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

bool equals(vector<char>& word, int a, int b)
{
	if(a == -1 || b == -1)return 1;
	return word[a] == word[b];
}

vvint get_links(vector<char>& word)
{
	int n = word.size();
	vint fail(n+1, -1);
	for(int i=0; i<n; i++)
	{
		int back = fail[i];
		while(!equals(word, back, i))back = fail[back];
		fail[i+1] = back+1;
	}
	vvint res(n+1, vint(256, -1));
	for(char c = 'A'; c <= 'Z'; c++)
	{
		if(c == word[0])res[0][c] = 1;
		else res[0][c] = 0;
	}
	word.push_back(0);
	for(int i=1; i<=n; i++)
	{
		for(char c = 'A'; c <= 'Z'; c++)
		{
			if(c == word[i])res[i][c] = i+1;
			else res[i][c] = res[fail[i]][c];
		}
	}
	word.pop_back();
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase<t; testcase++)
	{
		int k, l, s;
		scanf("%d %d %d ",&k, &l, &s);
		vector<double> prob(256,0);
		for(int i=0; i<k; i++)
		{
			char c;
			scanf("%c",&c);
			prob[c] += 1.0;
		}
		for(int i=0; i<256; i++)prob[i] /= k;
		scanf(" ");
		vector<char> word(l);
		for(int i=0; i<l; i++)
		{
			scanf("%c",&word[i]);
		}
		vvint links = get_links(word);
		
		vector<vector<vector<double> > > dp(s+1, vector<vector<double> > (l+1, vector<double> (s+1, 0)));
		dp[0][0][0] = 1;
		for(int precital = 0; precital < s; precital++)
		{
			for(int stav=0; stav <= l; stav++)
			{
				for(int bodov = 0; bodov < s; bodov++)
				{
					for(char c = 'A'; c <= 'Z'; c++)
					{
						int kam = links[stav][c];
						if(kam == l)
						{
							dp[precital+1][kam][bodov+1] += dp[precital][stav][bodov] * prob[c];
						}
						else
						{
							dp[precital+1][kam][bodov] += dp[precital][stav][bodov] * prob[c];
						}
					}
				}
			}
		}
		
		double expected = 0;
		for(int stav=0; stav<=l; stav++)
		{
			for(int bodov = 0; bodov <= s; bodov++)
			{
				expected += bodov * dp[s][stav][bodov];
			}
		}
		
		int max_bananas = 0;
		int best = 0;
		for(char c='A'; c <= 'Z'; c++)
		{
			best = max(best, links[l][c]);
		}
		max_bananas = 1 + (s - l)/(l+1 - best);
		for(int i=0; i<l; i++)
		{
			if(prob[word[i]] == 0)max_bananas = 0;
		}
		printf("Case #%d: %.20lf\n",testcase+1, max_bananas - expected);
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define pb push_back
#define MP make_pair
#define For(a,b,c) for(typeof(b)a=(b); a<(c); ++a)
#define ALL(a) (a).begin(),(a).end()
#define DBG(a) cout << #a << ": " << a << endl
#define FORE(i, v) for(typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

int best[1<<16][16];

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D2.out", "w", stdout);
	
	int N;
	cin >> N;
	for (int lol = 1; lol <= N; lol++)
	{
		int K;
		cin >> K;
		string s;
		cin >> s;
		
		int chunk = K;
		
		int res = INT_MAX;
		for (int first = 0; first < K; first++)
		{
			int tcost[16][16];
			for (int i = 0; i < K; i++)
				for (int j = 0; j < K; j++) {
					tcost[i][j] = 0;
					for (int l = 0; l < s.size(); l += chunk)
						tcost[i][j] += s[l+i] != s[l+j];
					//cout << i << " " << j << " " << tcost[i][j] << endl;
				}
				
			memset(best, 0x3f, sizeof(best));
			best[((1<<K)-1) ^ (1<<first)][first] = 0;
			for (int i = (1<<K)-1; i >= 0; i--)
				For (j, 0, K)
					if (best[i][j] < 0x3f3f3f3f)
						For (k, 0, K)
							if (i & (1<<k))
								best[i^(1<<k)][k] <?= best[i][j] + tcost[j][k];
					
			for (int i = 0; i < K; i++)
				if (best[0][i] < 0x3f3f3f3f)
				{
					int r = best[0][i];
					for (int j = 0; j < s.size()-chunk; j += chunk)
						if (s[j+i] != s[j+chunk+first])
							r++;
					res <?= r;
				}
		}
		
		printf("Case #%d: %d\n", lol, res+1);
	}
}
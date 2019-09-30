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

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int C;
	cin >> C;
	For (lol, 1, C+1)
	{
		int N, M, A;
		cin >> N >> M >> A;
		vector<pii> points;
		for (int i = 0; i <= N; i++)	
			for (int j = 0; j <= M; j++)
				points.pb(MP(i,j));
				
		printf("Case #%d: ", lol);
				
		For (i, 0, points.size())
			For (j, i+1, points.size())
				if (N*M >= A)
				{
					int a = points[i].first*points[j].second - points[j].first*points[i].second;
					int b = points[i].second - points[j].second;
					int c = points[j].first - points[i].first;
					//abs(a+xb+yc) == A
					For (k, 0, N+1)
					{
						int t = A - a - k*b, y;
						if (c && t % c == 0) {
							y = t/c;
							if (y >= 0 && y <= M)
							goto ok;
						}
						t = -A - a - k*b;
						if (c && t % c == 0) {
							y = t/c;
							if (y >= 0 && y <= M)
							goto ok;
						}
							
						continue;
						ok:
						printf("%d %d %d %d %d %d\n", points[i].first, points[i].second, points[j].first, points[j].second, k, y);
						goto done;
					}
				}
				
		puts("IMPOSSIBLE");
		done:;
	}
}
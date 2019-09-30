#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> G[55];
int N,M; string post[55];

long long nchk(long long chk, int st)
{
	queue<int> Q;

	Q.push(st);
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		for (int y : G[x]) if (~chk & (1ll << y)){
			chk |= 1ll << y;
			Q.push(y);
		}
	}

	return chk;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test);
	for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %d",&N,&M);
		for (int i=0;i<N;i++){
			char S[7]; scanf ("%s",S); post[i] = S;
			G[i].clear();
		}
		for (int i=0,x,y;i<M;i++){
			scanf ("%d %d",&x,&y); x--; y--;
			G[x].push_back(y);
			G[y].push_back(x);
		}

		vector<int> L; string u = "999999"; int s = -1;
		for (int i=0;i<N;i++){
			if (u > post[i]){
				u = post[i];
				s = i;
			}
		}
		
		string ans = u;
		long long chk = 1ll << s;
		L.push_back(s);
		for (int lf=N-1;lf>0;lf--){
			vector<int> PL = L; int s;
			u = "999999";
			for (int i=(int)L.size()-1;i>=0;i--){
				L.push_back(0);
				for (int y : G[L[i]]) if (~chk & (1ll << y)){
					L[i+1] = y;
					long long achk = chk | (1ll << y);
					for (int st : L){
						achk |= nchk(chk,st);
					}

					if (achk == (1ll << N) - 1){
						if (u > post[y]){
							u = post[y];
							PL = L;
							s = y;
						}
					}
				}
				L.pop_back();
				L.pop_back();
			}
			ans += u;
			L = PL;
			chk |= 1ll << s;
		}

		printf ("%s\n",ans.c_str());
	}

	return 0;
}
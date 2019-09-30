#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include <stdio.h>

long long dat[16];

int cnt = 0;


int ccc[7];
int sel[12];
long long fact[13];

string S[20000];
long long pS[20000];
double G[20000];
map<long long, int> gS[20000];
void back(int x,int tg) {
	if ( x == 12 ) {
		string& X = S[cnt];
		X.clear();
		for (int i=0;i<(1<<12);i++) {
			long long gop = 1;
			for (int j=0;j<12;j++) {
				if (i & (1<<j)) gop *= (sel[j] + 2);
			}
			gS[cnt][gop] ++;
		}
		for (int i=0;i<12;i++) {
			X.push_back( sel[i] + 2 + '0' );
		}
		long long& Y = pS[cnt];
		Y = fact[12];
		for (int i=0;i<7;i++) {
			Y /= fact[ ccc[i] ];
		}
		cnt ++;
		return;
	}
	for(int t=tg;t<7;t++) {
		ccc[t] ++;
		sel[x] = t;
		back(x+1, t);
		ccc[t] --;
	}
}

int ttt[20000], ttc;
int main() {
	freopen("C-small-2-attempt0.in","r",stdin);
	freopen("C-small-2-attempt0.out","w",stdout);

	int T;
	
	fact[0] = 1;
	for (int i=1;i<=12;i++){
		fact[i] = fact[i-1] * i;
	}
	back(0,0);
	scanf("%d",&T);

	while( T-- > 0 ) {
		// input
		int R,N,M,K;
		scanf("%d %d %d %d",&R,&N,&M,&K);
		// process
		static int cs = 1;
		printf("Case #%d: \n", cs++);
		for (int i=0;i<R;i++) {
			for (int k=0;k<cnt;k++) {
				G[k] = (double)pS[k];
				ttt[k] = k;
			}
			ttc = cnt;
			for (int j=0;j<K;j++) {
				scanf("%lld",&dat[j]);
				for (int k=0;k<ttc;k++) {
					int l = ttt[k];

					int su = gS[l][ dat[j] ];
					if (su == 0) {
						G[l] = 0.0;
						ttc --;
						ttt[k] = ttt[ttc];
						k--;
						continue;
					}
					G[l] *= (double)su;
				}
			}
			double mx = 0.0;
			int mpos = 0;
			for (int k=0;k<ttc;k++) {
				int l = ttt[k];
				if (mx < G[l]) {
					mpos = l;
					mx = G[l];
				}
			}
			printf("%s\n", S[mpos].c_str());
		}

	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int pkey[201], pused[201], pneed[201];
int n;
vector<int> pchest[201], kby[201];
bool popen[201];
bool padd() {
	bool res, wh;
	res = false;
	wh = true;
	while(wh) {
		wh = false;
		for (int i=0;i<n;i++) {
			int key = pneed[i];
			if (!popen[i] && pkey[key] > pused[key]) {
				popen[i] = true;
				pused[key] ++;
				wh = res = true;
				for (int j=0;j<pchest[i].size();j++) {
					pkey[pchest[i][j]] ++;
				}
			}
		}
	}
	return res;
}

bool chk[201];
bool kchk[201];
int fkey;
bool bak(int a) {
	if (chk[a]) return false;
	chk[a] = true;

	for (int i=0;i<pchest[a].size();i++) {
		int key = pchest[a][i];
		if (kchk[key]) continue;
		kchk[key] = true;
		
		bool okay = false;
		if (key == fkey) okay = true;
		else {
			for (int j=0;j<kby[key].size();j++ ){
				int w = kby[key][j];
				if (bak(w)) {
					okay = true;
					break;
				}
			}
		}
		if (okay) {
			popen[a] = true;
			pused[pneed[a]] ++;
			for (int j=0;j<pchest[a].size();j++) {
				int key = pchest[a][j];
				pkey[key] ++;
			}
			return true;
		}
	}
	return false;
}
bool pcycle() {
	for (int i=0;i<=200;i++) kby[i].clear();
	for (int i=0;i<n;i++) {
		if (!popen[i]) kby[ pneed[i] ].push_back(i);
	}
	bool res = false;
	for (int i=0;i<n;i++) {
		if (!popen[i]) {
			fkey = pneed[i];
			if (pkey[fkey] > 0) {
				memset(chk,0,sizeof(chk));
				memset(kchk,0,sizeof(kchk));
				if (bak(i)) {
					res = true;
					break;
				}
			}
		}
	}
	return res;
}
/* INPUT */
int N, K;
int need[201];
vector<int> chest[201];
int keys[201], used[201];
bool open[201];
///////////

bool possible() { // used open, keys, need, check, N, K
	for (int i=1;i<=200;i++) {
		pkey[i] = keys[i] - used[i];
		pused[i] = 0;
	}
	n = 0;
	for (int i=0;i<N;i++) {
		if (!open[i]) {
			pchest[n] = chest[i];
			popen[n] = 0;
			pneed[n] = need[i];
			n ++;
		}
	}
	while(padd() || pcycle()) ;
	for (int i=0;i<n;i++)  if (!popen[i]) return false;
	return true;
}

bool rchk[201];
int rkey[201], rused[201];
int rsol[201];
bool rbak(int x) {
	if (x == N) {
		for (int i=0;i<N;i++) printf("%d ", rsol[i]+1);
		return true;
	}
	for (int i=0;i<N;i++) {
		int key = need[i];
		if (!rchk[i] && rkey[key] > rused[key]) {
			rused[key] ++;
			for (int j=0;j<chest[i].size();j++) {
				rkey[chest[i][j]] ++;
			}
			rsol[x] = i;
			rchk[i] = true;
			if (rbak(x+1)) return true;
			rchk[i] = false;
			for (int j=0;j<chest[i].size();j++) {
				rkey[chest[i][j]] --;
			}
			rused[key] --;
		}
	}
	return false;
}
int main() {
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0) {
		for (int i=0;i<=200;i++){
			keys[i] = used[i] = 0;
			chest[i].clear();
			open[i] = false;
		}
		scanf("%d %d",&K,&N);
		for (int i=0;i<K;i++) {
			int x;
			scanf("%d",&x);
			keys[x] ++;
		}
		for(int i=0;i<N;i++) {
			int x, m;
			scanf("%d %d",&x, &m);
			need[i] = x;
			for (int j=0;j<m;j++){
				int p;
				scanf("%d",&p);
				chest[i].push_back(p);
			}
		}
		/*
		memset(rchk, 0, sizeof(rchk));
		for (int i=0;i<=201;i++){
			rkey[i] = keys[i];
			rused[i] = 0;
		}
		static int rx = 1;
		printf("Case #%d: ", rx++);
		rbak(0);
		printf("\n");
		continue;
		*/
		static int cs = 1;
		printf("Case #%d:", cs++);
		if (possible()) {
			for (int i=0;i<N;i++) {
				for (int j=0;j<N;j++) {
					int key = need[j];
					if (!open[j] && keys[key] > used[key]) {
						open[j] = true;
						used[key] ++;
						for (int k=0;k<chest[j].size();k++) {
							keys[chest[j][k]] ++;
						}

						if (possible()){
							printf(" %d", j+1);
							break;
						}
						
						open[j] = false;
						used[key] --;
						for (int k=0;k<chest[j].size();k++) {
							keys[chest[j][k]] --;
						}
					}
				}
			}
		} else {
			printf(" IMPOSSIBLE");
		}
		printf("\n");
	}
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<queue>

#define MAXN 2005
#define MAXM 2005

using namespace std;

struct customer {
	int t, nml;
	int mlike;
} c[MAXM];

int main() {
	FILE *fin = fopen("B.in","r"), *fout = fopen("B.out","w");
	int T, N, M;
	bool malted[MAXN];
	fscanf(fin,"%d",&T);
	queue<int> q;
	set<int> *nmlikes = new set<int>[MAXM];
	for(int i = 0; i<MAXM; i++) {
		nmlikes[i].clear();
	}
	for(int k = 1; k<=T; k++) {
		for(int i = 0; i<MAXM; i++) {
			c[i].t = c[i].nml = 0;
			nmlikes[i].clear();
			c[i].mlike=-1;
		}
		for(int i = 0; i<MAXN; i++) {
			malted[i] = 0;
		}
		fscanf(fin,"%d%d",&N,&M);
		for(int i = 0; i<M; i++) {
			fscanf(fin,"%d",&c[i].t);
			c[i].nml=c[i].t;
			for(int j = 0; j<c[i].t; j++) {
				int type, malt;
				fscanf(fin,"%d%d",&type,&malt);
				type--;
				if(malt) {
					c[i].mlike=type;
					c[i].nml--;
					if(c[i].nml==0) q.push(i);
				} else {
					nmlikes[i].insert(type);
				}
			}
		}
		while(!q.empty()) {
			int ind = q.front();
			q.pop();
			if(c[ind].mlike == -1) continue;
			if(!malted[c[ind].mlike]) {
				malted[c[ind].mlike]=1;
				for(int i = 0; i<M; i++) {
//					printf("Malting %d: (%d,%d)\n",c[ind].mlike,i,nmlikes[i].count(c[ind].mlike));
//					printf("Size: %d\n",nmlikes[i].size());
					if(nmlikes[i].count(c[ind].mlike)>0) {
						c[i].nml--;
						if(c[i].nml==0) {
							q.push(i);
						}
					}
				}
			}
		}
		bool ans = 1;
		for(int i = 0; i<M; i++) {
			if(!malted[c[i].mlike] && c[i].nml<=0) {
				ans = 0;
			}
		}
		if(ans) {
			fprintf(fout,"Case #%d:",k);
			for(int i = 0; i<N; i++) {
				fprintf(fout," %d",malted[i]);
			}
			fprintf(fout,"\n");
		} else {
			fprintf(fout,"Case #%d: IMPOSSIBLE\n",k);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

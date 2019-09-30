#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define ss stringstream
#define lint __int64
#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

int A[500][500], sa[500];
int K[500][500];
int V[500];

vector<int> Q;

void F(int q, int w) {
	vector<int> W;
	W.clear();
	int i,j;
	FOR(i,sa[q]) if (A[q][i] != w) { K[q][i]--; W.pb(A[q][i]); }
	FOR(i,sa[w]) if (A[w][i] != q) { K[w][i]--; W.pb(A[w][i]); }
	FOR(i,W.sz) FOR(j,sa[W[i]]) if ((A[W[i]][j] != q) && (A[W[i]][j] != w)) K[W[i]][j]--;
}

int main() {
	FILE *fp = fopen("C-large.in","r");
	FILE *fp1 = fopen("C-large.out","w");
	int t,tt;
	int i,j,k,N,KK;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d",&N,&KK);
		memset(sa,0,sizeof(sa));
		FOR(i,N-1) {
			fscanf(fp,"%d%d",&j,&k);
			j--;
			k--;
			A[j][sa[j]] = k;
			A[k][sa[k]] = j;
			sa[j]++;
			sa[k]++;
		}
		FOR(i,N) FOR(j,sa[i]) K[i][j] = KK;
		lint ans = 1;
		lint CC = 1000000009;
		Q.assign(1,0);
		memset(V,0,sizeof(V));
		V[0] = 1;
		FOR(i,Q.sz) {
			FOR(j,sa[Q[i]]) if (V[A[Q[i]][j]] == 0) {
				V[A[Q[i]][j]] = 1;
				if (K[Q[i]][j] == 0) ans = 0; else ans = (ans * K[Q[i]][j])%CC;
				F(Q[i],A[Q[i]][j]);
				Q.pb(A[Q[i]][j]);
			}
		}
		fprintf(fp1,"Case #%d: %I64d\n",t+1, ans);
		printf("Case #%d: %I64d\n",t+1, ans);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
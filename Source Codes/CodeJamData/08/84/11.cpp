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

int A[2][2000];

int main() {
	int CC = 30031;
	FILE *fp = fopen("D-small.in","r");
	FILE *fp1 = fopen("D-small.out","w");
	int t,tt;
	int i,j,k,N,K,P,p;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d%d",&N,&K,&P);
		memset(A,0,sizeof(A));
		p = 0;
		A[0][(1<<K)-1] = 1;
		FOR(k,N-K) {
			p = 1-p;
			memset(A[p],0,sizeof(A[p]));
			FOR(j,(1<<P)) {
				if (j == (1<<K)-1) { 
					j = j;
				}
				if (j % 2 == 1) {
					j /= 2;
					if (j % 2 != 0) { FOR(i,P) if ((j & (1<<i)) == 0) A[p][j+(1<<i)] = (A[p][j+(1<<i)] + A[1-p][1 + 2*j]) % CC; }
						else FOR(i,1) if ((j & (1<<i)) == 0) A[p][j+(1<<i)] = (A[p][j+(1<<i)] + A[1-p][1 + 2*j]) % CC;
					j = 1 + 2*j;
				} else A[p][j/2] = (A[p][j/2] + A[1-p][j]) % CC;
			}
		}
		fprintf(fp1,"Case #%d: %d\n",t+1, A[p][(1<<K)-1]);
		printf("Case #%d: %d\n",t+1, A[p][(1<<K)-1]);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
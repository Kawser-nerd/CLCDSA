// A.cc

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1024

using namespace std;

int p[maxn];
int P,K,L;

void solve(int cas){
	int i,j,k,res;
	scanf("%d%d%d",&P,&K,&L);
	for (i=0;i<L;i++) scanf("%d",p+i);
	res=0;
	sort(p,p+L);
	for (i=1,k=L-1;i<=P;i++){
		for (j=0;j<K;j++){
			if (k>=0) res+=i*p[k--];
		}
	}
	printf("Case #%d: %d\n",cas,res);
}

int main(){
	int t,cas;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (cas=1;cas<=t;cas++)
		solve(cas);
	return 0;
}

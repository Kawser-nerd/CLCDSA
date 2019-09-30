#include <stdio.h>
#include <string.h>
typedef long long ll;
int R,N,M,K;
int prod[100];

int num[20];

ll ans;

int analyze() {
	int i,j,P;
	char found[12];
	memset(found,0,K);
	for(i=0;i<(1<<K);i++) {
		P=1;
		for(j=0;j<N;j++) if(i&(1<<j)) P*=num[j];
		for(j=0;j<N;j++) if(prod[j]==P) found[j]=1;
	}
	for(j=0;j<N;j++) if(!found[j]) return 0;
	for(j=ans=0;j<N;j++) ans=ans*10+num[j];
	return 1;
}

int btr(int at,int last) {
	int i;
	if(at==N) return analyze();
	for(i=last;i<=M;i++) {
		num[at]=i;
		if(btr(at+1,i)) return 1;
	}
	return 0;
}

int main() {
	int T,i;
	scanf("%d",&T);
	scanf("%d %d %d %d",&R,&N,&M,&K);
	printf("Case #%d:\n",T);
	while(R--) {
		for(i=0;i<K;i++) scanf("%d",&prod[i]);
		ans=-1;
		btr(0,2);
		printf("%I64d\n",ans);
	}
	return 0;
}

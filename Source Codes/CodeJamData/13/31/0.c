#include<stdio.h>
#include<string.h>

int isvowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

char str[1000001];
int d[1000001];
int q[1000001];
int n,m;

int main() {
	int N,cs=0,i,sp;
	long long ret;
	for(scanf("%d",&N);N--;) {
		scanf("%s %d",str,&m);
		n=strlen(str);
		d[n]=sp=0;
		for(i=n-1;i>=0;i--) {
			if (isvowel(str[i])) d[i]=0; else d[i]=d[i+1]+1;
			if (d[i]>=m) q[sp++]=i;
		}
		for(ret=i=0;i<n && sp;i++) {
			int mn=q[sp-1]+m;
			ret+=n-mn+1;
			if (q[sp-1]==i) sp--;
		}
		printf("Case #%d: %lld\n",++cs,ret);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>

long long n;
long long f[16];

void reverse(char *s,int len) {
	int i;
	char t;
	for(i=0;i<len-i-1;i++) {
		t=s[i],s[i]=s[len-i-1],s[len-i-1]=t;
	}
}

int len(long long n) {
	char str[16];
	sprintf(str,"%lld",n);
	return strlen(str);
}

int main() {
	int N,cs=0,i,l;
	char str[16];
	long long ret,t,t1,t2,tt;
	for(f[0]=i=1;i<16;i++) f[i]=f[i-1]*10;
	for(scanf("%d",&N);N--;) {
		scanf("%lld",&n);
		ret=n;
		sprintf(str,"%lld",n);
		l=strlen(str);
		for(t=i=0;i<l-1;i++) {
			t+=f[(i+1)/2]-1+f[(i+1)-(i+1)/2];
			if (!i) t--;
		}
		ret=t+(n-f[l-1])+1;
//		fprintf(stderr,"%lld %d %lld\n",t,l,ret);
		for(t1=i=0;i<=l;i++) {
			sscanf(str+i,"%lld",&t2);
			tt=t1+t2+t+1;
			if (!t2) {
				tt=t+f[l-i]+1;
				if (t1<f[i-1]) {
					int l1 = len(t1);
//					printf("%lld %d\n",tt,l1);
					tt+=f[i]+t1-f[l1]-f[l1-1];
				} else tt+=t1-f[i-1];
			}
//			printf("%d %lld %lld %lld\n",i,t1,t2,tt);
			if (tt<ret) ret=tt;
			t1=t1+(str[i]-'0')*f[i];
		}
		printf("Case #%d: %lld\n",++cs,ret);
	}
	return 0;
}

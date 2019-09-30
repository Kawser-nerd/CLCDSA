#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[99];
int main(){
	int cnt=0;
	while(1){
		char c=getchar();
		if(c==10)break;
		if(c=='B'){
			if(cnt>0)s[--cnt]=0;
		}else{
			s[cnt++]=c;
		}
	}
	puts(s);
}
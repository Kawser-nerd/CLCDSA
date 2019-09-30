#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int s[26];
int main(){
	while(1){
		char c=getchar();
		if(c==10)break;
		s[c-'a']++;
	}
	rep(i,0,26)if(!s[i]){
		putchar('a'+i);
		return 0;
	}
	puts("None");
}
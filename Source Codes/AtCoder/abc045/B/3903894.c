#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[3][110];
int a[3];
int main(){
	scanf("%s%s%s",s[0],s[1],s[2]);
	int crr=0;
	while(1){
		if(s[crr][a[crr]]==0){
			putchar('A'+crr);
			return 0;
		}
		crr=s[crr][a[crr]++]-'a';
	}
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",s[0],s[1],s[2]);
  ^
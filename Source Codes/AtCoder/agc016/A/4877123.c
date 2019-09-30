#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int min(int x, int y){return x<y?x:y;}
int main(void){
	char S[101];
	scanf("%s",S);
	char s,U[101];
	int ans=101,l,ok;
	for(int i=0;i<26;i++){
		strcpy(U,S);
		l=strlen(S);
		s = 'a'+i;
		int c=0;
		ok=1;
		for(int j=0;j<l;j++){
			if(U[j]!=s)ok=0;
		}
		while(ok!=1){
			ok=1;
			for(int k=0;k<l-1;k++){
				if(U[k]==s || U[k+1]==s){
					U[k] = s;
				}else{
					ok=0;
				}
			}
			l--;
			c++;
		}
		ans = min(c,ans);
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^
#include<stdio.h>

int main(){
		int i,ans=0,j=0;char s[12][11];
		for(i=0;i<12;i++)scanf("%s",s[i]);
		for(i=0;i<12;i++){
				for(j=0;s[i][j]!=0;j++){
						if(s[i][j]=='r'){
								ans++;
								break;
						}
				}
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<12;i++)scanf("%s",s[i]);
                    ^
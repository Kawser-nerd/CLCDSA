#include<stdio.h>

int main(){
		char s[3][101];
		scanf("%s%s%s",s[0],s[1],s[2]);
		int si[3]={0},gen[3]={0},t=0,i;
		while(s[0][gen[0]]!=0)gen[0]++;
		while(s[1][gen[1]]!=0)gen[1]++;
		while(s[2][gen[2]]!=0)gen[2]++;
		while(1){
				for(i=0;i<3;i++){
						if(si[i]==gen[i]+1){
								printf("%c\n",'A'+i);
								return 0;
						}
				}
				t=s[t][si[t]++]-'a';				
//				printf("%d\n",t);
		}
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s%s",s[0],s[1],s[2]);
   ^
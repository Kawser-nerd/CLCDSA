#include<stdio.h>

int han(char s[],int gen){
		int i;
		for(i=0;i<gen/2;i++){
				if(s[i]!=s[i+gen/2])return 0;
		}
		return 1;
}

int main(){
		int i,gen=0;
		char s[201];
		scanf("%s",s);
		while(s[gen]!=0)gen++;
		for(i=gen-1;i>=0;i--){
				if(i%2==0){
						if(han(s,i)==1){
								printf("%d\n",i);
								return 0;
						}
				}
		}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
#include <stdio.h>
#include <string.h>

int main(void){
	int n,gc=0,pc=0,res=0;
	char s[100000];
	scanf("%s",s);
	n = strlen(s);
	for(int i=0;i<n;i++){
		if(s[i] == 'g'){
			if(pc < gc){
				pc++;
				res++;
			}else{
				gc++;
			}
		}else{
			if(pc < gc){
				pc++;
			}else{
				gc++;
				res--;
			}
		}
	}
	printf("%d\n",res);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
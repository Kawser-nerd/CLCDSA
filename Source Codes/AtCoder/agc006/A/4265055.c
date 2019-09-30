#include<stdio.h>

int main(){
	int n,i,sg=0,j;
	char s[101],t[101];
	scanf("%d%s%s",&n,s,t);
	for(i=n;i>=0;i--){
		int f=0;
		for(j=0;s[i+j]!=0;j++){
			if(s[i+j]!=t[j]){
				f=1;
				break;
			}
		}
		if(f!=1){
		sg=n-i;
	//		printf("%d\n",i);
	//		break;
		}
//		sg=n-i-1;
	}
	printf("%d\n",n*2-sg);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s%s",&n,s,t);
  ^
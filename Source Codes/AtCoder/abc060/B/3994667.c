#include<stdio.h>

int main(){
	int a,b,c,i;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<b;i++){
		if(a*i%b==c){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^
#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==5 && b==5){
		if(c==7) printf("YES\n");
		else printf("NO\n");
	}
	else if(b==5 && c==5){
		if(a==7) printf("YES\n");
		else printf("NO\n");
	}
	else if(c==5 && a==5){
		if(b==7) printf("YES\n");
		else printf("NO\n");
	}
	else printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^
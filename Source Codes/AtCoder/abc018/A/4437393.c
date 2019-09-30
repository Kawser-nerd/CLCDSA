#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b && a<c){
		if(b<c) printf("3\n2\n1\n");
		else printf("3\n1\n2\n");
	}
	if(b<c && b<a){
		if(c<a) printf("1\n3\n2\n");
		else printf("2\n3\n1\n");
	}
	if(c<a && c<b){
		if(a<b) printf("2\n1\n3\n");
		else printf("1\n2\n3\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^
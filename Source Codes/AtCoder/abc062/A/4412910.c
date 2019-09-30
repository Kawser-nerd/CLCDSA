#include <stdio.h>
int main(void){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12){
		if(y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12) printf("Yes\n");
		else printf("No\n");
	}
	else if(x==4 || x==6 || x==9 || x==11){
		if(y==4 || y==6 || y==9 || y==11) printf("Yes\n");
		else printf("No\n");
	}
	else if(x==2){
		if(y==2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&x,&y);
  ^
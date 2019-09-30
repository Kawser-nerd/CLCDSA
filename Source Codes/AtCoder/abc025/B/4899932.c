#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int n,a,b,x=0;
	scanf("%d%d%d",&n,&a,&b);
	char east[5]="East";
	for(int i=0;i<n;i++){
		char s[5];
		int d;
		scanf("%s%d",s,&d);
		if(strcmp(s,east)==0){
			if(a>d)d=a;
			if(d>b)d=b;
			x += d;
		}else{
			if(a>d)d=a;
			if(d>b)d=b;
			x-=d;
		}
	}
	if(x!=0){
		if(x>0)printf("East %d\n",x);
		else printf("West %d\n",-x);
	}
	else printf("%d\n",x);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&d);
   ^
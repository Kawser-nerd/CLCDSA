#include<stdio.h>

int main(){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b<=c||d<=a){
				puts("0");
				return 0;
		}
		if(a>c){
				if(b<d)printf("%d",b-a);
				else printf("%d",d-a);
		}
		else {	
				if(b<d)printf("%d",b-c);
				else printf("%d",d-c);
		}
		puts("");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^
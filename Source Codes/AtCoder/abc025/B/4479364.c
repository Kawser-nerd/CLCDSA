#include <stdio.h>
#include <stdlib.h>
int main(void){
	int n,a,b,d,kyori=0,i;
	char s[10];
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<n;i++){
		scanf("%s%d",s,&d);
		if(s[0]=='E'){
			if(d<a) kyori+=a;
			else if(d>b) kyori+=b;
			else kyori+=d;
		}
		if(s[0]=='W'){
			if(d<a) kyori-=a;
			else if(d>b) kyori-=b;
			else kyori-=d;
		}
	}
	if(kyori>0) printf("East %d\n",kyori);
	else if(kyori<0) printf("West %d\n",abs(kyori));
	else printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&d);
   ^
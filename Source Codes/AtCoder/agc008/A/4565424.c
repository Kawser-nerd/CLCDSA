#include<stdio.h>

int main(){
	long long x,y,ans=2000000000000;
	scanf("%ld%ld",&x,&y);
	if(y-x>=0&&y-x<ans)ans=y-x;
	if(y+x>=0&&1+y+x<ans)ans=1+y+x;
	if(-y-x>=0&&1-y-x<ans)ans=1-y-x;
	if(-y+x>=0&&2-y+x<ans)ans=2-y+x;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%ld%ld",&x,&y);
        ^
./Main.c:5:8: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld",&x,&y);
  ^
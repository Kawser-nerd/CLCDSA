#include <stdio.h>
#include <stdlib.h>
#define bit(n,m)(((n)>>(m))&1)

void f(int a,int b,int n,int fix){
	if(__builtin_popcount(fix)==n-1){
		printf("%d %d ",a,b);
		return;
	}
	int nfix=0;//fix????????a?b???bit???
	while(bit(fix,nfix)==1||bit(a^b,nfix)==0)nfix++;
	int dif=0;//fix????????nfix???bit???
	while(bit(fix,dif)==1||nfix==dif)dif++;
	
	f(a,a^(1<<dif),n,fix^(1<<nfix));
	f(a^(1<<dif)^(1<<nfix),b,n,fix^(1<<nfix));
}
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(__builtin_popcount(a^b)%2==0)puts("NO");
	else puts("YES"),f(a,b,n,0);
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
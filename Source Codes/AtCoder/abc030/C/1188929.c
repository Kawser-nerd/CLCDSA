#include<stdio.h>

int main(void){
	int n,m,x,y,a[131072],b[131072],i,t,r=0,sa,sb;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i = 1;i <= n;i++){scanf("%d\n",&a[i]);}
	for(i = 1;i <= m;i++){scanf("%d\n",&b[i]);}
	t = a[1]+x;
	sa = 1;
	sb = 1;
	while(1){
		if(b[m] < t){break;}
		for(i = sa;i <= m;i++){if(t <= b[i]){t = b[i]+y;sa = i+1;break;}}
		r++;
		if(a[n] < t){break;}
		for(i = sb;i <= n;i++){if(t <= a[i]){t = a[i]+x;sb = i+1;break;}}
	}
	printf("%d\n",r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&n,&m,&x,&y);
  ^
./Main.c:6:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%d\n",&a[i]);}
                        ^
./Main.c:7:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= m;i++){scanf("%d\n",&b[i]);}
                        ^
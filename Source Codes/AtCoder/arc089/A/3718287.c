#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))


int main(void)
{
	//?????
	int n;
	static int t[100010];
	static int x[100010];
	static int y[100010];
	
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int sum=0;
	llong int temp,temp1,temp2;
	int max,min;
	//int len;
	//????????
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&t[i],&x[i],&y[i]);
	}
	t[0]=0;
	x[0]=0;
	y[0]=0;
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	flag=1;
	for(i=1;i<=n;i++){
//		printf("%d %d\n",t[i]-t[i-1],abs(x[i]-x[i-1])+abs(y[i]-y[i-1]));
		if(t[i]-t[i-1]<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])||(t[i]-t[i-1]-abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))%2==1){
//			printf("i=%d?flag??\n",i);
			flag=0;
		}
	}
	
//	printf("??????\n");
	//??
	
	if(flag==0){
		printf("No");
	}else{
		printf("Yes");
	}
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&t[i],&x[i],&y[i]);
   ^
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))

int main(void)
{
	//?????
	int n,m;
	int a,b;
	int num[100010];
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	long long int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<100010;i++){
		num[i]=0;
	}
	
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		num[a]++;
		num[b]++;
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=1;i<=n;i++){
		if(num[i]%2==1) flag=1;
	}
	
	
//	printf("??????\n");
	//??
	
	if(flag==0){
		printf("YES");
	}else{
		printf("NO");
	}
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
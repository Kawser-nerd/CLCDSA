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
	int f[110][10];
	int p[110][10];
	int mise[110];
	
	//??????
	int i,j,k,l;
	int flag=0;
	llong int ans=0;
	int count=0;
	int sum=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<10;j++){
			scanf("%d",&f[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<=10;j++){
			scanf("%d",&p[i][j]);
		}
	}
	
	
//	for(i=0;i<n;i++){
//		for(j=0;j<=10;j++){
//			printf("%d ",p[i][j]);
//		}
//		printf("\n");
//	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	ans=-100000000000;
	for(i=1;i<1024;i++){
		for(j=0;j<n;j++){
			mise[j]=0;
		}
		sum=0;
		
		for(j=0;j<10;j++){
			if(i&(1<<j)){
				for(k=0;k<n;k++){
					mise[k]=mise[k]+f[k][j];
//					printf("f[0][%d]=%d\n",j,f[0][j]);
				}
			}
		}
		
		for(j=0;j<n;j++){
			sum=sum+p[j][mise[j]];
		}
		if(ans<sum) ans=sum;
//		printf("i=%d,mise[0]=%d,mise[1]=%d,sum=%d\n",i,mise[0],mise[1],sum);
	}
	
	
//	printf("??????\n");
	//??
	
	printf("%lld",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:37:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&f[i][j]);
    ^
./Main.c:43:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&p[i][j]);
    ^
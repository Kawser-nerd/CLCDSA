#include<stdio.h>
#include<stdlib.h>

#define big(a,b) ((a)>(b)?(a):(b))

int compare_int(const void *a, const void *b)
{
    return *(long*)b - *(long*)a;
}

int main(){
	int n,k,i;
	long td[100000][3]={0},max[100001]={0};
	long long ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%ld%ld",&td[i][0],&td[i][1]);
	for(i=0;i<=n;i++)max[i]=-1;
	for(i=0;i<n;i++){
		if(max[td[i][0]]==-1){
			td[i][2]=1;
			max[td[i][0]]=i;
		}else 
		if(td[max[td[i][0]]][1]<td[i][1]){
			td[max[td[i][0]]][2]=0;
			max[td[i][0]]=i;
			td[i][2]=1;
		}
	}
	long kot[2][100000]={0},k0c=0,k1c=0;
	for(i=0;i<=n;i++){
		if(td[i][2]==1){
			kot[1][i]=td[i][1];
			k1c++;
		}
		if(td[i][2]==0){
			kot[0][i]=td[i][1];
			k0c++;
		}
	}
	qsort(kot[0],100000,sizeof(long),compare_int);
	qsort(kot[1],100000,sizeof(long),compare_int);
	int c=k1c;
	long long x=0,y=big(0,k-c);
	for(i=0;i<y;i++)x+=kot[0][i];
	for(i=0;i<k-y;i++)x+=kot[1][i];
	while(1){
//		printf("%lld\n",x+(k-y)*(k-y));
		ans=big(ans,x+(k-y)*(k-y));
		if(y>=k||y>=k1c)break;
		x+=kot[0][y];
		x-=kot[1][k-y-1];
		y++;
	}
//	for(i=0;i<k1c;i++)printf("%ld\n",kot[1][i]);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:16:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%ld%ld",&td[i][0],&td[i][1]);
                  ^
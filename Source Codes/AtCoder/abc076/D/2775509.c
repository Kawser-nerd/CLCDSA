#include <stdio.h>

int t[105];
int v[105];

double maxv[50000];

double min(double a,double b){
	if(a<=b){return a;}
	else{return b;}
}

int main(){

	int N;

	scanf("%d",&N);

	int i,j;
	for(i=0;i<N;i++){
	scanf(" %d",&t[i]);
	}

	for(i=0;i<N;i++){
	scanf(" %d",&v[i]);
	}

	int sum=0;
	for(i=0;i<N;i++){
		for(j=sum;j<=sum+(t[i]*2);j++){
			if(maxv[j]>0){
			maxv[j]=min(maxv[j],(double)v[i]);
			}
			else{
			maxv[j]=(double)v[i];
			}
		}
		sum+=t[i]*2;
	}
	maxv[0]=0;
	maxv[sum]=0;
	for(i=1;i<=sum;i++){
	maxv[i]=min(maxv[i],maxv[i-1]+0.5);
	}
	for(i=(sum)-1;i>=0;i--){
	maxv[i]=min(maxv[i],maxv[i+1]+0.5);
	}

	double ans=0;

	for(i=0;i<sum;i++){
	ans+=(maxv[i]+maxv[i+1])/4.0;
	}
	printf("%lf\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %d",&t[i]);
  ^
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %d",&v[i]);
  ^
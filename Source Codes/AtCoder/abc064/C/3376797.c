#include<stdio.h>

int color[8];
int any;
int sum;

int main(){
	int N;
	scanf("%d",&N);
	int a[N];

	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		if(a[i]<400)color[0]=1;
		else if(a[i]<800)color[1]=1;
		else if(a[i]<1200)color[2]=1;
		else if(a[i]<1600)color[3]=1;
		else if(a[i]<2000)color[4]=1;
		else if(a[i]<2400)color[5]=1;
		else if(a[i]<2800)color[6]=1;
		else if(a[i]<3200) color[7]=1;
		else any++;
	}
	for(int i=0;i<8;i++)sum+=color[i];
	if(sum==0 && any>0){
		sum=1;
		any--;
	}
	printf("%d %d\n",sum,sum+any);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
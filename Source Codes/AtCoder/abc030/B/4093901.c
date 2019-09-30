#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main(){
	int n,m;
	float ji,hun,ans;
	scanf("%d%d",&n,&m);
	ji=(n%12)*30+m*(0.5);
	hun=m*6;
	if(ji>hun)ans=ji-hun;
	else ans=hun-ji;
	printf("%f\n",min(ans,360-ans));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
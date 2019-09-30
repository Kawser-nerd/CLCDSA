#include<stdio.h>

int main(){
	int n,i,yak[101]={0},j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int icp=i;
		for(j=1;j<=icp;j++){
			if(icp%j==0&&j!=1){
				yak[j]++;
				icp=icp/j;
				j=1;
			}
		}
	}
	//for(i=1;i<=100;i++)printf("%d,",yak[i]);
	int thr=0,fv=0,thfv=0,tf=0,ft=0,sf=0;
	for(i=0;i<=100;i++){
		//if(yak[i]>=2)thr++;
		if(yak[i]<=23&&yak[i]>=4)fv++;
		if(yak[i]>=2&&yak[i]<=3)thfv++;
		if(yak[i]>=24)tf++;
		if(yak[i]>=14)ft++;
		if(yak[i]>=74)sf++;
		
	}
	int ans=0;
	if(thfv>0)ans+=thfv*(tf+fv-1)*(tf+fv)/2;
	if(tf+fv>=3)ans+=(tf+fv)*(tf+fv-1)*(tf+fv-2)/2;
	if(tf>0)ans+=tf*(fv+thfv+tf-1);
	if(ft>0)ans+=ft*(tf+fv-1);
	ans+=sf;
	printf("%d\n",ans>0?ans:0);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
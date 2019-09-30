#include<stdio.h>
#include<math.h>

int main(){
		int xa,ya,xb,yb,i,t,v,n,xy[1000][2],f=0;
		scanf("%d%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&t,&v,&n);
		for(i=0;i<n;i++)scanf("%d%d",&xy[i][0],&xy[i][1]);
		double tmp=(double)(t*v),xyf,xys;
		for(i=0;i<n;i++){
				xyf=sqrt((double)((xa-xy[i][0])*(xa-xy[i][0]))+(double)((ya-xy[i][1])*(ya-xy[i][1])));
				xys=sqrt((double)((xb-xy[i][0])*(xb-xy[i][0]))+(double)((yb-xy[i][1])*(yb-xy[i][1])));
				if(tmp>=xyf+xys)f=1;
		}
		//printf("%f,%f,%f\n",tmp,xyf,xys);
		if(f==0)puts("NO");
		else puts("YES");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&t,&v,&n);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d%d",&xy[i][0],&xy[i][1]);
                   ^
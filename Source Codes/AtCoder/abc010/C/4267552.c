#include<stdio.h>
#include<math.h>
int main(void)
{
	int txa,tya,txb,tyb,T,V,n,x[1000],y[1000],i,l;
	scanf("%d %d %d %d %d %d",&txa,&tya,&txb,&tyb,&T,&V);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	l=T*V;
	double a,b;
	for(i=0;i<n;i++){
		a=(double)sqrt((txa-x[i])*(txa-x[i])+(tya-y[i])*(tya-y[i]));
		b=(double)sqrt((txb-x[i])*(txb-x[i])+(tyb-y[i])*(tyb-y[i]));
		if(a+b<=l){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d",&txa,&tya,&txb,&tyb,&T,&V);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x[i],&y[i]);
   ^
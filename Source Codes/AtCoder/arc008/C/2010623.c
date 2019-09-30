#include<stdio.h>
#include<math.h>
double MIN(double a,double b){return a<b?a:b;}
double MAX(double a,double b){return a<b?b:a;}
double d[1010][1010],co[1010],max=0;
int main(){
	int n,x[1010],y[1010],t[1010],c[1010],i,j,mi,f[1010]={};
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d %d %d",&x[i],&y[i],&t[i],&c[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)d[i][j]=hypot(x[i]-x[j],y[i]-y[j])/MIN(t[i],c[j]);
	}
	/*printf("%lf\n",MIN(t[2],c[3]));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)printf("%lf ",d[i][j]);
		printf("\n");
	}*/
	co[0]=mi=0;
	for(i=1;i<n;i++)co[i]=1e9;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(f[j])continue;
			if(mi==-1||co[mi]>co[j])mi=j;
		}
		for(j=0;j<n;j++)co[j]=MIN(co[j],co[mi]+d[mi][j]);
		f[mi]=1;
		mi=-1;
	}
	//for(i=0;i<n;i++)printf("%d %lf\n",i,co[i]);
	for(i=0;i<n;i++){
		max=co[i];
		for(j=i;j&&max>co[j-1];j--)co[j]=co[j-1];
		co[j]=max;
	}
	//for(i=0;i<n;i++)printf("%lf\n",co[i]);
	for(i=max=0;i<n-1;i++)max=MAX(max,co[i]+i);
	printf("%lf\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d %d %d %d",&x[i],&y[i],&t[i],&c[i]);
                  ^
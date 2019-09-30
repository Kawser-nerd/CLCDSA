#include<stdio.h>
#include<stdlib.h>
double s=0,d[1010][1010]={{},{0,1}};
int main(){
	int n,m,a,b,i,j;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	if(a%m+b%m||(n-a/m+b/m)%2){
		printf("0\n");
		return 0;
	}
	for(i=2;i<1010;i++){
		for(j=1;j<=i;j++)d[i][j]=(d[i-1][j]+d[i-1][j-1])/2;
	}
	/*for(i=0;i<5;i++){
		for(j=0;j<5;j++)printf("%f ",d[i][j]);printf("\n");
	}//*/
	a=abs(a/m);
	b=abs(b/m);
	for(i=a;i+b<=n;i+=2)s+=d[n+1][i+1]*d[i+1][(i+a)/2+1]*d[n-i+1][(n-i+b)/2+1];
	printf("%.14lf\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&n,&m,&a,&b);
  ^
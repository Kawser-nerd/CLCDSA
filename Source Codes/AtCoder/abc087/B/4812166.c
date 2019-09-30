#include<stdio.h>
int main(void)
{
	int i,j,k,a,b,c,x,cnt=0;
	scanf("%d %d %d %d",&a,&b,&c,&x);
	for(i=0;i<=a;i++){
		for(j=0;j<=b;j++){
			for(k=0;k<=c;k++){
				if(x==500*i+100*j+50*k){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&x);
  ^
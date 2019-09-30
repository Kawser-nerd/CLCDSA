#include<stdio.h>
int main(void)
{
	int i,n,x,a[1000]={0},s=0;
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int b[n];
	for(i=0;i<n;i++){
		if(x%2==1){
			b[i]=1;
		}else{
			b[i]=0;
		}
		x=x/2;
	}
	for(i=0;i<n;i++){
		if(b[i]==1){
			s+=a[i];
		}
	}
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&x);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
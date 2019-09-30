#include<stdio.h>
int A[20],B[20];
int main()
{
    int n,x,i,sum=0;
    scanf("%d%d",&n,&x);
    i=0;
    while(x!=0){
	B[i++]=x%2;
	x/=2;
    }
    for(i=0;i<n;i++){
	scanf("%d",&A[i]);
	if(B[i]) sum+=A[i];
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&x);
     ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&A[i]);
  ^
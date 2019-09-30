#include<stdio.h>

int main(void){
 int n,m,k,i,j,sum;
  int a[30],count[30]={0};
  sum=0;
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++){
   scanf("%d",&k);
   for(j=0;j<k;j++){
    scanf("%d",&a[j]);
    count[a[j]]++;
   }
 }
	for(i=0;i<=m;i++){
		if(count[i]==n) 
		sum++;
	}
    printf("%d",sum);
    return 0;
 } ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&k);
    ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[j]);
     ^
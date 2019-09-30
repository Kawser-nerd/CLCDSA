#include<stdio.h>
int main(){
	int A[200010],i,j,n,a=0,b=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		if(A[i]%4==0) b++;
		if(A[i]%2!=0) a++;
	}
	if(a+b==n){
		if(a<=b+1) printf("Yes\n");
		else printf("No\n");
	}
	else{
		if(a<=b) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^
#include <stdio.h>
int main(void){
	int n,q,i;
	scanf("%d %d",&n,&q);
	int l,r,s[200000]={0};
	for(i=0;i<q;i++){
		scanf("%d %d",&l,&r);
		s[l-1]++;
		s[r]--;
	}
	printf("%d",s[0]%2);
	for(i=1;i<n;i++){
		s[i]+=s[i-1];
		printf("%d",s[i]%2);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&q);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&l,&r);
   ^
#include<stdio.h>

int main(void) {
	int i,j,n,num[201],cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&num[i]);
	}
	while(1) {
		for(j=0;j<n;j++)
			if(num[j]%2==1)
				goto end;
		cnt++;
		for(j=0;j<n;j++) {
			num[j]/=2;
			if(num[j]%2==1)
				goto end;
		}
	}
	end:
	printf("%d",cnt);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&num[i]);
   ^
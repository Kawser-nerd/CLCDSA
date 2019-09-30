#include <stdio.h>
int main(void){
	int n,k,i,j;
	int a,b,p[101];
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for(i=0;i<k;i++){
		scanf("%d",&p[i]);
	}
	if(n<k+2){
		printf("NO\n");
		return 0;
	}
	for(i=0;i<k;i++){
		if(n<k+2) break;
		if(p[i]==a || p[i]==b){
			printf("NO\n");
			return 0;
		}
	}
	for(i=0;i<k;i++){
		if(n<k+2|| p[i]==a || p[i]==b) break;
		for(j=0;j<k;j++){
			if(i==j) continue;
			if(p[i]==p[j]){
				printf("NO\n");
				return 0;
			}
		}
		if(p[i]==p[j]) break;
	}
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&n,&a,&b,&k);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p[i]);
   ^
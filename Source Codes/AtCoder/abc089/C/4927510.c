#include <stdio.h>
int main(void){
	int n,i;
	long long ans = 0;
	long long a[5]={0};
	char s[11];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		if(s[0]=='M'){
			a[0]++;
		}else if(s[0]=='A'){
			a[1]++;
		}else if(s[0]=='R'){
			a[2]++;
		}else if(s[0]=='C'){
			a[3]++;
		}else if(s[0]=='H'){
			a[4]++;
		}
	}
	long long func(int x,int b,int c){
		return a[x]*a[b]*a[c];
	}
	ans = func(0,1,2) + func(0,1,3) + func(0,1,4)
	+ func(0,2,3) + func(0,2,4)+func(0,3,4)+func(1,2,3)+func(1,2,4)
	+ func(1,3,4)+func(2,3,4);
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
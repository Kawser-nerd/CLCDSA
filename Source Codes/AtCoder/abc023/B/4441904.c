#include <stdio.h>
int main(void){
	int n,l,r;
	char s[101];
	scanf("%d",&n);
	scanf("%s",s);
	if(s[n/2]!='b'){
		printf("-1\n");
		return 0;
	}
	l=0;
	r=n-1;
	while(l<r){
		if((s[l]=='a' && s[r]=='c') || (s[l]=='c' && s[r]=='a') || (s[l]=='b' && s[r]=='b')){
			l++;
			r--;
		}
		else{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",n/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
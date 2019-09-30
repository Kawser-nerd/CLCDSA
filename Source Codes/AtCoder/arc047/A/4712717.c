#include<stdio.h>

int main(){
	int n,l,i,ans=0,f=1;
	char s[100001];
	scanf("%d%d%s",&n,&l,s);
	for(i=0;i<n;i++){
		if(s[i]=='+')f++;
		else f--;
		if(f>l){
			ans++;
			f=1;
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s",&n,&l,s);
  ^
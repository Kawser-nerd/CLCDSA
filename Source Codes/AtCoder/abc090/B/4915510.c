#include <stdio.h>

int check(int x){
	char s[6];
	snprintf(s,6,"%d",x);
	if(s[0]==s[4] && s[1]==s[3]){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int a,b;
	int i,ans=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++){
		if(check(i)==1){
			ans ++;
		}
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^
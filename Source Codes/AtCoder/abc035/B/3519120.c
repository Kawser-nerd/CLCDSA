#include <stdio.h>
#include <string.h>
int abs(int x){return x>0?x:-x;}
int max(int x, int y){return x<y?y:x;}
int main(void){
	char s[100000];
	int t,i,x=0,y=0,ans,z=0;
	scanf("%s %d",s,&t);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='?')z++;
	}
	if(t==1){
		ans=abs(x)+abs(y)+z;
	}else{
		ans=max(abs(x)+abs(y)-z,strlen(s)%2);
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %d",s,&t);
  ^
#include<stdio.h>
#include<stdlib.h>

int main(){
	char s[100001];
	int t,x=0,y=0,hat=0,i;
	scanf("%s%d",s,&t);
	for(i=0;s[i]!=0;i++){
		if(s[i]=='R')x++;
		if(s[i]=='L')x--;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='?')hat++;
	}
	if(t==1){
		printf("%d\n",abs(x)+abs(y)+hat);
	}else{
		if(abs(x)+abs(y)<=hat){
			if((hat-abs(x)-abs(y))%2==0){
				puts("0");
			}else puts("1");
		}else printf("%d\n",abs(x)+abs(y)-hat);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d",s,&t);
  ^
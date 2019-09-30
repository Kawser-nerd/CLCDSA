#include<stdio.h>
int T;
char s[201];
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%s",s);
		char *t=s+1;
		int ans=1;
		while(*t){
			if(*t!=*(t-1)) ++ans;
			++t;
		}
		if(*(t-1)=='+') --ans;
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

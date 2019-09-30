#include <stdio.h>

int main(){
	int t,n,tt,i,res,tmp;
	char s[2008];
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		scanf("%d %s",&n,s);
		res=tmp=0;
		for(i=0;i<=n;i++){
			if(s[i]=='0')continue;
			if(tmp<i){
				res+=(i-tmp);
				tmp=i;
			}
			tmp+=(s[i]-48);
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}

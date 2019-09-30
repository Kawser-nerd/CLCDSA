#include<stdio.h>
#include<string.h>
int tcn,tc;
int n;
char s[20100];
char stk[20100];
int sp;
int main(){
	int i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%s",&s);
		n=strlen(s);
		sp=0;
		for(i=0;i<n;i++){
			if(sp==0||stk[sp-1]!=s[i]){
				stk[sp]=s[i];
				sp++;
			}
			else sp--;
		}
		printf("Case #%d: %d\n",tc,(n-sp/2)*5);
	}
	return 0;
}
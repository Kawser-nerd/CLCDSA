#include <stdio.h>
#include <string.h>
#define ll long long
int main(void)
{
	char s[11];
	int len,i,j;
	ll t,sum,res=0;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<(1<<(len-1));i++){
		t=sum=0;
		for(j=0;j<len;j++){
			t=t*10+(s[j]-'0');
			 if(i>>j&1||j==len-1) sum+=t,t=0;
		}
		res+=sum;
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
#include <stdio.h>
#include <string.h>
#define rep(i,n) for(i=0;i<n;i++)
int main(void){
	int i,k=0,n=0,f[26]={};
	char s[100001];
	scanf("%s",s);
	rep(i,strlen(s))f[s[i]-'a']++;
	rep(i,26){
		k+=f[i]%2;
		n+=f[i]/2;
	}
	if(k<=1)printf("%d\n",strlen(s));
	else printf("%d\n",n/k*2+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
  if(k<=1)printf("%d\n",strlen(s));
                 ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
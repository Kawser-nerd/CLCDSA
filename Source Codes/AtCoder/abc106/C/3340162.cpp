#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char s[1005];
long long k;
int main(){
	scanf("%s",s);
	scanf("%lld",&k);
	int ans=0;
	while(s[ans]=='1'&&ans<strlen(s)-1)ans++;
	if(k<ans+1)printf("1");
	else printf("%c",s[ans]);
}
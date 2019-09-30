#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	int ans=0;
	for(int i=1;i<n;i++)ans+=s[i]!=s[i-1];
	printf("%d",ans);
	return 0;
}
#include<cstdio>
#include<cstring>
long long cnt[200];
char s[300000];
int main()
{
	scanf("%s",s);
	long long n=strlen(s);
	for(int i=0;i<n;i++)cnt[s[i]]++;
	long long tot=0;
	for(int i='a';i<='z';i++)tot+=cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",n*(n-1)/2-tot+1);
}
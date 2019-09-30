#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005];
int main()
{	
	scanf("%s",s+1);
	int n=strlen(s+1),ans=0;
	for(int i=1;i<n;i++)ans+=(s[i]!=s[i+1]);
	cout<<ans;
	return 0;
}
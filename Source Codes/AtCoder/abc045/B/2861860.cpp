#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define	 N 101
char s[4][N+5];
int lens[4];
queue<char> S[4];
int main()
{
	scanf("%s %s %s",s[1]+1,s[2]+1,s[3]+1);
	lens[1]=strlen(s[1]+1);
	lens[2]=strlen(s[2]+1);
	lens[3]=strlen(s[3]+1);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=lens[i];j++)
	{
		if(i==1)
			S[1].push(s[1][j]);
		if(i==2)
			S[2].push(s[2][j]);
		if(i==3)
			S[3].push(s[3][j]);
	}
	int t=1;
	while(!S[t].empty())
	{
		int f=S[t].front();
		S[t].pop();
		t=f-'a'+1;
	}
	printf("%c",t+'a'-1-32);
 }
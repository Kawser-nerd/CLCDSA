#include<cstdio>
using namespace std;
char s[110][110];
int n,m;
int main()
{
	scanf("%d%d",&n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf(" %c", &s[i][j]);
		
	}
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<m;j++)
			if(s[i][j]=='#')
				flag=true;
		if(flag==true)
			continue;
		for(int j=0;j<m;j++)
			s[i][j]='/';
	}
	for(int i=0;i<m;i++)
	{
		bool flag=false;
		for(int j=0;j<n;j++)
			if(s[j][i]=='#')
				flag=true;
		if(flag==true)
			continue;
		for(int j=0;j<n;j++)
			s[j][i]='/'; 
	}
	for(int i=0;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<m;j++)
			if(s[i][j]!='/')
			{
				printf("%c", s[i][j]);
				flag=true;
			}
		if(flag==true)
			printf("\n");
	}	
	return 0;
 }
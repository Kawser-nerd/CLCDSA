#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[205][205];
int main()
{
 freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int T,t,t1,t2,i,j,k,n,m,flag;
  scanf("%d",&T);
  for (t=1;t<=T;t++)
  {
	scanf("%d%d",&n,&m);
	t1=t2=0;
	for (i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
		if (s[i][j]!='.')
		{
		  t2++;
		  flag=0;
		  if (s[i][j]=='<') 
			for (k=1;j-k>=1;k++)
			  if (s[i][j-k]!='.') flag=1;
		  if (s[i][j]=='>')
			for (k=1;j+k<=m;k++)
			  if (s[i][j+k]!='.') flag=1;
		  if (s[i][j]=='^')
			for (k=1;i-k>=1;k++)
			  if (s[i-k][j]!='.') flag=1;
		 if (s[i][j]=='v')
		   for (k=1;i+k<=n;k++)
			 if (s[i+k][j]!='.') flag=1;
		 if (flag==0) t1++;
		}
	t2=0;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
		if (s[i][j]!='.')
		{
		  flag=0;
		  for (k=1;k<=m;k++)
			if (k!=j&&s[i][k]!='.') flag=1;
		  for (k=1;k<=n;k++)
			if (k!=i&&s[k][j]!='.') flag=1;
		  if (flag==0) t2++;
		}
	printf("Case #%d: ",t);
	if (t2!=0) printf("IMPOSSIBLE\n");
	else printf("%d\n",t1);
  }
  return 0;  
}

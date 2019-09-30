#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define st vector <string>
#define in(x,y) x>=0 && x<y
#define lim 5
#define pb push_back

int cs,c,i,j,x,y,n,m;
map <st,int> M;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char str[lim];

int solve(st V)
{
  int &res=M[V],i,j,x,y,x2,y2;
  st V2;
  
  if(res==0)
  {
    res=1;
    for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	    if(V[i][j]=='K')
		{
		  x=i;
		  y=j;
		}
    for(i=0;i<8;i++)
	{
	  x2=x+dx[i];
	  y2=y+dy[i];
	  if(in(x2,n) && in(x2,n) && V[x2][y2]=='.')
	  {
	    V2=V;
		V2[x][y]='k';
		V2[x2][y2]='K';
		if(solve(V2)==0)
		  res=2;
	  }
	}
  }
  return res-1;
}
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d %d",&n,&m);
	vector <string> V;
	for(i=0;i<n;i++)
	{
	  scanf("%s",str);
      V.pb(str);
	  for(j=0;j<strlen(str);j++)
	    if(str[j]+='K')
		{
		  x=i;
		  y=j;
		}
	}
	printf("Case #%d: ",c);
	M.clear();
	if(solve(V)==0)
	  printf("B\n");
	else
	  printf("A\n");
  }
  return 0;
}

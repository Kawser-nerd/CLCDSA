#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
#define p(x) ;//cout<<#x<<":"<<x<<"\n"
#define lim 1001
#define pb push_back
#define lim2 21

int cs,c,i,j,n;
map <string,int> M2;
vector <int> V[lim];
int M[lim],A[lim];
char N[lim][lim2],N2[lim][lim2][lim2];

int solve(int k)
{
  int &res=M[k],i,x,y,z;
  
  if(res==-1)
  {
    if(V[k].size()==0)
	  res=1;
	else
	{
	  vector <int> V2;
	  for(i=0;i<V[k].size();i++)
	    V2.pb(solve(V[k][i]));
      sort(V2.begin(),V2.end());
      reverse(V2.begin(),V2.end());
	  x=V2[0];
	  y=V2[0]-1;
	  p(x);
	  for(i=1;i<V2.size();i++)
	  {
	    if(V2[i]<=y)
		  y--;
		else
		{
		  z=V2[i]-y;
		  p(z);
		  x+=z;
		  y+=z-1;
		}
		p(x);
	  }
	  res=x;
	  p(y);
	  if(y==0)
	    res++;
	}
//	printf("%d %d\n",k,res);
  }
  return res;
}
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
	M2.clear();
	for(i=1;i<=n;i++)
	{
	  scanf("%s",N[i]);
	  scanf("%d",&A[i]);
	  for(j=0;j<A[i];j++)
	    scanf("%s",N2[i][j]);
	  M2[N[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
	  V[i].clear();
	  for(j=0;j<A[i];j++)
	    if(isupper(N2[i][j][0]))
		  V[i].pb(M2[N2[i][j]]);
	}
	memset(M,-1,sizeof M);
    printf("Case #%d: %d\n",c,solve(1));
  }
  return 0;
}

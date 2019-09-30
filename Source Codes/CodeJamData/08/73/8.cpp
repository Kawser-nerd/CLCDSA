#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 40001
#define lim2 31

int cs,c,i,j,k,n,m;
double s;
double M[lim],M2[lim],A[lim2][5];

int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
	  for(j=0;j<4;j++)
	    scanf("%lf",&A[i][j]);
    for(i=0;i<m;i++)
	  M[i]=0;
	M[0]=1;
	for(i=0;i<n;i++)
	{
	  memcpy(M2,M,sizeof M);
	  for(j=0;j<4*m;j++)
	    M[j]=0;
      for(j=0;j<m;j++)
	    for(k=0;k<4;k++)
		  M[4*j+k]=M2[j]*A[i][k];
	  sort(M,M+4*m);
	  reverse(M,M+4*m);
	}
	s=0;
    for(i=0;i<m;i++)
	  s+=M[i];
    printf("Case #%d: %lf\n",c,s);
  }
  return 0;
}

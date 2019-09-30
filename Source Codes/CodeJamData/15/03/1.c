#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int id(char c)
{
  if (c=='i') return 2;
  if (c=='j') return 3;
  if (c=='k') return 4;
}
int mul(int x,int y)
{
  int f=1;
  if (x<0) f=-1,x=-x;
  if (x==1)
	return f*y;
  else if (x==2){
	if (y==2) return -f;
	if (y==3) return f*4;
	if (y==4) return f*(-3);
  }
  else if (x==3){
	if (y==2) return f*(-4);
	if (y==3) return -f;
	if (y==4) return f*2;
  }
  else if (x==4){
	if (y==2) return f*3;
	if (y==3) return f*(-2);
	if (y==4) return -f;
  }
}
char s[10005];
int main()
{
  int T,t,l,i,j,x,judge;
  long long n;
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++){
	scanf("%d%lld",&l,&n);
	scanf("%s",s);
	if (n>12) n=n%4+12;
	judge=0; x=1;
	for (i=1;i<=n;i++)
	  for (j=0;j<l;j++)
	  {
		x=mul(x,id(s[j]));
		if (x==2&&judge==0) judge++;
		if (x==4&&judge==1) judge++; 
	  }
	if (x==-1&&judge==2) judge++;
	if (judge==3) printf("Case #%d: YES\n",t);
	else printf("Case #%d: NO\n",t);
  }
  return 0;
}

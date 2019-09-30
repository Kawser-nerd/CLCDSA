#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
  int T,t,x,r,c,judge;
//  freopen("1.in","r",stdin);
//  freopen("1.out","w",stdout);
  scanf("%d",&T);
  for (t=1;t<=T;t++)
  {
	scanf("%d%d%d",&x,&r,&c);
	printf("Case #%d: ",t);
	judge=0;
	if (x==1) judge=1;
	if (x==2&&(r%2==0||c%2==0)) judge=1;
	if (x==3&&((r%3==0&&c>=2)||(r>=2&&c%3==0))) judge=1;
	if (x==4&&r*c%4==0&&((r>=4&&c>=3)||(r>=3&&c>=4))) judge=1; 
	if (x==5&&(r!=5||c!=3)&&(r!=3||c!=5))
	  if (r%5==0&&c>=3||c%5==0&&r>=3) judge=1;
	if (x==6&&(r*c%6==0&&r>=4&&c>=4)) judge=1;
	if (judge)  printf("GABRIEL\n");
	else printf("RICHARD\n");
  }
  return 0;
}

#include<cstdio>
using namespace std;
int a,b;
int main()
{
  scanf("%d%d",&a,&b);
  if(a<=0&&b>=0)
    return puts("Zero"),0;
  if(a<0)
   	puts((b-a)&1?"Positive":"Negative");
  else
	puts("Positive");
}
//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<ctime>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int a[1000];

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      for(int i=0;i<n;i++)
        a[i]=get();
      int ans0=0;
      for(int i=1;i<n;i++)
        ans0+=max(a[i-1]-a[i],0);
      int m=0;
      for(int i=1;i<n;i++)
        m=max(m,a[i-1]-a[i]);
      int ans1=0;
      for(int i=1;i<n;i++)
        ans1+=min(m,a[i-1]);
      printf("Case #%d: %d %d\n",test,ans0,ans1);
    }
  return 0;
}

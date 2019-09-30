//program B

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

long long a[1000];

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      long long m=get();
      for(int i=0;i<n;i++)
        a[i]=get();
      long long Left=0,Right=m*100000;
      while(Left<Right)
        {
          long long mid=(Left+Right)/2;
          long long cnt=0;
          for(int i=0;i<n&&cnt<m;i++)
            cnt+=mid/a[i]+1;
          if(cnt>=m)
            Right=mid;
          else
            Left=mid+1;
        }
      for(int i=0;i<n;i++)
        m-=(Left-1)/a[i]+1;
      int ans=-1;
      for(int i=0;ans==-1&&i<n;i++)
        if(!(Left%a[i]))
          {
            m--;
            if(!m)
              ans=i;
          }
      printf("Case #%d: %d\n",test,ans+1);
    }
  return 0;
}

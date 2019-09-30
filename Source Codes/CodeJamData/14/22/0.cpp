//program B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>

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

int a[30],b[30],c[30];
bool flag[30][2][2][2];
long long f[30][2][2][2];

long long dp(int n,bool fx,bool fy,bool fz)
{
  if(n<0)
    return fx&&fy&&fz;
  if(flag[n][fx][fy][fz])
    return f[n][fx][fy][fz];
  long long ans=0;
  for(int x=0;x<2;x++)
    for(int y=0;y<2;y++)
      {
        if(!fx&&x&&!a[n])
          continue;
        if(!fy&&y&&!b[n])
          continue;
        if(!fz&&x&&y&&!c[n])
          continue;
        ans+=dp(n-1,fx||(x<a[n]),fy||(y<b[n]),fz||((x&y)<c[n]));
      }
  flag[n][fx][fy][fz]=true;
  return f[n][fx][fy][fz]=ans;
}

int main()
{
  freopen("B.in","r",stdin);
  //freopen("B.out","w",stdout);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int x=get(),y=get(),z=get();
      for(int i=0;i<30;i++)
        {
          a[i]=x%2;x/=2;
          b[i]=y%2;y/=2;
          c[i]=z%2;z/=2;
        }
      memset(flag,0,sizeof(flag));
      printf("Case #%d: ",test);
      cout<<dp(29,0,0,0)<<endl;
    }
  return 0;
}

//Google Code Jam 2016, Round 1A, Problem C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<map>

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

int p[1000],path[1000];
bool flag[1000];

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      for(int i=0;i<n;i++)
        p[i]=get()-1;
      int ans=0;
      memset(path,0,sizeof(path));
      for(int i=0;i<n;i++)
        {
          memset(flag,0,sizeof(flag));
          int len=1,x=i,pre=-1;
          flag[x]=true;
          while(!flag[p[x]])
            {
              pre=x;
              x=p[x];
              flag[x]=true;
              len++;
            }
          if(p[x]==i)
            ans=max(ans,len);
          if(p[x]==pre&&x!=pre)
            path[pre]=max(path[pre],len-1);
        }
      int sum=0;
      for(int i=0;i<n;i++)
        sum+=path[i];
      ans=max(ans,sum);
      printf("Case #%d: ",test);
      output(ans);
    }
  return 0;
}

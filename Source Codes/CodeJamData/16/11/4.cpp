//Google Code Jam 2016, Round 1A, Problem A

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

int main()
{
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      string s;
      cin>>s;
      string ans="";
      for(int i=0;i<s.size();i++)
        {
          string a=s[i]+ans,b=ans+s[i];
          ans=max(a,b);
        }
      printf("Case #%d: ",test);
      cout<<ans<<endl;
    }
  return 0;
}

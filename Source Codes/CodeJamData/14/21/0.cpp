//program A

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

int main()
{
  freopen("A.in","r",stdin);
  //freopen("A.out","w",stdout);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int n=get();
      vector<pair<char,int> > s[100];
      for(int i=0;i<n;i++)
        {
          s[i].clear();
          char c;
          while(c=getchar(),c<'a'||c>'z');
          while(c>='a'&&c<='z')
            {
              if(s[i].empty()||(c!=s[i][s[i].size()-1].first))
                s[i].push_back(make_pair(c,1));
              else
                s[i][s[i].size()-1].second++;
              c=getchar();
            }
        }
      bool fail=false;
      for(int i=1;!fail&&i<n;i++)
        {
          bool same=(s[i].size()==s[i-1].size());
          for(int j=0;same&&j<s[i].size();j++)
            same=(s[i][j].first==s[i-1][j].first);
          fail=!same;
        }
      if(fail)
        printf("Case #%d: Fegla Won\n",test);
      else
        {
          int ans=0;
          for(int i=0;i<s[0].size();i++)
            {
              static int x[100];
              for(int j=0;j<n;j++)
                x[j]=s[j][i].second;
              sort(x,x+n);
              for(int j=0,k=n-1;j<k;j++,k--)
                ans+=x[k]-x[j];
            }
          printf("Case #%d: %d\n",test,ans);
        }
    }
  return 0;
}

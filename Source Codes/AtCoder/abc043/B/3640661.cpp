#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define Di 3.1415926
#include<math.h>
#include<string>
#include<stack>
#define INF 0x3f3f3f3f
using namespace std;
ll  gcd(ll a,ll b)
{
    return a%b? gcd(b,a%b):b;
}
int main()
{   stack<char>w;
      string s;
      cin>>s;
      char a[20];
     int len =s.length();
     for(int i=0;i<len;i++)
     {
         if(s[i]=='0')
            w.push('0');
         else if(s[i]=='1')
            w.push('1');
            else if(s[i]=='B')
            {
              if(!w.empty())
              {
                  w.pop();
              }
            }

     }
     int i=0;
     while(!w.empty() )
     {
         a[i]=w.top();
         w.pop();
         i++;

     }
     for(int j=i-1;j>=0;j--)
        cout<<a[j];
     cout<<endl;

 return 0;
}
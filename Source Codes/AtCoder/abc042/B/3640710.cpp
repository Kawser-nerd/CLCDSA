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
struct Node
{
    int t;
    char a[102];
}s[102];
bool cmp(Node a,Node b)
{
    return strcmp(a.a,b.a)<0;
}
int main()
{    int m,n,i,j;
     cin>>m>>n;
     for(i=0;i<m;i++)
     {
         cin>>s[i].a;
         s[i].t=i+1;
     }
     sort(s,s+m,cmp);
   /*  for(i=0;i<m-1;i++)
     {
         for(j=0;j<m-1-i;j++)
         {
             if(strcmp(s[i].a,s[j].a))
             {
                 int t=s[i].t;
                 s[i].t=s[j].t;
                 s[j].t=t;
             }
         }
     }*/
    // sort(s,s+m,cmp);
     for(i=0;i<m;i++)
     {
         cout<<s[i].a;
     }
     cout<<endl;

 return 0;
}
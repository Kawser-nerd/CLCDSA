#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct ns
{
    string s;
};
int cmp(ns a,ns b)
{
    return a.s<b.s;
}
int main()
{
    ns s[200];
    int n,l;
    while(cin>>n>>l)
    {
      for(int i=0;i<n;i++)
        cin>>s[i].s;
      sort(s,s+n,cmp);
      for(int i=0;i<n;i++)
        cout<<s[i].s;
        cout<<endl;
    }
    return 0;
}
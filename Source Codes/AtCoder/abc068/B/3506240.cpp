#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int a,b,cou,maxn;
    while(cin>>b&&b>=1&&b<=100)
    {
         maxn=0;
    for(int i=1;i<=b;i++)
    {
        int t=i;
        cou=0;
    while(t%2==0)
    {
        t=t/2;
        cou++;
    }
    if(cou>=maxn)
        {maxn=cou;
        a=i;}
    }
        cout<<a<<endl;

    }
return 0;
    }
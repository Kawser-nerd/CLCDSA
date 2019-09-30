#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll a,b,x;
int main()
{
    cin>>a>>b>>x;
    cout<<b/x-a/x+(bool)(a%x==0);
    return 0;
}
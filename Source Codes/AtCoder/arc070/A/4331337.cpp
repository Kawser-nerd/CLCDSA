#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans = 1, t = 1;
    while(t < n){
        ans++;
        t = (1+ans)*ans/2;
    }
    cout<<ans;


    return 0;
}
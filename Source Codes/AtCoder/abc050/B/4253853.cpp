#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int n;
    int t[100005];
    int sum = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>t[i];
        sum += t[i];
    }
    int m;
    cin>>m;
    for(int i = 1; i <= m; i++){
        int p, x;
        cin>>p>>x;
        cout<<sum-t[p]+x<<endl;
    }


    return 0;
}
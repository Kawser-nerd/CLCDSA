#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        ans = ans*i%1000000007;
    }
    cout<<ans;

    return 0;
}
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int n;
    int t = 0, ans = 0;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'I')t++;
        else if(s[i] == 'D')t--;
        ans = max(ans, t);
    }
    cout<<ans;

    return 0;
}
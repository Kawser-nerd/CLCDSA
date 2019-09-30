#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int k, s, ans = 0;
    cin>>k>>s;
    if(s == 3*k){
        ans = 1;
    }
    else {
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                if(i+j <= s && i+j >= s-k)ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
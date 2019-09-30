#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int w, a, b, ans;
    cin>>w>>a>>b;
    if(a > b){
        if(b+w <= a){
            ans = a-b-w;
        }
        else ans = 0;
    }
    else if(a == b){
        ans = 0;
    }
    else if(a < b){
        if(a+w >= b){
            ans = 0;
        }
        else ans = b-a-w;
    }
    cout<<ans;

    return 0;
}
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int a, b;
    string ans;
    cin>>a>>b;
    if(a == 1){
        if(b == 1){
            ans = "Draw";
        }
        else ans = "Alice";
    }
    else if(b == 1){
        if(a == 1){
            ans = "Draw";
        }
        else ans = "Bob";
    }
    else if(a > b)ans = "Alice";
    else if(a < b)ans = "Bob";
    else ans = "Draw";
    cout<<ans;


    return 0;
}
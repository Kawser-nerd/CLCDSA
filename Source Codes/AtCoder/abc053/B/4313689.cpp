#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a, z;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] == 'A'){
            a = i;
            break;
        }
    }
    for(int i = len-1; i >= 0; i--){
        if(s[i] == 'Z'){
            z = i;
            break;
        }
    }
    int ans = z-a+1;
    if(ans < 0)ans = 0;
    cout<<ans;


    return 0;
}
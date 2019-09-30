#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

char s[14];
int n;

int f(ll x,int i){
    if(i==n)return x%2==0 || x%3==0 || x%5==0 || x%7==0;
    if(i>n)return 0;
    int res=0;
    ll y=0;
    for(int j=i;j<n;++j){
        y=y*10+s[j]-'0';
        res+=f(x+y,j+1);
        if(i)res+=f(x-y,j+1);
    }
    return res;
}

int main(){
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    int tc=0,T;
    for(cin>>T;tc++<T;){
        cin>>s;
        n=strlen(s);
        printf("Case #%d: %d\n",tc,f(0,0));
    }
    return 0;
}

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
typedef pair<int,int> pii;

void Solve(){
    string s;cin>>s;
    map<char,int> F;
    int base=2;
    for(int i=0;i<s.size();++i){
        char c=s[i];
        if(F.count(c))continue;
        int v=F.size();
        if(v<2)v^=1;
        F[c]=v;
        base>?=v+1;
    }
    unsigned long long res=0;
    for(int i=0;i<s.size();++i)
        res=res*base+F[s[i]];
    cout<<res<<endl;
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    int a=0,b;
    for(cin>>b;a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}

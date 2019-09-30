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
typedef vector<int> vi;

#define pb  push_back

#define REP(i,n)    for(int i=0;i<n;++i)

void Solve(){
    int n;
    cin>>n;
    vi a;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        vector<char> v(s.begin(),s.end());
        while(v.size() && v.back()=='0')v.pop_back();
        a.pb(v.size());
    }
    int res=0;
    while(a.size()){
        int i=0;
        for(;i<a.size() && a[i]>1;++i);
        res+=i;
        a.erase(a.begin()+i);
        REP(i,a.size())a[i]--;
    }
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

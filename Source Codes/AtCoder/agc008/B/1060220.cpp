#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
vector<string> split(const string &str, char sep){
    std::vector<std::string> v;
    auto first = str.begin();
    while(first != str.end()){
        auto last = first;
        while(last != str.end() && *last != sep) ++last;
        v.push_back(std::string(first,last));
        if(last!=str.end()) ++last;
        first=last;
    }
    return v;
}

int n,k;
int a[100000];
long long b[100001];
long long c[100001];
int main(){
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    b[0]=c[0]=0;
    rep(i,n){
        if(a[i]>0) b[i+1]=b[i]+a[i];
        else b[i+1]=b[i];
        c[i+1]=c[i]+a[i];
    }
    long long ans=0;
    rep(i,n-k+1){
        ans=max(ans,b[i]+max((long long)0,c[i+k]-c[i])+b[n]-b[i+k]);
    }
    cout<<ans<<endl;
    return 0;
}
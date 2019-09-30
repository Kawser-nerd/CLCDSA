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
long long ai,ao,at,aj,al,as,az;
long long ans;
int main(){
    cin>>ai>>ao>>at>>aj>>al>>as>>az;
    ans=ao;
    int x=min({ai,aj,al});
    rep(i,min(10,x+1)){
        ans=max(ans,ao+i*3+((ai-i)/2)*2+((aj-i)/2)*2+((al-i)/2)*2);
    }
    cout<<ans<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
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
int n;
int slot[250000];
set<int> l;
void rev(){
    int slot2[250000];
    rep(i,n*n){
        slot2[i]=slot[n*n-i-1];
    }
    rep(i,n*n){
        slot[i]=slot2[i];
    }
}
int main(){
    cin>>n;
    rep(i,n){
        int x;
        cin>>x;
        if (slot[x-1]!=0){
            cout<<"No"<<endl;
            return 0;
        }
        slot[x-1]=i+1;
    }
    rep(i,n*n){
        if (slot[i]!=0 and l.find(slot[i])==l.end()){
            l.insert(slot[i]);
            int cnt=slot[i]-1;
            if (cnt==0) continue;
            rep(j,i){
                if (slot[j]==0) {
                    slot[j]=slot[i];
                    cnt-=1;
                    if (cnt==0) break;
                }
            }
            if (cnt!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    l.clear();
    rev();
    rep(i,n*n){
        if (slot[i]!=0 and l.find(slot[i])==l.end()){
            l.insert(slot[i]);
            int cnt=n-slot[i];
            if (cnt==0) continue;
            rep(j,i){
                if (slot[j]==0) {
                    slot[j]=slot[i];
                    cnt-=1;
                    if (cnt==0) break;
                }
            }
            if (cnt!=0){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    rev();
    cout<<"Yes"<<endl;
    rep(i,n*n-1) cout<<slot[i]<<" ";
    cout<<slot[n*n-1]<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include <set>
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
int main(){
    int N,s,e,K;
    cin >> N >> s >> e >> K;

    map <int ,int > m;
    m[s]++;
    m[e]++;

    REP(i,K){
        int a;cin >>a;
        m[a]++;
    }
    bool fl = true;
    for(auto x:m){
        if(x.second>1) fl = false;
    }

    if(fl){
        cout <<"YES" <<endl;
    }else{
        cout << "NO" <<endl;
    }
}
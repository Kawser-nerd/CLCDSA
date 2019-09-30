#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

vector<int>a,b;
vector<vector<int> > v;
vector<bool>flag;
string p;
void bfs(int x){
    if(flag[x])return;
    if(a[x]>0&&b[x]>0)return;
    flag[x] = 1;
    for(auto y:v[x]){
        if(flag[y])continue;
        if(p[x]=='A'){
            a[y]--;
            bfs(y);
        }
        if(p[x]=='B'){
            b[y]--;
            bfs(y);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m >> p;
    set<pair<int,int> > st;
    a.resize(n+1);
    b.resize(n+1);
    v.resize(n+1);
    flag.resize(n+1);
    rep(i,m){
        int s,t;
        cin >> s >> t;
        s--;
        t--;
        if(s>t)swap(s,t);
        if(st.count(MP(s,t))==1){
            continue;
        }else{
            if(s==t){
                v[s].PB(s);
                if(p[s]=='A'){
                    a[s]++;
                }else{
                    b[s]++;
                }
            }else{
                v[s].PB(t);
                v[t].PB(s);
                if(p[s]=='A'){
                    a[t]++;
                }else{
                    b[t]++;
                }
                if(p[t]=='A'){
                    a[s]++;
                }else{
                    b[s]++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        bfs(i);
    }
    bool ans=0;
    for(int i=0;i<n;i++){
        if(!flag[i]){
            ans = 1;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
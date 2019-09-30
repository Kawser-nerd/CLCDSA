#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define all(e) e.begin(), e.end()
#define vi vector<int>
#define vd vector<double>

//????AtCoder??define
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;

typedef long long ll;
typedef unsigned long long ull;

const int INF = ~(1 << 31);

using namespace std;

bool already[100001];
int num[100001];

vector<pair<int, int> > graph[100001];
// ?????
// vector???????????from
// ????to?????pair???
bool ng = false;

void dfs(int n, int cost){
    //cerr << "from = " << n << ", currentcost = " << cost << endl;
    /*if(already[n]) cerr << "true" << endl;
    else cerr << "false" << endl;*/
    if(already[n]){
        //cerr << "num = " << num[n] << ", cost = " << cost << endl;
        if(num[n] != cost){
            ng = true;
            //cerr << "flag has standed" << endl;
        }
        return;
    }
    already[n] = true;
    num[n] = cost;
    //cerr << "size = " << graph[n].size() << endl;
    rep(i, graph[n].size()){
        pair<int, int> p = graph[n][i];
        //cerr << "to = " << p.first << ", cost = " << p.second << endl;
        dfs(p.first, p.second + cost);
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int l, r, d;
    rep(i, m){
        cin >> l >> r >> d;
        l--;
        r--;
        graph[l].push_back(make_pair(r, d));
        graph[r].push_back(make_pair(l, -d));
    }

    /*
    rep(i, n){
        rep(j, graph[i].size()){
            cerr << "from = " << i << ", to = " << graph[i][j].first << ", cost = " << graph[i][j].second << endl;
        }
    }*/

    memset(already, false, sizeof(already));
    rep(i, n){
        if(already[i]) continue;
        dfs(i, 0);

        if(ng){
            no;
            return 0;
        }
    }
    yes;

    return 0;
}
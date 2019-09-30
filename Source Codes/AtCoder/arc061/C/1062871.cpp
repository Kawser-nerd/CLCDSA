#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 1000000000
#define ll long long
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
map<P,vector<T>> e;
map<P,bool> visit;
map<P,int> dist;
int n,m;
int main(){
    cin>>n>>m;
    int p,q,c;
    rep(i,m){
        cin>>p>>q>>c;
        p-=1;q-=1;
        if(e.find(make_pair(p,c))==e.end()) e[make_pair(p,c)]={};
        if(e.find(make_pair(q,c))==e.end()) e[make_pair(q,c)]={};
        e[make_pair(p,c)].push_back(make_pair(0,make_pair(q,c)));
        e[make_pair(q,c)].push_back(make_pair(0,make_pair(p,c)));
        e[make_pair(p,c)].push_back(make_pair(1,make_pair(p,-1)));
        e[make_pair(q,c)].push_back(make_pair(1,make_pair(q,-1)));
        e[make_pair(p,-1)].push_back(make_pair(0,make_pair(p,c)));
        e[make_pair(q,-1)].push_back(make_pair(0,make_pair(q,c)));
        dist[make_pair(p,c)]=INF;
        dist[make_pair(q,c)]=INF;
    }
    rep(i,n) dist[make_pair(i,-1)]=INF;

    priority_queue<T, vector<T>, greater<T>> que;
    que.push(make_pair(0,make_pair(0,-1)));
    while(!que.empty()){
        T x=que.top();
        que.pop();
        visit[x.second]=true;
        dist[x.second]=x.first;
        for (auto y:e[x.second]){
            if (!visit[y.second]){
                if (dist[y.second]>x.first+y.first){
                    que.push(make_pair(x.first+y.first,y.second));
                    dist[y.second]=x.first+y.first;
                }
            }
        }
    }
    int d=dist[make_pair(n-1,-1)];
    if (d<INF) cout<<d<<endl;
    else cout<<-1<<endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<double,int> P;
double xs,ys,xt,yt;
int n;
double x[1002],y[1002],r[1002];
vector<P> e[1002];
double dist[1002];
bool visit[1002];
priority_queue<P, vector<P>, greater<P>> q;
int main(){
    cin>>xs>>ys>>xt>>yt;
    cin>>n;
    x[0]=xs;y[0]=ys;r[0]=0;
    x[n+1]=xt;y[n+1]=yt;r[n+1]=0;
    rep(i,n) cin>>x[i+1]>>y[i+1]>>r[i+1];
    n+=2;
    rep(i,n){
        dist[i]=INF;
        for (int j=i+1;j<n;j++){
            double d=max(0.0,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j]);
            e[i].pb(mp(d,j));
            e[j].pb(mp(d,i));
        }
    }
    q.push(mp(0,0));
    while(!q.empty()){
        double d=q.top().first;
        int node=q.top().second;
        q.pop();
        visit[node]=true;
        for (auto y:e[node]){
            if (!visit[y.second]){
                if (dist[y.second]>d+y.first){
                    dist[y.second]=d+y.first;
                    q.push(mp(dist[y.second],y.second));
                }
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dist[n-1]<<endl;
    return 0;
}
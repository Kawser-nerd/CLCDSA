//#include "bits/stdc++.h"
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
#include <numeric>
#include <complex>
#include <bitset>
#include <functional>
#include <stack>
#include <regex>
#include <tuple>
#include <iomanip>

#define int long long
#define REP(i,l,r) REPEAT(i,l,r,true) //[l, r)
#define rep(i,n) REP(i,0,n)           //[0, n)
#define REPEAT(i,l,r,condition) for(int i=(condition)?l:r-1;(condition)?i<r:i>=l;(condition)?++i:--i) // false<-[l, r)->true
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define fs first
#define sc second
#define show(...) cerr<<#__VA_ARGS__<<" = ";_DEBUG(__VA_ARGS__)
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showslr(n,l,r) cerr<<#n<<" = ";for(int i=l;i<r;i++){cerr<<n[i];}cerr<<endl //[l, r))

#define yes puts("Yes")
#define no puts("No")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using vi=vector<int>;
using pint=pair<int,int>;

inline void io(){cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(20);}

void _DEBUG(){cerr<<endl;}
template<typename H,typename... T> void _DEBUG(H a,T...b){cerr<<a<<",";_DEBUG(b...);}

template<typename T> inline void in(T &e){cin>>e;}
template<typename H,typename... T>void in(H &a, T&... b){in(a);in(b...);}
template<typename T> inline void out(T e){cout<<e<<endl;}
template<typename H,typename... T> void out(H a, T... b){out(a);out(b...);}

const int INF=1LL<<55;
const int MOD=1000000007;
const double EPS=1e-8;

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int H,W;
int T;
int s,g;

char grid[10][10];

#define MAX_V 110

int d[MAX_V][MAX_V]; //distance[from][to]
int V;               //???

void warshall_floyd(){
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}


signed main(){
    io();
    //in
    in(H,W,T);
    V=H*W;

    rep(y,H){
        rep(x,W) {
            in(grid[x][y]);
            if(grid[x][y]=='S') s=y*W+x;
            if(grid[x][y]=='G') g=y*W+x;
        }
    }

    int ok=INF,ng=0;
    while(ok-ng>1){
        int mid=(ok+ng)/2;

        //fill cost
        fill(d[0],d[MAX_V-1],INF);
        rep(y,H){
            rep(x,W){
                int from=y*W+x;
                rep(i,4){
                    pint af={x+dx[i],y+dy[i]};
                    if(af.fs<0||af.fs>=W||af.sc<0||af.sc>=H) continue;

                    int to=af.sc*W+af.fs;

                    if(grid[af.fs][af.sc]=='#'){
                        d[from][to]=mid;
                    }else{
                        d[from][to]=1;
                    }
                    if(grid[x][y]=='#'){
                        d[to][from]=mid;
                    }else{
                        d[to][from]=1;
                    }
                }
            }
        }

        warshall_floyd();
        //show(mid,d[s][g],d[s][g]<=T);
        if(d[s][g]<=T){
            ng=mid;
        }else{
            ok=mid;
        }
    }
    out(ng);

    /*
    rep(i,W*H){
        rep(j,W*H){
            printf("%lld ",d[j][i]);
        }puts("");
    }*//*
    rep(i,W){
        printf("%2lld ",d[0][i]);
    }puts("");
    */

    return 0;
}
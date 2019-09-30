#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(i,x) for(auto i=(x).begin(); i!=(x).end();i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vec vector
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vec<vec<char>> v(a,vec<char>(a)),vv(b,vec<char>(b));
    rep(i,0,a)rep(j,0,a)cin>>v[i][j];
    rep(i,0,b)rep(j,0,b)cin>>vv[i][j];

    rep(i,0,a-b+1){
        rep(j,0,a-b+1){
            bool ok=true;
            rep(p,0,b){
                rep(q,0,b){
                    if(v[i+p][j+q]!=vv[p][q])ok=false;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    
    return 0;
}
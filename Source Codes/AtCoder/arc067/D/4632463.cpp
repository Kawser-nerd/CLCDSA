#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e13
#define mod 1000000007

struct UnionFind{
  vector<int> v,l,r;
  UnionFind(int n) : v(n, -1),l(n,0),r(n,0) {}
  void init(){ for(int i = 0;i < (int)v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x]=find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    l[x]=min(l[x],l[y]);
    r[x]=max(r[x],r[y]);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};


ll N,M;
ll A[5011];
ll C[5011][201];
ll sum[5011][5011];

int main(){

  scanf("%lld%lld",&N,&M);
  rep(i,N-1)scanf("%lld",&A[i+1]);
  rep(i,N)rep(j,M)scanf("%lld",&C[i][j]);
  rep(i,N-1)A[i+1]+=A[i];

  UnionFind uf(N);
  rep(i,M){
    vector<int> B(N),ord(N);
    rep(j,N){
      B[j]=C[j][i];
      ord[j]=j;
    }
    sort(all(ord),[=](const ll& a,const ll& b){
      return B[a] < B[b];
    });

    rep(j,N){
      uf.v[j]=-1;
      uf.l[j]=uf.r[j]=j;
    }
    for(ll j:ord){
      if(j>0&&B[j-1]<=B[j])uf.unite(j-1,j);
      if(j+1<N&&B[j]>=B[j+1])uf.unite(j,j+1);

      ll f=uf.find(j);
      ll l1=uf.l[f],l2=j+1;
      ll r1=j+1,r2=uf.r[f]+2;

      sum[l1][r1]+=B[j];
      sum[l1][r2]-=B[j];
      sum[l2][r1]-=B[j];
      sum[l2][r2]+=B[j];

    }
  }

  rep(i,N)rep(j,N+1)sum[i+1][j]+=sum[i][j];
  rep(i,N+1)rep(j,N)sum[i][j+1]+=sum[i][j];

  ll res=-INF;
  rep(l,N)repl(r,l+1,N+1){
    maxch(res,sum[l][r]-(A[r-1]-A[l]));
  }
  cout<<res<<endl;

  return 0;
}
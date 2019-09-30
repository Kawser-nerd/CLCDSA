#include <bits/stdc++.h>
#define M_PI    3.14159265358979323846  /* pi */
#define ff(i,s,n) for(int i=(s);i<(n);i++)
#define fr(i,s,n) for(int i=(n-1);i>=(s);i--)
#define FF(i,s,n) for(int i=(s);i<=(n);i++)
#define Fr(i,s,n) for(int i=(n);i>=(s);i--)
#define FR(i,s,n) for(int i=(n);i>=(s);i--)
#define all(a) a.begin(),a.end()
#define tnm typename
#define invd inline void
#define templ1 template<tnm T>
#define btempl templ1 invd
#define ln prln()
#define sp prsp()
invd init(int n){
  char buff[100];
  sprintf(buff,"xx/%d.txt",n);
#ifndef ONLINE_JUDGE
    freopen(buff,"r",stdin);
#endif
}
using namespace std;typedef int64_t ll;typedef unsigned int uint;
invd scan(char&s){int c;while((c=getchar())=='\n'||c==' '||c=='\r');s=c;};
invd pr(ll i){printf("%" PRId64 ,i);}
invd scan(int&i){scanf("%d",&i);}invd scan(double&i){scanf("%lf",&i);}invd scan(ll&i){scanf("%" PRId64 ,&i);}invd pr(string&s){cout<<s;}
template<typename T, typename V> invd scan(pair<T,V>&a){scan(a.first),scan(a.second);}
invd scan(string&s){int c;while((c=getchar())=='\n'||c==' '||c=='\r');do{switch(c){case'\n':case'\r':return;default:s+=c;}}while((c=getchar())!=EOF);};
invd pr(char c){putchar(c);};invd pr(const char*c){while(*c!=0)putchar(*c++);}
invd pr(int i){printf("%d",i);}invd pr(bool b){pr((int)b);}invd pr(double d){printf("%.9lf",d);}invd prln(){putchar('\n');}invd prsp(){putchar(' ');}
btempl scan(char*s){int c;while((c=getchar())){switch(c){case'\n':case'\r':case' ':break;default:*s++=c;}}*s=0;};
template<typename T, typename... Args>invd scan(T&first, Args (&... args)) {scan(first),scan(args...);}
template<typename T>invd pr(T arg) {arg.print();}
template<class A, class B> invd pr(pair<A,B> a){pr(a.first),sp,pr(a.second);}
btempl prsp(vector<T>&v){for(const T&t:v)pr(t),sp;}btempl prsp(T*a,int n){while(n--)pr(*a++),sp;}btempl prln(vector<T>&v){for(const T&t:v)pr(t),ln;}
btempl pr(vector<T>&v){prsp(v);}
invd pr(size_t i){pr((ll)i);}btempl scan(vector<T>&v){for(T&t:v)scan(t);}btempl scan(T*a,int n){while(n--)scan(*a++);}
btempl prln(T*a,int n){while(n--)pr(*a++),ln;}btempl prln(vector<vector<T> >&v){for(vector<T>&t:v)prsp(t),ln;}
template<typename T, typename... Args>invd pr(T first, Args... args) {pr(first),sp,pr(args...);}
templ1 vector<T>& operator+=(vector<T>& v,T x) {v.push_back(x);return v;}
templ1 vector<T>& operator--(vector<T>& v) {v.pop_back();return v;}templ1 vector<T>& operator--(vector<T>& v,int) {v.pop_back();return v;}
templ1 bool operator!(stack<T>&q) {return !q.empty();}templ1 stack<T>& operator+=(stack<T>& v,T x) {v.push(x);return v;}
templ1 T operator--(stack<T>& v) {v.pop();return v.top();}templ1 T operator--(stack<T>& v,int) {T t=v.top();v.pop();return t;}
templ1 bool operator!(queue<T>&q) {return !q.empty();}templ1 queue<T>& operator+=(queue<T>& v,T x) {v.push(x);return v;}
templ1 T operator--(queue<T>& v) {v.pop();return v.front();}templ1 T operator--(queue<T>& v,int) {T t=v.front();v.pop();return t;}
template<tnm T,tnm U>invd smax(T&a,U b){if(b>a)a=b;}template<tnm T,tnm U>invd smin(T&a,U b){if(b<a)a=b;}
template<tnm T,tnm U>inline T gcd(T a, U b){return __gcd(a,b);}typedef vector<int> vi;typedef vector<vi > vvi;typedef pair<int, int> pii;typedef pair<ll,ll> pll;
typedef vector<pii > vpii;
const ll MOD = 1E9+7;
const ll linf=~(1ll<<63);
const int inf=~(1<<31);
const int sk = 1E9;



int solve(){
  int k, l, s;
  scan(k,l,s);
  vi keyprob(255,0);
  {
    string keys;
    scan(keys);
    for(char c:keys)
      keyprob[c]++;
  }
  string target;
  scan(target);
  int overlap = 1;
  ff(i,1,target.size()){
    bool ok = 1;
    ff(j,i,target.size()){
      if(target[j]!=target[j-i]){
        ok = 0;
        break;
      }
    }
    if(ok){
      break;
    }
    overlap++;
  }
  int bstart = 1 + (s-l)/overlap;
  double prob = 1;
  for(char c:target){
    prob = prob*keyprob[c]/k;
  }
  if(prob == 0){
    pr(0.);
    return 0;
  }
  prob = prob*(s-l+1);
  pr(bstart-prob);
}
init(){
  freopen("e:/users/johan/downloads/B-large.in","r",stdin);
  freopen("output.txt","w",stdout);
}

int main(){
  init();
  int t;
  scan(t);
  ff(i,0,t){
    printf("Case #%d: ",i+1);
    solve();
    ln;
  }
}
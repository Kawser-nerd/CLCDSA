#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>

using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()?n???????
#define all(x) (x).begin,(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}


int n;
vector<int> p;

int main(){
  cin >> n; p.resize(n);
  rep(i,n) cin >> p[i];
  VSORT(p);
  p.back() /= 2;

  int sum=0;
  rep(i,n) sum += p[i];

  cout << sum << endl;
  return 0;
}
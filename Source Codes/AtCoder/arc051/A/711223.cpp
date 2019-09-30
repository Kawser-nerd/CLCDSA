#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
template<typename T>
void echo_array(vector<T> v){
  rep(i, v.size())cout << v[i] << " ";
  cout << endl;
}
void echo_array(int *arr, int size){
  rep(i, size)cout << arr[i] << " ";
  cout << endl;
}
template<typename T>
void echo_mat(vector<T> v[], int rows){
  rep(i, rows){
    rep(j, v[i].size())cout << v[i][j] << " ";
    cout << endl;
  }
}
void echo_mat(int *mat[], int rows, int cols){
  rep(i, rows){
    rep(j, cols)cout << mat[i][j] << " ";
    cout << endl;
  }
}

double distance(pint a, pint b){
  return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int main(){
  pint p1, p2, p3;
  int r;
  scanf("%d %d %d", &p1.first, &p1.second, &r);
  scanf("%d %d %d %d", &p2.first, &p2.second, &p3.first, &p3.second);

  if(p2.first <= p1.first-r && p1.first+r <= p3.first &&
     p2.second <= p1.second-r && p1.second+r <= p3.second){
    printf("NO\n");
  }else printf("YES\n");
  
  if(distance(p1, p2) <= r && distance(p1, p3) <= r &&
     distance(p1, pint(p2.first, p3.second)) <= r &&
     distance(p1, pint(p3.first, p2.second)) <= r)printf("NO\n");
  else printf("YES\n");

  return 0;
}
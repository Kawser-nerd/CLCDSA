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

#define MAX_K 40
#define BASE 1000000007
int fibm[MAX_K+1];


int fib(int n){
  if(fibm[n-1] != 0) return fibm[n-1];
  fibm[0] = 1;
  fibm[1] = 1;
  REP(i, 2, n){
    fibm[i] = fibm[i-1]+fibm[i-2];
  }
  return fibm[n-1];
}




int main(){
  int K;
  scanf("%d", &K);
  fill(fibm, fibm+K+1, 0);
  printf("%d %d\n", fib(K+2), fib(K+1));
  return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include "math.h"
#include <complex>
#include <iomanip>
#include <map>
#define ifor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
using namespace std;
typedef long double ld;
typedef long long int  lli;
typedef complex <double> P;
const double eps = 1e-11;
int vex[4]={1,0,-1,0};
int vey[4]={0,1,0,-1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD=1000000007;
//Ax=b???A?????
//rankA<=min(m,n)???????vec???
int main(){
  int N,M,A[1004];
  cin >> N >> M;
  int cnt =0;
  vector<int> odd;
  rep(i,M){
    cin >> A[i];
    if(A[i]&1){
      cnt++;
      odd.push_back(i);
    }
  }
  vector<int>a,b;
  if(M==1){
    a.push_back(1);
    a.push_back(A[0]-1);
    b.push_back(A[0]);
  }
  else if(M==2){
    a.push_back(A[0]-1);
    a.push_back(A[1]+1);
    b.push_back(A[0]);
    b.push_back(A[1]);
  }else {
    if(cnt>2){
      cout<<"Impossible"<<endl;
      return 0;
    }
    else if(cnt!=0) {
      a.push_back(A[odd[0]]-1);
      b.push_back(A[odd[0]]);
      rep(i,M){
        if(i!=odd[0]&&i!=odd[1]){
          b.push_back(A[i]);
          a.push_back(A[i]);
        }
      }
      a.push_back(A[odd[1]]+1);
       b.push_back(A[odd[1]]);
    }
    
    else{
      rep(i,M){
        a.push_back(A[i]);
        b.push_back(A[i]);
      }
      a[0]++;
      a[M-1]--;
    }
  }
  vector<int>c;
  rep(i,a.size()){
    if(a[i]!=0)c.push_back(a[i]);
  }
  rep(i,b.size())cout<<b[i]<<' ';
  cout<<endl;
  cout<<c.size()<<endl;
  rep(i,c.size())cout<<c[i]<<' ';
  cout<<endl;
}
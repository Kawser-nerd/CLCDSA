#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int cntS[26],cntT[26];
int main(){
  string S,T;
  cin>>S>>T;
  repeat(i,S.length()){
    cntS[S[i]-'a']++;
    cntT[T[i]-'a']++;
  }
  sort(cntS,cntS+26);
  sort(cntT,cntT+26);
  bool isok=true;
  repeat(i,26){
    isok &= cntS[i]==cntT[i];
  }
  cout<<(isok? "Yes":"No")<<endl;
  return 0;
}
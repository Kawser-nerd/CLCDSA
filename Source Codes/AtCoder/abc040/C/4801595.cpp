#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <vector>
#include <cmath>

//! https://qiita.com/drken/items/dc53c683d6de8aeacf5a

using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
inline int64_t rec( int i);

static const size_t MLEN= 1'000'000;
static int N;
static int64_t s[ MLEN];
static int64_t dp[ MLEN];
static enum Algorithm{ Collect, Distribute, Recursion } alg= Recursion;

int main(){
  cin>> N;

  for( int i= 0; i< N; i++){ cin>> s[ i]; }
  for( int i= 0; i< MLEN; i++){ dp[i]= i?INT64_MAX:0; }

  for( int i= 0; i< N; i++){
    switch( alg){
      case Collect:
        if(!i) continue;
        chmin( dp[ i], dp[ i- 1]+ abs( s[ i]- s[ i- 1]));
        if( i> 1) chmin( dp[ i], dp[ i- 2]+ abs( s[ i]- s[ i- 2]));
        break;
      case Distribute:
        chmin( dp[ i+ 1], dp[ i]+ abs( s[ i]- s[ i+ 1]));
        chmin( dp[ i+ 2], dp[ i]+ abs( s[ i]- s[ i+ 2]));
        break;
      case Recursion:
        rec( N- 1);
      default:
        break;
    }
  }

  cout<< dp[ N- 1]<< endl;
  return 0;
}

int64_t rec(int i) {
  if( !i) return 0;
  if( dp[i]< INT64_MAX) return dp[i];

  int64_t res= INT64_MAX;
  chmin( res, rec( i- 1)+ abs( s[i] - s[i - 1]));
  if( i > 1) chmin( res, rec( i- 2)+ abs( s[ i]- s[ i - 2]));

  return dp[i ] = res;
}
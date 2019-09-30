#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

LL f[50][2][2][2];
LL a , b , k;
LL numa[50] , numb[50];

int F(LL s , LL da , LL db , LL dk){
    if (s == 1) return 1 ;
    LL d = da & db ;
    if (d < dk) return 1 ;
    if (d > dk) return -1 ;
    return 0 ;
}

LL DP( int i , int s , bool ea , bool eb ) {
    if ( i == -1 ) return s ;
    if ( f[i][s][ea][eb] != -1 ) return f[i][s][ea][eb] ;
    LL res = 0 , ua = ea?numa[i]:1 , ub = eb?numb[i]:1;
    for ( LL da = 0 ; da <= ua ; da ++ ) for ( LL db = 0 ; db <= ub ; db ++ ) {
        int nexts = F( s , da , db , !!(k & (1LL<<i)) ) ;
        if ( nexts != -1 ) res += DP(i-1, nexts , ea&&da==ua , eb && db == ub) ;
    }
    return f[i][s][ea][eb] = res ;
}

int main() {
    freopen("B.in","r",stdin) ;
    freopen("B.out","w",stdout) ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> a >> b >> k ; a -- ; b -- ;
        memset( f , -1 , sizeof(f) ) ;
        for ( int j = 0 ; j < 50 ; j ++ ) numa[j] = !!(a & (1LL<<j)) , numb[j] = !!(b & (1LL<<j)) ;
        cout << "Case #" << i << ": " << DP(49 , 0 , 1 , 1) << "\n" ;
    }
}

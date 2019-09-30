#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;
LL P , Q , F , ans , U ;

LL GCD(LL X1 , LL X2) {
    if ( X2 == 0LL ) return X1 ;
    else return GCD(X2,X1%X2) ;
}

int main() {
    freopen("A-large.in","r",stdin) ;
    freopen("A_large.out","w",stdout) ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> P >> Q ;
        if ( P == 0 && Q == 0 ) {
            cout << "Case #" << i << ": impossible\n" ;
            continue ;
        }
        LL W = GCD(P,Q) ;
        P /= W ;
        Q /= W ;
        for ( F = 1LL ; F <= Q ; F = F * 2LL ) {
            if ( F == Q ) break ;
        }
        if ( F > Q ) {
            cout << "Case #" << i << ": impossible\n" ;
            continue ;
        }
        ans = 0LL , U = 1LL ;
        while ( 1 ) {
            if ( U * P == Q ) break ;
            if ( U * P > Q ) break ;
            ans ++ , U *= 2LL ;
        }
        cout << "Case #" << i << ": " << ans << "\n" ;
    }
}

//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 + 100; 
typedef long double ld; 
typedef long long ll;
const ll inf = 1e17 ; 

struct Problem { 
    ll d[maxN]; 
    ll s[maxN]; 
    ll mat[maxN][maxN]; 
    ld c[maxN][maxN];

    void solve() { 
        int n, q; 
        cin >> n >> q; 
        for( int i = 0 ; i < n ; i++ ) 
            cin >> d[i] >> s[i]; 
        for( int i = 0 ; i < n ; i++ ) 
            for( int j = 0 ; j < n ; j++ ) { 
                cin >> mat[i][j]; 
                if( mat[i][j] == -1 ) 
                    mat[i][j] = inf; 
            }
        for( int k = 0 ; k < n ; k++ ) 
            for( int i = 0 ; i < n ; i++ ) 
                for( int j = 0 ; j < n ; j++ ) 
                    mat[i][j] = min( mat[i][j] , mat[i][k] + mat[k][j] ); 

        for( int i = 0 ; i < n ; i++ ) 
            for( int j = 0 ; j < n ; j++ ) 
                if( mat[i][j] <= d[i] ) 
                    c[i][j] = mat[i][j] / ld(s[i]); 
                else
                    c[i][j] = inf; 

        for( int k = 0 ; k < n ; k++ ) 
            for( int i = 0 ; i < n ; i++ ) 
                for( int j = 0 ; j < n ; j++ ) 
                    c[i][j] = min( c[i][j] , c[i][k] + c[k][j] ); 

        for( int i = 0; i < q ; i++ ) { 
            int u, v; 
            cin >> u >> v;
            u--; v--; 
            cout << c[u][v] << " " ; 
        }
        cout << endl;
    }
};

int main() { 
    cout << fixed << setprecision(20); 

    int t; cin >> t; 
    for( int i = 1 ; i <= t ; i++ ) { 
        cout << "Case #" << i << ": "; 
        Problem x; 
        x.solve(); 
    }
}

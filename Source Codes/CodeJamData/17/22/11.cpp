
//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

struct Problem { 
    void solve() { 
        int n; 
        int r, o, y, g, b, v; 
        cin >> n >> r >> o >> y >> g >> b >> v; 

        if( g == r && n == r + g ) { 
            for( int i = 0 ; i < r ; i++ ) 
                cout << "RG" ; 
            cout << endl;
            return;
        }
        if( v == y && n == v + y ) { 
            for( int i = 0 ; i < v ; i++ ) 
                cout << "VY" ; 
            cout << endl;
            return;
        }
        if( o == b && n == o + b ) { 
            for( int i = 0 ; i < o ; i++ ) 
                cout << "OB" ; 
            cout << endl;
            return;
        }

        if( (g && g + 1 > r) || ( v && v + 1 > y )  || ( o && o + 1 > b )  ) { 
            cout << "IMPOSSIBLE" << endl;
            return; 
        }

        string first[] = { "R" , "Y" , "B" } ; 

        if( g ) { 
            r -= g; 
            string s = "R"; 
            for( int i = 0 ; i < g ; i++ ) 
                s += "GR" ; 
            first[0] = s; 
        }
        if( v ) { 
            y -= v; 
            string s = "Y"; 
            for( int i = 0 ; i < v ; i++ ) 
                s += "VY" ; 
            first[1] = s;
        }
        if( o ) { 
            b -= o; 
            string s = "B"; 
            for( int i = 0 ; i < o ; i++ ) 
                s += "OB" ; 
            first[2] = s;
        }

        int all = max( r, max(y, b) ); 
        if( r + y + b - all < all ) { 
            cout << "IMPOSSIBLE" << endl;
            return; 
        }


        char pr[] = { 'R' , 'Y' , 'B' } ; 

        int cnt[] = { r , y , b }; 


        if( r == all ) {
        } else if( y == all ) { 
            swap( pr[0] , pr[1] ) ; 
            swap( cnt[0] , cnt[1] ); 
            swap( first[0] , first[1] );
        } else if( b == all ) { 
            swap( pr[0] , pr[2] ) ; 
            swap( cnt[0] , cnt[2] ); 
            swap( first[0] , first[2] );
        }

        for( int i = 0 ; i < cnt[0] ; i++ ) { 
            string ret = ""; 
            if( i == 0 ) 
                ret += first[0];
            else
                ret += pr[0]; 
            if( i < cnt[1] ) { 
                if( i == 0 ) 
                    ret += first[1]; 
                else
                    ret += pr[1]; 
            }
            if( cnt[0] - i - 1 < cnt[2] ) { 
                if( i == cnt[0] - 1 ) 
                    ret += first[2];
                else
                    ret += pr[2]; 
            }
            cout << ret;
        }
        cout << endl;
    }
};

int main() { 
    int t; cin >> t; 
    for( int i = 1 ; i <= t ; i++ ) { 
        cout << "Case #" << i << ": "; 
        Problem x; 
        x.solve(); 
    }
}

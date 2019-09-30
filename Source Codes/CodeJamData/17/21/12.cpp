//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 + 100; 
typedef long double ld; 

struct Problem { 
    pair<int,int> horse[maxN];
    int que[maxN]; 
    void solve() { 
        int d, n;
        cin >> d >> n; 
        for( int i = 0 ; i < n ; i++ ) 
            cin >> horse[i].first >> horse[i].second; 

        ld s = 0 , e = 1e18; 
        for( int t = 0 ; t < 250 ; t++ ) { 
            ld m = (s+e)/2;
            bool canDo = true;
            for( int i = 0 ; i < n ; i++ )
                if( m > horse[i].second ) { 
                    ld t = horse[i].first / ( m - horse[i].second ); 
                    if( t * m < d ) 
                        canDo = false;
                }
            if( canDo )
                s = m; 
            else
                e = m;
        }
        cout << s << endl;
    }
};

int main() { 
    cout << fixed << setprecision(15); 

    int t; cin >> t; 
    for( int i = 1 ; i <= t ; i++ ) { 
        cout << "Case #" << i << ": "; 
        Problem x; 
        x.solve(); 
    }
}

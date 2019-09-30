#include <iostream>
#include <cstdio>
#include <algorithm>



using namespace std;
typedef long long lint;

#define rep(i, n) for(int i=0; i<n; i++)
#define max(a, b) (a > b)? a:b

lint N;
lint H;
lint a[100010];
lint b[100010];


int main() {
    cin >> N >> H;

    lint maxa = -1;
    rep(i, N) {
        scanf("%ld %ld", &a[i], &b[i]);
        maxa = max(maxa, a[i]);
    }
    
    sort(b, b + N);
    
    lint x = 0;
    for(int i = N-1; b[i] > maxa && H > 0; i--) {
        H -= b[i];
        x++;
    }
    if(H > 0) {
        x += H / maxa;
        if(H % maxa) x += 1;
    }
    cout << x  << " " << endl;
    
} ./Main.cpp:24:26: warning: format specifies type 'long *' but the argument has type 'lint *' (aka 'long long *') [-Wformat]
        scanf("%ld %ld", &a[i], &b[i]);
               ~~~       ^~~~~
               %lld
./Main.cpp:24:33: warning: format specifies type 'long *' but the argument has type 'lint *' (aka 'long long *') [-Wformat]
        scanf("%ld %ld", &a[i], &b[i]);
                   ~~~          ^~~~~
                   %lld
2 warnings generated.
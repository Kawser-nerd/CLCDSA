#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

pair<int,int> pow (int x) {
    if (x == 0)
        return make_pair(1, 0);
    if (x == 1)
        return make_pair(3, 1);
    
    pair<int,int> cur, neo;
    
    cur = pow(x >> 1);
    neo.first = (cur.first * cur.first + cur.second * cur.second * 5) % 1000;
    neo.second = (cur.first * cur.second * 2) % 1000;
    
    if (x & 1) {
        cur = neo;
        neo.first = (cur.first * 3 + cur.second * 5) % 1000;    
        neo.second = (cur.first + cur.second * 3) % 1000;
        }
    return neo;
    }

int main () {
    int t, ct;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d", &n);
        
        printf("Case #%d: %03d\n", ++ct, (pow(n).first * 2 + 999) % 1000);
        }
    
    return 0;
    }

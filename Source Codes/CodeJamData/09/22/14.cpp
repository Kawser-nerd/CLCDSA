#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define REP(i, n) for ( int i = 0; i < (n); i++ ) 
#define FOR(i, a, b) for ( int i = (a); i < (b); i++ ) 

using namespace std;


void fun(int cs) {
    char s[1000];
    scanf(" %s", s);
    
    vector<int> data;
    int l = strlen(s);
    REP(i, l) {
        data.push_back(s[i]-'0');
    }

    vector<int> two;
    REP(i, data.size()) two.push_back(data[i]);

    printf("Case #%d: ", cs);
    if ( next_permutation(two.begin(), two.end()) ) {
        REP(i, two.size()) {
            printf("%d", two[i]);
        }
    } else {
        vector<int> x;
        int zeros = 1;
        REP(i, data.size()) {
            if ( data[i] == 0 ) {
                zeros++;
            } else {
                x.push_back(data[i]);
            }
        }
        sort(x.begin(), x.end());
        printf("%d", x[0]);
        REP(i, zeros) printf("0");
        FOR(i, 1, x.size()) printf("%d", x[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    REP(i, T) fun(i+1);

    return 0;
}

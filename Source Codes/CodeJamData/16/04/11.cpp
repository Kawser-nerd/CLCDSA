#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

ll ipow(ll b, int n) {
    ll res = 1;
    for (int i=0; i<n; i++)
        res *= b;
    return res;
}

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++) {
        int k,c,s;
        cin >> k >> c >> s;
        printf("Case #%d:", t);
        int min_moves = (k+c-1)/c;
        if (s < min_moves)
            cout << " IMPOSSIBLE";
        else {
            for (int i=0; i<min_moves; i++) {
                ll test=0;
                for (int j=0; j<c && i*c+j<k; j++) {
                    //cout << "pouf";
                    test += ipow(k, j) * (i*c+j);
                }
                cout << ' ' << 1+test;
            }
        }
        cout << endl;
    }
}

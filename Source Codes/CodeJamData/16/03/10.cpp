#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

#define MARGIN 14

ll ipow(ll b, int n) {
    ll res = 1;
    for (int i=0; i<n; i++)
        res *= b;
    return res;
}

int main()
{
    int dummy, num;
    cin >> dummy >> dummy >> num;
    cout << "Case #1:" << endl;
    for (int i=0; i<num; i++) {
        bitset<MARGIN> bs(i);
        cout << "1" << bs << "11" << bs << "1";
        for (int j=2; j<=10; j++) {
            cout << ' ' << ipow(j, MARGIN+2) + 1;
        }
        cout << endl;
    }
}

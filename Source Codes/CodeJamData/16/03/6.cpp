#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/


int N, J;
int nPrimes;

vector <int> primeList;

void seedPrimes() {
    bool isNotP[100005];
    memset (isNotP,false,sizeof(isNotP));
    FO (i,2,100005) {
        if (!isNotP[i]) {
            primeList.push_back(i);
            for (int p = i+i; p < 100005; p += i) isNotP[p] = true;
        }
    }
}

bool checkPrime (ll c) {
    bool bitRep[35];
    memset (bitRep,false,sizeof(bitRep));
    ll temC = c;
    if (c%2 == 0) return false;
    FO (i,0,35) {
        bitRep[i] = temC%2;
        temC /= 2;
    }
    int witnesses[11];
    FO (i,2,11) witnesses[i] = -1;
    FO (i,2,11) {
        FO (p,0,primeList.size()) {
           
            if (c == primeList[p]) continue;
            ll totMod = 0;
            ll cMod = 1;
            FO (t,0,32) {
                if (bitRep[t]) {
                    totMod += cMod;
                    if (totMod >= primeList[p]) totMod -= primeList[p];
                }
                    cMod = cMod*i;
                    while (cMod >= primeList[p]) cMod -= primeList[p];
            }
            //printf ("%d, base %d \%% %d: %d\n", c, i, primeList[p], totMod);
            if (totMod == 0) {
                witnesses[i] = primeList[p];
                break;
            }
        }
        if (witnesses[i] == -1) return false;
    }
    for (int i = 0; i < N; i++) printf ("%d", bitRep[N-i-1]);
    FO (i,2,11) printf (" %d", witnesses[i]);
    printf ("\n");
    return true;
}
            


int main() {
    int _T;
    seedPrimes();
    scanf ("%d", &_T);
    printf ("Case #1:\n");
    scanf ("%d %d", &N, &J);
    for (ll i = ((long long)1<<(N-1));; i++) {
        if (checkPrime(i)) {
            nPrimes++;
        }
        if (nPrimes == J) break;
    }
    return 0;
}



#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;

/*~~~~TEMPLATE END~~~~*/

#define TARGET -1
#define MAX_L 10005
int T;
long long L, X;
char inp[MAX_L];

int multM[5][5] = {
                    {0,0,0,0,0},
                    {0,1,2,3,4},
                    {0,2,-1,4,-3},
                    {0,3,-4,-1,2},
                    {0,4,3,-2,-1}
                };

int quarMult (int a, int b) {
    //printf ("MULT %d %d\n", a, b);
    int sgn = (a*b) < 0;
    a = abs (a);
    b = abs (b);
    if (sgn) return -multM[a][b];
    else return multM[a][b];
}
int nYes;

int main() {
    freopen ("q3.in", "r", stdin);
    freopen ("q3.out", "w", stdout);
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%lld %lld", &L, &X);
        long long totLength = L*X;
        long long m4 = X % 4;
        scanf (" %s", inp);
        FO (i,0,L) {
            if (inp[i] == 'i') inp[i] = 2;
            if (inp[i] == 'j') inp[i] = 3;
            if (inp[i] == 'k') inp[i] = 4;
        }
        int strRep = 1;
        FO (i,0,L) {
            strRep = quarMult (strRep,inp[i]);
        }
        int fRep = 1;
        FO (i,0,m4) {
            fRep = quarMult (fRep, strRep);
        }
        if (fRep != TARGET) {
            printf ("NO\n");
            continue;
        }
        int startRep = 1;
        long long fStar = -1;
        for (long long i = 0; i < min(totLength,5*L); i++) {
            startRep = quarMult (startRep,inp[i%L]);
            if (startRep == 2) {
                fStar = i;
                break;
            }
        }
        startRep = 1;
        long long sStar = -1;
        for (long long i = totLength-1; i >= max (0ll,totLength-5*L); i--) {
            startRep = quarMult (inp[i%L], startRep);
            if (startRep == 4) {
                sStar = i;
                break;
            }
        }
        if (fStar == -1 || sStar == -1) {
            printf ("NO\n");
            continue;
        }
        if (fStar < sStar) {
            printf ("YES\n");
            nYes++;
        } else {
            printf ("NO\n");
        }
    }
    //printf ("%d\n", nYes);
    return 0;
}







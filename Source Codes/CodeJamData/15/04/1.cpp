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

void p1W() { printf ("RICHARD\n"); }
void p2W() { printf ("GABRIEL\n"); }

int T, X, R, C;

int main() {
    freopen ("q4.in", "r", stdin);
    freopen ("q4.out", "w", stdout);
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%d %d %d", &X, &R, &C);
        if (R > C) swap (R, C);
        if (R == 5 && C == 3) assert (false);
        if ((R*C)%X != 0) {
            p1W();
            continue;
        }
        if (X == 1) {
            p2W();
            continue;
        }
        if (X == 2) {
            p2W();
            continue;
        }
        if (X == 3) {
            if (R == 1 || C == 1) {
                p1W();
            } else {
                p2W();
            }
            continue;
        }
        if (X == 4) {
            if (R <= 2 || C <= 2) {
                p1W();
            } else {
                p2W();
            }
        }
        if (X == 5) {
            if (R <= 2 || C <= 2) {
                p1W();
            } else if (R == 3 && C == 5) {
                p1W();
            }
            else {
                p2W();
            }
        }
        if (X == 6) {
            if (R <= 3 || C <= 3) {
                p1W();
            } else {
                p2W();
            }
        }
        if (X >= 7) {
            p1W();
            continue;
        }
    }
    return 0;
}
        
        
        
        
            

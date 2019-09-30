#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;

#define INF 1000000000
#define PB push_back
 
//////////////////////////////////////////

struct node {
    double p;
    string name;
};
int tak[1000000];
int nie[1000000];
vector<node> drzewa;

int czytaj_drzewo() {
    int x = size(drzewa);
    drzewa.resize(x+1);
    scanf(" (%lf", &drzewa[x].p);
    char ch;
    scanf(" %c", &ch);
    drzewa[x].name = "";
    if (ch!=')') {
        while (ch>='a' && ch<='z') {
            drzewa[x].name += ch;
            scanf("%c", &ch);
        }
        tak[x] = czytaj_drzewo();
        nie[x] = czytaj_drzewo();
        scanf(" )");
    }
    return x;
}


int main() {
    int N, A, F;
    scanf("%d", &N);
    REP(t, N) {
        printf("Case #%d:\n", t+1);
        drzewa.clear();
        scanf("%*d");
        int d = czytaj_drzewo();
        scanf("%d", &A);
        REP(a, A) {
            scanf("%*s%d", &F);
            set<string> wlas;
            REP(f, F) {
                char buf[100];
                scanf("%s", buf);
                wlas.insert(buf);
            }
            int d2 = d;
            double p = drzewa[d].p;
            while (drzewa[d2].name!="") {
                d2 = wlas.find(drzewa[d2].name)!=wlas.end() ? tak[d2] : nie[d2];
                p *= drzewa[d2].p;
            }
            printf("%.7f\n", p);
        }
    }
    
}



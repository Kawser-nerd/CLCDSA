#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <set>

#define REP(i, n) for ( int i = 0; i < (n); i++ ) 
#define FOR(i, a, b) for ( int i = (a); i < (b); i++ ) 

using namespace std;

class el {
    public:
        el() {
            isLeaf = 1;
        }

        ~el() {
            if ( ! isLeaf ) {
                delete good;
                delete bad;
            }
        }

        int isLeaf;
        el* good;
        el* bad;
        double w;
        string feature;

        double rek(set<string>& zb) {
            double res = w;
            
            if ( isLeaf ) return res;

            if ( zb.find(feature) != zb.end() ) {
                return res * good->rek(zb);
            } else {
                return res * bad->rek(zb);
            }
        }

        void get() {
/*            char r;
            scanf(" %c", &r);
            assert(r == '(');*/


//            printf("in\n");
            scanf(" %lf", &w);

//            printf("waga: %lf\n", w);

            char feat[1000];
            feat[0] = feat[1] = 0;
        
            char e;
            scanf(" %c", &e);

            if ( e == ')' ) {
//                printf("out\n");
                return;
            } else {
                feat[0] = e;
                int pp = 1;
                bool got = 0;
                while ( true ) {
                    scanf("%c", &e);
                    if ( e != ' ' and e != ')' and e != '(' and e != '\n' ) {
                        feat[pp] = e;
                        pp++;
                    } else if ( e == '(' ) {
                        got = 1;
                        break;
                    } else 
                        break;
                }

                while ( ! got ) {
                    scanf("%c", &e);
                    if ( e == '(' ) got = 1;
                }

                feat[pp] = 0;
                feature = string(feat);
//                printf("%s\n", feature.c_str());
                assert(feature[feature.size()-1] != ')');
                good = new el;
                good->get();

                scanf(" %c", &e);
                assert(e == '(');

                bad = new el;
                bad->get(); 

                char c;
                scanf(" %c", &c);
//                printf("|%c|\n", c);
                assert(c == ')');
                isLeaf = 0;
            }
//            printf("out\n");
        }
};

void fun(int cs) {
    printf("Case #%d:\n", cs);
    int L;
    scanf("%d", &L);

    char r;
    scanf(" %c", &r);
    el root;
    root.get(); 

    int N;
    scanf("%d", &N);
    REP(i, N) {
        char s[1000];
        scanf(" %s", s);
        string name(s);
        int m;
        scanf("%d", &m);
        set<string> F;
        REP(i, m) {
            scanf(" %s", s);
            F.insert(string(s));
        }

        printf("%.8lf\n", root.rek(F));
    }
//    printf("------------\n");
}

int main() {
    int T;
    scanf("%d", &T);
    REP(i, T) fun(i+1);

    return 0;
}

/**********************************************************************
Author: hanshuai
Created Time:  7/29/2011 10:48:19 AM
File Name: e.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int maxn = 20;
const int T2 = 7;
const double eps = 1e-8;
double P[maxn][maxn][T2];
int A, M, V;
double tP(int v){
    if(v >= V) return 1.0;
    if(v <= 0) return 0.0;
    return P[v][0][0];
}
bool modify;
int sgn(double v){
    return (v > eps) - (v < -eps);
}
void update(double& x, double v){
     x = max(x, v);
}
int cas = 0;
void solve(){
    scanf("%d%d%d", &A, &M, &V);
    memset(P, 0, sizeof(P));
    for(int B = 0; B < maxn; B ++){
        for(int t2 = 0; t2 < T2; t2 ++){
        }
    }
    modify = true;
    int cnt = 0;
//    P[0][0][0] = 0; P[V][0][0] = 1;
    while(modify){
//        modify = false;
        if(++cnt == 5000) break;
        for(int X = 1; X < V; X ++){
            //P[X][0][0]..
            for(int B = 1; B <= min(X, M); B ++){
                double v = 0.5 * tP(X+B) + 0.5 * P[X][B][1];
                update(P[X][0][0], v);
            }
            //P[X][B][t2];
            for(int B = 1; B <= min(X, M); B ++){
                for(int t2 = 0; t2 < T2; t2 ++){
                    if((B<<(t2-1)) > M) break;
                    int num = B<<t2;
                    //stop
                    double v = tP(X-num+B);
                    //continue
                    if(num <= M) v = max(v, 0.5 * P[X][B][t2+1] + 0.5 * tP(X+B));
                    update(P[X][B][t2], v);
                }
            }
        }
    }
//    printf("%.9lf\n", P[4][1][6]);
     for(int X = 1; X < V; X ++){
//         printf("X = %d ans = %.10lf\n", X, P[X][0][0]);
            //P[X][0][0]..
            for(int B = 1; B < min(X, M); B ++){
//                double v = 0.5 * tP(X+B) + 0.5 * P[X][B][1];
//                update(P[X][0][0], v);
            }
            //P[X][B][t2];
            for(int B = 1; B <= min(X, M); B ++){
                for(int t2 = 0; t2 < T2; t2 ++){
//                    if(cas == 3) printf("X = %d B = %d t2 = %d ans = %lf\n", X, B, t2, P[X][B][t2]);
                }
            }
     }
    printf("%.9lf ", P[A][0][0]);
    int ans2 = 0;
    for(int B = min(A, M); B >= 0; B --){
        double v = 0.5 * tP(A+B) + 0.5 * P[A][B][1];
        if(sgn(P[A][0][0]-v) == 0){
            ans2 = B; break;
        }
    }
    printf("%d\n", ans2);
}
int main() {
    freopen("e2.in", "r", stdin);
    freopen("e2.out", "w", stdout);
    int test;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d: ", ++cas);
        fprintf(stderr, "case = %d\n", cas);
        solve();
//        break;
    }
    return 0;
}



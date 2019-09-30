#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <queue>
#include <list>
#include <string.h>
#define sf scanf
#define pf printf
#define lf double
#define ll long long
#define p123 printf("123\n");
#define pn printf("\n");
#define pk printf(" ");
#define p(n) printf("%d",n);
#define pln(n) printf("%d\n",n);
#define s(n) scanf("%d",&n);
#define ss(n) scanf("%s",n);
#define ps(n) printf("%s",n);
#define sld(n) scanf("%lld",&n);
#define pld(n) printf("%lld",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c",n);
#define gc getchar();
#define re(n,a) memset(n,a,sizeof(n));
#define len(a) strlen(a)
#define LL long long
#define eps 1e-6
using namespace std;
const double pi = 3.1415926535;
/*
https://codeforces.com/contest/1106/problems
https://codeforces.com/contest/1106/submit
*/
char a[100][100];
char b[100][100];
int main() {
    int n,m;
    re(a,0);
    re(b,0);

    s(n) s(m) gc;
    for( int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            a[i][j] = gc;
        }
        gc;
    }

    for( int i = 1; i <= m; i ++){
        for(int j = 1; j <=m; j ++){
            b[i][j] = gc;
        }
        gc;
    }
    for(int i = 1; i <= n-m+1; i ++){
        for(int j = 1; j <= n-m+1; j ++){
            for(int k = 1; k <= m; k ++){
                for(int l = 1; l <= m ;l ++){
                    if(a[i+k-1][j+l-1] != b[k][l]){
                        goto l;
                    }
                }
            }
            puts("Yes");
            return 0;
            l:0;
        }
    }
    puts("No");


    return 0;
}



 //1 1 1 1 2 2 2 3 3 5 6 6 8 8 11 ./Main.cpp:72:15: warning: expression result unused [-Wunused-value]
            l:0;
              ^
1 warning generated.
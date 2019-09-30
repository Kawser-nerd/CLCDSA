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
char c[200500];
int main() {
    ss(c)
    int lena = len(c);
    int x = -1,y = -1;
    for(int i = 0; i < lena; i ++){
        if(c[i] == 'A' && x == -1){
            x = i;
        }
    }
    for(int i = lena-1; i >= 0; i --){
        if(c[i] == 'Z' && y == -1){
            y = i;
        }
    }
    p(y-x+1)


    return 0;
}
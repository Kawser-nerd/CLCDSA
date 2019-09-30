#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define COUT(a) cout << a;
#define ENDL cout << "\n";
int main() {
    int a,b;
    char s;
    scanf("%d %c %d\n",&a, &s,&b);
    if(s == '+') COUT(a+b)
    else if(s == '-') COUT(a-b)
}
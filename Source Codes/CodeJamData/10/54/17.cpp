#include <map>
#include <iostream>
#include <deque>
#include <list>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOREACH(i,c) for(__typeof((c).begin()) i =(c).begin();i!=(c).end();++i)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int NIL = (-1);

bool c[10][10];

int n,b;

bool can_add(int x) {
    int i = 0;
    while(x>0) {
        if (c[i][x%b]) return false;
        i++;
        x/=b;
    
    }
    return true;
}

void add(int x, bool state) {
    int i = 0;
    while(x>0) {
        c[i][x%b] = state;
        i++;
        x/=b;
    }
}

int cnt;

void rec(int m, int k) {
    if (m==0) { cnt++; return; }
    for(int i=k;i<=m;i++) {
        if (can_add(i)) {
            add(i, 1);
            rec(m-i, i+1);
            add(i, 0);
        }
    }
}

void scase() {
    scanf("%d%d",&n,&b);
    cnt = 0;
    REP(i,10) REP(j,10) c[i][j] = 0;
    rec(n,1);
    printf("%d\n",cnt);

}

int main() {
    int j;
    scanf("%d",&j);
    for(int i=1;i<=j;i++) {
        printf("Case #%d: ",i);
        scase();
    }
    return 0;
}


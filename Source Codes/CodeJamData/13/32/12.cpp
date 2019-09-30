// Artur Kraska, II UWr

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>


#define znak(z)                     ((z) <= '9' ? (z)-'0' : (z) - 'A'+10)
#define forr(it, lim)               for(int it=0; it < (lim); it++)
#define foreach(iter, coll)         for(typeof(coll.begin()) iter = coll.begin(); iter != coll.end(); ++iter)
#define foreachr(iter, coll)        for(typeof(coll.rbegin()) iter = coll.rbegin(); iter != coll.rend(); ++iter)
#define lbound(P,R,PRED)            ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})
#define CLEAR(TABB)                 memset(TABB, 0, sizeof(TABB));
#define vv(type, name, ...)         type name ## 77[] = { __VA_ARGS__ }; vector <type> name(name ## 77, (name ## 77)+sizeof(name ## 77)/sizeof(name ## 77[0]));
#define testy()                     int tests;scanf("%d", &tests);forr(test, tests)
#define jest(coll, val)             (coll.find(val) != coll.end())
#define deb(X)                      X

#define M   1000000007
#define INF 1000000007

const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
#define GET(ZZZ){ZZZ='a';if(BUF_POS<BUF_SIZE)ZZZ=BUFOR[BUF_POS++];\
else if(!feof(stdin)){BUF_SIZE=fread(BUFOR,1,MAX_BUF_SIZE,stdin);\
ZZZ=BUFOR[0];BUF_POS=1;}}
#define GI(WW){do{GET(ZZZ);}while(!isdigit(ZZZ));WW=ZZZ-'0';\
while(1){GET(ZZZ);if(!isdigit(ZZZ))break;WW=WW*10+(ZZZ-'0');}}
#define GC(WW){do{GET(ZZZ);}while(!isalpha(ZZZ));WW=ZZZ;}

using namespace std;

bool reachable(int x, int y, int ile)
{
    int odl = ile*(ile+1)/2, suma = abs(x)+abs(y);
    return (suma <= odl) && (odl%2 == suma%2);
}

void reach(int x, int y, int ile)
{
//    cout << " celuje w " << x << ", " << y << " w " << ile << " ruchach" << endl;
    if(x == 0 && y == 0 && ile == 0)
        return ;
    if(reachable(x, y-ile, ile-1))
    {
        reach(x, y-ile, ile-1);
        printf("N");
        return ;
    }
    if(reachable(x, y+ile, ile-1))
    {
        reach(x, y+ile, ile-1);
        printf("S");
        return ;
    }
    if(reachable(x-ile, y, ile-1))
    {
        reach(x-ile, y, ile-1);
        printf("E");
        return ;
    }
    if(reachable(x+ile, y, ile-1))
    {
        reach(x+ile, y, ile-1);
        printf("W");
        return ;
    }

    printf("??? doesnot work :(");
}

int main()
{
    int x, y;

    testy()
    {
        scanf("%d %d", &x, &y);
        int odl = x+y;
        int ile = 0, sum = 0;
        while(!reachable(x, y, ile))
            ile++;

        printf("Case #%d: ", test+1);

        reach(x, y, ile);

        printf("\n");

    }

    return 0;
}


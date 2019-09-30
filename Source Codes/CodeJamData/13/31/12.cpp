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

int n;
char slowo[10000007];
bool samogloska[128];

int main()
{
    samogloska['a'] = 1;
    samogloska['e'] = 1;
    samogloska['i'] = 1;
    samogloska['o'] = 1;
    samogloska['u'] = 1;

    testy()
    {

        scanf("%s %d", slowo, &n);

        int sp = 0, last_pocz = -1;
        long long wynik = 0;

        for(int i=0; slowo[i]; i++)
        {
            if(samogloska[slowo[i]])
                sp = 0;
            else
                sp++;


            if(sp >= n)
                last_pocz = i - n + 1;

            wynik += last_pocz+1;
            //cout << "i: " << i << ", sp: " << sp << ", last_pocz: " << last_pocz << ", wynik: " << wynik << endl;
        }

        printf("Case #%d: ", test+1);
        cout << wynik << endl;

    }

    return 0;
}


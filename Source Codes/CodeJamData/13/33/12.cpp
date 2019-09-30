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

#define size 4194304

struct przedzial
{
    int l, p;
    int s;
};
map <int, int> mapa;


class comp
{
     public:
     bool operator ()(const pair<int, przedzial> & f, const pair<int, przedzial> & s)
     {
          return f.first < s.first;
     }
};
multiset <pair<int, przedzial> , comp> S, S2;


struct drzewo
{
    int minn;
    int ile;
};
drzewo d[10000007];

void wkladaj(int nr, int pocz, int kon, int p, int k, int ile)
{
    if(pocz == p && kon == k)
    {
        //cout << "                         wklada " << ile << " na przedziale " << p << ", " << k << endl;
        d[nr].ile = max(ile, d[nr].ile);
        d[nr].minn = max(d[nr].minn, d[nr].ile);
    }
    else
    {
        int s = (pocz + kon) >> 1;
        if(k <= s)
            wkladaj(nr<<1, pocz, s, p, k, ile);
        else
        {
            if(p > s)
                wkladaj((nr<<1)+1, s+1, kon, p, k, ile);
            else
            {
                wkladaj(nr<<1, pocz, s, p, s, ile);
                wkladaj((nr<<1)+1, s+1, kon, s+1, k, ile);
            }
        }
    }

    if(nr < size)
    {
        d[nr].minn = max(d[nr].ile, min(d[nr<<1].minn, d[(nr<<1)+1].minn));
    }
}

int minimum(int nr, int pocz, int kon, int p, int k)
{
    if(pocz == p && kon == k)
    {
        //cout << "                       minimum na przedziale " << p << ", " << k << " wynosi " << d[nr].minn << endl;
        return max(d[nr].minn, d[nr].ile);
    }
    else
    {
        int s = (pocz + kon) >> 1;
        if(k <= s)
            return max(minimum(nr<<1, pocz, s, p, k), d[nr].ile);
        else
        {
            if(p > s)
                return max(minimum((nr<<1)+1, s+1, kon, p, k), d[nr].ile);
            else
            {
                return max(min(minimum(nr<<1, pocz, s, p, s),
                            minimum((nr<<1)+1, s+1, kon, s+1, k)), d[nr].ile);
            }
        }
    }
}

int main()
{
    int n, m, day, dd, dp, ds;
    przedzial p;

    testy()
    {
        scanf("%d", &n);
        S.clear();
        S2.clear();
        mapa.clear();
        CLEAR(d);

        forr(i, n)
        {
            scanf("%d %d %d %d %d %d %d %d", &day, &m, &p.l, &p.p, &p.s, &dd, &dp, &ds);
            p.p--;
            forr(j, m)
            {
                S.insert(make_pair(day, p));
                day += dd;
                p.l += dp;
                p.p += dp;
                p.s += ds;
            }
        }

//        foreach(it, S)
//            cout << "dzien: " << it->first << ", pocz: " << it->second.l << ", kon: " << it->second.p << ", sila: " << it->second.s << endl;

        foreach(it, S)
        {
            mapa[it->second.l] = 1;
            mapa[it->second.p] = 1;
        }

        int numm = 0;

        foreach(it, mapa)
        {
            it->second = numm;
            numm+=2;
        }

        foreach(it, S)
        {
            p.l = mapa[it->second.l];
            p.p = mapa[it->second.p];
            p.s = it->second.s;

            S2.insert(make_pair(it->first, p));
        }
//        cout << "numm: " << numm << endl;


//        foreach(it, S2)
//            cout << "dzien: " << it->first << ", pocz: " << it->second.l << ", kon: " << it->second.p << ", sila: " << it->second.s << endl;


        int result = 0;
        int last_day = -INF;
        list <przedzial> do_wpisania;
        do_wpisania.clear();

        foreach(it, S2)
        {
            if(last_day != it->first)
            {
                foreach(itt, do_wpisania)
                {
//                    cout << " wklada " << itt->s << " na przedziale " << itt->l << ", " << itt->p << endl;
                    wkladaj(1, 0, size-1, itt->l, itt->p, itt->s);
                }
                do_wpisania.clear();
                last_day = it->first;
            }

            p = it->second;
            int minn = minimum(1, 0, size-1, p.l, p.p);

//            cout << " minimum na przedziale " << p.l << ", " << p.p << " wynosi " << minn << endl;

            if(minn < p.s)
            {
                result++;
                do_wpisania.push_back(p);
            }
        }


        printf("Case #%d: ", test+1);
        printf("%d\n", result);
    }

    return 0;
}


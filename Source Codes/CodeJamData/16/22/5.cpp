/**
 *    author:  [itmo] enot.1.10
 *    created: 30.04.2016 19:15:20       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

typedef unsigned long long ull;

const ull INF = 1.01e19;

char s1[20];
char s2[20];

char t1[20];
char t2[20];

int n1, n2;

ull R1, R2;
ull diff;

void MIN(char *t, char *s, int n)
{
    forn(i, n)
    {
        t[i] = s[i];
        if (s[i] == '?') t[i] = '0';
    }
}

void MAX(char *t, char *s, int n)
{
    forn(i, n)
    {
        t[i] = s[i];
        if (s[i] == '?') t[i] = '9';
    }
}

void calc()
{
    ull V1 = 0, V2 = 0;
    for (int i = n1 - 1; i >= 0; --i)
    {
        V1 = V1 * 10 + t1[i] - '0';
        V2 = V2 * 10 + t2[i] - '0';
    }

    ull vdiff;
    if (V1 >= V2) vdiff = V1 - V2;
    else vdiff = V2 - V1;

    if (diff > vdiff || (diff == vdiff && (R1 > V1 || (R1 == V1 && R2 > V2))))
    {
        R1 = V1;
        R2 = V2;
        diff = vdiff;
    }
}

void write(ull R, char * t)
{
    forn(i, n1)
    {
        t[i] = R % 10 + '0';
        R /= 10;
    }
    reverse(t, t + n1);
}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif                       
    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        printf("Case #%d: ", tt + 1);
        scanf("%s%s", s1, s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        reverse(s1, s1 + n1);
        reverse(s2, s2 + n2);
        while (n1 < n2) s1[n1++] = '0';
        while (n2 < n1) s2[n2++] = '0';

        s1[n1] = 0, s2[n2] = 0;
        t1[n1] = 0, t2[n2] = 0;

        R1 = INF;
        R2 = 0;
        diff = INF;

        for (int i = n1 - 1; i >= 0; --i)
        {
            if (s1[i] == '?')
            {
                if (s2[i] == '?') t2[i] = '0';
                else t2[i] = s2[i];
                t1[i] = min((int)'9', t2[i] + 1);

                MIN(t1, s1, i);
                MAX(t2, s2, i);

                calc();

                t1[i] = max((int)'0', t2[i] - 1);

                MAX(t1, s1, i);
                MIN(t2, s2, i);
                
                calc();
            }
            
            if (s2[i] == '?')
            {
                if (s1[i] == '?') t1[i] = '0';
                else t1[i] = s1[i];
                t2[i] = min((int)'9', t1[i] + 1);

                MAX(t1, s1, i);
                MIN(t2, s2, i);

                calc();

                t2[i] = max((int)'0', t1[i] - 1);

                MIN(t1, s1, i);
                MAX(t2, s2, i);

                calc();
            }

            t1[i] = s1[i], t2[i] = s2[i];
            if (s1[i] == '?' && s2[i] == '?') t1[i] = '0', t2[i] = '0';
            else if (s1[i] == '?') t1[i] = t2[i];
            else if (s2[i] == '?') t2[i] = t1[i];
            else if (s1[i] < s2[i])
            {
                MAX(t1, s1, i);
                MIN(t2, s2, i);

                calc();
            }
            else if (s2[i] < s1[i])
            {
                MIN(t1, s1, i);
                MAX(t2, s2, i);

                calc();
            }
                
                
        }
        calc();

        write(R1, t1);
        write(R2, t2);
        
        printf("%s %s\n", t1, t2);
    }



             
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}

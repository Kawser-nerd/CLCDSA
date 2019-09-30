/**
 *    author:  [itmo] enot.1.10
 *    created: 30.04.2016 19:01:28       
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

char s[2010];
map<char, int> M;


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
        scanf("%s", s);
        M.clear();
        int n = strlen(s);
        forn(i, n) M[s[i]]++;

        string res = "";

        while (M['G'] > 0)
        {
            res += '8';
            for (auto c : "EIGHT") M[c]--;
        }

        while (M['U'] > 0)
        {
            res += '4';
            for (auto c : "FOUR") M[c]--;
        }

        while (M['Z'] > 0)
        {
            res += '0';
            for (auto c : "ZERO") M[c]--;
        }

        while (M['W'] > 0)
        {
            res += '2';
            for (auto c : "TWO") M[c]--;
        }

        while (M['F'] > 0)
        {
            res += '5';
            for (auto c : "FIVE") M[c]--;
        }

        while (M['X'] > 0)
        {
            res += '6';
            for (auto c : "SIX") M[c]--;
        }

        while (M['R'] > 0)
        {
            res += '3';
            for (auto c : "THREE") M[c]--;
        }

        while (M['S'] > 0)
        {
            res += '7';
            for (auto c : "SEVEN") M[c]--;
        }

        while (M['O'] > 0)
        {
            res += '1';
            for (auto c : "ONE") M[c]--;
        }

        while (M['I'] > 0)
        {
            res += '9';
            for (auto c : "NINE") M[c]--;
        }


        sort(all(res));
        printf("Case #%d: %s\n", tt + 1, res.data());
    }
                    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}

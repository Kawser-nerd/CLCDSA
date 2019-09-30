// Includes, declarations {{{
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <bitset>
using namespace std;
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,x) for(__typeof((x).begin())i=(x).begin();i!=(x).end();++i)
#define Dprintf(x...) fprintf(stderr, x);
typedef vector<int> VI;  typedef vector<VI> VVI;
typedef vector<string> VS;  typedef long long LL;
double PI = 2*acos(0.0);
// }}}
// String utils {{{
string readline() {
	string s; getline(cin, s);
	while (s.size() != 0 && isspace(s[s.size() - 1])) s.resize(s.size() - 1);
	return s;
}

string trim(const string &s) {
	size_t i, j, n = s.size();
	for (i = 0; i < n && isspace(s[i]); ++i) {}
	for (j = n; j > i + 1 && isspace(s[j-1]); --j) {}
	return s.substr(i, j - i);
}

vector<string> split(const string &s, const string &delims = " \t") {
	vector<string> res;
	for (size_t i = 0, j; i < s.size(); i = j + 1) {
		for (j = i; j < s.size() && delims.find(s[j]) == string::npos; ++j) {}
		if (j > i) res.push_back(s.substr(i, j - i));
	}
	return res;
}

LL atoi(string s) { return atoll(s.c_str()); }

template<typename T>
string tostr(const T &x) {
    stringstream os;
    os << x;
    return os.str();
}

string fmt(const char *f, ...) {
	va_list va; char *p = NULL; va_start(va, f);
	if (vasprintf(&p, f, va) < 0) return "";
	else { string s(p); free(p); return s; }
}

template<typename T> ostream &operator <<(ostream &o, const vector<T> &v) {
	o << "["; for (size_t i = 0; i < v.size(); i++) o << (i==0?"":", ") << v[i]; return o << "]";
}
// }}}

int reverse(int x)
{
    int y = 0;
    while (x != 0) {
        y = y * 10 + (x % 10);
        x /= 10;
    }
    return y;
}

int pow(int x, int k) {
    int y = 1;
    for (int i = 0; i < k; i++)
        y *= x;
    return y;
}

int dec_length(int x) {
    int k = 0;
    while (x > 0) {
        x /= 10;
        k++;
    }
    return k;
}

vector<LL> pals;
LL MOD = 1000000007LL;
LL INV2 = 500000004;

LL solve(LL L, LL R)
{
    assert((INV2 * 2) % MOD == 1);

    vector<LL> gaps;
    int i = 0;
    while (pals[i] < L) i++;

    if (pals[i] > R) {
        LL g = R - L + 1;
        gaps.push_back(g);
    } else {
        gaps.push_back(pals[i] - L);
        while (pals[i+1] <= R) {
            gaps.push_back(pals[i+1] - pals[i] - 1);
            i++;
        }
        gaps.push_back(R - pals[i]);
    }
/*
    cout << " L=" << L << " R=" << R << " pals:";
    for (int i = 0; pals[i] <= R; i++)
        if (pals[i] >= L) cout << " " << pals[i];

    cout << "  gaps:";
    for (int i = 0; i < (int)gaps.size(); i++)
        cout << " " << gaps[i];
    cout << "  ";*/


    LL res = 0;
    for (int i = 0; i < gaps.size(); i++) {
        LL g = gaps[i];
        if (g > 0) {
            g %= MOD;
            res = (res + g * (g + 1) / 2) % MOD;
        }
    }

    if (gaps.size() <= 1) return res;

    int K = gaps.size();
    vector<LL> sum(K+10, 0);
    for (int i = K-1; i >= 1; i--) {
        sum[i] = 1 + (gaps[i] % MOD) + sum[i+2];
        sum[i] %= MOD;
    }

    for (int i = 0; i < K; i++) {
        LL p = gaps[i] + 1;
        LL q = sum[i+2];
        p %= MOD;
        q %= MOD;
        res = (res + p*q) % MOD;
    }

    return res;
}

int main()
{
    {
        for (int l = 0; l <= 1000000; l++) {
            int len = dec_length(l);
            LL tlen = pow(10, len);

            LL n = l * tlen + reverse(l);
            pals.push_back(n);

            for (int c = 0; c <= 9; c++) {
                n = l * tlen * 10LL + c * tlen + reverse(l);
                pals.push_back(n);
            }
        }

        sort(pals.begin(), pals.end());
        pals.erase(unique(pals.begin(), pals.end()), pals.end());
    }

	int numCases = atoi(readline());
	for (int caseId = 1; caseId <= numCases; caseId++) {
        printf("Case #%d: ", caseId); fflush(stdout);

        LL L, R;
        cin >> L >> R;

        cout << solve(L, R) << endl;
	}
}

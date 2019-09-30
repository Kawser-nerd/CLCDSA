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

int MOD = 10009;

struct Monom {
    int e[26]; // exponents

    Monom() { memset(e, 0, sizeof(e)); }
    Monom(const string &s) {
        memset(e, 0, sizeof(e));
        for (size_t i = 0; i < s.size(); i++) {
            assert(islower(s[i]));
            ++e[s[i] - 'a'];
        }
    }

    void operator *=(const Monom &m) {
        for (int i = 0; i < 26; i++)
            e[i] += m.e[i];
    }

    int eval(const Monom &vals) const {
        int res = 1;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < e[i]; j++)
                res = (res * vals.e[i]) % MOD;
        }
        return res;
    }
};

ostream &operator <<(ostream &o, const Monom &v) {
    for (size_t i = 0; i < 26; i++) {
        for (int j = 0; j < v.e[i]; j++)
            o << (char)('a' + i);
    }
    return o;
}

struct Polynom {
    vector<Monom> m;
    vector<int> c;

    Polynom() {}

    Polynom(const string &s) {
        vector<string> v = split(s, "+");
        for (int i = 0; i < (int)v.size(); i++) {
            c.push_back(1);
            m.push_back(Monom(v[i]));
        }
    }

};

ostream &operator <<(ostream &o, const Polynom &v) {
    for (size_t i = 0; i < v.m.size(); i++)
        o << (i == 0 ? "" : " + ") << v.c[i] << "*" << v.m[i];
    return o;
}

vector<Monom> monoms;
vector<Monom> dict;

Monom sub_monom[10];

int rec(const char *s, int K)
{
    if (*s == 0) {
        int res = 1;
        for (int i = 0; i < K; i++) {
//            cout << "(" << sub_monom[i] << ")";

            int sum = 0;
            for (int j = 0; j < (int)dict.size(); j++) {
                sum += sub_monom[i].eval(dict[j]);
            }
            sum %= MOD;
            res = (res * sum) % MOD;
        }
  //      cout << " ";
        return res;
    } else {
        int v = *s - 'a';
        int res = 0;
        for (int i = 0; i < K; i++) {
            ++sub_monom[i].e[v];
            res += rec(s+1, K);
            --sub_monom[i].e[v];
        }
        return res % MOD;
    }
}

int eval(Monom monom, int K)
{
    string s = tostr(monom);
    sort(s.begin(), s.end());
//    cout << "\nK=" << K << " cur_monom=" << s << " ";
    for (int i = 0; i < K; i++) sub_monom[i] = Monom();
    int res = rec(s.c_str(), K);
    return res;
}

int main()
{
	int numCases = atoi(readline());
	for (int caseId = 1; caseId <= numCases; caseId++) {
        printf("Case #%d:", caseId); fflush(stdout);

        string poly_s;
        int K;
        cin >> poly_s >> K;

        int N;
        cin >> N;
        dict.clear();
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            dict.push_back(Monom(s));
        }

        Polynom poly(poly_s);
        for (int k = 1; k <= K; k++) {
            int res = 0;
            for (int i = 0; i < (int)poly.m.size(); i++) {
                Monom m = poly.m[i];
                res = (res + eval(m, k)) % MOD;
            }
            printf(" %d", res);
        }
        printf("\n");
	}
}

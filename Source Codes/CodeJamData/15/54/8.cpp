#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }

    ios::sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

static vector<pair<ll, ll> > elide(vector<pair<ll, ll> > terms, ll v)
{
    vector<pair<ll, ll> > terms2;
    if (v == 0)
    {
        terms2 = move(terms);
        for (auto &term : terms2)
        {
            if (term.second & 1)
                return {};
            term.second /= 2;
        }
    }
    else
    {
        while (!terms.empty())
        {
            if (terms.back().second == 0)
            {
                terms.pop_back();
                continue;
            }
            ll f = terms.back().second;
            ll q = terms.back().first - v;
            int pos = 0;
            while (pos < SZ(terms) && terms[pos].first != q)
                pos++;
            if (pos == SZ(terms) || terms[pos].second < f)
                return {};
            terms2.emplace_back(q, f);
            terms[pos].second -= f;
            terms.pop_back();
        }
        sort(RA(terms2));
    }
    return terms2;
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int P;
        cin >> P;
        vector<pair<ll, ll> > terms(P);
        for (int i = 0; i < P; i++)
            cin >> terms[i].first;
        for (int i = 0; i < P; i++)
            cin >> terms[i].second;

        ll delta = -terms[0].first;
        for (int i = 0; i < P; i++)
            terms[i].first += delta;
        auto orig_terms = terms;

        vector<ll> S;
        while (terms.size() > 1 || terms[0].second > 1)
        {
            ll v;
            if (terms[0].second > 1)
            {
                v = 0;
                for (auto &t : terms)
                    t.second /= 2;
            }
            else
            {
                v = terms[1].first;
                terms = elide(terms, v);
                assert(!terms.empty());
            }
            S.push_back(v);
        }

        terms = orig_terms;
        sort(RA(S));
        vector<ll> negs;
        while (delta)
        {
            int i;
            for (i = SZ(S) - 1; i >= 0; i--)
            {
                if (S[i] <= delta)
                {
                    auto trial = elide(terms, S[i]);
                    int pos = 0;
                    while (pos < SZ(trial) && trial[pos].first != delta - S[i])
                        pos++;
                    if (pos < SZ(trial))
                        break;
                }
            }
            assert(i >= 0);
            negs.push_back(-S[i]);
            delta -= S[i];
            S.erase(S.begin() + i);
        }
        copy(RA(negs), back_inserter(S));
        sort(RA(S));

        cout << "Case #" << cas + 1 << ":";
        for (ll s : S)
            cout << ' ' << s;
        cout << '\n';
    }
    return 0;
}

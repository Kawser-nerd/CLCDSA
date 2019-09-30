#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static vector<string> tokenize(const string &s)
{
    vs toks;
    for (int i = 0; i < SZ(s); i++)
    {
        switch (s[i])
        {
        case ' ':
        case '\n':
        case '\t':
            break;
        case '(':
        case ')':
            toks.push_back(string(1, s[i]));
            break;
        default:
            int j = i;
            while (j < SZ(s) && s[j] != ' ' && s[j] != '\n' && s[j] != ')' && s[j] != '(')
                j++;
            toks.push_back(s.substr(i, j - i));
            i = j - 1;
            break;
        }
    }
    return toks;
}

struct tree
{
    bool leaf;
    string feature;
    double prob;
    tree *left;
    tree *right;

    tree() : leaf(true), feature(), prob(1.0), left(NULL), right(NULL) {}

    ~tree()
    {
        delete left;
        delete right;
    }
};

static tree *make_tree(const vs &toks, int &start)
{
    tree *t = new tree;

    assert(toks[start] == "(");
    start++;
    sscanf(toks[start++].c_str(), "%lf", &t->prob);
    if (toks[start] != ")")
    {
        t->leaf = false;
        t->feature = toks[start++];
        t->left = make_tree(toks, start);
        t->right = make_tree(toks, start);
    }
    assert(toks[start] == ")");
    start++;
    return t;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        printf("Case #%d:\n", cas + 1);

        int L;
        cin >> L >> ws;
        string raw;
        for (int i = 0; i < L; i++)
        {
            string line;
            getline(cin, line);
            raw = raw + ' ' + line;
        }

        vs toks = tokenize(raw);
        int start = 0;
        tree *root = make_tree(toks, start);

        int A;
        cin >> A;
        for (int i = 0; i < A; i++)
        {
            string name;
            int F;
            set<string> features;

            cin >> name >> F;
            for (int j = 0; j < F; j++)
            {
                string f;
                cin >> f;
                features.insert(f);
            }

            tree *cur = root;
            double p = 1.0;
            while (!cur->leaf)
            {
                p *= cur->prob;
                if (features.count(cur->feature))
                    cur = cur->left;
                else
                    cur = cur->right;
            }
            p *= cur->prob;
            printf("%.9f\n", p);
        }
        delete root;
    }
    return 0;
}
